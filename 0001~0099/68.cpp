#include <stdio.h>
int main()
{
    char c;
    scanf("%s",&c);
    switch(c)
    {
        case 'A':
            printf("best!!!");
            break;
        case 'B':
            printf("good!!");
            break;
        case 'C':
            printf("run!");
            break;
        case 'D':
            printf("slowly~");
            break;
        default:
            printf("what?");
            break;
    }
}
