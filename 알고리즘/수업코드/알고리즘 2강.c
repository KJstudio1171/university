#include <stdio.h>
#include <stdlib.h>

void rPrintDigits(int n)
{
    if(n < 10)
        printf("%d\n", n);
    else
    {
        rPrintDigits(n/10);
        printf("%d\n",n % 10);
    }
}

void printDigits()
{
    int n;
    printf("Enter a number :");
    scanf("%d", &n);
    if(n<0)
        printf("Negative!");
    else
        rPrintDigits(n);
}

int recur_power(int x, int n)
{
    if(n == 0)
        return 1;
    else if ((n%2)==0)
        return recur_power(x*x , n/2);
    else
        return x* recur_power(x*x, (n-1)/2);
}

void rHanoi(int n, char from, char aux, char to)
{
    if(n == 1)
        printf("Disk %d : Move from %d to %d\n", n , from , to);
    else
    {
        rHanoi(n-1, from , to, aux);
        printf("Disk %d : Move from %c to %c\n", n, from, to);
        rHanoi(n-1, aux, from, to);
    }
}

void main()
{
    printDigits();
}