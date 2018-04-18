#include <iostream>
#include "t.h"
using namespace std;

template<class T> 
A<T>::A()
{
}


template<class T> 
T A<T>::g(T a,T b)
{
    return a+b;
}


template<class T> 
void draw(T &a)
{
    a.x = 2;
    a.y = 12;
}

struct PointInt 
{
    int x;
    int y;
};

struct PointFloat
{
    float x;
    float y;
};


int main(){
    A<int> a;
    cout<<a.g(2,3.2)<<endl;

    PointInt pt1;
    draw<PointInt>(pt1);
    cout<<pt1.x<<endl;
    cout<<pt1.y<<endl;


    PointFloat pt;
    draw<PointFloat>(pt);
    cout<<pt.x<<endl;
    cout<<pt.y<<endl;

}
