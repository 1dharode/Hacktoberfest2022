#include <stdio.h>

void mearge(int arrA[], int arrB[], int m, int n, int array[])
{
    int ptA = 0, ptB = 0, idx = 0; // ptA - pointer of arrayA , ptB - pointer of arrayB

    while (idx != m + n)
    {
        if (arrA[ptA] < arrB[ptB])
        {
            array[idx] = arrA[ptA];
            ptA++;
        }

        else if (arrA[ptA] > arrB[ptB])
        {
            array[idx] = arrB[ptB];
            ptB++;
        }

        else
        {
            array[idx] = arrA[ptA];
            ptA++;
            idx++;
            array[idx] = arrB[ptB];
            ptB++;
        }
        idx++;
    }
}

int main()
{
    int m, n;
    // get first array
    printf("Enter the lenght of first sorted array : ");
    scanf("%d", &m);
    int arrA[m];
    printf("Enter the values : ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arrA[i]);
    }

    // get secound array
    printf("Enter the lenght of second sorted array : ");
    scanf("%d", &n);
    int arrB[n], array[m + n];
    printf("Enter the values : ");
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &arrB[i]);
    }

    mearge(arrA, arrB, m, n, array);

    printf("Merge sorted array : ");
    for (int i = 0; i < m + n; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}
