#pragma once
#include <cstring>
#include <vector>
#include <algorithm>

class apImage
{
public:
	apImage();
	apImage(int width, int height);
	~apImage();

	apImage(const apImage& src);
	apImage& operator= (const apImage& src);	
	

	void swap(apImage& src);

	void setPixel(int x, int y, unsigned char pixel);
	unsigned char getPixel(int x, int y) const;

	bool isvalid() const { return pixels_ != 0; }

	int width() const { return width_; }
	int height() const { return height_; }

	class rangeError{};


private:
	void init();

	void cleanup();

	int width_;
	int height_;
	unsigned char* pixels_;

};

