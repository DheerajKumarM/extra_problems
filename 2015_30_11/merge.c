#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct testcases
{
    int size1;
    int input1[20];
    int size2;
    int input2[20];
    int output[40];
}t[10]={{4,{1,3,5,7},4,{2,4,6,8},{1,2,3,4,5,6,7,8}},
        {1,{1},1,{2},{1,2}},
        {1,{7},6,{1,2,3,4,5,6},{1,2,3,4,5,6,7}},
        {5,{1,2,3,4,5},5,{6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10}},
        {4,{-3,-2,-1,0},3,{1,2,3},{-3,-2,-1,0,1,2,3}},
        {4,{-4,-3,-2,-1},4,{1,2,3,4},{-4,-3,-2,-1,1,2,3,4}},
        {1,{1},5,{2,3,4,5,6},{1,2,3,4,5,6}},
        {5,{1,2,3,4,5},1,{6},{1,2,3,4,5,6}},
        {4,{-1,-3,-5,-7},1,{-2},{-1,-2,-3,-5,-7}},
        {1,{-5},3,{-1,-2,-4},{-1,-2,-4,-5}}};
struct node
{
int data;
struct node *next;
}*start=NULL,*start1=NULL,*start2=NULL;
struct node* create1(int i)
{
 char ch;
 int j=0;
 start=NULL;
 do
 {
  struct node *new_node,*current;
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=t[i].input1[j++];
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
 }while(j!=t[i].size1);
  return start;
}
struct node* create2(int i)
{
 char ch;
 int j=0;
 start=NULL;
 do
 {
  struct node *new_node,*current;
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=t[i].input2[j++];
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
 }while(j!=t[i].size2);
 return start;
}
int check(struct node *temp,int i)
{
    int j;
    for(j=0;j<t[i].size1+t[i].size2;j++)
    {
        if(temp->data==t[i].output[j])
        {
            //printf(" %d ",temp->data);
            temp=temp->next;
        }
    }
    if(j==t[i].size1+t[i].size2)
        return 1;
    else
        return 0;
}
struct node* merge(struct node* a, struct node* b)
{
    struct node* result = NULL;
    if (a == NULL)
        return(b);
    else if (b==NULL)
        return(a);
    if (a->data <= b->data)
    {
        result = a;
        result->next = merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge(a, b->next);
    }
    return(result);
}
int main()
{
    int i,res;
    for(i=0;i<10;i++)
    {
        start1=create1(i);
        start2=create2(i);
        start=merge(start1,start2);
        res=check(start1,i);
        if(res==1)
            printf("\nPass");
        else
            printf("\nFail");
    }
    return 1;
}
