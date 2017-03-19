/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int start = 0;
    int end = n - 1;
    int middle = (start + end) / 2;
    while (start <= end)
    {
        if (values[middle] == value) {
            return true;
        } else if (value < values[middle]) {
            end = middle - 1;
            n = end - start;
            search(value, values, n);
        } else if (value > values[middle]) {
            start = middle + 1;
            n = end - start;
            search(value, values, n);
        }
        middle = (start + end) / 2;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int temp;
    int swap_counter = -1;
    while (swap_counter != 0)
    {
        swap_counter = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (values[i] > values[i + 1]) {
                temp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = temp;
                swap_counter++;
            }
        }
    }
    return;
}
