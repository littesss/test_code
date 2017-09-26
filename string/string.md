string类的实现：
1. string类程序员不用考虑，内存分配以及释放，string内部都已经实现
2. 构造对象，可以是字符串，字符等，string内部均已经实现
3. 对对象的输出cout 其在内部也已经实现，使用友元函数，对输出运算符的重载<<
4. 也可以通过调用c_str()内的成员函数，将其转换成标准的c字符串，其内容和string
   类串是一样的

sting类：重要函数
1. 构造函数：
  a. 先判空，空分配一个字符，'\0'
  b. 不空，分配strlen+1个空间 strcpy（this->m_str, m_str）;
  注意：如果写了构造函数，而没有默认值的话，就不会调动构造函数，所以一般构造函数
        应该把默认值加上

2. 析构函数：
  a. 函数格式唯一
  b. 析构数组指针   delete [] m_str;
  c. 赋空

3. 拷贝构造：（对象去构造对象）
  a. 也是构造函数，只不过参数必须带引用传递，否则死递归
  b. 给this->m_str 开辟 sizeof(S.m_str)的大小
  c. 用strcpy(m_str, S.m_str);
  注意： 引用传递参数

4. 赋值运算符的重载=：（对象已经构造好了，可以对象给对象赋值，也可以其他给对象赋值，只不过重载就行）
  对象给对象赋值：
  a. 自赋值！！！必须判断1.提高效率2.更重要是，如果自赋值，而下一步就要析构自己
  b. 析构自己
  c. 拷贝构造函数
  d. 返回*this

  注意：引用传参，引用返回

5. +运算符的重载：(引用返回，非引用返回)
    非引用返回：构造一个临时对象(用this->m_str +S.m_str去构造)
    返回临时对象
    优点：不改变this->m_str ,缺点：调动构造函数，拷贝构造，析构函数

    引用返回：
    a.先用一个temp记住this->m_str,给temp开辟空间
    b.strcpy(temp,m_str);
    c.析构m_str
    d.m_str = new char[strlen(temp)+strlen(S.m_str)+1]
    e.strcpy(m_str,temp);
    f.strcat(m_str, S.m_str);
    g.return *this
    优点：效率高，缺点，改变了*this
    注意：引用返回一般用于对象，改变对象的返回如+=  -=  *=  /=，语义符合

6. 成员函数c_str():将对象转换成标准c字符串，和string串内容一样，
    char * c_str()
    {
        return *this->m_str;
    }

7. 输入输出运算符的重载：<<  >>  ------>友元
   友元函数/类：friend
   a. 声明成友元，不是属性限制，private，public,protected
   b. 友元可以访问私有数据
   c. 友元没有this指针
   d. 友元可以在类内部实现，也可在外部实现，一般在外部实现
   e. 友元类属于另外一个类的作用域，不属于当前作用域的成员函数
===========================================================
一般情况，在类的外部用友元实现，非成员方法
friend ostream& operator<<(ostream& out, const String& S);
friend istream& operator>>(istream& in, String& S);

ostream& operator<<(ostream& out, const String& S)
{
    out << S.m_str ；
    return out;
}

istream& operator>>(istream& in, String& S) 
{
    in >> S.m_str;
    return in;
}
======================================================
特殊：输出运算符可以成为类的成员方法
public:
    ostream& operator<<(ostream& out)
    {
        out << m_str;
        return out;
    }
    ostream& operator>>(istream& in)
    {
        in >> m_str;
        return in;
    }
注意：这个输出输入比较诡异 
输入S<<cout    S.operator<<(cout);
输出 S>>cin    S.operator>>(cin);
=======================================================



