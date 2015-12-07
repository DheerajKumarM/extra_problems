#include<stdlib.h>
#include<stdio.h>
struct testcases
{
    int size;
    int input[20];
    int output[20];
}t[10]={{5,{1,2,3,4,5},{5,4,3,2,1}},
        {1,{1},{1}},
        {2,{1,1},{1,1}},
        {3,{1,2,3},{3,2,1}},
        {5,{-2,-1,0,1,2},{2,1,0,-1,-2}},
        {5,{-6,-5,-4,-3,-2},{-2,-3,-4,-5,-6}},
        {10,{10,9,8,7,6,5,4,3,2,1},{1,2,3,4,5,6,7,8,9,10}},
        {6,{1,8,3,7,9,4},{4,9,7,3,8,1}},
        {3,{-1,-2,-3},{-3,-2,-1}},
        {1,{-20},{-20}}
       };
struct node
{
    int data;
    struct node *next;
}*temp1=NULL,*temp2=NULL,*start=NULL;
void create(int i)
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
        }
        else
        {
            current->next=new_node;
            current=new_node;
        }
    }while(j!=t[i].size);
}
int check(struct node *temp,int i)
{
    int j;
    for(j=0;j<t[i].size;j++)
    {
        if(temp->data==t[i].output[j])
        {
            temp=temp->next;
        }
    }
    if(j==t[i].size)
        return 1;
    else
        return 0;
}
struct node *reverse(struct node *temp)
{
    if(temp->next!=NULL)
    {
        temp2=reverse(temp->next);
        temp2->next=temp;
        return temp;
    }
    else if(temp->next==NULL)
    {
        start=temp;
        return start;
    }
}
int main()
{
    int i,res;
    struct node *temp,*tail1;
    for(i=0;i<10;i++)
    {
        create(i);
        temp=reverse(start);
        temp->next=NULL;
        res=check(start,i);
        if(res==1)
            printf("\nPass");
        else
            printf("\nFail");
    }
    return 1;
}
