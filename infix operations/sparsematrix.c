#include<stdio.h>
int main()
{
    int i,j,n,m;
    printf(" enter the number of rows and columns respectively:");
    scanf("%d %d",&m,&n);
    int arr[m][n];
    printf("enter the elements of the matrix: \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
        printf("\n");
    }
  /*  printf("The matrix is:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }*/
    int k=1;
    int b[100][100];
    b[0][0]=m;
    b[0][1]=n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=arr[i][j];
                k++;
            }
        }
        b[0][2]=k-1;
    }
    printf("The triplet form is:\n");
     for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}