#include<iostream>
#include<stdio.h>
using namespace std;

//M>=1
//N<=10
int getCount(int M, int N, int begin)
{
    if(N<=0)
    {
        return 0;
    }
    if(M>=begin && N==1)
    {
        return 1;
    }
    int count=0;
    for(int i=begin; i<=M; i++)
    {
        count+=getCount(M-i,N-1,i);
    }
    return count;
}


int main()
{
    int k;
    cin>>k;
    if(k>=0 && k<=20)
    {
        while(k--)
        {
            int M,N;
            cin>>M>>N;
            if(M>=1 && N<=10)
            {
                int cnt = getCount(M,N,0);
                cout<<cnt<<endl;
            }
        }
    }

}
