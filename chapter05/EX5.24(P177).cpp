
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
//0x7536C5AF ��(λ�� chapter05.exe ��)��δ��������쳣: Microsoft C++ �쳣: std::runtime_error��
//λ���ڴ�λ�� 0x0042F868 ����