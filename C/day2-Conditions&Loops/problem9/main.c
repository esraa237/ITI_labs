#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <windows.h>
/** \brief
void gotoxy(int x, int y){
    COORD coord;
    coord.x = x;
    coord.y = y; setConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
 */
void gotoxy(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main()
{
    int x,y,size;
    printf("Magic Box \nEnter size of magic box start from(3,5,7,...):-  ");
    scanf("%d",&size);
    for(int i=1;i<=(size*size);i++){
        if(i==1){
            y=1;
            x=(size/2)+1;
            gotoxy(x*4,y*4);
            printf("%d",i);
        }
        else if((i-1)%size==0){
            y++;
            x=x;
            if(y>size) y=1;
            gotoxy(x*4,y*4);
            printf("%d",i);
        }
        else if((i-1)%size!=0){
            x--;
            y--;
            if(x==0) x=size;
            if(y==0) y=size;
            gotoxy(x*4,y*4);
            printf("%d",i);
        }
    }
printf("\n\n");
    return 0;
}
