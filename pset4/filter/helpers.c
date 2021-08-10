#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int average = round((red + blue + green) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            } else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            } else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            } else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[width-1-j].rgbtRed = image[i][j].rgbtRed;
            temp[width-1-j].rgbtGreen = image[i][j].rgbtGreen;
            temp[width-1-j].rgbtBlue = image[i][j].rgbtBlue;
        }
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[j].rgbtRed;
            image[i][j].rgbtGreen = temp[j].rgbtGreen;
            image[i][j].rgbtBlue = temp[j].rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int redTotal;
    int greenTotal;
    int blueTotal;
    int counter;
    for (int i = 0; i < height; i++)
    {
        redTotal = greenTotal = blueTotal = counter = 0;
        for (int j = 0; j < width; j++)
        {
            //ONE
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                redTotal += image[i-1][j-1].rgbtRed;
                greenTotal += image[i-1][j-1].rgbtGreen;
                blueTotal += image[i-1][j-1].rgbtBlue;
                counter += 1;
            }
            //TWO
            if (i - 1 >= 0)
            {
                redTotal += image[i-1][j].rgbtRed;
                greenTotal += image[i-1][j].rgbtGreen;
                blueTotal += image[i-1][j].rgbtBlue;
                counter += 1;
            }
            //THREE
            if (i - 1 >= 0 && j + 1 < width)
            {
                redTotal += image[i-1][j+1].rgbtRed;
                greenTotal += image[i-1][j+1].rgbtGreen;
                blueTotal += image[i-1][j+1].rgbtBlue;
                counter += 1;
            }
            //FOUR
            if (j - 1 >= 0)
            {
                redTotal += image[i][j-1].rgbtRed;
                greenTotal += image[i][j-1].rgbtGreen;
                blueTotal += image[i][j-1].rgbtBlue;
                counter += 1;
            }
            //FIVE
            redTotal += image[i][j].rgbtRed;
            greenTotal += image[i][j].rgbtGreen;
            blueTotal += image[i][j].rgbtBlue;
            counter += 1;
            //SIX
            if (j + 1 < width)
            {
                redTotal += image[i][j+1].rgbtRed;
                greenTotal += image[i][j+1].rgbtGreen;
                blueTotal += image[i][j+1].rgbtBlue;
                counter += 1;
            }
            //SEVEN
            if (i + 1 < height && j - 1 >= 0)
            {
                redTotal += image[i+1][j-1].rgbtRed;
                greenTotal += image[i+1][j-1].rgbtGreen;
                blueTotal += image[i+1][j-1].rgbtBlue;
                counter += 1;
            }
            //EIGHT
            if (i + 1 < height)
            {
                redTotal += image[i+1][j].rgbtRed;
                greenTotal += image[i+1][j].rgbtGreen;
                blueTotal += image[i+1][j].rgbtBlue;
                counter += 1;
            }
            //NINE
            if (i + 1 < height && j + 1 < width)
            {
                redTotal += image[i-1][j+1].rgbtRed;
                greenTotal += image[i-1][j+1].rgbtGreen;
                blueTotal += image[i-1][j+1].rgbtBlue;
                counter += 1;
            }
            
            int newRed = round(redTotal/counter);
            int newGreen = round(greenTotal/counter);
            int newBlue = round(blueTotal/counter);
            
            image[i][j].rgbtRed = newRed;
            image[i][j].rgbtGreen = newGreen;
            image[i][j].rgbtBlue = newBlue;
        };
    }
    return;
}
