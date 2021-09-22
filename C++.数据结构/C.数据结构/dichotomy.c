#include<stdio.h>
#include<stdlib.h>

/* 二分查找，是则返回索引，否则返回-1 */
int dichotomy(int * ar,int size,int K);

int main()
{   
    int ar[20];
    for(int i=0;i<20;i++)
        ar[i] = i*2;
    for(int i=0;i<20;i++)
        printf("%d ",ar[i]);
    printf("\n");
    printf("%d",dichotomy(ar,20,-1));
    return 0;
}

int dichotomy(int * ar,int size,int K)
{
    int left=0;
    int right=size-1;

    if(ar[left]>K&&ar[right]>K)
        return -1;                  //表示ERROR
        
    while (left<right)
    {
        int mid = (left+right)/2;
        if(K<ar[mid])
            right = mid-1;
        else if(K>ar[mid])
            left = mid+1;
        
        if(K>ar[mid]&&K<ar[mid+1])
            return mid;
    }
}
