一. strlen strcpy strcmp strcat
1. strlen:
    计算字符串的长度，函数终止条件*str ！= '\0'
    assert(str);   str != NULL 的话继续，str == NULL 种植

2. strcpy（dest，src）：
    把原拷贝到目的，但必须给dest的空比src的字符串长度多+1
    src不等于‘\0’, 把*dest++ = * src++
    哦，一定要先定义一个temp记住dest 和 src的头，不然到时候就找不到头了

3. strcat(dest, src):
    把原字符串连接在目的字符串后面
    先让目的字符串先走到dest的最后，然后开始连接
    当然dest的空间必须足够大
    ！！！最后一定别忘了加上‘\0’

4. strcmp(str1, str2)
    比较str1 和str2 是否相等，相等0，str1>str2 返回1 否则返回-1
    while（*str1!='\0' && *str2!='\0' &&  ）
    {
        str1++, str2++;
    }
    if(*str1 == * str1)
        return 0;
    else if(*str1 > *str2)
        return 1;
    else
        return -1;

字符串编程心得：
    字符串开辟空间：栈区， 字符串常量区（代码段上来就是字符串常量）
    栈区 ： char arr[] = "hello"; //这个字符串在栈区，有系统开辟释放空间，不
    具有常性质

    字符串常量区: char * str = "hello";// 函数结束系统没有释放空间，它具有常
    行

左值,前++ 与后++
    int a ;
    ++a = 10; // 正确，并且a赋值后是10, 返回当前对象
    int operator++() // 前加加

    a++ = 10; // 编译错误， 返回一个临时对象， 当前对象再自+，而函数结束临时
    临时对象已经释放， 故不知道把10赋值给谁了，报错
    int operator++(int); // 后++
    
注意区别数组名++，
    数组名是一个常量，不能加加 









