/*************************************************************************
	> File Name: graph.cpp
	> Created Time: Tue 22 Aug 2017 04:41:07 PDT
 ************************************************************************/
#include <iostream>
using namespace std;

#include "graph.h"

int main()
{
    Graph g;
    g.insertVertex('a');
    g.insertVertex('b');
    g.insertVertex('c');
    g.insertVertex('d');
    g.insertVertex('e');
    g.showGraph();
    return 0;
}
