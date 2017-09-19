#pragma once


#include <string>
#include <vector>
#include <fstream>

#pragma pack(1)
struct TGAHeader
{
	char  idLength;
	char  colourMapType;
	char  dataTypeCode;
	short int colourMapOrigin;
	short int colourMapLength;
	char  colourMapDepth;
	short int xOrigin;
	short int yOrigin;
	short width;
	short height;
	char  bitsPerPixel;
	char  imageDescriptor;
};

struct TGAFooter
{
	int extOffset;
	int dev;	
	char signature[16];	// Contains "TRUEVISION-XFILE"
	char dot;		// Contains "."
	char last;		// Contains NULL
};
#pragma pack()

class TGAImage
{
	std::vector<unsigned char> m_imageData;
	unsigned int m_height, m_width;
	unsigned int m_bitsPerPixel;
	int m_imageSize;

public:
	TGAImage();
	~TGAImage();

	std::vector<unsigned char> GetImageData() { return m_imageData; }
	unsigned int GetHeight() {return m_height;}
	unsigned int GetWidth() {return m_width;}
	int GetImageSize() { return m_imageSize; }
	static bool Save(std::string fileName, std::vector<unsigned char> imageData, int width, int height, int bpp);
	bool Load(std::string fileName);
	
};
