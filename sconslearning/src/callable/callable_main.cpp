#include <iostream>
#include <functional>
using namespace std;

void global_func(int a)
{ //全局函数
    cout << "call global_func:" << a << endl;
}

auto labmda = [](int a) { cout << "lambda:" << a << endl; };

class ClassA
{
public:
    void member_func(int a)
    { //类成员函数
        cout << "call ClassA::member_func:" << a << endl;
    }

    static void static_member_func(int a)
    { //类静态函数
        cout << "call ClassA::static_member_func:" << a << endl;
    }
};

class Functor
{ //仿函数
public:
    void operator()(int a)
    {
        cout << "call Functor()" << a << endl;
    }
};

int main(int argc, const char *argv[])
{
    function<void(int)> func;
    func = global_func;
    func(10);
    auto bindGlobalFunc = std::bind(global_func, 10);
    bindGlobalFunc();

    func = labmda;
    func(11);
    auto bindLabmdaFunc = std::bind(labmda, 11);
    bindLabmdaFunc();

    Functor testFunctor;
    func = testFunctor;
    func(12);
    auto bindFunctorFunc = std::bind(testFunctor, 12);
    bindFunctorFunc();

    ClassA a_object;
    func = std::bind(&ClassA::member_func, &a_object, std::placeholders::_1);
    func(13);
    auto bindClassMemberFunc = std::bind(&ClassA::member_func, &a_object, 13);
    bindClassMemberFunc();

    func = std::bind(&ClassA::static_member_func, std::placeholders::_1);
    func(14);
    auto bindClassStaticFunc = std::bind(&ClassA::static_member_func, 14);
    bindClassStaticFunc();
    return 0;
}