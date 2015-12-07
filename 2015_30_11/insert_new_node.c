#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct testcases
{
    int size;
    int input[20];
    int insnode;
    int output[20];
}t[10]={{5,{1,2,3,5,6},4,{1,2,3,4,5,6}},{1,{0},5,{0,5}},{4,{-2,-1,0,3},5,{-2,-1,0,3,5}},{5,{1,2,3,4,5},0,{0,1,2,3,4,5}},{3,{-3,-2,-1},0,{-3,-2,-1,0}}
       ,{10,{10,20,30,40,50,60,70,80,90,100},200,{10,20,30,40,50,60,70,80,90,100,200}},
       {4,{-5,-4,-3,-2},-1,{-5,-4,-3,-2,-1}},{5,{-5,-4,-3,-2,-1},-6,{-6,-5,-4,-3,-2,-1}}
       ,{5,{-6,-5,-4,-3,-1},-2,{-6,-5,-4,-3,-2,-1}},{4,{-2,-1,1,2},0,{-2,-1,0,1,2}}};
struct node
{
int data;
struct node *next;
}*start=NULL;
create(int i)
{
 char ch;
 int j=0;
 do
 {
  struct node *new_node,*current;
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=t[i].input[j++];
  new_node->next=NULL;
  if(start==NULL)
  {
  start=new_node;
  current=new_node;
  current->next=start;
  }
  else
  {
  current->next=new_node;
  current=new_node;
  current->next=start;
  }
 }while(j<t[i].size);
}
int insert(int i)
{
    int inf,flag=0,j;
    struct node *temp,*temp1=NULL,*temp2;
    inf=t[i].insnode;
    temp=start;
    while(temp->next!=start)
    {
        if(start->data>inf)
        {
            temp1=(struct node*)malloc(sizeof(struct node));
            temp1->data=inf;
            temp1->next=start;
            flag=1;
        }
        temp2=temp;
        temp=temp->next;
        if(temp->data>inf&&flag==0)
        {
            temp1=(struct node*)malloc(sizeof(struct node));
            temp1->data=inf;
            temp2->next=temp1;
            temp1->next=temp;
            break;
        }
    }
    if(flag==1)
    {
        temp->next=temp1;
        start=temp1;
    }
    else if(temp1==NULL)
    {
        temp1=(struct node*)malloc(sizeof(struct node));
        temp1->data=inf;
        temp->next=temp1;
        temp1->next=start;
    }
    temp=start;
    for(j=0;j<t[i].size+1;j++)
    {
        if(temp->data==t[i].output[j])
        {
            //printf(" %d ",temp->data);
            temp=temp->next;
        }
    }
    if(j==t[i].size+1)
        return 1;
    else
        return 0;
}
int main()
{
    int res,i;
    for(i=0;i<10;i++)
    {
        create(i);
        res=insert(i);
        if(res==1)
            printf("\nPass");
        else
            printf("\nFail");
    }
    return 1;
}
