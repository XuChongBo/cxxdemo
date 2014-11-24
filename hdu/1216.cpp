#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

using namespace std;
#define N 40000
int a[N];  //160KB    2 -- remain   1--exsit  0--exclusive

void setup()
{
    for(int i=2;i<N;i++)
    {
        a[i]=1;
    }
}

//1<= n <=3000
int luckyNumber(int n)
{
    for(int i=2;i<N;i++)
    {
        if(a[i]==1)
        {
            a[i]=2;
            int acc=0;
            for(int j=i+1;j<N;j++)
            {
                if(a[j]!=0)
                {
                    acc++;
                    if(acc%i==0)
                    {
                        a[j]=0;     //
                    }
                }
            }
        }
        if(a[i]==2 && (--n)==0 )
        {
            return i;
        }
    }
}

int main()
{
    int n;
    setup();
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        cout<<luckyNumber(n)<<endl;
    }
}
