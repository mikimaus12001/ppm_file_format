#include "ppm.h"
#include "fstream"

PPM::PPM()
{
}

PPM::PPM(unsigned int width, unsigned int height)
{
	this->width = width;
	this->height = height;
}

PPM::~PPM()
{
}

void PPM::set_size(unsigned int width, unsigned int height)
{
	this->width = width;
	this->height = height;
}

void PPM::set_version(char* version)
{
	this->version = version;
}

int* PPM::get_size()
{
	int width = this->width;
	int height = this->height;
	int array[2] = { width, height };
	return array;
}

void PPM::set_body(RGB* array)
{
	this->body = array;
}

void PPM::save(char* filename)
{
	// open file stream
	std::wofstream fout(filename, std::ios::trunc);

	fout << this->version << '\n' << this->width << ' ' << this->height << "\n255\n";

	for (int i = 0; i < this->width * this->height; i++)
	{
		unsigned char r = this->body[i].getR();
		unsigned char g = this->body[i].getG();
		unsigned char b = this->body[i].getB();

		fout << r << ' ' << g << ' ' << b << "\n";
	}

	// close file stream
	fout.close();
}
