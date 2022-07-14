#include <stdio.h>
#include <stdlib.h>

#define N 100

int weight[N], value[N], cap;
int maxSet[N], maxSetSize = 0, maxValue = 0;
int c[15][150];

void printArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("[%d]", arr[i]);
    printf("\n");
}

void calculate_subset_sum(int s[], int n, int m)
{
    int i,j;

    for(i = 0; i <= n; i++)
        c[i][0] = 1;
    
    for(i = 1; i <=m; i++)
        c[0][i] = 0;
    
    for(i = 1; i <= m; j++)
    {
        for(j = 1;j <= m;j++)
        {
            c[i][j] = 0;
            
            if(j >= s[i-1])
                if(c[i-1][j-s[i - 1]] == 1)
                    c[i][j] = 1;

            if(c[i-1][j] == 1)
                c[i][j] = 1;
        }
    }
}

void eval(int arr[], int setSize)
{
    int currWeight = 0, currValue = 0;
    for(int i = 0; i < setSize; i++)
    {
        currWeight += weight[arr[i]];
        currValue += value[arr[i]];
    }

    if(currWeight > cap)
        return;

    if(currValue > maxValue)
    {
        maxValue = currValue;
        maxSetSize = setSize;
        for(int i = 0; i < setSize; i++)
            maxSet[i] = arr[i];
    }
}

void subset(int arr[], int setSize, int n, int idx)
{
    if(idx == n)
    {
        eval(arr,setSize);
        return;
    }

    arr[setSize] = idx;

    subset(arr, setSize + 1, n, idx + 1);
    subset(arr, setSize, n, idx + 1);
}

int main()
{
    int arr[N], n;
    scanf("%d %d", &n, &cap);

    subset(arr, 0, n, 0);
}