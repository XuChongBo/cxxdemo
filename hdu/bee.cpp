#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MAX_NUM 50
long long int cache[MAX_NUM*MAX_NUM]; //={0};  //the initialize method ok?

long long int choice_num(int src, int dst)
{
    if(src<=0 || dst<=0 || src>dst)
    {
        return 0;
    }else if(src==dst)
    {
        return 1;
    }else if(src==dst-1)
    {
        return 1;
    }else
    {
         long long int  tmp = cache[src*MAX_NUM + dst];
        if(tmp<=0)
        {
            tmp = choice_num(src,dst-1) + choice_num(src,dst-2);
            cache[src*MAX_NUM + dst] = tmp;
        }
        return  tmp;
    }
}

int main()
{
    memset(cache,0,sizeof(cache));
    //cout<<sizeof(long long int)<<" "<<sizeof(cache)<<endl;
    //exit(0);
    int k;
    cin>>k;
    while(k>0)
    {
        k--;
        int a,b;
        cin>>a>>b;
        long long int n = choice_num(a,b);
        cout<<n<<endl;
    }
}
