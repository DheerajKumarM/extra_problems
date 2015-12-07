#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct testcases
{
    int size;
    int input[20];
    int output;
}t[7]={{5,{1,2,3,4,5},3},{4,{1,2,3,4},5},{1,{1},1},{2,{1,2},3},{7,{-3,-1,-1,4,13,17,20},4},{5,{1,2,3,7,9},3},{3,{-1,2,5},2}};
struct node
{
int data;
struct node *next;
}*start=NULL;
int create(int count)
{
 char ch;
 int i=0;
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
int median(int count)
{
    int i,sum=0;
    struct node *temp;
    temp=start;
    if(count%2==0)
    {
        count=(count/2)-1;
        for(i=0;i<count;i++)
        {
            temp=temp->next;
        }
        sum+=temp->data;
        temp=temp->next;
        sum+=temp->data;
    }
    else
    {
        count=count/2;
        for(i=0;i<count;i++)
        {
            temp=temp->next;
        }
        sum=temp->data;
    }
    return sum;
}
void main()
{
    int count,med,i;
    for(i=0;i<7;i++)
    {
        count=create(i);
        med=median(count);
        //printf(" \n%d ",med);
        if(med==t[i].output)
            printf("\nPass");
        else
            printf("\nFail");
    }
}
