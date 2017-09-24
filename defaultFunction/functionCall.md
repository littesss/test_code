函数调用：
实参
    1. 必须是已知值， 
    2. 可以是常量，变量，表达式，函数，但是在调用时候必须是确定值
形参
    1. 就是在调用的时候才分配空间，函数一结束，变量的作用域结束，自然要释放空间
       如果堆区空间一定要记得释放，否则内存泄露

步骤：
    1. 记住调用函数的下一条语句地址
    2. 实参去初始化形参，函数压栈
    3. 函数出栈
    4. 回到函数调用的下一条语句

心得：
    1. 函数在调用的时候才是形参分配空间而，实参区初始化形参
    2. 函数带有返回值的话，不是以引用返回的话，系统先回为其申请一个临时变量
       ，如果是对象的话就会造成拷贝构造，当返回的值赋值给其他的值的时候，此
       时这个临时无名变量才会析构

string:
    1. 使用string时程序员不用考虑开辟空间释放空间；string自己的底层实现需要。
    2. 准确的来说，char是数据类型，而string是类，不严格算基础数据类型。
       当string的生命周期结束时，会自动调用string类的析构函数，释放内存，不用手动释放
    
