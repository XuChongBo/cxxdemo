#include<iostream>
#include<string>

using namespace std;

int f(int a, int b, int c, int d)
{
    int tmp;
    int c_div_a, d_div_b;
    // make sure  a>=b,  c>=d
    if(a<b)
    {
        tmp=a;
        a=b;
        b=tmp;
    }
    if(c<d)
    {
        tmp=c;
        c=d;
        d=tmp;
    }
    //cout<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    c_div_a=c*100/a;
    d_div_b=d*100/b;

    //cout<<c_div_a<<d_div_b<<endl;

    if (c_div_a>d_div_b)
    {
        return d_div_b>100? 100:d_div_b;
    }else
    {
        return c_div_a>100? 100:c_div_a;
    }

}

int main()
{
    int a, b, c, d;
    while(cin>>a>>b>>c>>d)
    {
        if(0==a && 0==b && 0==c && 0==d)
            break;
        cout<<f(a,b,c,d)<<"%"<<endl;
    }
    return 0;
}
