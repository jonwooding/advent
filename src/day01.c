#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "advent.h"

AdventError day01(void)
{
    FILE *fd = 0;
    int ret = ADVENT_SUCCESS;
    int bytes_read = 0;
    char *line = NULL;
    size_t line_len = 1024;


    fd = fopen("inputs/day01.txt", "r");
    if (NULL == fd)
    {
        printf("Failed to access input file!\n");
        ret = ADVENT_BAD_INPUT;
        goto cleanup;
    }

    line = (char*) malloc(line_len);

    unsigned int curr = 0;
    unsigned int max = 0;
    unsigned int max2 = 0;
    unsigned int max3 = 0;

    // getline returns -1 on eof
    while(bytes_read = getline(&line, &line_len, fd) > 0)
    {
        // does not handle \r\n, lazy
        if (strlen(line) == 1)
        {
            if (curr > max)
            {
                printf("Encountered new max!\n");
                max3 = max2;
                max2 = max;
                max = curr; 
                curr = 0;
            }

            if (curr > max2)
            {
                max3 = max2;
                max2 = curr;
                curr = 0;
            }

            if (curr > max3)
            {
                max3 = curr;
                curr = 0;
            }

            curr = 0;
            continue;
        }

        curr += atoi(line);
    }

    printf("Maximum calories found: %d\n", max); 
    printf("Top 3: %d\n", max + max2 + max3); 

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

