#include<stdlib.h>
#include<stdio.h>
struct testcases
{
    int size;
    int input_arr[20];
    int output_arr[20];
}t[10]={{5,{1,2,3,4,5},{1,2,3,4,5}},{5,{-1,-2,-3,-4,-5},{-1}},{10,{-256,-128,-64,-8,0,16,512,1024,4096,8500},{0,16,512,1024,4096,8500}},
       {1,{23},{23}},{0,{},{}},{6,{2,4,-7,2,5,-8},{2,5}},{5,{156,-10,71,81,5},{156,-10,71,81,5}},{5,{3000,-500,2500,-30000,2501},{3000,-500,2500}}
       ,{4,{1,2,3,-4},{1,2,3}},{7,{-10,-20,0,25,63,-5,-6},{0,25,63}}};
int max_subarray(int *array, int len,int z)
{
    int start,end,maxSum;
    int maxSumSoFar=-1;
    int Sum = 0;
    int a = 0,b = 0,s = 0,i = 0;
    for( i = 0; i < len; i++ )
    {
        Sum += array[i];
        if ( Sum > maxSumSoFar )
        {
            maxSumSoFar = Sum;
            a = s;
            b = i;
        }
        if( Sum < 0 )
        {
            Sum = 0;
            s = i + 1;
        }
    }
    start = a;
    end = b;
    maxSum = maxSumSoFar;
    return validate(array,a,b,z);
}
int validate(int *array,int a,int b,int z)
{
    int i,j,flag=0;
    for(i=a,j=0;i<=b;i++,j++)
    {
        //printf(" %d ",array[i]);
        if(array[i]!=t[z].output_arr[j])
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        return 0;
    else
        return 1;
}
int main()
{
    int ans,i;
    for(i=0;i<10;i++)
    {
        ans=max_subarray(t[i].input_arr,t[i].size,i);
        if(ans==1)
            printf("\nPass");
        else
            printf("\nFail");
    }
    return 1;
}
