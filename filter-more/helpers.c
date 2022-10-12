#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE gray = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtRed = gray;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE *pixel = &image[i][j];
            RGBTRIPLE *reverse = &image[i][width - (j + 1)];
            RGBTRIPLE buffer = *pixel;
            *pixel = *reverse;
            *reverse = buffer;
        }
    }
    return;
}

RGBTRIPLE black;
black.rgbtred = 0;
black.rgbtgreen = 0;
black.rgbtblue = 0;
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE surrounding_pixels[9];
            surrounding_pixels[0] = image[i][j];
            if (i = 0)
            {
                surrounding_pixel[1] = black;
                surrounding_pixel[2] = black;
                surrounding_pixel[3] = black;
            }
            if (i = height - 1)
            {
                surrounding_pixel[4] = black;
                surrounding_pixel[5] = black;
                surrounding_pixel[6] = black;
            }
            if (j = 0)
            surrounding_pixels[1] = image[i - 1][j - 1];
            surrounding_pixels[2] = image[i - 1][j];
            surrounding_pixels[3] = image[i - 1][j + 1];
            surrounding_pixels[4] = image[i + 1][j - 1];
            surrounding_pixels[5] = image[i + 1][j];
            surrounding_pixels[6] = image[i + 1][j + 1];
            surrounding_pixels[7] = image[i][j - 1];
            surrounding_pixels[8] = image[i][j + 1];

            BYTE redavg = 0;
            BYTE greenavg = 0;
            BYTE blueavg = 0;
            for (int h = 0; h < 9; h++)
            {
                blueavg += surrounding_pixels[h].rgbtBlue;
                greenavg += surrounding_pixels[h].rgbtGreen;
                redavg += surrounding_pixels[h].rgbtRed;
            }
            BYTE bufferblue = blueavg;
            BYTE buffergreen = greenavg;
            BYTE bufferred = redavg;
            blueavg = round(bufferblue / 3);
            greenavg = round(buffergreen / 3);
            redavg = round(bufferred / 3);

            image[i][j].rgbtBlue = blueavg;
            image[i][j].rgbtGreen = greenavg;
            image[i][j].rgbtRed = redavg;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
