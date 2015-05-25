//fast fourier transform
/*
8
1.0 1.0 1.0 1.0 0.0 0.0 0.0 0.0
*/
#include <bits/stdc++.h>
#define MAX 1000
#define MOD 1000000007
#define INF 99999
#define for_each(i,x,n) for(i=x;i<n;++i)
#define for_each_dec(i,x,n) for(i=n-1;i>=x;--i)
typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<LL> vll;
typedef vector<vll> vvll;


//fucntion to display a vector
template <typename T>
void displayVector(T v)
{
    for(typename T::iterator i=v.begin();i!=v.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}

//fucntion to display a vector
template <typename T>
void displayVector(T v,int size)
{
    for(typename T::iterator i=v.begin();i!=v.begin()+size;i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}

//function to display a matrix
template <typename T>
void displayMatrix(T mat)
{
    for(typename T::iterator i=mat.begin();i!=mat.end();i++)
    {
            displayVector(*i);       
    }
    cout<<endl; 
}

//function to display a matrix
template <typename T>
void displayMatrix(T mat,int size)
{
    for(typename T::iterator i=mat.begin();i!=mat.begin()+size;i++)
    {
            displayVector(*i,size);       
    }
    cout<<endl; 
}


//fucntion to input a vector
template <typename T>
void inputVector(T &v)
{
    for(typename T::iterator i=v.begin();i!=v.end();i++)
    {
        cin>>*i;
    }
}

//function to input a matrix
template <typename T>
void inputMatrix(T &mat)
{
    for(typename T::iterator i=mat.begin();i!=mat.end();i++)
    {
            inputVector(*i);
    }
}

const double PI=3.141592;

class comp
{
    public:
        double real;
        double img;
    friend comp operator+(comp a,comp b);
    friend comp operator-(comp a,comp b);
};

comp operator+(comp a,comp b)
{
    comp t;
    t.real=a.real+b.real;
    t.img=a.img+b.img;
    return t;
}

comp operator-(comp a,comp b)
{
    comp t;
    t.real=a.real-b.real;
    t.img=a.img-b.img;
    return t;
}

typedef vector<comp> Carray;
void fft(Carray &data)
{
    int size=data.size();
    if(size<=1)   
    {
        return;
    }

    //divide
    Carray even(size/2);
    Carray odd(size/2);

    for(int i=0,j=0;i<size;i+=2,j++)
    {
        even[j]=data[i];
    }

    for(int i=1,j=0;i<size;i+=2,j++)
    {
        odd[j]=data[i];
    }

    //conquer
    fft(even);
    fft(odd);

    //combine
    for(int k=0;k<size/2;k++)
    {
        double cs=cos(2*PI*k/(double)size);
        double sn=sin(2*PI*k/(double)size);
        comp t;
        t.real= cs*odd[k].real + sn*odd[k].img;
        t.img=cs*odd[k].img - sn*odd[k].real;
        data[k]=even[k]+t;
        data[k+size/2]=even[k]-t;
    }

}

void ifft(Carray &data)
{
    int i;
    int size=data.size();
    for_each(i,0,size)
    {
        data[i].img=-data[i].img;
    }
    fft(data);
    for_each(i,0,size)
    {
        data[i].img=-data[i].img;
    }
    for_each(i,0,size)
    {
        data[i].real/=size;
        data[i].img/=size;
    }

}
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.out","w",stdout);
    int i,n,j,k;
    cout<<"Enter the size of the input array:";
    cin>>n;
    Carray data(n);    
    cout<<endl;
    cout<<"Enter the input array:"<<endl;
    for_each(i,0,n)
    {
        cin>>data[i].real;
    }
    fft(data);
    cout<<"fft of the entered array is:"<<endl;
    for_each(j,0,n)
    {
        if(data[i].img>=0)
            cout<<data[j].real<<" + "<<data[j].img<<"i"<<endl;
        else
            cout<<data[j].real<<" - "<<data[j].img<<"i"<<endl;
    }   

    ifft(data);
    cout<<"inverse fft:"<<endl;
    for_each(j,0,n)
    {
         if(data[i].img>=0)
            cout<<data[j].real<<" + "<<data[j].img<<"i"<<endl;
        else
            cout<<data[j].real<<" - "<<data[j].img<<"i"<<endl;
    }
 
}