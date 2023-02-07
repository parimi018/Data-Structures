#include<stdio.h>
#include<stdio.h>
void main()
{
        int n;
        printf("\nEnter n:");
        scanf("%d",&n);
        int a[n+1];
        printf("\nEnter elements into the array:");
        for(int i=0;i<=n;i++)
        {
                scanf("%d",&a[i]);
        }
        int s=a[0];
        int k,dupli;
        while(1)
        {
                if (a[s]<0)
                {
                        dupli=s;
                        break;
                }
                a[s]=-1*a[s];
                s=-1*a[s];
        }

        printf("\nThe duplicate is:%d\n",dupli);
}
