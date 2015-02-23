#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	
	int d1,d2;
	cout<<"Enter the degree of first polynomial"<<endl;
	cin>>d1;
	d1=d1+1;
	
	int* a = new int[d1];

	cout<<"Enter the coefficients Polynomial 1:"<<endl;
	for(int i=0;i<d1;i++)
	{
		cout<<"Coefficient of degree "<<i<<": "<<endl;
		cin>>a[i];
	}
	cout<<"Enter the degree of Polynomial 2"<<endl;
	cin>>d2;
	d2=d2+1;
	int *b = new int[d2];
	cout<<"Enter the coefficients of Polynomial 2:"<<endl;
	for(int i=0;i<d2;i++)
	{
		cout<<"Coefficient of degree "<<i<<": "<<endl;
		cin>>b[i];
	}

	cout<<endl;
	cout<<"Polynomial 1"<<endl;
	for(int i=0;i<d1;i++)
	{
		if(a[i])
		{
			cout<<a[i]<<"*x("<<i<<")";
			if(i!=(d1-1))
				cout<<"+";
		}
	}
	cout<<endl;
	cout<<"Polynomial 2"<<endl;
	for(int i=0;i<d2;i++)
	{
		if(b[i])
		{
			cout<<b[i]<<"*x("<<i<<")";
			if(i!=(d2-1))
				cout<<"+";
		}
	}

	int d3;

	if(d1>d2) 
	   d3=d1;
	else 
		d3=d2;

	
	int c[d3];

	for(int i=0;i<d3;i++)
	{

	
		if(i<d1 && i<d2)
			c[i]=a[i]+b[i];
		else if(i>=d1)
			c[i]=b[i];
		else if(i>=d2)
			c[i]=a[i];
	
	}


	cout<<endl;
	cout<<"Sum"<<endl;
	for(int i=0;i<d3;i++)
	{
		if(c[i])
		{
			cout<<c[i]<<"*x("<<i<<")";
			if(i!=(d3-1))
				cout<<"+";
		}
	}

	int d4=d1+d2-1;

	int* d = new int[d4];

	for(int i=0;i<d4;i++)
		d[i]=0;

	for(int i=0;i<d1;i++)
	{
		for(int j=0;j<d2;j++)
		{
			d[i+j]+=a[i]*b[j];
		}
	}


	cout<<endl;
	cout<<"Product"<<endl;
	for(int i=0;i<d4;i++)
	{
		if(d[i])
		{
			cout<<d[i]<<"*x("<<i<<")";
			if(i!=(d4-1))
				cout<<"+";
		}
	}

	return 0;
}
