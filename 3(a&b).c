#include<stdlib.h>
#include<stdio.h>
void merge(char a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    char L1[n1], L2[n2];

    for (i = 0; i < n1; i++)
        L1[i] = a[l + i];
    for (j = 0; j < n2; j++)
        L2[j] = a[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L1[i] <= L2[j])
        {
            a[k] = L1[i];
            i++;
        }
        else
        {
            a[k] =L2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = L2[j];
        j++;
        k++;
    }
}
void mergesort(int a,int b,char ptr[])
{
        if(a<b)
        {
        int c=(a+b)/2;
        mergesort(a,c,ptr);
        mergesort(c+1,b,ptr);
        merge(ptr,a,c,b);
        }
}
int main()
{
    int n;
    printf("Enter no of elements in string=");
    scanf("%d",&n);
    char *arr;
    arr=(char *)malloc(n*sizeof(char));
    printf("Enter string(without spaces)-");
            scanf("%s",arr);
    mergesort(0,n-1,arr);

    printf("\nSorted string is\n");
    for(int x=0;x<n;x++)
    {
         printf(" %c",arr[x]);
    }
 }
