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
    int n=0,m=0,lr=0;
    int flag=0;
    char menu[3][10]={"New","Display","Exit"};
    char New[3][15]={"NewKeyword","NewLine","NewPage"};
    char Display[3][15]={"DisplayKeyword","DisplayLine","DisplayPage"};
    do{
            system("cls");
        for(int i=0;i<3;i++){
                gotoxy(7,7+i);
                if(i==n) textatrr(0x30);
            _cprintf("%s",menu[i]);
            textatrr(0x07);
        }
        ch=_getch();
        switch(ch){
            case -32:
                ch=_getch();
                switch (ch){
                case 72://up
                    n--;
                    if(n<0)n=2;
                    break;
                case 80://down
                    n++;
                    if(n>2)n=0;
                    break;
                }
                break;
            case 13://enter
                //sub menu
                // New
                if(n==0){
                    lr=1;
                while(lr==1){
                    for(int j=0;j<3;j++){
                        if(j==m) textatrr(0x03);
                        gotoxy(15,9+j);
                        _cprintf("%s",New[j]);
                        textatrr(0x07);
                    }
                    ch=_getch();
                    if(ch==-32){
                        ch=_getch();
                        switch(ch){
                            case 72://up
                                m--;
                                if(m<0)m=2;
                                break;
                            case 80://down
                                m++;
                                if(m>2)m=0;
                                break;
                            case 75://left
                                lr=0;
                                break;
                    }
                }
                    else if(ch==13){
                        lr=0;
                        system("cls");
                        printf("New line selected");
                    }
                    else if(ch==27){
                        system("cls");
                        printf("Escape Selected");
                        flag=1;
                        lr=0;
                    }
                }
            }
            //Display
                else if(n==1){
                    lr=1;
                while(lr==1){
                    for(int j=0;j<3;j++){
                        if(j==m) textatrr(0x03);
                        gotoxy(15,9+j);
                        _cprintf("%s",Display[j]);
                        textatrr(0x07);
                    }
                    ch=_getch();
                    if(ch==-32){
                        ch=_getch();
                        switch(ch){
                            case 72://up
                                m--;
                                if(m<0)m=2;
                                break;
                            case 80://down
                                m++;
                                if(m>2)m=0;
                                break;
                            case 75://left
                                lr=0;
                                break;
                    }
                }
                    else if(ch==13){
                        lr=0;
                        system("cls");
                        printf("display selected");
                    }
                    else if(ch==27){
                        system("cls");
                        printf("Escape Selected");
                        flag=1;
                        lr=0;
                    }
                }
                }
                else if(n==2){
                    system("cls");
                    printf("Exit selected");
                    flag=1;
                }
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
