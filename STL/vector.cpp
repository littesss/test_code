/*************************************************************************
	> File Name: vector.cpp
	> Created Time: Tue 17 Oct 2017 03:44:44 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <vector>

void print(vector<int>);
int main()
{
    vector<int> array;
    array.push_back(1);
    array.push_back(6);
    array.push_back(6);
    array.push_back(3);

    vector<int>::iterator it;   //每个容器都定义了自己的迭代器
    vector<int>::iterator it2;

    for(it=array.begin(); it!=array.end(); )
    {
        //cout << array << endl;
        cout << *it << endl;
        if(6 == *it)
        {
            it2 = it;
            array.erase(it2);
            it--;
        }
        it++;
    }
    print(array);

    return 0;
}

void print(vector<int> v)
{
    cout << "vector size is:" << v.size() << endl;
}
