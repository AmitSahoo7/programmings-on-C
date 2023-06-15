// program to find the transpose of the triplet matrix
#include<stdio.h>
int a[100][3],b[100][3];
void main()
{
    int i,j,m,n=3;
    printf("Enter the rows \n");
    scanf("%d",&m);
    printf("Enter the elements of triplet matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
    int k=1;
    b[0][0]=a[0][1];
    b[0][1]=a[0][0];
    b[0][2]=a[0][2];
    for(i=0;i<m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==a[j][1])
            {
                b[k][0]=i;
                b[k][1]=a[j][0];
                b[k][2]=a[j][2];
                k++;
            }
        }
    }
    printf("The transppose of the triplet matrix is:\n");
    for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",&b[i][j]);
        }
        printf("\n");
    }
} 