#include <stdio.h>
#include <stdlib.h>
/*
A point on the two-dimensional plane can be represented by two numbers: an x coordinate and a y coordinate. For example, (4,5) represents a point 4 units to the right of the
vertical axis, and 5 units up from the horizontal axis. The sum of two points can be
defined as a new point whose x coordinate is the sum of the x coordinates of the two
points, and whose y coordinate is the sum of the y coordinates.
Write a program that uses a structure called point to model a point. Define three points,
and have the user input values to two of them. Then set the third point equal to the sum
of the other two, and display the value of the new point. Interaction with the program
might look like this:
Enter coordinates for p1: 3 4
Enter coordinates for p2: 5 7
Coordinates of p1+p2 are: 8, 11
*/
struct point{
    int x;
    int y;
};
int main()
{
    struct point p1;
    struct point p2;
    struct point p3;
    printf("Enter coordinates for p1: ");
    scanf("%d %d",&p1.x,&p1.y);
    printf("Enter coordinates for p2: ");
    scanf("%d %d",&p2.x,&p2.y);
    p3.x=p1.x+p2.x;
    p3.y=p1.y+p2.y;
    printf("Coordinates of p1+p2 are: %d %d",p3.x,p3.y);
    return 0;
}
