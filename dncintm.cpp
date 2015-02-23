#include <iostream>
#include <stdio.h>

int nod(int s)
{
	s=log(s,2);
	s=int(s+0.5);
	s=pow(2,s);
	return s;
}

int** toarr(int num,int*size)
{
	int arr[16];
	int i=0;
	while(num)
	{
		arr[i]=num%10;
		num/=num/10;
		i++;
	}
	for(int j=0;j<size;j++)
		arr[j]=0;
	return arr;
}

int** multiply(int num1[],int num2[],int size)
{
	int arr[32]={0};
	return arr;
} 

using namespace std;
int main()
{
	int anum1[16]={0},anum2[16]={0},anum[32]={0};
	int num1,num2;
	cin>>num1;
	cin>>num2;
	
	int s1,s2;
	s1=nod(s1);
	anum1=toarr(num1,&s1);
	s2=nod(s2);
	anum2=toarr(num2,&s2);
	int s = s1>s2?s1:s2;
	cout<<s<<endl;
	anum=multiply(anum1,anum2,s);










	return 0;
}
