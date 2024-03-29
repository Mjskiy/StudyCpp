#include "image.h"


apImage::apImage():width_(0),height_(0),pixels_(0)
{
}

apImage::apImage(int width, int height):width_(width),height_(height),pixels_(0)
{
	init();
}

apImage::~apImage()
{
	cleanup();
}

apImage::apImage(const apImage & src):width_(0),height_(0),pixels_(0)
{
	if (src.isvalid())
	{
		width_ = src.width();
		height_ = src.height();
		init();
		memcpy(pixels_, src.pixels_, width_ * height_);
	}
}

apImage& apImage::operator=(const apImage & src)
{
	if(&src != this)
	{
		cleanup();
		width_ = src.width();
		height_ = src.height();
		init();

		memcpy(pixels_, src.pixels_, width_*height_);
	}

	return *this;
}

#pragma region (+)Sutter_Technic

template<typename T> void swap(T& a, T& b)
{
	T copy(a);
	a = b;
	b = copy;
}

void apImage::swap(apImage & src)
{
	::swap(width_, src.width_);
	::swap(height_, src.height_);
	::swap(pixels_, src.pixels_);
}

apImage& apImage::operator=(const apImage & src)
{
	apImage temp(src);
	swap(temp);
	return *this;
}

#pragma endregion


void apImage::init()
{
	if (width_ >0 && height_ >0)
	{
		pixels_ = new unsigned char[width_ * height_];
	}
}

void apImage::cleanup()
{
	delete[] pixels_;
	width_ = 0;
	height_ = 0;
	pixels_ = 0;

}
