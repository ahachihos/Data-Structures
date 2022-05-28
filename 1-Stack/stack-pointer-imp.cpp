//? STACK POINTER IMPLEMENTATION (LINKED LIST IMPLEMENTATION)
//? By: HOSSAIN AHACHI 26 MAY 2022

#include <iostream>
#include <string>

using namespace std;

template <class t>
class stack
{
private:
    // template <class t>
    struct node
    {
        t value;
        node *next;
    };
    // template <class c>
    bool isLastNode(node *&temp)
    {
        return (temp->next == NULL);
    }

    node *head;
    int size;
    int max;

public:
    stack()
    {
        head = NULL;
        size = 0;
        max = 1000000000;
    }
    stack(int max)
    {
        head = NULL;
        size = 0;
        this->max = max;
    }
    ~stack()
    {
        if (!isEmpty())
        {
            node *temp = NULL;
            node *ahead = head;
            while (!isLastNode(ahead))
            {
                temp = ahead;
                ahead = ahead->next;
                delete (temp);
            }
            delete (ahead);
        }
        delete (head);
    }
    void push(t a)
    {
        if (size < max)
        {
            node *temp = temp = new node;
            temp->value = a;
            temp->next = head;
            head = temp;
            size++;
            return;
        }
        cout << endl
             << "The stack has reached its maximum size you can't push: " << a << endl;
    }
    t pop()
    {
        if (size == 0)
        {
            cout << "the stack is empty nothing to pop" << endl;
            exit;
        }
        t popResult = head->value;
        node *temp = head;
        head = head->next;
        delete (temp);
        size--;
        return popResult;
    }
    t getTop()
    {
        if (size == 0)
        {
            cout << "the stack is empty nothing to pop" << endl;
            exit;
        }
        return head->value;
    }
    void print()
    {
        if (!isEmpty())
        {
            node *temp = head;
            cout << endl;
            // while (temp->next != NULL)
            while (!isLastNode(temp))
            {
                // cout << "the linked list is not empty" << endl;
                cout << temp->value << endl;
                temp = temp->next;
            }
            // after finishing the while loop; we still didn't print the last node; that's why we have the line bellow
            cout << temp->value << endl
                 << "End" << endl;
            return;
        }
        cout << endl
             << "The Stack is empty" << endl;
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
    bool isFull()
    {
        return size == max;
    }
    int getSize()
    {
        return size;
    }
};

int main()
{
    stack<string> a(3);
    a.push("hossain");
    a.push("mohamed");
    a.push("said");
    a.push("insaf");
    a.push("youssra");

    // stack<int> a(2);
    // a.push(1);
    // a.push(2);
    // a.push(3);
    // a.push(4);
    // a.push(5);

    a.print();
    cout << "the size is of the stack is: " << a.getSize() << endl;
    cout << a.isFull() << endl;

    // a.pop();
    // a.pop();

    // a.print();
    // cout << "the size is: " << a.getSize() << endl;

    return 0;
}