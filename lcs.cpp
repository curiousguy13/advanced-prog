//Kunal Arora
//737/IT/12
//longest common subsequence using dp
#include <iostream>
#include <stdio.h>
#include <vector>
#define up 0
#define left 1
#define diag 2
#define upleft 3
using namespace std;
/*
typedef struct node
{
	int val;
	int dir;
};
*/
int mat[100][100]={0};
int mat2[100][100]={0};
void lcs(string str1,string str2)
{
	int s1=str1.length();
	int s2=str2.length();

	for(int i=1;i<=s1;i++)
	{
		for(int j=1;j<=s2;j++)
		{
			//cout<<str1[i-1]<<" "<<str2[j-1];
			
			if(str1[i-1]==str2[j-1])
			{
				mat[i][j]=mat[i-1][j-1]+1;
				mat2[i][j]=diag;
			}
			else
			{
				mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
				if(mat[i][j]==mat[i-1][j])
				{
					mat2[i][j]=up;
				}
				if(mat[i][j]==mat[i][j-1])
				{
					mat2[i][j]=left;
				}
				if(mat[i][j]==mat[i-1][j] && mat[i][j]==mat[i][j-1])
				{
					mat2[i][j]=upleft;
				}
			}
		}
	}
	vector<char> arr;
	int i=s1,j=s2;
	for(i=s1,j=s2;;)
	{
		if((i==0)||(j)==0)
			break;
		//cout<<mat2[i][j];
		if(mat2[i][j]==up)
		{
			i--;
		}
		if(mat2[i][j]==left)
		{
			j--;
		}
		if(mat2[i][j]==diag)
		{
			arr.push_back(str1[i-1]);
			i--;
			j--;
		}
		if(mat2[i][j]==upleft)
		{
			i--;
		}
	}
	cout<<"Length of the LCS is:";
	cout<<mat[str1.length()][str2.length()]<<endl;
	cout<<"LCS of the entered strings is:";
	for(int i=mat[s1][s2]-1;i>=0;i--)
	{
		cout<<arr[i];
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	string str1,str2;
	cout<<"Enter string1:";
	cin>>str1;
	cout<<endl;
	cout<<"Enter string2:";
	cin>>str2;
	cout<<endl;
	//cout<<str1.length();
	
	lcs(str1,str2);

	cout<<endl;
	/*
	for(int i=0;i<=str1.length();i++)
	{
		for(int j=0;j<=str2.length();j++)
		{
			cout<<mat2[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	
	return 0;

}
