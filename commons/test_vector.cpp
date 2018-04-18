#include <map>
#include <vector> 
#include <iostream>

using namespace std;

void printVector(int *pts, int num)
{
  for (int i = 0; i < num; i++){
      std::cout<<"printVector2: x:"<<pts[i]<<std::endl;
  }
}

void print2DVector(std::vector< std::vector<int> > &x)
{
  for (int i = 0; i < x.size(); i++){
      std::cout<<"printVector2: x:"<<x[i][0]<<std::endl;
  }
}

/*
std::vector copy()
{
}
*/

void func(int *pts, int num)
{
  printVector(pts, num);
  std::cout<<"origin pts: "<<pts <<std::endl;
  vector<int> *vs = new vector<int>(1024);
  std::cout<<"after pts: "<<pts <<std::endl;
  std::cout<<"vs loacte: "<< vs <<std::endl;
  std::cout<<"vs[0] loacte: "<< &vs[0] <<std::endl;
  printVector(pts, num);
}

int main()
{
    std::vector<int> a(200, 123);
    std::vector<int> b = {2,3,4}; //Only works in C++ 11.    //   g++ -std=c++11 test_vector.cpp
    std::vector< std::vector<int> > c = {{2,3,4},{34,55}}; //Only works in C++ 11.    //   g++ -std=c++11 test_vector.cpp
    func(&a[0], a.size());
    print2DVector(c);
}

