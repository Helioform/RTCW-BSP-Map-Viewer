#pragma once


#include <string>
#include <vector>
#include <fstream>

#pragma pack(push, 1)
struct TGAHeader
{
	unsigned char  idLength;
	unsigned char  colourMapType;
	unsigned char  dataTypeCode;
	unsigned short colourMapOrigin;
	unsigned short colourMapLength;
	unsigned char  colourMapDepth;
	unsigned short xOrigin;
	unsigned short yOrigin;
	unsigned short width;
	unsigned short height;
	unsigned char  bitsPerPixel;
	unsigned char  imageDescriptor;
};
#pragma pack(pop)

struct TGAFooter
{
	unsigned short extOffset;
	unsigned short dev;	
	char signature[18];		
};


class TGAImage
{
	unsigned char*				m_imageData;
	unsigned int				m_height, m_width;
	unsigned int				m_bitsPerPixel;
	int							m_imageSize;

public:
	TGAImage();
	~TGAImage();

	unsigned char* GetImageData() { return m_imageData; }
	unsigned int GetHeight() {return m_height;}
	unsigned int GetWidth() {return m_width;}
	int GetImageSize() { return m_imageSize; }
	static bool Save(std::string fileName, unsigned char* imageData, int width, int height, int bpp);
	bool Load(std::string fileName);
	
};
