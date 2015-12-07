#include<stdio.h>
#include<stdlib.h>
struct testcases
{
    int size;
    int input[20];
    int output[20];
}t[10]={{7,{1,5,7,10,6,3,2},{1,2,3,5,6,7,10}},{5,{10,15,20,11,1},{1,10,11,15,20}},{3,{0,2,1},{0,1,2}},{1,{1},{1}},{7,{-3,-2,-1,0,1,2,3},{-3,-2,-1,0,1,2,3}},
        {8,{-8,-7,-6,-1,-2,-3,-4,-5},{-8,-7,-6,-5,-4,-3,-2,-1}},{8,{100,255,366,955,566,452,129,26},{26,100,129,255,366,452,566,955}},
        {3,{1,2,1},{1,1,2}},{3,{-56,0,89},{-56,0,89}},{15,{1,5,10,15,20,25,30,35,34,29,24,19,14,9,4},{1,4,5,9,10,14,15,19,20,24,25,29,30,34,35}}};
struct node
{
    int data;
    struct node *next;
}*start=NULL;
int create(int count)
{
 char ch;
 int i=0;
 start=NULL;
 do
 {
  struct node *new_node,*current;
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=t[count].input[i];
  i++;
  new_node->next=NULL;
  if(start==NULL)
  {
  start=new_node;
  current=new_node;
  }
  else
  {
  current->next=new_node;
  current=new_node;
  }
 }while(i<t[count].size);
 return i;
}
int validate(struct node *start,int i)
{
    int j=0;
    struct node *temp = start;
    while (temp!=NULL)
    {
        //printf(" %d ",temp->data);
        if(temp->data!=t[i].output[j++])
            return 0;
        temp = temp->next;
    }
    return 1;
}
void Sort(struct node *start)
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
    ptr1=start;
    if (ptr1 == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
int main()
{
    int i,ans;
    for(i=0;i<10;i++)
    {
        create(i);
        Sort(start);
        ans=validate(start,i);
        if(ans==1)
            printf("\nPass");
        else
            printf("\nFail");
    }
    return 0;
}
