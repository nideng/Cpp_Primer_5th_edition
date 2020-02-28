
#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
    int i, j;
    while (cin >> i >> j)
    {
        if (j == 0)
            throw std::runtime_error("divisor is 0");
        std::cout << i / j << std::endl;
    }
    return 0;
}
//0x7536C5AF 处(位于 chapter05.exe 中)有未经处理的异常: Microsoft C++ 异常: std::runtime_error，
//位于内存位置 0x0042F868 处。