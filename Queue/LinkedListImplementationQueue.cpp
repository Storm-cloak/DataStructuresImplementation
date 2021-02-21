#include <iostream>
#include <stdexcept>
//   | -> | -> | -> |-> |
//front                back
struct node
{
    int data;
    node *next;
};

class Queue
{
private:
    node *front, *back;
    int len;

public:
    Queue()
    {
        front = nullptr;
        back = nullptr;
        len = 0;
    };
    void push_back(int value)
    {
        node *tmp = new node;
        tmp->data = value;

        //if Queue is empty then front = back = newNode;
        if (len == 0)
        {
            front = back = tmp;
            len++;
            return;
        }
        back->next = tmp;
        back = tmp;
        len++;
    };
    void pop_front()
    {
        //if queue is empty then throw error
        if (front == nullptr)
        {
            std::cout << "Underflow" << '\n';
            return;
        }
        // store prev front and move front one node ahead
        node *tmp = new node();
        tmp = front;
        front = front->next;

        // if after front movement, front becomes NULL (means that front was equal to back)
        // then equate back to NULL
        if (front == nullptr)
        {
            back == nullptr;
        }
        len--;
        delete tmp;
    };

    int size()
    {
        return len;
    };
    // if queue is empty returns true
    bool empty()
    {
        if (len == 0)
        {
            return 1;
        }
        return 0;
    };
    int get_front()
    {
        if (front)
        {
            return front->data;
        }
        throw std::out_of_range("Queue is empty");
    }

    int get_back()
    {
        if (back)
        {
            return back->data;
        }
        throw std::out_of_range("Queue is empty");
    }
};

// QUEUE methods: FIFO - first in first out
//   +empty
//   +len
//   +front
//   +back
//   +push_back
//   +pop_front

int main()
{
    Queue Q;
    Q.push_back(5);
    Q.push_back(2);
    Q.push_back(10);
    Q.pop_front();
    int f = Q.get_front();
    std::cout << f << '\n';
    std::cout << Q.size() << '\n';
};