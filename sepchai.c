#include<stdio.h>
#include<stdlib.h>
struct n
{
    int sno;
    char name[25];
    int sal;
    struct n *next;
};

struct n **h[10];

struct n* createnode(int sn,char nam[],long sa)
{
    struct n*h=(struct n*)malloc(sizeof(struct n));
    h->sno=sn;
    strcpy(h->name,nam);
    h->sal=sa;
    h->next=NULL;
    return h;
}

void createlist()
{
    struct n *nn;
    int rn,no;
    char n[25];
    int s;
    printf("Enter no of employees:");
    scanf("%d",&no);
    for(int i=0;i<no;i++)
    {
        printf("\nEnter employee Regdno:");
        scanf("%d",&rn);
        printf("\nEnter employee Name:");
        scanf("%s",&n);
        printf("\nEnter employee Salary:");
        scanf("%d",&s);
        nn=createnode(rn,n,s);
        int j=rn%10;
        if(h[j]==NULL)
        {
            h[j]=nn;
        }
        else
        {
            nn->next=h[j];
            h[j]=nn;
        }

    }
}

struct n* search()
{
    int v;
    printf("\nEnter employee Regno:");
    scanf("%d",&v);
    int j=v%10;
    if(h[j]==NULL)return NULL;
    struct n *t=h[j];
    if(t->sno==v)
    {
        return t;
    }
    t=t->next;
}

void printnode(struct n *h)
{
    printf("\nRegdno\tName\tSalary");
    printf("\n%d\t%s\t%d\t",h->sno,h->name,h->sal);
}

void printrow(struct n *h)
{
    while(h)
    {
        printnode(h);
        h=h->next;
    }
}

void printtable()
{
    for(int i=0;i<10;i++)
    {
        if(h[i]!=NULL)printrow(h[i]);
    }
}

void main()
{
    struct n *h;
    createlist();
    printf("The details of all the employees is:");
    printtable();
    h=search();
    printf("The details of the given employee is:");
    printnode(h);
}
