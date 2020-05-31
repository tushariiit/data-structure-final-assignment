#include<stdio.h>
int main()
{
    int n,temp,j;
    printf("Enter no of elements:");
    scanf("%d",&n);

    int a[n];
    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i=1;i<n;i++)
    {
       temp=a[i];
        j=i-1;
        while(j>=0&&a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }

    printf("The sorted array is:\n");

    for(int i=0;i<n;i++)
    {
        printf("%d element=%d\n",i,a[i]);
    }


}
