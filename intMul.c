//integer multiplication using divide and conquer
#include<stdio.h>
#include<string.h>
#include<math.h>
int digits(int a)
{
	int count=0;
	while(a!=0)
	{
		a=a/10;
		count++;
	}
	return count;
}

int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}
int leftDigits(int a)
{
	int x=pow(10,digits(a)/2);
	return a/x;
}

int rightDigits(int a)
{
	int x=pow(10,digits(a)/2);
	return a%x;
}
int multiply(int a,int b)
{
	int n=max(digits(a),digits(b));
	if(n==1)
	{
		return a*b;
	}
	int aL=leftDigits(a);
	int aR=rightDigits(a);
	int bL=leftDigits(b);
	int bR=rightDigits(b);
	int x1=multiply(aL,bL);
	//printf("x1=%d:::%d:::%d\n",x1,a,b);
	int x2=multiply(aR,bR);
	//printf("x2=%d::%d::%d\n",x2,aL,aR);
	int x3=multiply(aL+aR,bL+bR);
	//printf("x3=%d::%d\n",x3,x3-x1-x2);
	return x1*pow(10,n)+(x3-x1-x2)*pow(10,n/2)+x2;
}
int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	printf("First Number:");
	scanf("%d",&a);
	printf("\n");
	printf("Second Number:");
	scanf("%d",&b);
	printf("\n");
	c=multiply(a,b);
	printf("Product of these numbers:%d\n",c);

	return 0;
}