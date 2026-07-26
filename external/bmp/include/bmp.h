#ifndef BMP_H
#define BMP_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct
{
    int width;
    int height;

    int stride;
    int dataSize;

    unsigned char *data;
    
} BMPImage;


#pragma pack(push, 1)

typedef struct
{
    uint16_t signature;
    uint32_t fileSize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t pixelOffset;
    
} BMPFileHeader;

typedef struct
{
    uint32_t headerSize;
    int32_t witdth;
    int32_t height;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t importantColors;
    
} BMPInfoHeader;

#pragma pack(pop)


BMPImage *bmp_create(int width, int height);

void bmp_set_pixel(BMPImage *image, int x, int y, unsigned char r, unsigned char g, unsigned char b);
void bmp_clear(BMPImage *image, unsigned char r, unsigned char g, unsigned char b);



void bmp_destroy(BMPImage *image);
int bmp_save(BMPImage *image, const char *filename);


#endif