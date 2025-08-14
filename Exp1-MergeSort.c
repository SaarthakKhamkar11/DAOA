#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int mid, int low, int high){
    int i,j,k,temp[100];
    i = low;
    j = mid +1;
    k = low;

    while(i<=mid && j <=high) {
        if (arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while(j<=high){
        temp[k] = arr[j];
        j++;
        k++;
    }
    
    while(i<=mid){
        temp[k] = arr[i];  
        i++;
        k++;
    }

    

    for (i = low; i<=high; i++){
        arr[i] = temp[i];
    }
}

void MergeSort(int arr[], int low, int high){
    
    int mid;

    if(low<high) {
        mid = (low + high) /2;  
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        merge(arr, mid, low, high);

    }
}

int main()
{

    int arr[100];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Original Array: ");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

    MergeSort(arr, 0,n-1);
        
    printf("\nSorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

    return 0;
}