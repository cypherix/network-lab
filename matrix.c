/*
	Author : Arjun Muraleedharan
	Date : 9/1/18
	Program : Matrix addition and multiplication
*/
#include<stdio.h>
#include<sys/types.h>
pid_t pid1,pid2;
void main()
{
	int mat1[10][10],n,m,mat2[10][10],p,q,i,j,k,sum[10][10],prod[10][10];
	printf("\nID : %d\n",getpid());
	printf("Enter row of 1st matrix:");
	scanf("%d",&n);
	printf("Enter column of 1st matrix:");
	scanf("%d",&m);
	printf("Enter first matrix:");
	for(i=0;i<n;i++)				//Getting matrix 1
		for(j=0;j<n;j++)
			scanf("%d",&mat1[i][j]);

	printf("Enter row of 2nd matrix:");
	scanf("%d",&p);
	printf("Enter column of 2nd matrix:");
	scanf("%d",&q);
	printf("Enter second matrix:");
	for(i=0;i<p;i++)				//Getting matrix 2
		for(j=0;j<q;j++)
			scanf("%d",&mat2[i][j]);

	printf("\n\n");

	pid1=fork();					//Creating a child process
	
	if(pid1==0)					//Inside child process
	{
		if(n==p && m==q)
		{
			for(i=0;i<n;i++)		//Adding the two matrices
				for(j=0;j<n;j++)
					sum[i][j]=mat1[i][j]+mat2[i][j];
			printf("Inside child process 1 and parent id:%d\n",getppid());
			printf("Sum\n");
			for(i=0;i<n;i++)		//Printing SUM
			{
				for(j=0;j<n;j++)
					printf("%d ",sum[i][j]);	
				printf("\n");
			}
		}
		else
			printf("Cannot be added");
	}	


	else if (pid1>0)				//Inside parent process
	{
		pid2=fork();				//creating 2nd child process
		
		if(pid2==0)
		{
			if(m==p)
			{
				for(i=0;i<n;i++)	//Multiplication of matrices
				{
					for(j=0;j<m;j++)
					{
						prod[i][j]=0;
						for(k=0;k<p;k++)
						{
							prod[i][j]=prod[i][j]+mat1[i][k]*mat2[k][j];
						}
					}
				}	
				printf("Inside child process 2 and parent id:%d\n",getppid());
				printf("Product \n");
				for(i=0;i<n;i++)	//Printing Product
				{
					for(j=0;j<q;j++)
						printf("%d ",prod[i][j]);
					printf("\n");
				}
			}

			else
				printf("Cannot be multiplicated");
		}
		
		else if(pid2==-1)			//Error Condition
			printf("2nd child Error");
	}

	else
		printf("Error\n");

	printf("\n\n");

}
