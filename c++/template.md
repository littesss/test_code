template:
1. 分为类模板，函数模板
类模板
template <typename/class T>
class A
{};

函数模板
template <typename T>
T fun(T a, T b)
{}

2. 类模板的成员函数属于函数模板，一般在类外实现
template <class T>
void A<T>::fun(T a, T b)
{}

3. 类模板，函数模板的出现是为了提高代码的复用性

4. 函数模板在实例化的时候由编译器自动确定，
   类模板在实例化的时候必须由程序员显示给定。 

5. 提高复用性，可移植性高，编译时检查数据类型

