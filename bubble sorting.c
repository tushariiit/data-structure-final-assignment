#include<stdio.h>
int main()
{
int m,i,j,k;

printf("Enter the size of array:");
scanf("%d",&m);

int a[m];

printf("Enter the array elements:");
for(i=0;i<m;++i)
{
    scanf("%d",&a[i]);
}
for(i=1;i<m;++i)
{
    for(j=0;j<(m-i);++j)
    {
        if(a[j]>a[j+1])
            {
            k=a[j];
            a[j]=a[j+1];
            a[j+1]=k;
            }
    }
}

printf("\nArray after sorting: ");
for(i=0;i<m;++i)
{
printf("%d\t ",a[i]);
}
return 1;
}
