#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "advent.h"

AdventError day02(void)
{
    FILE *fd = 0;
    int ret = ADVENT_SUCCESS;
    int bytes_read = 0;
    char *line = NULL;
    size_t line_len = 1024;


    fd = fopen("inputs/day02.txt", "r");
    if (NULL == fd)
    {
        printf("Failed to access input file!\n");
        ret = ADVENT_BAD_INPUT;
        goto cleanup;
    }

    // abc xyz
    // win = 6, draw = 3, lose = 0
    line = (char*) malloc(line_len);

    int us = 0;
    int them = 0;
    int score = 0;
    int score2 = 0;

    // getline returns -1 on eof
    while(bytes_read = getline(&line, &line_len, fd) > 0)
    {
        if (strlen(line) < 3)
        {
            continue;
        }

        them = line[0] - 'A';
        us = line[2] - 'X';
        score += us + 1;
        if (them == us)
        {
            // draw
            score += 3;
        } 
        else if (
                (us > them && us - them == 1) || 
                (us == 0 && them == 2)
                )
        {
            // win
            score += 6;
        }

        // part 2! x lose y draw z win
        printf("--- %d %d\n", them, us);
        score2 += (us * 3) + 1;
        switch (us)
        {
            case 0:
                if (them == 0)
                {
                    score2 += 2;
                }
                else
                {
                    score2 += (them - 1) % 3;
                }
                printf("lose, %d\n", (them - 1) % 3);
                break;
            case 1:
                printf("draw, %d\n", them);
                score2 += them;
                break;
            case 2:
                printf("win, %d\n", (them + 1) % 3);
                score2 += (them + 1) % 3;
                break;
        }
    }

    printf("Final score: %d\n", score);
    printf("Final score (part 2): %d\n", score2);


cleanup:
    if (NULL != line)
    {
        free(line);
    }

    if (NULL != fd)
    {
        fclose(fd);
    }

    return ret;
}

