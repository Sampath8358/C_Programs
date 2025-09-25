#include <stdio.h>

int main(){
    int arr[5] = {1,2,3,4,5};
    int low,high,mid,s,flag = -1;
    low = 0;
    high = 5 - 1;
    printf("Enter the element to be searched: ");
    scanf("%d",&s);
    while(low<=high)
    {
        mid = (low + high)/2;
        if(arr[mid] == s)
        {
            printf("Element found");
            flag = mid;
            break;
        }
        if(arr[mid]<s)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }     
    }
    if(flag == -1){
        printf("Element not found");
    }

}