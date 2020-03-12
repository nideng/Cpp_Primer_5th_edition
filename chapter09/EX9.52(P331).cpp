#include<iostream>
#include<string>
#include<stack>
#include<stdexcept>
#include<deque>
using namespace std;
enum Type_list { LP, RP, ADD, SUB, VAL };
struct Element
{
    Element(Type_list type, double val = 0) { typeID = type; Value = val; }
    Type_list typeID;
    double Value;
};
inline void skip_space(string& exp, size_t& p)
{
    p = exp.find_first_not_of(" ", p);
}
inline void new_val(stack<Element>& so, double v)
{
    if (so.empty() || so.top().typeID == LP)
    {
        so.push(Element(VAL, v));
    }
    else if (so.top().typeID == ADD || so.top().typeID == SUB)
    {
        Type_list type = so.top().typeID;
        so.pop();
        if (type == ADD)
            v += so.top().Value;
        else
            v = so.top().Value - v;
        so.pop();
        so.push(Element(VAL, v));
    }
    else
        throw invalid_argument("invalid expression");
}

int main(int argc, char** argv)
{
    stack<Element>so;
    string exp;
    size_t p = 0, q;
    double v;

    cout << "enter an expression:" << endl;
    getline(cin, exp);
    while (p < exp.size())
    {
        skip_space(exp, p);
        if (exp[p] == '(')
        {
            so.push(Element(LP));
            p++;
        }
        else if ((exp[p] == '+') || exp[p] == '-')
        {
            if (so.empty() || so.top().typeID != VAL)
                throw invalid_argument("short of value");
            if (exp[p] == '+')
                so.push(Element(ADD));
            else
                so.push(Element(SUB));
            p++;
        }
        else if (exp[p] == ')')
        {
            p++;
            if (so.empty())
                throw invalid_argument("invalid expression");
            if (so.top().typeID == LP)
                throw invalid_argument("empty bracket");
            if (so.top().typeID == VAL)
            {
                v = so.top().Value;
                so.pop();
                if (so.empty() || so.top().typeID != LP)
                    throw invalid_argument("invalid expression");
                so.pop();
                new_val(so, v);
            }
            else
                throw invalid_argument("invalid expression");

        }
        else
        {
            v = stod(exp.substr(p), &q);
            p += q;
            new_val(so, v);
        }
    }
    if (so.size() != 1 || so.top().typeID != VAL)
    {
        throw invalid_argument("invalid expression");
    }
    cout << so.top().Value << endl;
    return 0;
}