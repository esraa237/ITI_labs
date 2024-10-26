#include <stdio.h>
#include <stdlib.h>/jk
#include <windows.h>
#include<conio.h>
#include<string.h>
void gotoxy(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void textatrr(int i){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
}
int main()
{
    char ch;
    int n=0;
    int flag=0;
    char menu[3][10]={"New","Display","Exit"};

    do{
            system("cls");
        for(int i=0;i<3;i++){
                gotoxy(7,7+i);
                if(i==n) textatrr(0x20);
            _cprintf("%s",menu[i]);
            textatrr(0x07);
        }
        ch=_getch();
        switch(ch){
            case -32:
                ch=_getch();
                switch (ch){
                case 72:
                    n--;
                    if(n<0)n=2;
                    break;
                case 80:
                    n++;
                    if(n>2)n=0;
                    break;
                }
                break;
            case 13:
                system("cls");
                if(n==0){
                    printf("New Line selected");
                }
                else if(n==1){
                    printf("Display selected");
                }
                else if(n==2){
                    printf("Exit selected");
                    flag=1;
                }
                ch=_getch();
                break;
            case 27:
                system("cls");
                printf("Escape Selected");
                flag=1;
                break;
        }
    }
    while(flag==0);
    return 0;
}
