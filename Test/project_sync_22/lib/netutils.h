/*************************************************************************
	> File Name: netutils.h
	> Created Time: Wed 30 Aug 2017 15:18:04 PDT
 ************************************************************************/
#ifndef _NETUTILS_H
#define _NETUTILS_H

#include <string>
using namespace std;

class netutils
{
    public:
        static int getnicbrdaddr(string& ifname, string& brdaddr);
};

#endif
