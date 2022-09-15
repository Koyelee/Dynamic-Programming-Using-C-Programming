#include <stdio.h>
# define MAX 20
int main()
{
	int n,i,j,a[3][MAX],costmat[MAX][MAX]={},kc,sum,k,c;
	printf("Enter the number of item: ");
	scanf("%d",&n);
	printf("Enter the item number and profit in ascending order of their weights: \n");
	// Inputs from the user in ascending order of their weights
	for(i=0;i<n;i++)
	{
		printf("Enter the item number: ");
		scanf("%d",&a[0][i]);
		printf("Enter the profit: ");
		scanf("%d",&a[1][i]);
		printf("Enter its weight: ");
		scanf("%d",&a[2][i]);
	}
	printf("Enter the knapsack capacity: ");
	scanf("%d",&kc);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=kc;j++)
		{
			sum=0;
			if(a[2][i-1]<=j)
			sum=a[1][i-1]+costmat[i-1][j-a[2][i-1]];
			if(sum>costmat[i-1][j])
			costmat[i][j]=sum;
			else
			costmat[i][j]=costmat[i-1][j];
		}
	}
	printf("\n\nItems\tProfit\tWeight\t");
	for(i=0;i<=kc;i++)
	printf("%d\t",i);
	printf("\n--------------------------------------------------------------------------------------------------------\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t%d\t%d\t",a[0][i-1],a[1][i-1],a[2][i-1]);
		for(j=0;j<=kc;j++)
		printf("%d\t",costmat[i][j]);
		printf("\n");
	}
	i=n;
	j=kc;
	c=costmat[i][j];
	printf("--------------------------------------------------------------------------------------------------------\nTHE CHOSEN ITEMS ARE:\n");
	while(costmat[i][j]!=0)
	{
		if(costmat[i-1][j]!=costmat[i][j])
		{
			printf("I%d\n",a[0][i-1]);
			c=c-a[1][i-1];
			i--;
			for(k=0;k<=kc;k++)
			{
				if(costmat[i][k]==c)
				{
					j=k;
					break;
				}
			}
		}
		else
		i--;
	}
}
