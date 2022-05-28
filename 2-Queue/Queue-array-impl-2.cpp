#include <iostream>
#include <string>

using namespace std;

class Etudiant
{
private:
    string prenom;
    string nom;
    string niveau;
    int age;

public:
    Etudiant()
    {
        prenom = "Pas de Prenom";
        nom = "Pas de Nom";
        niveau = "ENSA";
        age = 18;
    }
    Etudiant(string prenom, string nom, string niveau, int age)
    {
        this->prenom = prenom;
        this->nom = nom;
        this->niveau = niveau;
        this->age = age;
    }
    string getPrenom()
    {
        return prenom;
    }
    string getNom()
    {
        return nom;
    }
    string getNiveau()
    {
        return niveau;
    }
    int getAge()
    {
        return age;
    }
};

template <class t>
class Queue
{
private:
    t *tab;
    int front, rear, size, max;

public:
    Queue()
    {
        max = 100;
        size = 0;
        front = 0;
        rear = max - 1;
        tab = new t[max];
    }
    Queue(int max)
    {
        this->max = max;
        size = 0;
        front = 0;
        rear = this->max - 1;
        tab = new t[this->max];
    }
    ~Queue()
    {
        size = front = rear = max = 0;
        delete[] tab;
    }
    void enqueue(t a)
    {
        if (!isFull())
        {
            size++;
            rear = (rear + 1) % max;
            tab[rear] = a;
        }
        else
        {
            cout << endl
                 << "Queue is Full" << endl;
            //  << "Queue is Full No Place to add: " << a << endl;  // for other types you need to overload << operator
        }
    }
    t dequeue()
    {
        if (!isEmpty())
        {
            size--;
            front = (front + 1) % max;
            return tab[front];
        }
        cout << endl
             << "Queue is empty nothing to dequeue" << endl;
        t a;
        return a;
    }
    bool isFull()
    {
        return (size == max);
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    int getSize()
    {
        return size;
    }
    t getFront()
    {
        if (!isEmpty())
        {
            return tab[front];
        }
        cout << endl
             << "Queue is Empty front doesn't hold anything" << endl;
        return false;
    }
    t getRear()
    {
        if (!isEmpty())
        {
            return tab[rear];
        }
        cout << endl
             << "Queue is Empty Rear doesn't hold anything" << endl;
        return false;
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
                 << "Queue: " << endl;
            int i;
            for (i = front; i != rear; i = (i + 1) % max)
            {
                cout << tab[i] << endl;
            }
            cout << tab[i] << endl
                 << "End" << endl; // tab[rear]  the loop didn't print the last element 'cause rear contradicts the loop condition
            return;
        }
        cout << endl
             << "The Queue is Empty" << endl;
    }
    int search(int person)
    {
        if (!isEmpty())
        {
            for (int i = front; i != rear; i = (i + 1) % max)
            {
                if (tab[i] == person)
                {
                    return i;
                }
            }
            if (tab[rear] == person)
                return rear;
        }
        return -1;
    }
};

int main()
{
    Etudiant e2("Ahachi", "Hossain", "Genie info", 24);
    Etudiant e3("Ahachi", "Mohamed", "Genie info", 24);
    Etudiant e4("Ahachi", "Said", "Genie info", 24);
    Etudiant e5("Ahachi", "Yassin", "Genie info", 24);

    Queue<Etudiant> q(9);
    q.enqueue(e2);
    q.enqueue(e3);
    q.enqueue(e4);
    // q.enqueue(e5);
    // q.enqueue();
    // q.enqueue();
    // q.enqueue();

    cout << endl
         << "age: "
         << (q.dequeue()).getAge() << endl;

    // q.dequeue();
    // q.dequeue();
    // q.dequeue();
    // q.dequeue();
    // q.dequeue();
    // q.dequeue();

    // q.print();
    // cout << q.search(6);
    // cout << endl
    //      << "Rear is: " << q.getRear() << endl;
    // cout << endl
    //      << "Front is: " << q.getFront() << endl;
    cout << endl
         << "Queue Size is: " << q.getSize();

    cout << endl
         << "fin du programme";
    return 0;
}
