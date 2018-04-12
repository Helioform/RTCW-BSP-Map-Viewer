
#include "TGAImage.h"

TGAImage::TGAImage()
{
	m_height = m_width = m_bitsPerPixel = m_imageSize = 0;
}

TGAImage::~TGAImage()
{
	m_imageData.clear();

}

bool TGAImage::Load(std::string fileName)
{
	std::ifstream tgaFile;
	tgaFile.open(fileName.c_str(), std::ios::binary);

	if (!tgaFile.is_open())
		return false;

	TGAHeader head;

	tgaFile.read((char*)(&head), sizeof(TGAHeader));
	
	if (head.dataTypeCode != 2 && head.dataTypeCode != 10)
		return false;

	if (head.bitsPerPixel != 24 && head.bitsPerPixel != 32)
		return false;
	m_height = head.height;
	m_width = head.width;
	m_bitsPerPixel = head.bitsPerPixel;
	m_imageSize = (head.bitsPerPixel / 8) * head.width * head.height;
	m_imageData.reserve(m_imageSize);
	
	tgaFile.seekg(head.idLength + head.colourMapType * head.colourMapLength, tgaFile.beg);
	unsigned char* imageData = new unsigned char[m_imageSize];

	tgaFile.read((char*)imageData, m_imageSize);

	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_width; ++j)
		{
			if (m_bitsPerPixel == 32)
			{
				m_imageData.push_back(imageData[2]);
				m_imageData.push_back(imageData[1]);
				m_imageData.push_back(imageData[0]);
				m_imageData.push_back(imageData[3]);
			}
			else if (m_bitsPerPixel == 24)
			{
				m_imageData.push_back(imageData[2]);
				m_imageData.push_back(imageData[1]);
				m_imageData.push_back(imageData[0]);
			}
		}
	}

	delete [] imageData;
	tgaFile.close();

	return true;
}

bool TGAImage::Save(std::string fileName, std::vector<unsigned char> imageData, int width, int height, int bpp)
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

	tgaFile.write((char*)&header, sizeof(header));
	tgaFile.write((char*)imageData.data(), imageData.size());

	char* signature = "TRUEVISION-XFILE";
	memcpy(&footer.signature, signature, strlen(signature));
	footer.dot = '.';
	footer.extOffset = sizeof(header) + imageData.size() + sizeof(footer);
	footer.dev = 0;

	tgaFile.write((char*)&footer, sizeof(footer));

	return true;
}
