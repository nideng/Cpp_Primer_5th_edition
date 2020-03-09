#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include<vector>
using namespace std;
int main()
{
    map<int, vector<int>> m = { { 1,{1,2} },{ 2,{1,2 }} };
    using KeyType = std::map<int, vector<int>>::key_type;

    cout << "type to subscript: " << typeid(KeyType).name() << endl;
    cout << "returned from the subscript operator: " << typeid(decltype(m[1])).name() << endl;
    cout << "map_type: " << typeid(map<int, vector<int>>::mapped_type).name() << endl;
    return 0;
}