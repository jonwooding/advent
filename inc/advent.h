#pragma once

typedef void(*ADVENT)(void);

typedef enum 
{
    ADVENT_BAD_INPUT,
    ADVENT_SUCCESS = 0,
} AdventError;

// the define sets the size of the array and bounds of it 
#define DAYS        1

// one per
AdventError day01(void);
