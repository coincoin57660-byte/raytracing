#include "bmp.h"


BMPImage *bmp_create(int width, int height)
{
    BMPImage *image = malloc(sizeof(BMPImage));

    if (image == NULL)
    {
        return NULL;
    }

    image -> width = width;
    image -> height = height;

    int padding = (4 - (width * 3) % 4) % 4;

    image -> stride = width * 3 + padding;
    image -> dataSize = image -> stride * image -> height;

    image -> data = calloc(image -> dataSize, sizeof(unsigned char));

    if (image -> data == NULL)
    {
        free(image);
        return NULL;
    }

    return image;
}


void bmp_destroy(BMPImage *image)
{
    free(image -> data);
    free(image);
}


void bmp_set_pixel(BMPImage *image, int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
    if (image == NULL)
    {
        return;
    }

    if (x < 0 || x >= image -> width || y < 0 || y >= image -> height)
    {
        return;
    }

    int row = image -> height - 1 - y;
    int index = row * image -> stride + x * 3;

    image -> data[index + 0]     = b;
    image -> data[index + 1] = g;
    image -> data[index + 2] = r;
}


void bmp_clear(BMPImage *image, unsigned char r, unsigned char g, unsigned char b)
{
    for (int y = 0; y < image -> height; y++)
    {
        for (int x = 0; x < image -> width; x++)
        {
            bmp_set_pixel(image, x, y, r, g, b);
        }
    }
}


int bmp_save(BMPImage *image, const char *filename)
{
    printf("start saving...\n");
    
    if (image == NULL || filename == NULL)
    {
        return 0;
    }

    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        return 0;
    }

    
    BMPFileHeader fileHeader;

    fileHeader.signature = 0x4D42;  // "BM"
    fileHeader.reserved1 = 0;
    fileHeader.reserved2 = 0;
    fileHeader.pixelOffset = 54;  // 14 (file header) + 40 (info header)

    BMPInfoHeader infoHeader;

    infoHeader.headerSize = 40;
    infoHeader.witdth = image -> width;
    infoHeader.height = image -> height;
    infoHeader.planes = 1;
    infoHeader.bitsPerPixel = 24;
    infoHeader.compression = 0;
    infoHeader.imageSize = 0;  // 0 au début
    infoHeader.xPixelsPerMeter = 0;
    infoHeader.yPixelsPerMeter = 0;
    infoHeader.colorsUsed = 0;
    infoHeader.importantColors = 0;

    fwrite(&fileHeader, sizeof(fileHeader), 1, file);
    fwrite(&infoHeader, sizeof(infoHeader), 1, file);

    fwrite(image -> data, 1, image -> dataSize, file);

    fclose(file);

    printf("Image succesfuly save\n");
    return 1;
}