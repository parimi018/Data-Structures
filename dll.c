#include<stdio.h>
#include<stdlib.h>
struct dll
{
        int val;
        struct dll *before,*next;
};

struct dll* createnode(int v)
{
        struct dll *h;
        h=(struct dll*)malloc(sizeof(struct dll));
        h->val=v;
        h->before=NULL;
        h->next=NULL;
        return h;
}

struct dll* createlist(int n)
{
        struct dll *h=NULL,*nn,*tail;
        for(int i=0;i<n;i++)
        {
                int v;
                printf("Enter the value:");
                scanf("%d",&v);
                nn=createnode(v);
                if(h==NULL)
                        h=nn;
                else
                {
                        tail->next=nn;
                        nn->before=tail;
                }
                tail=nn;
        }
        return h;
}

int listsize(struct dll *h)
{
        int c=0;
        while(h)
        {
                c+=1;
                h=h->next;
        }
        return c;
}

struct dll* delbeg(struct dll *h)
{
        struct dll *t=h->next;
        free(h);
        return t ;
}

struct dll* delend(struct dll *h)
{
        struct dll *t=h,*temp;
        while(h->next->next!=NULL)
                h=h->next;
        temp=h->next;
        h->next=NULL;
        free(temp);
        return t;
}

struct dll* inserbeg(struct dll *h)
{
         struct dll *nn;
         int v;
         printf("Enter a value to insert at the beginning:");
         scanf("%d",&v);
         nn=createnode(v);
         nn->next=h;
         h->before=nn;
         printf("The list after inserting %d at the beggining is:",v);
         return nn;
}

struct dll* inserend(struct dll *h)
{
        struct dll *t=h,*nn;
        int v;
        printf("Enter a value to insert at the end:");
        scanf("%d",&v);
        nn=createnode(v);
        while(h->next)
                h=h->next;
        h->next=nn;
        nn->before=h;
        printf("The list after inserting %d at the end is:",v);
        return t;
}

struct dll* inserpos(struct dll *h)
{
        struct dll *t=h,*temp,*nn;
        int n=listsize(h);
        int p,v;
        printf("Enter the value to insert:");
        scanf("%d",&v);
        printf("Enter the position to insert:");
        scanf("%d",&p);
        nn=createnode(v);
        for(int i=1;i<p-1;i++)
                h=h->next;
        nn->next=h->next;
        nn->before=h;
        h->next->before=nn;
        h->next=nn;
        return t;
}

struct dll* delpos(struct dll *h)
{
        struct dll *t=h,*temp;
        int p,n;
        n=listsize(h);
        printf("Enter the position to delete the element:");
        scanf("%d",&p);
        if(p==1)
        {
            temp=h->next;
            free(h);
            return temp;
        }
        else if(p==n)
        {
            while(h->next->next!=NULL)
                h=h->next;
            temp=h->next;
            h->next=NULL;
            free(temp);
            return t;
        }
        else
        {
            for(int i=0;i<p-1;i++)
                h=h->next;
            h->next=temp;
            h->next=temp->next;
            temp->next->before=h->next;
            free(temp);
            return t;
        }
}

void display(struct dll *h)
{
        while(h)
        {
                printf("%d <-> ",h->val);
                h=h->next;
        }
        printf("\n");
}

void main()
{
        struct dll *h;
        int n;
        printf("Enter n:");
        scanf("%d",&n);
        h=createlist(n);
        printf("The given list is:");
        display(h);
        printf("The given list after the deletion of 1st node:");
        h=delbeg(h);
        display(h);
        printf("The given list after the deletion of last node:");
        h=delend(h);
        display(h);
        h=inserbeg(h);
        display(h);
        h=inserend(h);
        display(h);
        h=inserpos(h);
        display(h);
        h=delpos(h);
        display(h);
}

