/*************************************************************************
	> File Name: copy1.cpp
	> Created Time: Tue 17 Oct 2017 04:42:55 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <algorithm>
#include <vector>
#include <iterator>

int  main()
{
    vector<int> v;
    copy(istream_iterator<int>(cin), istream_iterator<int>(),
         back_insert_iterator<vector<int> >(v));
    sort(v.begin(), v.end(), greater<int>());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
