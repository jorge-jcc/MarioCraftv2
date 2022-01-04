#pragma once
#include "libs.h"

using namespace std;

class MarioCraftTexture : Texture {
private:
	static int imageWidth, imageHeight;
	static FIBITMAP *bitmap;
	static unsigned char *data;

public:
	GLuint id;

	MarioCraftTexture(const string& FileName);
	~MarioCraftTexture();
};

