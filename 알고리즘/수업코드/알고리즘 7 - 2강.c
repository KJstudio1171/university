#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 15
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

void partition(char list[], int left, int right)
{
    int low = left - 1,high = right + 1;
    char temp;

    do
    {
        do
            low++;
        while (list[low] == 'B');

        do
            high--;
        while(list[high] == 'R');

        if(low < high)
            SWAP(list[low], list[high], temp);
        
    } while (low < high);
    
}

