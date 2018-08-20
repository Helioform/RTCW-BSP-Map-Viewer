
#include "HelperFunctions.h"

LPCWSTR StringToLPCWSTR(const std::string& s)
{
	std::wstring wideString = std::wstring(s.begin(), s.end());
	return wideString.c_str();
}

void HSVtoRGB(float h, float s, float v, float* rgb) {
	int i;
	float f;
	float p, q, t;

	h *= 5;

	i = floor(h);
	f = h - i;

	p = v * (1 - s);
	q = v * (1 - s * f);
	t = v * (1 - s * (1 - f));

	switch (i)
	{
	case 0:
		rgb[0] = v;
		rgb[1] = t;
		rgb[2] = p;
		break;
	case 1:
		rgb[0] = q;
		rgb[1] = v;
		rgb[2] = p;
		break;
	case 2:
		rgb[0] = p;
		rgb[1] = v;
		rgb[2] = t;
		break;
	case 3:
		rgb[0] = p;
		rgb[1] = q;
		rgb[2] = v;
		break;
	case 4:
		rgb[0] = t;
		rgb[1] = p;
		rgb[2] = v;
		break;
	case 5:
		rgb[0] = v;
		rgb[1] = p;
		rgb[2] = q;
		break;
	}
}

void ColorShiftLightingBytes(unsigned char in[4], unsigned char out[4])
{
	int shift, r, g, b;

	// shift the color data based on overbright range
	shift = 4 - 1;//r_mapOverBrightBits->integer - tr.overbrightBits;

	// shift the data based on overbright range
	r = in[0] << shift;
	g = in[1] << shift;
	b = in[2] << shift;

	// normalize by color instead of saturating to white
	if ((r | g | b) > 255)
	{
		int max;

		max = r > g ? r : g;
		max = max > b ? max : b;
		r = r * 255 / max;
		g = g * 255 / max;
		b = b * 255 / max;
	}

	out[0] = r;
	out[1] = g;
	out[2] = b;
	out[3] = in[3];
}

bool GetFileNames(const std::string& path, std::vector<std::string>& fileNames)
{
	WIN32_FIND_DATA ffd;
	LARGE_INTEGER fileSize;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD error = 0;

	std::wstring wideString = std::wstring(path.begin(), path.end());
	LPCWSTR wpath = wideString.c_str();
	LPCSTR wpath2 = path.c_str();

#if defined(ENV64BIT)
	hFind = FindFirstFile(wpath, &ffd);
#elif defined(ENV32BIT)
	hFind = FindFirstFile(wpath2, &ffd);
#endif

	if (INVALID_HANDLE_VALUE == hFind)
		return false;

	do
	{
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			continue;
		}
		else
		{
			std::string fileName;
#if defined(ENV64BIT)
		fileName = CW2A(ffd.cFileName);
#elif defined(ENV32BIT)
		fileName = ffd.cFileName;
#endif

			fileNames.push_back(fileName);
		}

	} while (FindNextFile(hFind, &ffd) != 0);

	return true;
}

int StrCaseCmpN(const char *s1, const char *s2, int n)
{
	int c1, c2;

	do
	{
		c1 = *s1++;
		c2 = *s2++;

		if (!n--)
			return 0;       // strings are equal until end point

		if (c1 != c2)
		{
			if (c1 >= 'a' && c1 <= 'z') 
				c1 -= ('a' - 'A');
		
			if (c2 >= 'a' && c2 <= 'z') 
				c2 -= ('a' - 'A');
		
			if (c1 != c2)
				return c1 < c2 ? -1 : 1;
		}

	} while (c1);

	return 0;       // strings are equal
}

int StrCaseCmp(const char* s1, const char* s2)
{
	return StrCaseCmpN(s1, s2, 999999);
}
