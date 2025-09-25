#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a; 
    *a = *b;
    *b = temp;
}

int main(){
    int arr[4] = {4,3,2,1};
    int n = 4;
    int i, j;

    for(i = 1; i < n; i++)
    {
        j = i;
        while(j >= 1 && arr[j] < arr[j - 1])
        {
            swap(&arr[j], &arr[j - 1]);
            j--;
        }
    }

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
