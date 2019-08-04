#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *create_node(int data);
struct node *insert(struct node *start,int data);
struct node *create_loop(struct node *start,int count);
void display(struct node *start,int count);
struct node *remove_loop(struct node *start,struct node *f);
int main()
{
    int data,check,count=0;
    struct node *start=NULL;
    while(1)
    {
        printf("Enter any data: ");
        scanf("%d",&data);
        start=insert(start,data);
        printf("Enter \'1\' to continue or any other key to quit : ");
        scanf("%d",&check);
        if(check!=1)
            break;
        count++;
    }
    printf("Enter \'1\' to create loop or any other key to quit : ");
    scanf("%d",&check);
    if(check==1)
        start=create_loop(start,count);
    struct node *slow=start,*fast=start;
    while(slow!=NULL && fast!=NULL && fast->link!=NULL)
    {
        slow=slow->link;
        fast=fast->link->link;
        if(slow==fast)
        {
            printf("\nLoop detected\n");
            display(start,0);
            start=remove_loop(start,fast);
            printf("\nLoop removed\n");
            display(start,count);
            return 0;
        }
    }
    printf("\nThere is no loop in the linked list\n");
    display(start,count);
    return 0;
}
struct node *create_node(int data)
{
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->info=data;
    t->link=NULL;
    return t;
}
struct node *insert(struct node *start,int data)
{
    if(start==NULL)
    {
        start=create_node(data);
        return start;
    }
    struct node *t=start;
    while(t->link!=NULL)
        t=t->link;
    t->link=create_node(data);
    return start;
}
struct node *create_loop(struct node *start,int count)
{
    int i;
    srand(time(NULL));
    int countf=1+(rand()%count); //loop is created randomly at any position
    printf("\n%d\n",countf);
    struct node *t=start;
    for(i=1;i<countf;i++)
        t=t->link;
    struct node *q=start;
    while(q->link!=NULL)
        q=q->link;
    q->link=t;
    return start;
}
struct node *remove_loop(struct node *start,struct node *fast)
{
    struct node *slow=start;

    //finding starting of the loop
    while(slow!=fast)
    {
        slow=slow->link;
        fast=fast->link;
    }

    //removing loop
    while(fast->link!=slow)
        fast=fast->link;
    fast->link=NULL;
    return start;
}
void display(struct node *start,int count)
{
    struct node *t=start;
    if(count==0)
    {
        count=30;
        while(count--)
        {
            printf("%d ",t->info);
            t=t->link;
        }
        printf("...");
    }
    else
    {
        while(t!=NULL)
        {
            printf("%d ",t->info);
            t=t->link;
        }
    }
}
