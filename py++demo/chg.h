#ifndef chg_
#define chg_
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Chg
{
  public:
    Chg():
      m_age(28){ m_friend.push_back("mm");}
    int getAge()
    {
      return m_age;
    }
    int friendSize()
    {
      return m_friend.size();
    }
    int m_age;
    vector<string> m_friend;
};

void haha();
#endif
