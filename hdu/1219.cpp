#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define N 26
int a[N];

int main()
{
    string line;
    while(getline(cin,line))
    {
        memset(a,0,sizeof(a));
        for(int i=0; i<line.length();i++)
        {
            if(line[i]>='a' && line[i]<='z')
            {
                a[line[i]-'a']++;
            }
        }

        for(int i=0; i<N;i++)
        {
            char t='a'+i;
            cout<<t<<":"<<a[i]<<endl;
        }
        cout<<endl;
    }
}
