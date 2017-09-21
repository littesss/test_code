#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nfsutils.h"

static string svc = "nfs-kernel-server.service";

int nfsutils::nfsstart()
{
    string cmd("systemctl start " + svc + "  >/dev/null 2>&1");
    int ret = system(cmd.c_str());
    return ret;
}


int nfsutils::nfsstop()
{
    string cmd("systemctl stop " + svc + "  >/dev/null 2>&1");
    int ret = system(cmd.c_str());
    return ret;
}

int nfsutils::nfsstatus()
{
    string cmd("systemctl status " + svc + " >/dev/null 2>&1");
    int status = system(cmd.c_str());
    if (WIFEXITED(status)) 
    {
       return  WEXITSTATUS(status);
                                                  
    }
    else if (WIFSIGNALED(status)) 
    {
        return  WTERMSIG(status);
                                                  
    }
}
/*
int nfsutils::confignfs(string sharedir, string nfsopts)
{
    string filename("/etc/exports"); 
    ifstream fin(filename.c_str());
    
    vector<string> lines;
    string line;

    while(!fin.eof())
    {
       getline(fin, line);
       lines.push_back(line);
    }
    fin.close();
    return 0;

    //open()
    //write()
    //close()
    /*
       1. manupulate the "/etc/exports" with linux system calls
       a. open
       b. close
       c. read
       d. write

       2. manupulate the "/etc/exports" with c FILE related apis
       a. fopen 
       b. fwrite
       c. fread
       d. fclose

       3. manupulate the "/etc/exports" with c++ ifstream/ofstream apis
       a. ifstream
       b. ofstream
       c. operator "<<"
       d. operator ">>"

       string utils 
       1. int startswith(string lhs, string rhs);
       2. int endswith(string lhs, string rhs);
       intstr="a,bc,cc,ddd,eff", separator=","
       {"a", "bc", "cc", "dd", "eff"}
       3. vector<string> split(string inputstr, string separator)
       4. int join(vector<string> strvec, string separator)



}

//client side 
int nfsutils::mountnfs(string nfsloc, string sharedir, 
        string mpt, string mountopts)
{
    string cmd("mount ");

    cout << "here" << endl;

    cmd += mountopts + nfsloc + ":" + sharedir + " " + mpt; 

    cout << "mount cmd: " << cmd << endl;

    int ret = system(cmd.c_str());

    return ret;

}

bool nfsutils::ismounted(string nfsloc, string sharedir, string mpt)
{
    return 0;
}

int nfsutils::umount(string mpt, int isforce)
{
    string cmd("umount");
    if(isforce)
    {
        cmd += " -f ";
    }
    cmd += mpt;
    int ret = system(cmd.c_str());
    return ret;
}
*/
