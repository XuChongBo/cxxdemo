#include <map>
#include <vector> 
#include <iostream>

using namespace std;

int main()
{
	map<int ,int> m1, m2, m3;

	std::map<int, int>::iterator itr;

	m1.insert(pair<int,int >(1,100));
	m1[2]=200;

	//m1[1]=300;  //will overwrite the same elem
	m1.insert(pair<int,int >(1,100));  //will not overwirte 
	
	m2[1]=10;
	m2[3]=30;
	m2[4]=40;

	m1.insert(m2.begin(),m2.end());

	for (itr=m1.begin(); itr!=m1.end(); itr++) {
		cout<<"<"<<itr->first <<", " <<itr->second << ">" << endl;
	}
	cout<<"total:"<<m1.size()<<endl;

	std::vector< std::vector<int> > rlt(5); // it is tha same as rlt.reserve(5);

}