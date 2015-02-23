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
        cout<<"displayPoop"<<endl;
        cout<<top->coef<<"x^"<<top->pow;

    }
}
poly* top=NULL,*start=NULL;
void insertPoly(int coef,int pow)
{
    poly* p=(poly*)malloc(sizeof(poly));
    p->coef=coef;
    p->pow=pow;
    p->nextPoly=NULL;
    if(top==NULL)
    {
        start=p;
        top=p;;
    }
    else
    {
        top->nextPoly=p;
        top=top->nextPoly;
    }

}
int main()
{
		freopen("input.txt","r",stdin);
		int p;
    	//freopen("output.out","w",stdout);
    	//string str;
        
        //cout<<"Enter the highest power of polynomial";
        cin>>p;

        for(int i=0;i<p;i++)
        {/*
            poly *p1;
            
            p1=(struct poly*)malloc(sizeof(struct poly));
            if(i==0)
            {
                start=p1;

                top=p1;
                top->nextPoly=NULL;

            }
            else
            {
                top->nextPoly=p1;
            }
           // cout<<"Enter the coeffecient of polynomial of"<<i<<"th power";
            cin>>p1->coef;
            p1->pow=i;poly *p1;
            
            p1=(struct poly*)malloc(sizeof(struct poly));
            if(i==0)
            {
                start=p1;

                top=p1;
                top->nextPoly=NULL;

            }
            else
            {
                top->nextPoly=p1;
            }
           // cout<<"Enter the coeffecient of polynomial of"<<i<<"th power";
            cin>>p1->coef;
            p1->pow=i;
            
            top=p1;
            p1->nextPoly=NULL;
            top->nextPoly=NULL;            
            */

            int c;
            cin>>c;
            insertPoly(c,i);

        }
        if(top->nextPoly==NULL)
        cout<<"poop"<<top->nextPoly<<endl;
        //displayPoly(start,p);

        //
    	return 0;
}