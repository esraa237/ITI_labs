#include <stdio.h>
#include <stdlib.h>

struct point{
int x;
int y;
};
int main()
{
    struct point p1;
    printf("Enter X and Y for point:- \n");
    scanf("%d",&(p1.x));
    scanf("%d",&(p1.y));
    printf("point in ( %d , %d )",p1.x,p1.y);
    return 0;
}
