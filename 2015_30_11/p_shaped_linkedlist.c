#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct testcases
{
    int size;
    int input[20];
    int number;
    int output;
}t[12]={{3,{1,2,3},2,2},{5,{10,20,30,40,50},3,30},{5,{2,4,6,8,10},1,2},{2,{1,2},2,2},{10,{2,4,6,7,9,11,15,18,19,25},7,15},
        {1,{10},1,10},{5,{1,2,3,4,5},1,1},{5,{10,20,30,40,50},4,40},{10,{1,2,3,4,5,6,7,8,9,10},5,5},{6,{-3,-2,-1,0,1,5},2,-2},
        {6,{-3,-2,-1,0,1,5},4,0},{8,{-20,-17,-15,-14,-10,-8,-6,-4},4,-14}};
struct node
{
int data,flag;
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
        new_node->data=t[count].input[i++];
        new_node->flag=0;
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
int main()
{
    struct node *temp,*temp1=NULL;
    int num,count,med,i,j;
    for(j=0;j<12;j++)
    {
        count=create(j);
        temp=start;
        for(i=0;temp->next!=NULL;i++)
        {
            if(i==t[j].number-1)
                temp1=temp;
            temp=temp->next;
        }
        if(temp1==NULL&&t[j].number<=++i)
            temp->next=temp;
        else if(t[j].number>t[j].size)
        {
            printf("\nInvalid number");
        }
        else if(t[j].size==1)
            temp->next=temp;
        else
            temp->next=temp1;
        temp=start;
        for(i=0;;i++)
        {
            if(temp->flag==0)
            {
                temp->flag=1;
                temp=temp->next;
            }
            else if(temp->flag==1)
            {
                break;
            }
        }
        //printf("%d",temp->data);
        if(temp->data==t[j].output)
            printf("\nPass");
        else
            printf("\nFail");
    }
    return 1;
}
