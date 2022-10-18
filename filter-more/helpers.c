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


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            int rowCoords[] = {i - 1, i, i + 1};
            int colCoords[] = {j - 1, j, j + 1};
            float Rtotal = 0;
            float Gtotal = 0;
            float Btotal = 0;
            for (int h = 0; h < 3; h++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (rowCoords[h] >= 0 && rowCoords[h < height] && colCoords[k] >= 0 && colCoords[k] < width)
                    {
                        count++;
                        Rtotal += image[rowCoords[h]][colCoords[k]].rgbtRed;
                        Gtotal += image[rowCoords[h]][colCoords[k]].rgbtGreen;
                        Btotal += image[rowCoords[h]][colCoords[k]].rgbtBlue;
                    }
                }
            }
            temp[i][j].rgbtRed = round(Rtotal / count);
            temp[i][j].rgbtGreen = round(Gtotal / count);
            temp[i][j].rgbtBlue = round(Btotal / count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
