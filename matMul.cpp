//matrix multiplication using divide and conquer
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define SIZE 100

using namespace std;
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

void dispMat(int A[][SIZE],int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}

void multiply(int A[][SIZE],int B[][SIZE],int C[][SIZE],int size)
{
	if(size==1)
	{
		C[0][0]=A[0][0]*B[0][0];
		return;
	}
	int a[SIZE][SIZE];
	for(int i=0;i<size/2;i++)
	{
		for(int j=0;j<size/2;j++)
		{
			a[i][j]=A[i][j];
		}
	}
	int b[SIZE][SIZE];
	for(int i=0,k=0;i<size/2;i++,k++)
	{
		for(int j=size/2,l=0;j<size;j++,l++)
		{
			b[k][l]=A[i][j];
		}
	}
    int c[SIZE][SIZE];
	for(int i=size/2,k=0;i<size;i++,k++)
	{
		for(int j=0,l=0;j<size/2;j++,l++)
		{
			c[k][l]=A[i][j];
		}
	}
	int d[SIZE][SIZE];
	for(int i=size/2,k=0;i<size;i++,k++)
	{
		for(int j=size/2,l=0;j<size;j++,l++)
		{
			d[k][l]=A[i][j];
		}
	}
	/*
	printf("a=\n");
	dispMat(a,size/2);
	printf("b=\n");
	dispMat(b,size/2);
	printf("c=\n");
	dispMat(c,size/2);
	printf("d=\n");
	dispMat(d,size/2);
	*/
	int e[SIZE][SIZE];
	for(int i=0;i<size/2;i++)
	{
		for(int j=0;j<size/2;j++)
		{
			e[i][j]=B[i][j];
		}
	}
	int f[SIZE][SIZE];
	for(int i=0,k=0;i<size/2;i++,k++)
	{
		for(int j=size/2,l=0;j<size;j++,l++)
		{
			f[k][l]=B[i][j];
		}
	}
    int g[SIZE][SIZE];
	for(int i=size/2,k=0;i<size;i++,k++)
	{
		for(int j=0,l=0;j<size/2;j++,l++)
		{
			g[k][l]=B[i][j];
		}
	}
	int h[SIZE][SIZE];
	for(int i=size/2,k=0;i<size;i++,k++)
	{
		for(int j=size/2,l=0;j<size;j++,l++)
		{
			h[k][l]=B[i][j];
		}
	}
	/*
	printf("e=\n");
	dispMat(e,size/2);
	printf("f=\n");
	dispMat(f,size/2);
	printf("g=\n");
	dispMat(g,size/2);
	printf("h=\n");
	dispMat(h,size/2);
	*/
	//p=ae+bg
	//q=af+bh
	//r=ce+dg
	//s=cf+dh

	/*
	C=[p,q]
	  [r,s]
	 */
//	 printf("poop::size/2=%d\n",size/2);
     int temp1[SIZE][SIZE],temp2[SIZE][SIZE];;

	 int p[SIZE][SIZE];
	 multiply(a,e,temp1,size/2);
//	 printf("temp1=\n");
//	 dispMat(temp1,size/2);
	 multiply(b,g,temp2,size/2);
//	 printf("temp2=\n");
//	 dispMat(temp2,size/2);
	 addMat(temp1,temp2,p,size/2);
//	 printf("poop2\n");
//	 dispMat(p,size/2);
//	 printf("poop3\n");
	 int q[SIZE][SIZE];
	 multiply(a,f,temp1,size/2);
	 multiply(b,h,temp2,size/2);
	 addMat(temp1,temp2,q,size/2);


	 int r[SIZE][SIZE];
	 multiply(c,e,temp1,size/2);
	 multiply(d,g,temp2,size/2);
	 addMat(temp1,temp2,r,size/2);


	 int s[SIZE][SIZE];
	 multiply(c,f,temp1,size/2);
	 multiply(d,h,temp2,size/2);
	 addMat(temp1,temp2,s,size/2);


	/*
	dispMat(p,size/2);
	dispMat(q,size/2);
	dispMat(r,size/2);
	dispMat(s,size/2);
	*/
	for(int i=0;i<size/2;i++)
	{
		for(int j=0;j<size/2;j++)
		{
			C[i][j]=p[i][j];
		}
	}
	
	for(int i=0,k=0;i<size/2;i++,k++)
	{
		for(int j=size/2,l=0;j<size;j++,l++)
		{
			C[i][j]=q[k][l];
		}
	}
    
	for(int i=size/2,k=0;i<size;i++,k++)
	{
		for(int j=0,l=0;j<size/2;j++,l++)
		{
			C[i][j]=r[k][l];
		}
	}
	
	for(int i=size/2,k=0;i<size;i++,k++)
	{
		for(int j=size/2,l=0;j<size;j++,l++)
		{
			C[i][j]=s[k][l];
		}
	}

}
int main()
{
	//freopen("input.txt","r",stdin);
	int mat1[SIZE][SIZE]={0} , mat2[SIZE][SIZE]={0},mat3[SIZE][SIZE]={0};
	printf("Enter the dimension of the square matrices:");
	int n;
	scanf("%d",&n);
	
	
	printf("\n");
	printf("Enter the first matrix:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat1[i][j];
		}
	}
	printf("\n");

	printf("Enter the second matrix:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat2[i][j];
		}
	}


	printf("\n");
	printf("Product of these matrices:\n");
	//if n is odd make it to nearest even dimension and fill with zeroes
	if(n%2==0)
	{
		multiply(mat1,mat2,mat3,n);
	}
	else
	{
		multiply(mat1,mat2,mat3,n+1);	
	}
	printf("multiplication done\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<mat3[i][j]<<" ";
		}
		cout<<endl;
	}
	printf("\n");
	return 0;
}