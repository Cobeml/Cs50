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

void blacken(RGBTRIPLE pixel)
{
    pixel.rgbtGreen = 0;
    pixel.rgbtBlue = 0;
    pixel.rgbtRed = 0;
}
// Blur image
// there is no way this is efficient
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE *surrounding_pixels[9];
            surrounding_pixels[0] = &image[i][j];
            // if on edge, treat ones over the edge as black
            if (i == 0)
            {
                blacken(*surrounding_pixels[1]);
                blacken(*surrounding_pixels[2]);
                blacken(*surrounding_pixels[3]);
            }
            if (i == height - 1)
            {
                blacken(*surrounding_pixels[4]);
                blacken(*surrounding_pixels[5]);
                blacken(*surrounding_pixels[6]);
            }
            if (j == 0)
            {
                blacken(*surrounding_pixels[1]);
                blacken(*surrounding_pixels[4]);
                blacken(*surrounding_pixels[7]);
            }
            if (j == width - 1)
            {
                blacken(*surrounding_pixels[3]);
                blacken(*surrounding_pixels[6]);
                blacken(*surrounding_pixels[8]);
            }
            RGBTRIPLE *notblack[8];
            notblack[0] = &image[i - 1][j - 1];
            notblack[1] = &image[i - 1][j];
            notblack[2] = &image[i - 1][j + 1];
            notblack[3] = &image[i + 1][j - 1];
            notblack[4] = &image[i + 1][j];
            notblack[5] = &image[i + 1][j + 1];
            notblack[6] = &image[i][j - 1];
            notblack[7] = &image[i][j + 1];

            for (int h = 0; h < 8; h++)
            {
                if (*surrounding_pixels[h + 1].rgbtGreen != 0 && *surrounding_pixels[h + 1].rgbtBlue != 0 && *surrounding_pixels[h + 1].rgbtRed != 0)
                {
                    surrounding_pixels[h + 1] = notblack[h];
                }
            }

            BYTE redavg = 0;
            BYTE greenavg = 0;
            BYTE blueavg = 0;
            for (int h = 0; h < 9; h++)
            {
                blueavg += *surrounding_pixels[h].rgbtBlue;
                greenavg += *surrounding_pixels[h].rgbtGreen;
                redavg += *surrounding_pixels[h].rgbtRed;
            }
            BYTE bufferblue = blueavg;
            BYTE buffergreen = greenavg;
            BYTE bufferred = redavg;
            blueavg = round(bufferblue / 3);
            greenavg = round(buffergreen / 3);
            redavg = round(bufferred / 3);

            // reassignment might need pointers or smthing idk I added lots of stars and &s, not done, prob fucked shit up
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
