//簡単なソートを作ってみようと思う

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int main(int num, char **getstr)
{
    (void)num;
    int i = 0;
    int count = 0;
    while(getstr[count])
        count++;
    
    int *arr = (int *)malloc(count * sizeof(int));

    while(i < count)
    {
        arr[i] = atoi(getstr[i]);
        i++;
    }

    int j = 0;
    while(j < count - 1)
    {
        i = 0;
        while(i < count - 1 - j)
        {
            if (arr[i] > arr[i + 1])
            {
                int tmp;
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
            i++;
        }
        j++;
    }

    i = 1;
    while (i < count)
    {
        printf("%d ", arr[i]);
        i++;
    }
    return 0;
}