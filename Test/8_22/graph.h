/*************************************************************************
	> File Name: graph.h
	> Created Time: Tue 22 Aug 2017 04:41:30 PDT
 ************************************************************************/
#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
using namespace std;

#define SIZE  10
class Graph
{
    public:
        Graph()
        {
            MaxVertices = SIZE;
            NumVertices = NumEdges = 0;
            VerticesList =  new char[MaxVertices];
            Edges = new int*[MaxVertices]; //int *Edges[10]
            
            int i,j;
            for(i=0; i<MaxVertices; ++i)
            {
                Edges[i] = new int[MaxVertices];
            }

            for(i=0; i<MaxVertices; ++i)
            {
                for(j=0; j<MaxVertices; ++j)
                    Edges[i][j] = 0;
            }
        }
    public:
        void insertVertex(char v)
        {
            if(NumVertices  < MaxVertices)
            {
                for(int i=0; i<NumVertices; ++i)
                {
                    if(VerticesList[i] == v)
                        return ;
                }
                VerticesList[NumVertices] = v;
                NumVertices++;

            }
        }
        void showGraph()
        {
            int i,j;
            cout << "  ";
            for(i=0; i<NumVertices; ++i)
            {
                cout << VerticesList[i] << " ";
            }
            cout << endl;
            for(i=0; i<NumVertices; ++i)
            {
                cout << VerticesList[i] << " ";
                for(j=0; i<NumVertices; ++j)
                {
                    cout << Edges[i][j] << " ";
                }
                cout << endl;
            }
        }
    private:
        int MaxVertices;
        int NumVertices;
        char * VerticesList;
        int    NumEdges; // 边的条数
        int ** Edges;    // 边的数组
};

#endif
