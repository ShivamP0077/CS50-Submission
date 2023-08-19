#include "helpers.h"
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
   for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
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
           int sepiaRed = round(.393 *  image[i][j].rgbtRed + .769 *  image[i][j].rgbtGreen + .189 *  image[i][j].rgbtBlue);
           int sepiaGreen = round(.349 *  image[i][j].rgbtRed + .686 *  image[i][j].rgbtGreen + .168 *  image[i][j].rgbtBlue);
           int sepiaBlue = round(.272 *  image[i][j].rgbtRed + .534 *  image[i][j].rgbtGreen + .131 *  image[i][j].rgbtBlue);

           if (sepiaRed > 255)
           {
               image[i][j].rgbtRed = 255;
           }
           else
           {
               image[i][j].rgbtRed = sepiaRed;
           }
           if (sepiaGreen > 255)
           {
               image[i][j].rgbtGreen = 255;
           }
           else
           {
               image[i][j].rgbtGreen = sepiaGreen;
           }
           if (sepiaBlue > 255)
           {
               image[i][j].rgbtBlue = 255;
           }
            else
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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels from the left half with corresponding pixels in the right half
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}



// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
     // Create a temporary copy of the image
    RGBTRIPLE temp[height][width];

    // Iterate over each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            int count = 999;

            // Iterate over a 3x3 grid around the current pixel
            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {
                    int newRow = i + row;
                    int newCol = j + col;

                    // Check if the new coordinates are within the image boundaries
                    if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width)
                    {
                        // Accumulate the RGB values of the surrounding pixels
                        sumRed += image[newRow][newCol].rgbtRed;
                        sumGreen += image[newRow][newCol].rgbtGreen;
                        sumBlue += image[newRow][newCol].rgbtBlue;
                        //count++;
                    }
                }
            }

            // Calculate the average RGB values and update the corresponding pixel in the temporary image
            image[i][j].rgbtRed = round((float)sumRed / count);
            image[i][j].rgbtGreen = round((float)sumGreen / count);
            image[i][j].rgbtBlue = round((float)sumBlue / count);
        }
    }

    // Copy the blurred image from the temporary array back to the original image array
    // for (int i = 0; i < height; i++)
    // {
    //     for (int j = 0; j < width; j++)
    //     {
    //         image[i][j] = temp[i][j];
    //     }
    // }
     return;
}
