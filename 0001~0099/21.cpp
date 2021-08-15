#include <stdio.h>
int main()
{
    char data[2001];
    fgets(data,2000,stdin);
    puts(data);
}
