#ifndef PPM_H
#define PPM_H
#include "rgb.h"

class PPM
{
public:
	PPM();
	PPM(unsigned int width, unsigned int height);
	~PPM();
	int* get_size();
	bool get_version();
	void set_size(unsigned int width, unsigned int height);
	void set_version(char* version);
	void save(char* filename);
	bool read(char* filename);
	void set_body(RGB* array);
	bool Release();
private:
	unsigned int width;
	unsigned int height;
	char* version;
	RGB* body;
};
#endif
