#file description
    内核（kernel）利用文件描述符（file descriptor）来访问文件。文件描述符是非负整
    数。打开现存文件或新建文件时，内核会返回一个文件描述符。读写文件也需要使用文
    件描述符来指定待读写的文件。
    windows 下叫句柄， Linux下叫文件描述符
    0 标准输入， 1 标准输出  2 标准错误输出
    标准相当于在屏幕

#systemCall: creat open write read lseek close

#creat 返回文件描述符
int fd = creat("pathname", 0666);
#open 返回文件描述符，从3开始， 参数： 路径， flag O_RDWR|0_CREAT, mode 0666
int fd = open("pathname", flags);
int fd = open("pathname", flags, mode);
#write 返回值是成功写了多少字节，返回0表示没有写东西，<0 表示失败
int nbyte = write(fd, buff, strlen(str));
#read 返回值是成功读取多少字节，返回0表示没有字节可读，<0 表示失败
int nbyte = read(fd, buff, 512);
#lseek 随机读写
off_t lseek(int fd, off_t offset, int whence);
SEEK_SET  >起始位置   0
The offset is set to offset bytes.
SEEK_CUR  >当前位置   1
The offset is set to its current location plus offset bytes.
SEEK_END  >结束位子   2
The offset is set to the size of the file plus offset bytes.
#close 关闭文件描述符
int close(fd);
记得关闭文件描述符
