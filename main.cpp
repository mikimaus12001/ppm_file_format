#include <iostream>
#include <fstream>
#include "ppm.h"
#include "image.h"

#pragma warning(disable:4996)

// файл JPEG можно распознать по первым двум байтам: FF D8
int isJpeg(const char* fName)
{

    FILE* file = fopen(fName, "r");

    // JPEG-файл состоит из байтов.
    // Array to store the bytes 
    uint8_t bytes[2];

    // 10 system - 16 system
    // 255 = FF
    // 170 = AA
    // 16 = 99
    // 0 = 00
    uint8_t a = 0x99;
    uint8_t ab = 0xAA;

    // Read the file bytes 
    fread(bytes, 2, 1, file);

    // If the given file is a JPEG file 
    if (bytes[0] == 0xFF && bytes[1] == 0xD8)
    {
        return 0;
    }

    // If file is NULL return 
    if (file == NULL) {
        return 1;
    }
    
    else
    {
        return 2;
    }
}

int main()
{

    // -----------------------Программа отвечает, является ли фаил фаилом JPEG или нет.------------------//
    
    // Take file as argument as an 
    // input and read the file 
    const char* filename = "E:\\tests\\Org chart.jpg";

    int result = isJpeg(filename);
    std::cout << result << std::endl;

    // -----------------------PPM Image-----------------------------------//
    
    // Create PPm image width = 3, height = 2
    PPM ppm1 = PPM(3, 2);
    // Set version P6
    char vers[] = "P6";
    ppm1.set_version(vers);
    // Set body
    RGB r_array[6] = 
    { 
        RGB(255, 0, 0), 
        RGB(0, 255, 0),
        RGB(0, 0, 255),
        RGB(255, 255, 0),
        RGB(255, 255, 255),
        RGB(0, 0, 0)
    };
    ppm1.set_body(r_array);
    ppm1;
    char fName[] = "result.ppm";
    ppm1.save(fName);

    char vers2[] = "P3";
    char fName2[] = "result2.ppm";

    PPM ppm2 = PPM(3, 2);
    ppm2.set_version(vers2);
    ppm2.set_body(r_array);
    ppm2.save(fName2);
    ppm2;

    // ----------------------------------Work with Image---------------------------------------//
    Image img = Image(256, 256);

    int w = img.getWidth();
    int h = img.getHeight();

    // Allocate memory for Image
    img.Data = img.Allocate2DArray(img.Data, img.getWidth(), img.getHeight());

    // Use img.Data
    img;

    // Initialize img.Data
    int counter = 0;
    size_t size = sizeof(img.Data);
    for (int i = 0; i < img.getHeight(); i++)
    {
        for (int j = 0; j < img.getWidth(); j++)
        {
            img.Data[i][j] = counter;
        }
        counter++;
    }

    // Deallocate memory, reserved for Image
    img.DeAllocate2DArray(img.Data, img.getHeight());

    return 0;
}
