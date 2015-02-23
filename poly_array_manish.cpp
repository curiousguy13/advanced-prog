#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	
	int n1,n2;
	cout<<"Enter the degree of first polynomial"<<endl;
	cin>>n1;
	n1=n1+1;
	
	//int* arr1 = (int*)malloc(sizeof(int)*n1);
	//int arr1[n1];
	
	int* a = new int[n1];

	cout<<"Enter the coefficients of first poly:"<<endl;
	for(int i=0;i<n1;i++)
	{
		cout<<"Enter the coefficient of degree "<<i<<": "<<endl;
		cin>>a[i];
	}
	cout<<"Enter the degree of second polynomial"<<endl;
	cin>>n2;
	n2=n2+1;
	int *b = new int[n2];
	cout<<"Enter the coefficients of second poly:"<<endl;
	for(int i=0;i<n2;i++)
	{
		cout<<"Enter the coefficient of degree "<<i<<": "<<endl;
		cin>>b[i];
	}

	cout<<endl;
	for(int i=0;i<n1;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n2;i++)
	{
		cout<<b[i]<<" ";
	}

	int n3;

	n3 = (n1>n2) ? n1 : n2;

	
	int c[n3];

	for(int i=0;i<n3;i++)
	{

	
		if(i<n1 && i<n2)
			c[i]=a[i]+b[i];
		else if(i>=n1)
			c[i]=b[i];
		else if(i>=n2)
			c[i]=a[i];
	
	}


	cout<<endl;
	for(int i=0;i<n3;i++)
	{
		cout<<[i]<<" ";
	}

	int n4=n1+n2-1;

	int* d = new int[n4];

	for(int i=0;i<n4;i++)
		d[i]=0;

	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			d[i+j]+=a[i]*bj];
		}
	}


	cout<<endl;
	for(int i=0;i<n4;i++)
	{
		cout<<d[i]<<" ";
	}

	return 0;
}
