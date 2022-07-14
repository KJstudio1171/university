#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 8
#define COLS 8

#define SIZE 8

void makeArray(int A[][COLS])
{
    for(int r = 0; r < ROWS; r++)
        for(int c = 0; c < COLS; c++)
            A[r][c] = rand() % 100;        
}

void makeArray2(int A[][COLS])
{
    for(int r = 0; r < ROWS; r++)
    {
        int count = rand() % 9;
        for(int i = 0; i < count; i++)
            A[r][i] = 1;
        for(int j = count; j < COLS; j++)
            A[r][j] = 0;
    }
}

void makeArray3(int A[])
{
    for(int i = 0 ; i< SIZE; i++)
        printf("[%d]", A[i]);
    printf("\n");
}

void prefixAVg1(int A[])
{
    int X[SIZE];
    int sum;
    for(int i = 0; i < SIZE; i++)
    {
        sum = 0;
        for(int j = 0; j <=i; j++)
            sum +=A[j];
        X[i] = sum / (i + 1);
    }
    printArray(X);
}

void prefixAVg2(int A[])
{
    int X[SIZE];
    int sum = 0;
    for(int i = 0; i < SIZE; i++)
    {
        sum += A[i];
        X[i] = sum / (i + 1);
    }
    printArray(X);
}


void printArray(int A[][COLS])
{
    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLS; c++)
            printf("%2d", A[r][c]);
        printf("\n");
    }
    printf("\n");
}

int findRow(int A[], int key)
{
    for(int c = 0; c < COLS; c++)
        if(A[c] == key)
            return c;
    return -1;
}

void mostOnesButSlow(int A[][COLS])
{
    int jmax = 0;
    int i, j, row;
    for(i = 0; i < ROWS; i++)
    {
        j = 0;
        while(j < COLS && A[i][j] == 1)
            j++;
        if(j > jmax)
        {
            row = i;
            jmax = j;
        }
    }
}

int mostOnes(int A[][COLS])
{
    int i = 0, j = 0;
    int row;

    while(1)
    {
        while(A[i][j] == 1)
        {
            j++;
            if(j == COLS -1)
                return i;
        }
        row = i;
        while(A[i][j] == 0)
        {
            i++;
            if(i ==  COLS-1)
                return row;
        }
    }
}

void findMatrix(int A[][COLS], int key)
{
    int r = 0;
    int index;

    while(r < ROWS)
    {
        index = findRow(A[r],key);
        if(index >=0)
        {
            printf("%d행 %d열" , r, index);
            return;
        }
        else
            r++;
    }
}


void main()
{
    int A[ROWS][COLS];
    srand(time(NULL));
    makeArray(A);
    printArray(A);

    int key;
    printf("Input a key value : ");
    scanf("%d", &key);
    findMatrix(A, key);
}



