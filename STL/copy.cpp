/*************************************************************************
  > File Name: copy.cpp
  > Created Time: Sat 14 Oct 2017 04:06:35 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <iterator>  
#include <string>  

using namespace std;  

int main ()   
{  
    typedef vector<int> IntVector;  
    typedef istream_iterator<int> IstreamItr;  
    typedef ostream_iterator<int> OstreamItr;  
    typedef back_insert_iterator< IntVector > BackInsItr;  

    IntVector myvector;  

    // 从标准输入设备读入整数  
    // 直到输入的是非整型数据为止 请输入整数序列，按任意非数字键并回车结束输入  
    cout << "Please input element：" << endl;  
    copy(IstreamItr(cin), IstreamItr(), BackInsItr(myvector));  

    //输出容器里的所有元素，元素之间用空格隔开  
    cout << "Output : " << endl;  
    copy(myvector.begin(), myvector.end(), OstreamItr(cout, " "));   
    cout << endl;  

    return 0;  
}  
