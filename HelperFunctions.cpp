#include "stdafx.h"
#include "HelperFunctions.h"

LPCWSTR StringToLPCWSTR(const std::string& s)
{
	std::wstring wideString = std::wstring(s.begin(), s.end());
	return wideString.c_str();
}

void HSVtoRGB(float h, float s, float v, float rgb[3]) {
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

void ColorShiftLightingBytes(char in[4], char out[4])
{
	int shift, r, g, b;

	// shift the color data based on overbright range
	shift = 2 - 1;//r_mapOverBrightBits->integer - tr.overbrightBits;

	// shift the data based on overbright range
	r = in[0] << shift;
	g = in[1] << shift;
	b = in[2] << shift;

	// normalize by color instead of saturating to white
	if ((r | g | b) > 255) {
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