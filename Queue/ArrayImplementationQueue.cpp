#include <iostream>
#include <stdexcept>
class Queue
{
private:
    int front;    //index of front element
    int back;     //index of back(rear) element
    int capacity; //maximum possible size of queue
    int *arr;     //pointer to the array to store queue elements
    int len;      // count of the length of the queue

public:
    Queue(int max_size)
    {
        arr = new int[max_size]; // allocate memory for 'max_size' number of elements
        len = 0;                 // initialize length
        capacity = max_size;
        // -1 means Queue is empty
        front = -1;
        back = -1;
    };
    // Destructor to free allocated memory
    ~Queue()
    {
        delete[] arr;
    };

    //return the current size of queue
    int size()
    {
        return len;
    }

    // pretty straightforward
    bool isFull()
    {
        return back == capacity - 1 ? true : false;
    };

    bool isEmpty()
    {
        return (front == -1 && back == -1);
    };

    //add new element to the end of the queue
    void push_back(int value)
    {
        if (isFull())
        {
            throw std::out_of_range("Queue is full");
        }
        if (isEmpty())
        {
            front = back = 0;
        }
        else
        {
            back = back + 1;
        }
        arr[back] = value;
        len++;
    };

    //pop out from the queue the front element
    void pop_front()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Queue is empty");
        }
        front = front + 1;
        len--;
    }
    //show the front element
    int get_front()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Queue is empty");
        }
        return arr[front];
    }
    //show the back(rear) element
    int get_back()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Queue is empty");
        }
        return arr[back];
    }

    //for testing
    void Display()
    {
        std::cout << "Queue : ";
        for (int i = 0; i < size(); i++)
        {
            int index = (front + i) % capacity; // Index of element while travesing circularly from front
            std::cout << arr[index] << " ";
        }
        std::cout << "\n";
    }
};

// QUEUE methods: FIFO - first in first out
//   +empty
//   +size
//   +front
//   +back
//   +push_back
//   +pop_front

int main()
{
    // 5 2 10 22 30
    Queue Q(10);
    Q.push_back(5);
    Q.push_back(2);
    Q.push_back(10);
    Q.push_back(22);
    Q.push_back(25);
    Q.push_back(7);
    Q.push_back(20);
    Q.pop_front();
    Q.pop_front();
    // std::cout << Q.get_front() << ' ' << Q.get_back() << '\n';
    Q.Display();
    return 0;
};