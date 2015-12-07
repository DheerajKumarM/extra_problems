#include <stdio.h>
struct gasstation
{
  int gas;
  int distance;
};
int printTour(struct gasstation arr[], int n)
{
    int start = 0;
    int end =  1;
    int availablepetrol = arr[start].gas - arr[start].distance;
    while (end!=start||availablepetrol< 0)
    {
        while(availablepetrol<0&&start!=end)
        {
            availablepetrol-=arr[start].gas-arr[start].distance;
            start = (start + 1)%n;
            if (start == 0)
               return -1;
        }
        availablepetrol+=arr[end].gas-arr[end].distance;
        end = (end + 1)%n;
    }
    return start;
}
int main()
{
    int n,start,i;
    struct gasstation arr[] = {{1,2},{2,3},{3,4},{8,5}};
    n = sizeof(arr)/sizeof(arr[0]);
        start = printTour(arr, n);
        if(start!=-1)
            printf("Start = %d", start+1);
        else
            printf("No solution");
    return 0;
}
