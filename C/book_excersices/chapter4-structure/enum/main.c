#include <stdio.h>
#include <stdlib.h>
/*We said earlier that C++ I/O statements don’t automatically understand the data types of
enumerations. Instead, the (>>) and (<<) operators think of such variables simply as integers. You can overcome this limitation by using switch statements to translate between
the user’s way of expressing an enumerated variable and the actual values of the enumerated variable. For example, imagine an enumerated type with values that indicate an
employee type within an organization:
enum etype { laborer, secretary, manager, accountant, executive,
researcher };
Write a program that first allows the user to specify a type by entering its first letter
(‘l’, ‘s’, ‘m’, and so on), then stores the type chosen as a value of a variable of type
enum etype, and finally displays the complete word for this type.*/
enum etype{laborer=1, secretary, manager, accountant, executive,researcher};
int main()
{
    enum etype w;
    char ch;
    printf("Enter employee type (first letter only)laborer, secretary, manager,accountant, executive, researcher): ");
    _flushall();
    scanf("%c",&ch);
    switch(ch){
        case 'a':
            w=accountant;
            break;
        case 'l':
            w=laborer;
            break;
        case 's':
            w=secretary;
            break;
        case 'm':
            w=manager;
            break;
        case 'e':
            w=executive;
            break;
        case 'r':
            w=researcher;
            break;
        }
        printf("Employee type is %d",w);

    return 0;
}
