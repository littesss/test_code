#ifndef __NFSUTILS__
#define __NFSUTILS__


#include <string>

//server side 
class nfsutils
{
    public:
        //server side
        static int nfsstart();
        static int nfsstop();
        static int nfsstatus();
        
        static int confignfs(string sharedir, string nfsopt);

        //client side 
        static int mountnfs(string nfsloc, string sharedir, 
                string mpt, string mountopts="");
        static int umount(string mpt, int isforce = 0);
};
#endif
