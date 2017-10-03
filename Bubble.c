#include<stdio.h>

void bubble_sort(int a[],int n)
{
    int x,i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                x=a[j];
                a[j]=a[j+1];
                a[j+1]=x;
            }
        }
    }
}

void main()
{
    int a[100],n,i;
    printf("\nEnter the number of elements :");
    scanf("%d",&n);
    printf("\nEnter the elements : \n");
    for(i=0;i<=n;i++)
        scanf("%d",&a[i]);
    bubble_sort(a,n);
    for(i=0;i<=n;i++)
        printf(" %d",a[i]);
}
