#include "MarioCraftTexture.h"

int MarioCraftTexture::imageWidth, MarioCraftTexture::imageHeight;
FIBITMAP *MarioCraftTexture::bitmap;
unsigned char *MarioCraftTexture::data;

MarioCraftTexture::MarioCraftTexture(const string& FileName) : Texture(FileName) {
	MarioCraftTexture::bitmap = Texture::loadImage();
	MarioCraftTexture::data = Texture::convertToData(MarioCraftTexture::bitmap, 
		MarioCraftTexture::imageWidth, MarioCraftTexture::imageHeight
	);
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	if (MarioCraftTexture::data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, MarioCraftTexture::imageWidth, 
			MarioCraftTexture::imageHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, 
			MarioCraftTexture::data
		);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
		cout << "Failed to load texture" << endl;
	Texture::freeImage(MarioCraftTexture::bitmap);
}

MarioCraftTexture::~MarioCraftTexture() {
	glDeleteTextures(1, &id);
}