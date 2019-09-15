#include <iostream>
#include <vector>
#include <thread>

void accumulator_function2(const std::vector<int> &v, unsigned long long &acm,
                           unsigned int beginIndex, unsigned int endIndex)
{
    acm = 0;
    for (unsigned int i = beginIndex; i < endIndex; ++i)
    {
        acm += v[i];
    }
}

class CAccumulatorFunctor3
{
public:
    void operator()(const std::vector<int> &v,
                    unsigned int beginIndex, unsigned int endIndex)
    {
        _acm = 0;
        for (unsigned int i = beginIndex; i < endIndex; ++i)
        {
            _acm += v[i];
        }
    }
    unsigned long long _acm;
};

int main()
{
    std::cout << "here i am multithreading...\n";
    std::vector<int> v;

    int size = 10;
    for (int i = 0; i < size; i++)
    {
        v.push_back(i + 1);
    }

    CAccumulatorFunctor3 accumulator1 = CAccumulatorFunctor3();
    CAccumulatorFunctor3 accumulator2 = CAccumulatorFunctor3();
    std::thread t1(std::ref(accumulator1),
                   std::ref(v), 0, v.size() / 2);
    std::thread t2(std::ref(accumulator2),
                   std::ref(v), v.size() / 2, v.size());
    t1.join();
    t2.join();

    std::cout << "acm1: " << accumulator1._acm << std::endl;
    std::cout << "acm2: " << accumulator2._acm << std::endl;
    std::cout << "accumulator1._acm + accumulator2._acm : " << accumulator1._acm + accumulator2._acm << std::endl;
    return 0;
}