#include<stdio.h>
void main()
{
        int n;
        printf("\nEnter n:");
        scanf("%d",&n);
        int a[n];
        printf("\nEnter elements into the array:");
#include<stdio.h>
void main()
{
        int n;
        printf("\nEnter n:");
        scanf("%d",&n);
        int a[n];
        printf("\nEnter elements into the array:");
        for(int i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
        int c=0,max=0;
        for(int i=0;i<n;i++)
        {
                if (a[i]==1)
                {
                        c++;
                }
                else
                {

                        if(max<c)
                                max=c;
                        c=0;
                }

        }
        if(max<c)
                max=c;
        printf("\nMaximum no of consecutive ones are:%d\n",max);
}
