
#include "TGAImage.h"

TGAImage::TGAImage()
{
	m_height = m_width = m_bitsPerPixel = m_imageSize = 0;
	m_imageData = nullptr;
}

TGAImage::~TGAImage()
{
	if(m_imageData)
		delete [] m_imageData;
}

bool TGAImage::Load(std::string fileName)
{
	std::ifstream tgaFile;
	tgaFile.open(fileName.c_str(), std::ios::binary);

	if (!tgaFile.is_open())
		return false;

	TGAHeader head;

	tgaFile.read((char*)(&head), sizeof(TGAHeader));
	
	if (head.dataTypeCode != 2 && head.dataTypeCode != 10) // don't allow encoded images
	{
		tgaFile.close();
		return false;
	}

	if (head.bitsPerPixel != 24 && head.bitsPerPixel != 32)
	{
		tgaFile.close();
		return false;
	}

	m_height = head.height;
	m_width = head.width;
	m_bitsPerPixel = head.bitsPerPixel;
	int pitch = head.bitsPerPixel / 8;
	m_imageSize = 4 * head.width * head.height; // allow space for a 32 bit image
	m_imageData = new unsigned char[m_imageSize];
	

	tgaFile.seekg(head.idLength + head.colourMapType * head.colourMapLength, std::ios::cur);
	unsigned char* imageData = new unsigned char[m_imageSize];

	tgaFile.read((char*)imageData, m_imageSize);
	unsigned char* rgb = imageData;

	int rowStart, colStart;
	int r, g, b, a;

	for (int i = m_height-1 ; i >= 0; i--) // start from last row to load it upside down
	{
		rowStart = i * 4 * m_width;

		for (int j = 0; j < m_width; j++)
		{
			colStart = 4 * j;

			if (m_bitsPerPixel == 32)
			{			
				b = *rgb++;
				g = *rgb++;
				r = *rgb++;
				a = *rgb++;
				m_imageData[rowStart + colStart + 0] = r;
				m_imageData[rowStart + colStart + 1] = g;
				m_imageData[rowStart + colStart + 2] = b;
				m_imageData[rowStart + colStart + 3] = a;
			}
			else if (m_bitsPerPixel == 24)
			{			
			
				m_imageData[rowStart + colStart + 2] = *rgb++;
				m_imageData[rowStart + colStart + 1] = *rgb++;
				m_imageData[rowStart + colStart + 0] = *rgb++;
				m_imageData[rowStart + colStart + 3] = 255;
			}
		}
	}

	delete [] imageData;
	tgaFile.close();

	return true;
}

bool TGAImage::Save(std::string fileName, unsigned char* imageData, int width, int height, int bpp)
{
	std::ofstream tgaFile;
	tgaFile.open(fileName.c_str(), std::ios::binary);

	if (!tgaFile.is_open())
		return false;

	TGAHeader header;
	TGAFooter footer;

	header.bitsPerPixel = bpp;
	header.dataTypeCode = 2;
	header.width = width;
	header.height = height;
	header.xOrigin = 0;
	header.yOrigin = 0;
	header.colourMapType = 0;
	header.colourMapDepth = 0;
	header.colourMapLength = 0;
	header.colourMapOrigin = 0;
	header.idLength = 0;
	header.imageDescriptor = 0;
	
	int size = width * height * (bpp/4);

	tgaFile.write((char*)&header, sizeof(header));
	tgaFile.write((char*)&imageData, size);

	const char* signature = "TRUEVISION-XFILE";
	memcpy(&footer.signature, signature, strlen(signature));
	footer.extOffset = sizeof(header) +  + sizeof(footer);
	footer.dev = 0;

	tgaFile.write((char*)&footer, sizeof(footer));

	return true;
}
