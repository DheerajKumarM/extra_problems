#include<stdio.h>
#include<stdlib.h>
struct testcases
{
    int input1;
    int input2;
    int k;
    int output;
}t[10]={{2,3,10,15},{1,1,1,1},{2,2,10,20},{2,3,1,2},{2,3,2,3},{100,100,100,10000},{-2,-5,5,-20},{5,9,15,54},{100,110,50,2750},{100000,50000,250,12500000}};
int find_value(int n1,int n2,int k)
{
    int *small,*large,i,j,current=0,count=2;
    small=(int*)malloc(sizeof(int)*k);
    large=(int*)malloc(sizeof(int)*k);
    if(n1<n2)
    {
        small[0]=n1;
        large[0]=n2;
    }
    else if(n1>n2)
    {
        small[0]=n2;
        large[0]=n1;
    }
    else
        return n1*k;
    if(k==1)
        return small[0];
    else if(k==2)
        return large[0];
    for(i=0,j=0;count!=k;)
    {
        if(small[i]<large[j])
        {
            current=1;
            small[i+1]=small[i]+small[0];
            i++;
            count++;
        }
        else if(large[j]<small[i])
        {
            current=2;
            large[j+1]=large[j]+large[0];
            j++;
            count++;
        }
        else
        {
            current=1;
            small[i+1]=small[i]+small[0];
            i++;
        }
    }
    if(current==1)
        return small[i];
    else
        return large[j];
}
int main()
{
    int answer,i;
    for(i=0;i<10;i++)
    {
        answer=find_value(t[i].input1,t[i].input2,t[i].k);
        if(answer==t[i].output)
            printf("\nPass");
        else
            printf("\nFail");
    }
    return 1;
}
