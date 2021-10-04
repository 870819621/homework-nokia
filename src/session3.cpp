//
// Created by c2xu on 2021/9/14.
//
#include <algorithm>
#include "iostream"
#include "vector"
using namespace std;
class Person{
public:
    Person(string name):name(name){
        cout<<"construct "<<" name:"<<name
            <<" age:"<<age
            <<endl;
    }
    Person(string name,int age):name(name),age(age){
        cout<<"construct "<<" name:"<<name
            <<" age:"<<age
            <<endl;
    }
    virtual void fun(){
        cout<<"Person:fun()"<<endl;
    }
    virtual void fun2() final{
        cout<<"Person:fun2()"<<endl;
    }
private:
    int age;
    string name;
};

class Employee:public Person{
public:
    using Person::Person;
    Employee(string name,int age,string dept):Person(name,age){
        cout<<"construct "<<" name:"<<name
                        <<" age:"<<age
                        <<" dept:"<<dept
                        <<endl;
    };
    void fun() override{
        cout<<"Employee:fun()"<<endl;
    }
//    void fun2() override{
//        cout<<"Employee:fun2()"<<endl;
//    }

private:
    string dept{""};
};
int main(){
//    Employee a{"aaa",18};
//    a.fun();
//    a.fun2();

    std::vector<int> vec{1,3,4,3,8,9};
    int val =10;
    auto fun = [val]()mutable{
        val+=1;
    };
    cout<<val<<endl;
    fun();
    auto num = std::count_if(vec.begin(),vec.end(),[=](auto x) {return x == 3;});
    cout<<num<<endl;
    return 1;
}