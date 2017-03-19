#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {   
        printf("Height: ");
        height = get_int();
    }
    while (height < 0 || height > 23);
    for (int i = 0; i < height; i++)
    {
        for (int j = height - 1 - i; j > 0; j--)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}