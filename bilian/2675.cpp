#include<iostream>
#include<stdio.h>
using namespace std;
#define NUM 10
float fee[NUM]={28.9,32.7,45.6,78,35,86.2,27.8,43,56,65};
int main()
{
    int k;
    cin>>k;
    if(k>0 && k<100)
    {
        while(k--)
        {
            float x;
            float sum=0;
            for(int i=0;i<NUM;i++)
            {
                cin>>x;
                sum+= x*fee[i];
            }
            //cout<<sum<<endl;
            printf("%.2f\n",sum);
        }
    }
}
