#include <iostream>
#include <string>
// #include <string>

using namespace std;

template <class t>
class stack
{
private:
    t *array;
    int max; // this is the max numbers our array could hold
    int top; // we could say this is the index with whom we push in the stack
public:
    stack()
    {
        max = 100;
        array = new t[max];
        top = 0;
        // cout << "You created a stack of 100 places";
    }
    stack(int a)
    {
        max = a;
        array = new t[max];
        top = 0;
    }
    ~stack()
    {
        delete (array);
        top = 0;
        max = 0;
    }
    void push(t a)
    {
        if (!(top < max))
        {
            cout << endl
                 << "the stack is full you can't add "
                 << "\"" << a << "\"";
            return;
        }
        array[top++] = a;
    }
    t pop()
    {
        if (top == 0)
        {
            cout << "The stack is empty!";
            exit;
        }
        t popResult = array[--top];
        cout << popResult << endl;
        return popResult;
    }
    t getTop()
    {
        if (top == 0)
        {
            cout << "The stack is empty!";
            exit;
        }
        int popResult = array[top - 1];
        cout << popResult << endl;
        return popResult;
    }
    int getSize()
    {
        return top;
    }
    int getMax()
    {
        return max;
    }
    bool isEmpty()
    {
        return (top == 0); //  (top == 0) ? true : false these 2 expressions are the same
    }
    bool isFull()
    {
        return (top == max) ? true : false;
    }
    void allStack()
    {
        if (!isEmpty())
        {
            cout << "This is the whole stack" << endl;
            for (int i = top - 1; i >= 0; i--)
            {
                cout << array[i] << endl;
            }
            cout << "End of the stack" << endl;
            return;
        }
        cout << "The stack is empty" << endl;
    }
};

int main()
{
    stack<string> todo(12);

    todo.push("hossain");
    todo.push("mohamed");
    todo.push("said");
    todo.push("safwan");
    todo.push("imane");

    // todo.push(1);
    // todo.push(2);
    // todo.push(3);
    // todo.push(4);
    // todo.push(5);

    // todo.pop();
    // todo.pop();
    // todo.pop();
    // todo.pop();
    // todo.pop();
    // todo.allStack();
    // todo.getTop();
    todo.allStack();


    return 0;
}