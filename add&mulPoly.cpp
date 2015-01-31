#include <stdio.h>
#include <list>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

#define size 50
void qst(int *A,int low,int high);
int partition(int *A,int low,int high);
void display(int *x,int n);
void merge_sort(int *A,int low,int high);
void merge(int arr[],int min,int max,int mid);


struct poly{
    int coef;
    int pow;
    struct poly *nextPoly;

};

void displayPoly(poly* top,int p)
{
    while(top->nextPoly!=NULL)
    {
        cout<<top->coef<<"x^"<<top->pow;

    }
}
int main()
{
		//freopen("input.txt","r",stdin);
		int p;
    	//freopen("output.out","w",stdout);
    	//string str;
        poly* top=NULL;
        cout<<"Enter the highest power of polynomial";
        cin>>p;
        for(int i=0;i<p;i++)
        {
            poly *p1;
            
            p1=(struct poly*)malloc(sizeof(struct poly));
            if(i==0)
            {
                top=p1;
            }
            cout<<"Enter the coeffecient of polynomial of"<<i<<"th power";
            cin>>p1->coef;
            p1->pow=i;
            top->nextPoly=p1;
            top=p1;
            p1->nextPoly=NULL;

        }

        //
    	return 0;
}