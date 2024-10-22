#include <stdio.h>
#include <stdlib.h>

int main()
{
    //problem 5
    char ch;
    char pause;
    do{
        printf("Menu\n");
        system("cls");
        printf("New(n)\nDisplay(d)\nExit(e)\n");
        printf("\nEnter n/d/e\n");
        _flushall();
        scanf("%ch",&ch);
        switch(ch){
            case 'n':
                printf("New line Selected\n");
                break;
            case 'd':
                printf("Display Selected\n");
                break;
            case 'e':
                printf("Exit Selected\n");
                break;
        }
        system("pause");
    }while(ch!='e');

    return 0;
}
