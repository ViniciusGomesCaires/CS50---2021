void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float mediaRGB;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            mediaRGB = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = round(mediaRGB);
            image[i][j].rgbtGreen = round(mediaRGB);
            image[i][j].rgbtRed = round(mediaRGB);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE(*tmp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    for (int i = 0; i < height; i++)
    {
        for (int j = width - 1; j >= 0; j--)
        {
            tmp[i][(width - 1) - j].rgbtBlue = image[i][j].rgbtBlue;
            tmp[i][(width - 1) - j].rgbtGreen = image[i][j].rgbtGreen;
            tmp[i][(width - 1) - j].rgbtRed = image[i][j].rgbtRed;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
        }
    }
    free(tmp);
    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*tmp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    float average[3];
    float divider;

    for (int i = 0; i < height; i++)
    {
        for (int j = width - 1; j >= 0; j--)
        {
            divider = 0;
            for (int n = 0; n < 3; n++)
            {
                average[n] = 0;
            }
            for (int y = -1; y < 2; y++)
            {
                for (int x = -1; x < 2; x++)
                {
                    if (i + y >= 0 && i + y < height)
                    {
                        if (j + x >= 0 && j + x < width)
                        {
                            average[0] = image[i + y][j + x].rgbtBlue + average[0];
                            average[1] = image[i + y][j + x].rgbtGreen + average[1];
                            average[2] = image[i + y][j + x].rgbtRed + average[2];
                            divider++;
                        }
                    }
                }

            }

            if (average[0] != 0)
            {
                tmp[i][j].rgbtBlue = round(average[0] / divider);
            }
            if (average[1] != 0)
            {
                tmp[i][j].rgbtGreen = round(average[1] / divider);
            }
            if (average[2] != 0)
            {
                tmp[i][j].rgbtRed = round(average[2] / divider);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
        }
    }
    free(tmp);
    return;
}
