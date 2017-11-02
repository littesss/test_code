一.继承
    1. 除了父类析构和构造没有被继承外，其他所有都被全盘接受
    2. 父类的私有数据不能被继承的子类直接访问，可以通过父类间接访问

二.public protected private继承属性会有所变话
        最后假如public属性的继承就把父类中public、protected、private在子类的还
    是该性质，只不过父类的私有不能被访问。
        protect属性的继承就把父类中public、protected、private在子类的public看成
    protected、protected不变、private不变。并且父类的私有不能被子类直接访问。
        private属性的继承就把父类中public、protected、private在子类的public看
    成private、protected看成private、private不变。并且父类的私有不能被子类直接访问


三.继承 静态成员函数
    保护属性继承：不能通过类名被访问
    共有属性继承：可以通过父类名直接访问，或者子类类名访问
