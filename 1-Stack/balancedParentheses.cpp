//? STACK POINTER IMPLEMENTATION (LINKED LIST IMPLEMENTATION)
//? By: HOSSAIN AHACHI 27 MAY 2022
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// bool areBalanced(string exp)
// {
//     stack<char> s;

//     for (int i = 0; i < exp.length(); i++)
//     {
//         if (exp[i] == '(')
//         {
//             s.push('(');
//         }
//         else if (exp[i] == '{')
//         {
//             s.push('{');
//         }
//         else if (exp[i] == ')')
//         {
//             if (s.size() == 0)
//             {
//                 s.push(')');
//                 break;
//             }
//             if (s.top() == '(')
//             {
//                 s.pop();
//             }
//             else
//             {
//                 s.push(')');
//             }
//         }
//         else if (exp[i] == '}')
//         {
//             if (s.size() == 0)
//             {
//                 s.push('}');
//                 break;
//             }
//             if (s.top() == '{')
//             {
//                 s.pop();
//             }
//             else
//             {
//                 s.push('}');
//             }
//         }
//         else if (exp[i] == '[')
//         {
//             s.push('[');
//         }
//         else if (exp[i] == ']')
//         {
//             if (s.size() == 0)
//             {
//                 s.push(']');
//                 break;
//             }
//             if (s.top() == '[')
//             {
//                 s.pop();
//             }
//             else
//             {
//                 s.push(']');
//             }
//         }
//     }
//     // this is for testing what is and what is not in the stack
//     // int size = s.size();
//     // for (int i = 0; i < size; i++)
//     // {
//     //     cout << endl
//     //          << s.top();
//     //     s.pop();
//     // }

//     return s.empty();
// }

bool areBalanced(string exp)
{
    stack<char> s;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            s.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (s.empty())
            {
                return false;
            }
            if (((s.top() == '(') && (exp[i] == ')')) || ((s.top() == '{') && (exp[i] == '}')) || ((s.top() == '[') && (exp[i] == ']')))
            {
                s.pop();
                continue;
            }
            return false;
        }
    }
    return s.empty();
}

int main()
{
    // string a = ;
    (areBalanced("h{((os)s)a}in")) ? (cout << "balanced") : (cout << "not balanced");
}