#include <stdio.h>
#define MAX 20
void print(int a[MAX][MAX], int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d\t\t",a[i][j]);
		printf("\n");
	}
}
int main()
{
	int n,a[MAX][MAX],i,j,k;
	printf("ENTER THE NUMBER OF VERTICES: ");
	scanf("%d",&n);
	printf("ENTER THE PATH MATRIX:\n");
	for(i=0;i<n;i++)
	{
		printf("ENTER THE EDGES FOR VERTEX %d:\n",i+1);
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	printf("\n\n-----------------------------------------------------------------------------------------\n");
	printf("COST MATRIX 0 =\n");
	print(a,n);
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i!=k || j!=k || i!=j)
				{
					if(a[i][k] && a[k][j] || a[i][j] == 1)
					a[i][j]=1;
				}
			}
		}
		printf("PATH MATRIX %d =\n",k+1);
		print(a,n);
		printf("\n\n-----------------------------------------------------------------------------------------\n");
	}
	printf("\nFINAL PATH MATRIX : \n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d\t",a[i][j]);
		printf("\n");
	}
}
