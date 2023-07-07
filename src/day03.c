#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "advent.h"

int priority(char c)
{
    printf("priority %c\n", c);
    if (c >= 'a')
    {
        return c - 'a' + 1;
    }
    else 
    {
        return c - 'A' + 27;
    }
}

AdventError day03(void)
{
    FILE *fd = 0;
    int ret = ADVENT_SUCCESS;
    int bytes_read = 0;
    char *line = NULL;
    size_t line_len = 1024;


    fd = fopen("inputs/day03.txt", "r");
    if (NULL == fd)
    {
        printf("Failed to access input file!\n");
        ret = ADVENT_BAD_INPUT;
        goto cleanup;
    }

    line = (char*) malloc(line_len);

#define PART2

#ifdef PART1
    int buflen = 0;
    int score = 0;
    char *buf1 = NULL;
    char *buf2 = NULL;

    // getline returns -1 on eof
    while((bytes_read = getline(&line, &line_len, fd)) > 0)
    {
        --bytes_read; // dont count \n
        // char will occur only once in both lines
        buflen = bytes_read / 2;
        buf1 = line;
        buf2 = line + buflen;
        for (int i=0; i < buflen; ++i)
        {
            for (int j=0; j < buflen; ++j)
            {
                if (buf1[i] != buf2[j])
                {
                    continue;
                }
                printf("mid: %c\n", line[i]);
                score += priority(line[i]);
                goto next;
            }
        }
next:
    }

    printf("score: %d\n", score); 
#endif

#ifdef PART2
    int score = 0; 

    while (1)
    {
        // 3 lines, 128 options per line (really only need 26 *2 but this is easier)
        char buf[3][128] = {0};
        for (int i = 0; i < 3; ++i)
        {
            bytes_read = getline(&line, &line_len, fd);
            if (bytes_read <= 0)
            {
                // probably just EOF, naively exit
                goto bail;
            }

            --bytes_read; // remove training \n
            for (int n = 0; n < bytes_read; ++n)
            {
                buf[i][line[n]] |= 1;
            }
        }

        for (int i = 0; i < 128; ++i)
        {
            if (buf[0][i] && buf[1][i] && buf[2][i])
            {
                score += priority(i);
                break;
            }
        }
    }

bail:
    printf("score: %d\n", score);

#endif

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

