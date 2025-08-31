#include <stdio.h>

int main()
{
    int a[] = {3,2,2,2,4,3,4};
    int length = sizeof(a)/sizeof(a[0]);
    int count = 0;

    for(int i=0;i<length;i++)
    {
        count = 0;
        for(int j=0;j<length;j++)
        {
            if(a[j]==a[i])
            {
                count++;
            }
        }
        if(count>1)
        {
         printf("%d is repeated %d times\n",a[i],count);
        }
    }
    return 0;

}
