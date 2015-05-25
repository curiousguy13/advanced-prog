//matrix multiplication using divide and conquer
#include<stdio.h>
#include<string.h>
#include<math.h>
#define SIZE 100

void addMat(int A[][SIZE],int B[][SIZE],int C[][SIZE],int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			C[i][j]=A[i][j]+B[i][j];
		}
	}
}
void multiply(int A[][SIZE],int B[][SIZE],int C[][SIZE],int size)
{
	int a[SIZE][SIZE];
	for(int i=0;i<size/2;i++)
	{
		for(int j=0;j<size/2;j++)
		{
			a[i][j]=A[i][j];
		}
	}
	int b[SIZE][SIZE];
	for(int i=size/2;i<size;i++)
	{
		for(int j=0;j<size/2;j++)
		{
			b[i][j]=A[i][j];
		}
	}
    int c[SIZE][SIZE];
	for(int i=0;i<size/2;i++)
	{
		for(int j=size/2;j<size;j++)
		{
			c[i][j]=A[i][j];
		}
	}
	int d[SIZE][SIZE];
	for(int i=size/2;i<size;i++)
	{
		for(int j=size/2;j<size;j++)
		{
			d[i][j]=A[i][j];
		}
	}

	int e[SIZE][SIZE];
	for(int i=0;i<size/2;i++)
	{
		for(int j=0;j<size/2;j++)
		{
			e[i][j]=B[i][j];
		}
	}
	int f[SIZE][SIZE];
	for(int i=size/2;i<size;i++)
	{
		for(int j=0;j<size/2;j++)
		{
			f[i][j]=B[i][j];
		}
	}
    int g[SIZE][SIZE];
	for(int i=0;i<size/2;i++)
	{
		for(int j=size/2;j<size;j++)
		{
			g[i][j]=B[i][j];
		}
	}
	int h[SIZE][SIZE];
	for(int i=size/2;i<size;i++)
	{
		for(int j=size/2;j<size;j++)
		{
			h[i][j]=B[i][j];
		}
	}

	//p=ae+bg
	//q=af+bh
	//r=ce+dg
	//s=cf+dh

	/*
	C=[p,q]
	  [r,s]
	 */

     int temp1[SIZE][SIZE],temp2[SIZE][SIZE];;

	 int p[SIZE][SIZE];
	 multiply(a,e,temp1,size/2)
	 multiply(a,e,temp2,size/2)
	 addMat(temp1,temp2,p,size/2);


	 int q[SIZE][SIZE];
	 multiply(a,f,temp1,size/2)
	 multiply(b,h,temp2,size/2)
	 addMat(temp1,temp2,q,size/2);


	 int r[SIZE][SIZE];
	 multiply(c,e,temp1,size/2)
	 multiply(d,g,temp2,size/2)
	 addMat(temp1,temp2,r,size/2);


	 int s[SIZE][SIZE];
	 multiply(c,f,temp1,size/2)
	 multiply(d,h,temp2,size/2)
	 addMat(temp1,temp2,s,size/2);


	
	for(int i=0;i<size/2;i++)
	{
		for(int j=0;j<size/2;j++)
		{
			C[i][j]=p[i][j];
		}
	}
	
	for(int i=size/2;i<size;i++)
	{
		for(int j=0;j<size/2;j++)
		{
			C[i][j]=q[i][j];
		}
	}
    
	for(int i=0;i<size/2;i++)
	{
		for(int j=size/2;j<size;j++)
		{
			C[i][j]=r[i][j];
		}
	}
	
	for(int i=size/2;i<size;i++)
	{
		for(int j=size/2;j<size;j++)
		{
			C[i][j]=s[i][j];
		}
	}

}
int main()
{
	freopen("input.txt","r",stdin);
	int mat1[SIZE][SIZE],mat2[SIZE][SIZE];
	printf("Enter the dimension of the square matrices:");
	scanf("%d",&n);
	printf("\n");
	printf("Enter the first matrix:");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat1[i][j]
		}
	}
	printf("\n");

	printf("Enter the second matrix:");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat2[i][j]
		}
	}
	printf("\n");
	printf("Product of these matrices:%d\n",c);
	multiply(mat1,mat2,mat3,n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<mat3[i][j]
		}
	}
	printf("\n");
	return 0;
}