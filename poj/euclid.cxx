#include<iostream>
#include<string>

using namespace std;

//get the gcd and the solution for ax+by=gcd(a,b) at the same time.
int get_x_y_and_gcd(int a, int b, int &x, int &y)
{
    int x2=0,y2=0;
    int the_gcd;
    if(b==0)
    {
        x=1;
        y=-1;    //y can use any integer value
        the_gcd=a;     
    }else
    {
        the_gcd = get_x_y_and_gcd(b,a%b,x2,y2);
        x=y2;
        y=x2-(a/b)*y2;
    }
    cout<<"x:"<<x<<" y:"<<y<<" gcd:"<<the_gcd<<endl;
    return the_gcd;     
}
// solve the ax+by=c  when a >0, b>0.  a,b,c are integers. 
void solve_x_y_for_c(int a, int b, int c)
{
    int x,y;
    int d,k;
    cout<<"a:"<<a<<" b:"<<b<<" c:"<<c<<endl;
    d=get_x_y_and_gcd(a,b,x,y);
    cout<<"the gcd is "<<d<<endl;
    k=c/d;
    if(c%d!=0)
    {
        cout<<"no solution for c, because c%gcd="<<c%d<<endl;
        return;
    }else
    {
        cout<<"one solution is (x:"<<k*x<<" y:"<<k*y<<")"<<endl;
        return;
    }
}


// get the greatest common divisor for a,b.  a>0, b>0
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

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        cout<<gcd(a,b)<<endl;
        solve_x_y_for_c(a,b,3);
    }
    return 0;
}
