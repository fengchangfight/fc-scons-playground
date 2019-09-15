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

int getMaximumNumberOfThreads()
{
    unsigned int c = std::thread::hardware_concurrency();
    return c;
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

void prepareFakeData(std::vector<int> &v)
{
    int size = 10;
    for (int i = 0; i < size; i++)
    {
        v.push_back(i + 1);
    }
}

int main()
{
    std::cout << "here i am multithreading...\n";
    std::vector<int> v;
    prepareFakeData(v);

    int c = getMaximumNumberOfThreads();

    std::cout << "Number of cores:" << c << std::endl;
    return 0;
}