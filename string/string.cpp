/*************************************************************************
	> File Name: string.cpp
	> Created Time: Mon 25 Sep 2017 01:12:16 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

class String;
ostream& operator<<(ostream &out, const String& str);
istream& operator>>(istream &in, String& str);
#include <string.h>
class String
{
    friend ostream& operator<<(ostream &out, const String& str);
    friend istream& operator>>(istream &in, String& str);
    public:
        String(const char * str = "")
        {
            if(str == NULL)
            {
                m_str = new char[1];
                m_str[0] = '\0';
            }
            else
            {
                m_str = new char[strlen(str)+1];
                strcpy(m_str, str); //后面自动不起\0
            }
            cout << "constructor :" << m_str << endl;
        }

        String(char s)
        {
            cout << "constructor :" << s << endl;
            m_str = new char[2];
            m_str[0] = s;
            m_str[1] = '\0';
        }

        ~String()
        {
            cout << "destructor:" << m_str << endl;
            delete m_str;
            m_str = NULL;
        }

        //拷贝构造函数
        String(const String& str)
        {
            cout << "copy constructor:" << str.m_str << endl;
            m_str = new char[sizeof(str.m_str)];
            strcpy(m_str, str.m_str);
        }
        //赋值运算符的重载
        String& operator=(const String& s)
        {
            if(this == &s)//必须判断
                return *this;
            
            delete m_str;
            m_str = NULL;

            m_str = new char[sizeof(s.m_str)];
            strcpy(m_str ,s.m_str);
            
            return *this;
        }

       //加号运算符的重载
       String operator+(const String& s)
       {
           char * temp = new char[strlen(m_str) + strlen(s.m_str)+1];
           
           strcpy(temp, m_str);
           strcat(temp, s.m_str);

           String T(temp);
           
           delete []temp;
           temp = NULL;

           return T;
       }

/*       String& operator+(const String& s)
       {
           char * temp = new char[sizeof(m_str)];
           strcpy(temp, m_str);
    
           if(m_str == NULL)
               delete []m_str;
           m_str = NULL;
    
           m_str = new char[strlen(temp)+strlen(s.m_str)+1];
           strcpy(m_str, temp);
           strcat(m_str, s.m_str);

           delete temp;
           temp = NULL;
           return *this;
           
       }
*/
    public:
       char * c_str()
       {
           return this->m_str;
       }
       ostream& operator<<(ostream &out)
       {
           out << m_str;
           return out;
       }
       istream& operator>>(istream &in)
       {
           in >> m_str;
           return in;
       }
    private:
        char * m_str;
};

ostream& operator<<(ostream& out, const String& str)
{
    out << str.m_str;
    return out;
}
istream& operator>>(istream &in, String& str)
{
    in >> str.m_str;
    return in; 
}
int main()
{
/*    String a("nihao");
    String b('n');
    String c("linux");
    b = a = c = "hello";
*/
    String a = "hello linux";
    cout << "11111111111111" << endl;
    a<<cout << endl;
    cout << "11111111111111" << endl;


    cout << "a = " << a << endl;
    cout << "a.c_str() = " << a.c_str() << endl;
    String d,f;
    cout << "begin" << endl;
    cin >> d >> f;
    cout << "end" << endl;
    cout << d << endl;
    cout << f << endl;
   //  cout << "b+c = " << b+c << endl;
    //String c;//写了默认构造函数，但是又不带默认值的话，编译报错
    return  0;
}

