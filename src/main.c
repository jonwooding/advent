#include <stdio.h>
#include "advent.h"

ADVENT days[DAYS] = {
    day01,
    day02,
    day03,
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage:\n%s <day>\n\n", argv[0]);
        return -1;
    }

    int choice = atoi(argv[1]);
    if (choice < 1 || choice > DAYS)
    {
        fprintf(stderr, "Unable to interpret argument -- %s\n", argv[1]);
    }

    printf("Advent of Code!\n");
    printf("Executing Day %02d\n", choice);

    days[choice - 1]();

    return 0;
}
