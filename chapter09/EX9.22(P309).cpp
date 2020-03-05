/*
1.It's a endless loop. iter never equal mid.
2.mid will be invalid after the insert
*/

#include <iostream>
#include <vector>
using namespace std;

void double_and_insert(vector<int>& v, int some_val)
{
    auto mid = v.begin() + v.size() / 2;
    for (auto curr = v.begin(); curr != mid; ++curr)
    {
        if (*curr == some_val)
            ++(curr = v.insert(curr, 2 * some_val));
        mid = v.begin() + v.size ()/ 2;//necessary
    }
}

int main()
{
    std::vector<int> v{ 1, 9, 1, 1, 9, 9, 1, 1 };
    double_and_insert(v, 1);
    for (auto i : v)
        std::cout << i << std::endl;
}