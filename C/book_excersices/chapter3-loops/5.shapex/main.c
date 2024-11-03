#include <stdio.h>
/*Use for loops to construct a program that displays a pyramid of Xs on the screen. The
pyramid should look like this
    X
   XXX
  XXXXX
 XXXXXXX
XXXXXXXXX*/
int main()
{
    int i, space, rows=9, k = 0;

    for (i = 1; i <= rows; ++i, k = 0)
    {
        for (space = 1; space <= rows - i; ++space)
        {
            printf(" ");
        }
        while (k != 2 * i - 1)
        {
            printf("X");
            ++k;
        }
        printf("\n");
    }
    return 0;
}


