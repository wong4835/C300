#include <stdio.h>

void main(void)
{
    char *animal[3];
    char **ppanimal;

    animal[0]= "Tiger";
    animal[1]= "Lion";
    animal[2]= "Rabbit";

    ppanimal = animal;

    puts(animal[0]);
    puts(ppanimal[1]);
    puts(ppanimal[2]);
}
