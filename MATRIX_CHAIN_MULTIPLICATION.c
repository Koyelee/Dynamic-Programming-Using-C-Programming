#include <stdio.h>
# define MAX 20
void print(int a[MAX][MAX], int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		printf("%d\t",a[i][j]);
		printf("\n");
	}
	printf("\n");
}
int main()
{
	int n,i,p[MAX],a[MAX][MAX]={},j,c=1,m,sum=0,ind,min,k;
	printf("ENTER THE NUMBER OF MATRICES: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("ENTER THE ROW AND COLUMN OF MATRIX %d RESPECTIVELY:\n",i);
		scanf("%d",&p[i-1]);
		scanf("%d",&p[i]);
	}
	m=n-1;
	while(m>=1)
	{
		c++;
		i=1;
		j=c;
		while(j<=n)
		{
			min=0;
			for(k=i;k<j;k++)
			{
				sum=a[i][k]+a[k+1][j]+p[i-1]*p[k]*p[j];
				if (min==0)
				{
					min=sum;
					ind=k;
				}
				else
				{
					if(min>sum)
					{
						min=sum;
						ind=k;
					}
				}
			}
			a[i][j]=min;
			printf("The value of 'k' for which we have the minimum value of a[%d][%d] is : %d\n",i,j,ind);
			i++;
			j++;
		}
		printf("THE CURRENT STATUS OF ARRAY IS:\n");
		print(a,n);
		m--;
	}
	printf("\nMINIMUM NUMBER OF MULTIPLICATION REQUIRED : %d",a[1][n]);
}
