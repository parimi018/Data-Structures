

















#include<stdio.h>
#include<stdlib.h>
struct cll
{
        int val;
        struct cll *next;
};

struct cll* cllnode(int v)
{
        struct cll *h;
        h=(struct cll*)malloc(sizeof(struct cll));
        h->val=v;
        h->next=NULL;
        return h;
}

struct cll* clllist(int n)
{
        struct cll *h=NULL,*nn,*tail;
        int v;
        for(int i=0;i<n;i++)
        {
                printf("Enter the value:");
                scanf("%d",&v);
                nn=cllnode(v);
                if(h==NULL)
                        h=nn;
                else
                        tail->next=nn;
                tail=nn;
        }
        tail->next=h;
        return tail;
}

int listsize(struct cll *h)
{
        struct cll *t=h->next;
        int c=1;
        while(t!=h){
                c++;
                t=t->next;
        }
        return c;
}

struct cll* inserbeg(struct cll *h)
{
        struct cll *nn;
        int v;
        printf("\nEnter a value to insert at the beginning:");
        scanf("%d",&v);
        nn=cllnode(v);
        nn->next=h->next;
        h->next=nn;
        return h;
}

struct cll* inserend(struct cll *h)
{
        struct cll *nn;
        int v;
        printf("\nEnter a value to insert at the ending:");
        scanf("%d",&v);
        nn=cllnode(v);
        nn->next=h->next;
        h->next=nn;
        return nn;
}

struct cll* inserpos(struct cll *h)
{
        struct cll *nn,*t=h,*temp;
        int v,p,n;
        printf("\nEnter the position to insert a value:");
        scanf("%d",&p);
        n=listsize(h);
        if(p==1) return inserbeg(h);
        if(p>=n) return inserend(h);
        printf("\nEnter a value to insert at position %d:",p);
        scanf("%d",&v);
        nn=cllnode(v);
        for(int i=1;i<p;i++)
                h=h->next;
        nn->next=h->next;
        h->next=nn;
        return t;

}

struct cll* delbeg(struct cll *h)
{
        struct cll *temp;
        temp=h->next;
        h->next=temp->next;
        free(temp);
        return h;
}

struct cll* delend(struct cll *h)
{
        struct cll *temp,*t=h->next;
        while(t->next!=h)
                t=t->next;
        temp=t->next;
        t->next=temp->next;
        free(temp);
        return t;
}

struct cll* delpos(struct cll *h)
{
        struct cll *temp,*t=h;
        int p,n;
        printf("\nEnter the position to delete the value:");
        scanf("%d",&p);
        n=listsize(h);
        if(p==1)
                return delbeg(h);
        else if(p==n)
                return delend(h);
        else if(p>n || p<1)
        {
                printf("\n %d position does not exist in the list\n",p);
                return h;
        }
        else
        {
                for(int i=1;i<p;i++)
                        h=h->next;
                temp=h->next;
                h->next=temp->next;
                free(temp);
                return t;
        }
}

struct cll* delval(struct cll *h)
{
        struct cll *t=h->next,*temp;
        int e,n=listsize(h);
        printf("\nEnter element to delete:");
        scanf("%d",&e);
        if(h->val==e)
                return delend(h);
        else if(h->next->val==e)
"cll.c" 284L, 45return delbeg(h);
        else if(e>n || (e<0 || e==0))
        {
                printf("Given value not found in the list\n");
                return h;
        }
        else
        {
                while(t->next!=h)
                {
                        if(t->next->val==e)
                        {
                                temp=t->next;
                                t->next=temp->next;
                                free(temp);
                                return h;
                        }
                        t=t->next;
                }
        }
}

int seaval(struct cll *h)
{
        struct cll *t=h->next;
        int e,n,c=2;
        printf("\nEnter the value to search:");
        scanf("%d",&e);
        n=listsize(h);
        if(h->val==e)
                return n;
        else if(h->next->val==e)
                return 1;
        else
        {
                while(t->next!=h)
                {
                        if(t->next->val==e)
                                return c;
                        c++;
                        t=t->next;
                }
        }
        printf("Given element not found in the list");
        return 0;
}

int seapos(struct cll *h)
{
        struct cll *t=h->next;
        int p,n;
        printf("\nEnter the position:");
        scanf("%d",&p);
        n=listsize(h);
        if(p>n&&p<1)
        {
                printf("Given position not found in the list");
                return 0;
        }
        else
        {
                if(p==1)
                        return t->val;
                else if(p==n)
                        return h->val;
                else
                {
                        for(int i=1;i<p-1;i++)
                                t=t->next;
                        return t->next->val;
                }
        }
}

int detect(struct cll *h,struct cll *t,int n)
{
        for(int i=0;i<n;i++)
        {
                if(h==t)
                        return 1;
                h=h->next;
        }
        return 0;
}

int cycle(struct cll *h)
{
        struct cll *temp=h;
        int i=0;
        while(h->next)
        {
                if(detect(h,temp,i))
                        return temp->val;
                h=h->next;
                i++;
        }
        return -1;
#include<stdio.h>
#include<stdlib.h>
struct cll
{
        int val;
        struct cll *next;
};

struct cll* cllnode(int v)
{
        struct cll *h;
        h=(struct cll*)malloc(sizeof(struct cll));
        h->val=v;
        h->next=NULL;
        return h;
}

struct cll* clllist(int n)
{
        struct cll *h=NULL,*nn,*tail;
        int v;
        for(int i=0;i<n;i++)
        {
                printf("Enter the value:");
                scanf("%d",&v);
                nn=cllnode(v);
                if(h==NULL)
                        h=nn;
                else
                        tail->next=nn;
                tail=nn;
        }
        tail->next=h;
        return tail;
}

int listsize(struct cll *h)
{
        struct cll *t=h->next;
        int c=1;
        while(t!=h){
                c++;
                t=t->next;
        }
        return c;
}

struct cll* inserbeg(struct cll *h)
{
        struct cll *nn;
        int v;
        printf("\nEnter a value to insert at the beginning:");
        scanf("%d",&v);
        nn=cllnode(v);
        nn->next=h->next;
        h->next=nn;
        return h;
}

struct cll* inserend(struct cll *h)
{
        struct cll *nn;
        int v;
        printf("\nEnter a value to insert at the ending:");
        scanf("%d",&v);
        nn=cllnode(v);
        nn->next=h->next;
        h->next=nn;
        return nn;
}

struct cll* inserpos(struct cll *h)
{
        struct cll *nn,*t=h,*temp;
        int v,p,n;
        printf("\nEnter the position to insert a value:");
        scanf("%d",&p);
        n=listsize(h);
        if(p==1) return inserbeg(h);
        if(p>=n) return inserend(h);
        printf("\nEnter a value to insert at position %d:",p);
        scanf("%d",&v);
        nn=cllnode(v);
        for(int i=1;i<p;i++)
                h=h->next;
        nn->next=h->next;
        h->next=nn;
        return t;

}

struct cll* delbeg(struct cll *h)
{
        struct cll *temp;
        temp=h->next;
        h->next=temp->next;
        free(temp);
        return h;
}

struct cll* delend(struct cll *h)
{
        struct cll *temp,*t=h->next;
        while(t->next!=h)
                t=t->next;
        temp=t->next;
        t->next=temp->next;
        free(temp);
        return t;
}

struct cll* delpos(struct cll *h)
{
        struct cll *temp,*t=h;
        int p,n;
        printf("\nEnter the position to delete the value:");
        scanf("%d",&p);
        n=listsize(h);
        if(p==1)
                return delbeg(h);
        else if(p==n)
                return delend(h);
        else if(p>n || p<1)
        {
                printf("\n %d position does not exist in the list\n",p);
                return h;
        }
        else
        {
                for(int i=1;i<p;i++)
                        h=h->next;
                temp=h->next;
                h->next=temp->next;
                free(temp);
                return t;
        }
}

struct cll* delval(struct cll *h)
{
        struct cll *t=h->next,*temp;
        int e,n=listsize(h);
        printf("\nEnter element to delete:");
        scanf("%d",&e);
        if(h->val==e)
                return delend(h);
        else if(h->next->val==e)
                return delbeg(h);
        else if(e>n || (e<0 || e==0))
        {
                printf("Given value not found in the list\n");
                return h;
        }
        else
        {
                while(t->next!=h)
                {
                        if(t->next->val==e)
                        {
                                temp=t->next;
                                t->next=temp->next;
                                free(temp);
                                return h;
                        }
                        t=t->next;
                }
        }
}

int seaval(struct cll *h)
{
        struct cll *t=h->next;
        int e,n,c=2;
        printf("\nEnter the value to search:");
        scanf("%d",&e);
        n=listsize(h);
        if(h->val==e)
                return n;
        else if(h->next->val==e)
                return 1;
        else
        {
                while(t->next!=h)
                {
                        if(t->next->val==e)
                                return c;
                        c++;
                        t=t->next;
                }
        }
        printf("Given element not found in the list");
        return 0;
}

int seapos(struct cll *h)
{
        struct cll *t=h->next;
        int p,n;
        printf("\nEnter the position:");
        scanf("%d",&p);
        n=listsize(h);
        if(p>n&&p<1)
        {
                printf("Given position not found in the list");
                return 0;
        }
        else
        {
                if(p==1)
                        return t->val;
                else if(p==n)
                        return h->val;
                else
                {
                        for(int i=1;i<p-1;i++)
                                t=t->next;
                        return t->next->val;
                }
        }
}

int detect(struct cll *h,struct cll *t,int n)
{
        for(int i=0;i<n;i++)
        {
                if(h==t)
                        return 1;
                h=h->next;
        }
        return 0;
}

int cycle(struct cll *h)
{
        struct cll *temp=h;
        int i=0;
        while(h->next)
        {
                if(detect(h,temp,i))
                        return temp->val;
                h=h->next;
                i++;
        }
        return -1;
}

void display(struct cll *h)
{
            struct cll *t=h->next;
            while(h!=t)
            {
                    printf("%d->",t->val);
                    t=t->next;
            }
            printf("%d->",h->val);
}

void main()
{
            struct cll *h;
            int n,v;
            printf("\nEnter no of elements:");
            scanf("%d",&n);
            h=clllist(n);
            v=cycle(h);
            if(v==-1)
                    printf("Cycle not detected in the list");
            else
                    printf("Cycle detected at the node with the value %d",v);
            printf("\nThe given circular list is:\n");
            display(h);
            h=inserpos(h);
            display(h);
            h=delpos(h);
            display(h);
            h=delval(h);
            display(h);
            n=seaval(h);
            if(n!=0)
                    printf("\nThe given element is found at position %d in the list",n);
            n=seapos(h);
            if(n!=0)
                printf("\nThe element %d is found at the given position",n);
}
