#include <iostream>
#include <string>
#include <utility>

using namespace std;
class Test
{
public:
    //constructor
    Test(const string &name="",const string &pstr ="",int i=0)
        :m_name(name),mp_str(new string(pstr)),m_i(i)
    {
        cout<<"constructor : "<<m_name<<" p : "<<&m_name<<endl
            <<"mp_str: "<<(*mp_str)<<" p: "<<mp_str<<endl
            <<"m_i: "<<m_i<<" p: "<<&m_i<<endl;
    }

    //copy constructor
    Test(const Test &test)
        :m_name(test.m_name),m_i(test.m_i)
    {
        mp_str = new string(*(test.mp_str));
        cout<<"copy constructor : "<<m_name<<" p : "<<&m_name<<endl
        <<"mp_str: "<<(*mp_str)<<" p: "<<mp_str<<endl
        <<"m_i: "<<m_i<<" p: "<<&m_i<<endl;
    }

    //move constructor
    Test(Test &&test)
        :m_name(test.m_name),m_i(test.m_i)
    {
        mp_str = new string(*(test.mp_str));
        cout<<"move constructor : "<<m_name<<" p : "<<&m_name<<endl
        <<"mp_str: "<<(*mp_str)<<" p: "<<mp_str<<endl
        <<"m_i: "<<m_i<<" p: "<<&m_i<<endl;

        test.mp_str=nullptr;
    }

    //decpmstructor
    ~Test()
    {
        cout<<"de constructor : "<<m_name<<" p : "<<&m_name<<endl
        <<"mp_str: "<<(*mp_str)<<" p: "<<mp_str<<endl
        <<"m_i: "<<m_i<<" p: "<<&m_i<<endl;

        delete mp_str;
    }
    void show()
    {
        cout<<"show : "<<m_name<<" p : "<<&m_name<<endl
        <<"mp_str: "<<(*mp_str)<<" p: "<<mp_str<<endl
        <<"m_i: "<<m_i<<" p: "<<&m_i<<endl; 
    }
private:
    string m_name;
    string *mp_str;
    int m_i;
public:
};

Test func(Test t)
{
    // long long i[100];
    cout<<"--pass end--"<<endl;
    int l = 1;
    cout<<l<<endl;
    Test test3("test3 obj func","point",3);
    cout<<"--start return--"<<endl;
    
    return test3;
}


int main()
{
    cout<<"-----------stack obj----------"<<endl;
    Test t1("stack obj main","point",1);
    cout<<"------------------------------"<<endl;

    int i=1;
    cout<<"-------------stack :"<<&i<<endl;
    
    cout<<"----------copy pass----------"<<endl;
    Test tt=func(t1);
    cout<<"------------------------------"<<endl;
    int i1=1;
    cout<<"-------------stack :"<<&i1<<endl;
    cout<<"----------move pass----------"<<endl;
    Test t2=func(move(t1));
    cout<<"------------------------------"<<endl;

    int i2=1;
    cout<<"-------------stack :"<<&i2<<endl;

    t2.show();



    cout<<"------------------------------"<<endl;
    
    // Test t3("pending main","point",1);
    // Test t4("pending main","point",1);
    // Test t5("pending main","point",1);
    // Test t6("pending main","point",1);
    // Test t7("pending main","point",1);
    int i3;
    cout<<"------------------------------"<<&i3<<endl;
    
    
}