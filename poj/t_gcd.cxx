#include <iostream>
#include <cstring>
#include <string>
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

int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        cout << gcd(a,b) << endl; 
    }
}
