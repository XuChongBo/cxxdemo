#include<iostream>
#include<string>

using namespace std;

string f(string &s, int n)
{
    int len=s.length();
    int *r=new int[len];
    int *mediate_sum=new int[2*len-1];
    int dot_position=len;

    cout<<"len: "<<len<<endl;
    cout<<"r= ";
    for(int i=0; i<len; i++)
    {
       if('.'==s[i])
       {
          dot_position=i;
          continue;
       }
       r[i]=s[i]-'0'; 
       cout<<r[i];
    }
    cout<<endl;
    cout<<"n="<<n<<endl;
    cout<<"dot_position="<<dot_position<<endl;

    // to do r^n
    for(int k=0; k<n; k++)
    {
        
    }
    for(int i=0; i<len; i++)
    {
        r[i]
    }

    return "abc";
}

int main()
{
    string s;
    int n;

    while(cin>>s>>n)
    {
        cout<<f(s,n)<<endl;
    }
    return 0;
}
