#include<stdio.h>
//to swap the nos
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}
// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}
int main()
{
    int n;
    printf("Enter no of elements:");
    scanf("%d",&n);
    int arr[n];
     printf("Enter elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);j
    }
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
