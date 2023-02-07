#include<stdio.h>
#include<stdlib.h>
struct sll
{
    int val;
    struct sll *next;
};

struct sll* createnode(int v)
{
    struct sll *h;
    h=(struct sll*)malloc(sizeof(struct sll));
    h->val=v;
    h->next=NULL;
    return h;
}

struct sll* createlist(int n)
{
    struct sll *nn,*t,*h=NULL;
    for(int i=0;i<n;i++)
    {
        int value;
        printf("\nEnter the value:");
        scanf("%d",&value);
        nn=createnode(value);
        if(h==NULL)
            h=nn;
        else
            t->next=nn;
        t=nn;
    }
    return h;
}

struct sll* revlist(struct sll *h,int n)
{
    for(int i=0;i<n;i++)
    {
        t=h->next;
        temp=t;
        while(t!=NULL)
            t=t->next;
        t->next=h;
        temp=temp->next;
    }
}

void display(struct sll *h)
{
    while(h!=NULL)
    {
        printf("%d -> ",h->val);
        h=h->next;
    }
}

void main()
{
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    struct sll *h;
    h=createlist(n);
    display(h);
}
