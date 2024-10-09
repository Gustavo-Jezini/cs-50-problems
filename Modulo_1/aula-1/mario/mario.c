#include <cs50.h>
#include <stdio.h>

int get_int_between_zero_and_eight(void);

int main(void)
{
    int height = get_int_between_zero_and_eight();

    int row, column, spaces;
    for (row = 0; row < height; row++)
    {

        for (spaces = 0; spaces < height - row - 1; spaces++)
        {
            printf(" ");
        }

        for (column = 0; column <= row; column++)
        {
            printf("#");
        }

        printf("\n");
    }
}

int get_int_between_zero_and_eight(void)
{
    int h;
    do
    {
        h = get_int("Escolha um número entre 1 e 8: \n");
    }
    while (h < 1 || h > 8);
    return h;
}
