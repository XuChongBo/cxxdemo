#include<iostream>
#include<string>

using namespace std;
int gcd(int a, int b)
{
    int tmp;
    //a-->b-->a%b-->b%(a%b)--> .. ->gcd->0
    while(b!=0)
    {
       tmp=b;
       b=a%b; 
       a=tmp;
    }
    return a; 
}


int palindrome(const string &s)
{
    int len=s.length();
    int N='z'-'a'+1;
    int count[N];
    int t=0;
    int num_sum=0;
    int res=1;
    int for_fraction[100];

    for(int i=0; i<100;i++)
    {
        for_fraction[i]=i+1;
    }

    cout<<"len(s):"<<len<<" N:"<<N<<endl; 
    for(int i=0; i<N; i++)
    {
        count[i]=0;
    }
    for(int i=0; i<len; i++)
    {
        
        count[s[i]-'a']++;
        
    }
    for(int i=0; i<N; i++)
    {
        //cout<<i<<":"<<count[i]<<" ";
        t+=count[i]%2;
        count[i]/=2;
        num_sum+=count[i];
    }
    cout<<"t:"<<t<<" num_sum:"<<num_sum<<endl;
    if(t>1)
    {
        cout<<"no palidrome.  num of odd:"<<t<<" >1"<<endl;
        return 0;
    }
    //calculate the 
    for(int i=0; i<N;i++)
    {
        for(int j=count[i]; j>0;j--)
        {
           int div=j;
           for(int k=num_sum-1; k>=0; k--)
           {
               if(div==1)
               {
                    break;
               }
               int the_gcd=gcd(for_fraction[k],j);
               for_fraction[k]/=the_gcd;
               div/=the_gcd;
           }
        }
    }
    for(int i=0; i<num_sum; i++)
    {
        //(a*b*c)%m=(((a%m)*b)%m)%m
        res*=for_fraction[i];
        res%=1000000007;
        
    }
    return res;
}

int main()
{
jjjj}
