//rsa//
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

int egcd(int a,int b)
{
    int x=0,y=1,u=1,v=0;
    int gcd,q,r,m,n;
    while(a!=0)
    {
        q=b/a;
        r=b%a;
        m=x-u*q;
        n=y-v*q;
        b=a;
        a=r;
        x=u;
        y=v;
        u=m;
        v=n;
        gcd=b;
    }
    return x;
}
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.out","w",stdout);
    long long i,j,k;
    long long p,q,phi_n,e,d,n;
    string msg;
    cout<<"Enter the first prime number"<<endl;
    cin>>p;
    cout<<"Enter the second prime number"<<endl;
    cin>>q;
    n=p*q;
    phi_n=(p-1)*(q-1);
    cout<<"n="<<n<<endl;
   // cout<<"The possible choices for e are:"<<endl;
    vi coprimes;
    j=0;
    bool coprime;
    for(i=2;i<phi_n;i++)
    {
        coprime=true;
        for(int p=2;p<i;p++)
        {
            if(i%p==0 && phi_n%p==0)
            {
                coprime=false;
                break;
            }
        }
        if(coprime)
        {
            coprimes.push_back(i);
            j++;
        }
    }

    //cout<<endl;

    cout<<"Let e="<<coprimes[j/2]<<endl;
    e=17;
    d=egcd(17,phi_n);
    if(d<0)
    {
        d=phi_n+d;
    }
    cout<<"Public key=("<<n<<","<<e<<")"<<endl;
    cout<<"Private key=("<<n<<","<<d<<")"<<endl;
    cout<<"Enter message to be encrypted:";
    cin>>msg;
    int size=msg.size();
    vll encode;
    for(i=0;i<size;i++)
    {
        int x=msg[i]-96;
        cout<<x<<endl;
        int temp=1;
        for(j=0;j<=e;j++)
        {
            cout<<"temp="<<temp<<endl;
            temp=temp*x;
            temp=temp%n;
        }
        x=temp;
       // cout<<"x"<<x<<endl;
        encode.push_back(temp);
    }
   // encode.push_back(-1);
    cout<<"the encoded message is:";
   // size++;
    for_each(i,0,size)
    {
        cout<<encode[i]<<" ";
    }
    cout<<endl;
    int decrypt[300];
    for_each(i,0,size)
    {
        int x=encode[i];
     //   cout<<x<<endl;
        int temp=1;
        for(j=0;j<d;j++)
        {
   //         cout<<"temp="<<temp<<endl;
            temp=temp*x;
            temp=temp%n;
        }
        x=temp;
        cout<<x<<endl;
        decrypt[i]=x+96;
    }
    for_each(i,0,size)
    {
        cout<<decrypt[i]<<endl;
    }
    return 0;

}