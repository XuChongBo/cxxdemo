#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef long long int int64;
//n>0
int64 getCount(int n)
{
    if(n>0 && n<=3)
    {
        return n;
    }
    return getCount(n-2)*2+getCount(n-3);
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n>0 && n<=50)
        {
            int64 num = getCount(n); //for 2*n
            cout<<num<<endl;
        }
    }
}
