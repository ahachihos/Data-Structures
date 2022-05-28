#include <iostream>
#include <string>
using namespace std;

template <class t>
class Queue
{
    struct node
    {
        t value;
        node *next;
    };

private:
    node *front, *rear;
    int size;

public:
    Queue()
    {
        front = rear = NULL;
        size = 0;
    }
    bool isEmpty()
    {
        return rear == NULL; // size == 0;
    }
    void print()
    {
        cout << endl;
        if (!isEmpty())
        {
            node *temp = front;
            while (temp != NULL)
            {
                cout << temp->value << endl;
                temp = temp->next;
            }
            return;
        }
        cout << "The Queue is Empty " << endl;
    }
    void enQueue(t a)
    {
        node *temp = new node; // Creation of the new node and assigning a value to it
        temp->value = a;
        temp->next = NULL;
        size++; // you have the choice to write it here or write it inside each block

        if (front == NULL)
        {
            front = rear = temp;
            // size++;
            return;
        }
        rear->next = temp;
        rear = temp;
        // size++;
    }
    t &deQueue()
    {
        if (!isEmpty())
        {
            node *temp = front;  // to Store the front in a temprory variable
            front = front->next; // move front to point on the next node

            // create a variable to store the return value 'cause the original one will be destroyed after the deletion
            t deQueueResult = new t; // if the return type is not a primitive dataType you should allocate memory for it
            deQueueResult = temp->value;
            delete (temp);
            size--;
            return deQueueResult;
        }
        cout << endl
             << "Queue is Empty nothing do deQueue" << endl;
        t a;
        return a;
    }
    t getFrontValue()
    {
        if (!isEmpty())
        {
            return front->value;
        }
        cout << endl
             << "The Queue is empty nothing to return";
        t a;
        return a;
    }
    t getRearValue()
    {
        if (!isEmpty())
        {
            return rear->value;
        }
        t a;
        return a;
    }
    int getSize()
    {
        return size;
    }
};

int main()
{
    Queue<string> q;
    q.enQueue("hossain");
    q.enQueue("Mohamed");
    q.enQueue("Said");
    q.enQueue("Youssra");

    q.print();
    cout << endl
         << q.getRearValue();
    // cout << endl
    //      << q.isEmpty() << endl;
    cout << endl
         << "Queue Size: " << q.getSize() << endl;

    cout << endl
         << "Fin du programme";

    return 0;
}