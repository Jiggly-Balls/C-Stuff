#include <stdio.h>
#include <unistd.h>
#include <string.h>


void print_animation(char text[], float delay);


void main(void)
{
    print_animation("HI hello", 50000);
}


void print_animation(char text[], float delay)
{
    for (int i = 0; i < strlen(text); i++)
    {
        printf("%c", text[i]);
        usleep(delay);
    }
}