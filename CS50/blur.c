void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //matriz temporária

    RGBTRIPLE tmp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //variáveis para armazenar novos valores dos RGB e contador "x" para fazer a média..
            int x = 0;
            int r = 0;
            int g = 0;
            int b = 0;
            //analisa os pixels adjacentes por linha, exemplo: o array [0][0], verificaria o que há em [-1][0] / [0][0] / [1][0]
            for (int k = i-1; k <= i+1; k++)
            {
                //analisa os pixels adjacentes por coluna, exemplo: o array [0][0], verificaria o que há em [0][-1] / [0][0] / [0][1]
                for (int l = j-1; l <= j+1; l++)
                {
                    //condiciona que os i´s e j´s tem que ser >= 0
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        //caso os números de k (i) e l (j) sejam válidos, as variáveis recebem e somam os valores do RGB, respectivamente, e contam X para calcular a média.
                        r += image[k][l].rgbtRed;
                        g += image[k][l].rgbtGreen;
                        b += image[k][l].rgbtBlue;
                        x++;
                    }
                }
            }
            //a matriz temporária recebe os valores do RGB somados, divide-se pelo contador X, arredondamos par que os valores fiquem entre 0 a 255..
            tmp[i][j].rgbtRed = round(r / x);
            tmp[i][j].rgbtGreen = round(g / x);
            tmp[i][j].rgbtBlue = round(b / x);
        }
    }

    //loop para trocar o valor da matriz temp para a imagem original...
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <width; j++)
        {
            image[i][j] = tmp[i][j];
        }
    }

    return;
}