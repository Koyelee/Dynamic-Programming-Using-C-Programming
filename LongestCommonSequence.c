/*	-1=left
	-2=Diagonal
	-3=Right
*/
#include <stdio.h>
#include <string.h>
# define MAX 50
struct matrix
{
	int data;
	int direction;
};
struct matrix arr[MAX][MAX];

int dir(int a,int b)
{
	return (b>a)?-3:-1;
}

int max(int a, int b)
{
	return (b>a)?b:a;
}

int main()
{
	char x[MAX],y[MAX],ans[MAX];
	int i,j,l1,l2,k;
	printf("Enter the First string in lowercase characters: ");
	scanf("%s",&x);
	printf("Enter the Second string in lowercase characters: ");
	scanf("%s",&y);
	l1=strlen(x);
	l2=strlen(y);
	for(i=0;i<=l1;i++)
	{
		arr[0][i].data=0;
		arr[0][i].direction=0;
	}
	for(i=0;i<=l2;i++)
	{
		arr[i][0].data=0;
		arr[i][0].direction=0;
	}
	for(i=1;i<=l1;i++)
	{
		for(j=1;j<=l2;j++)
		{
			if(x[i-1]==y[j-1])
			{
				arr[i][j].data=arr[i-1][j-1].data+1;
				arr[i][j].direction=-2;
			}
			else
			{
				arr[i][j].data=max(arr[i][j-1].data,arr[i-1][j].data);
				arr[i][j].direction=dir(arr[i][j-1].data,arr[i-1][j].data);
			}
		}
	}
	printf("\n\nThe matrix is: \n\n-1->Indicates that the arrow is on the LEFT HAND SIDE.\n-2->Indicates that the arrow is on the DIAGONAL.\n-3->Indicates that the arrow is on the RIGHT HAND SIDE.\n\n");
	for(i=0;i<=l1;i++)
	{
		for(j=0;j<=l2;j++)
		printf("%d %d\t",arr[i][j].data,arr[i][j].direction);
		printf("\n");
	}
	i=l1;
	j=l2;
	printf("\nThe Length Of The Longest Common Subsequence is= %d\n",arr[i][j].data);
	k=arr[i][j].data-1;
	while(arr[i][j].data!=0)
	{
		if(arr[i][j].direction==-2)
		{
			i--;
			j--;
			ans[k]=x[i];
			k--;
		}
		else if(arr[i][j].direction==-1)
		j--;
		else
		i--;
	}
	printf("THE LONGEST COMMON SUBSEQUENCE IS: ");
	for(i=0;i<strlen(ans);i++)
	printf("%c",ans[i]);
}
