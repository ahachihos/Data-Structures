#include <iostream>
#include <string>

using namespace std;

class Queue
{
private:
    int *tab;
    int front, rear;
    int size;
    int max;

public:
    Queue()
    {
        try
        {
            this->max = 100;
            tab = new int[max];
            front = rear = 0;
            size = 0;
        }
        catch (const std::exception &e)
        {
            cout << "Memory allocation failed default constructor";
        }
    }
    Queue(int max)
    {
        try
        {
            this->max = max;
            tab = new int[this->max];
            front = rear = 0;
            size = 0;
        }
        catch (const std::exception &e)
        {
            cout << "Memory allocation failed in overloaded constructor";
        }
    }
    ~Queue()
    {
        delete (tab);
        front = rear = 0;
        max = 0;
        size = 0;
    }
    void enQueue(int a)
    {
        if (!isFull())
        {
            tab[rear++] = a;
            size++;
        }
        else
        {
            cout << endl
                 << "The Queue is full; No place to enQueue: " << a << endl;
        }
    }
    int deQueue()
    {
        if (!isEmpty())
        {
            size--;
            return tab[front++];
        }
        cout << endl
             << "Queue is Empty nothing do deQueue" << endl;
        return false;
    }
    int getFront()
    {
        if (!isEmpty())
        {
            // size--;
            return tab[front];
        }
        cout << endl
             << "Queue is Empty no one is on front" << endl;
        return false;
    }
    int getRear()
    {
        if (!isEmpty())
        {
            // size--;
            return tab[rear - 1];
        }
        cout << endl
             << "Queue is Empty no one is in the back" << endl;
        return false;
    }
    bool isFull()
    {
        return (rear == max);
    }
    bool isEmpty()
    {
        return front == rear;
    }
    int getSize()
    {
        return size;
    }
    int getMax()
    {
        return max;
    }
    void print()
    {
        if (!isEmpty())
        {
            cout << endl
                 << "The Queue: ";
            for (int i = front; i < rear; i++)
            {
                cout << endl
                     << tab[i];
            }
            cout << endl
                 << "End" << endl;
            return;
        }
        cout << endl
             << "The Queue is Empty Nothing to print" << endl;
    }
};

int main()
{
    Queue q(5);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    // q.enQueue(6);
    // q.enQueue(7);
    // q.enQueue(7);

    // q.print();
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    // cout << q.deQueue();
    // q.deQueue();
    // q.deQueue();
    // q.deQueue();
    // q.deQueue();
    // q.deQueue();

    // q.print();
    cout << "Size: " << q.getSize();
    // cout << "hossain";

    return 0;
}