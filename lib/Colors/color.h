#ifndef COLOR_h
#define COLOR_h

const unsigned long BLACK 	= 0;
const unsigned long WHITE 	= 16777215;
const unsigned long RED		= 16737380;
const unsigned long BLUE 	= 9856255;

typedef unsigned long RGB;
unsigned long iRGB(int r, int g, int b) {

	return b + (g<<8) + (r<<16);

}

#endif
