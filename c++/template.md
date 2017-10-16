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

4. 类模板，函数模板实例化后才能成模板类，或者模板函数，模板推演这一步
   是由编译器来完成的。

5. 定义模板类的时候必须给出明确的类型定义


