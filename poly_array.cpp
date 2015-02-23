//Kunal Arora
//737/IT/12
//sum and product of two polynomials
#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	int n1,n2;
	cout<<"Enter the degree of first polynomial"<<endl;
	cin>>n1;
	n1=n1+1;
	
	//int* arr1 = (int*)malloc(sizeof(int)*n1);
	//int arr1[n1];
	
	int* arr1 = new int[n1];

	cout<<"Enter the coefficients of first poly:"<<endl;
	for(int i=0;i<n1;i++)
	{
		cout<<"Enter the coefficient of degree "<<i<<": "<<endl;
		cin>>arr1[i];
	}
	cout<<"Enter the degree of second polynomial"<<endl;
	cin>>n2;
	n2=n2+1;
	int *arr2 = new int[n2];
	cout<<"Enter the coefficients of second poly:"<<endl;
	for(int i=0;i<n2;i++)
	{
		cout<<"Enter the coefficient of degree "<<i<<": "<<endl;
		cin>>arr2[i];
	}

	cout<<"First polynomials is:";
	cout<<endl;
	for(int i=0;i<n1;i++)
	{
		if(arr1[i]!=0)
		{
			cout<<arr1[i]<<"*x^"<<i;
			if(i!=(n1-1))
				cout<<"+";
		}
	}
	cout<<endl;
	cout<<"Second polynomials is:";
	cout<<endl;
	for(int i=0;i<n2;i++)
	{
		if(arr2[i]!=0)
		{
			cout<<arr2[i]<<"*x^"<<i;
			if(i!=(n2-1))
				cout<<"+";
		}
	}

	int n3;

	n3 = (n1>n2) ? n1 : n2;

	//int *arr3 = new int(n3);
	int arr3[n3];
	//cout<<n3<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"Sum of the polynomials is:";
	for(int i=0;i<n3;i++)
	{

	//	cout<<arr1[i]<<" "<<arr2[i]<<" "<<arr3[i]<<endl;
		if(i<n1 && i<n2)
			arr3[i]=arr1[i]+arr2[i];
		else if(i>=n1)
			arr3[i]=arr2[i];
		else if(i>=n2)
			arr3[i]=arr1[i];
	}

	//display the sum
	cout<<endl;
	for(int i=0;i<n3;i++)
	{
		if(arr3[i]!=0)
		{
			cout<<arr3[i]<<"*x^"<<i;
			if(i!=(n3-1))
				cout<<"+";
		}
	}

	int n4=(n1-1)+(n2-1)+1;

	int* arr4 = new int[n4];

	for(int i=0;i<n4;i++)
		arr4[i]=0;
	cout<<endl;
	cout<<endl;
	cout<<"Product of the polynomials is:";
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			arr4[i+j]+=arr1[i]*arr2[j];
		}
	}

	cout<<endl;
	for(int i=0;i<n4;i++)
	{
		if(arr4[i]!=0)
		{
			cout<<arr4[i]<<"*x^"<<i;
			if(i!=(n4-1))
				cout<<"+";
		}
	}
	cout<<endl;
	return 0;
}
