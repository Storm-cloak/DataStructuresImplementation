#include <iostream>
#include <assert.h>
class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head, *tail;

public:
    int length = 0;
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void append(int value)
    {
        Node *tmp = new Node();
        tmp->data = value;
        tmp->next = nullptr;
        if (head == nullptr)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
        length += 1;
    }

    void prepend(int value)
    {
        Node *tmp = new Node();
        tmp->data = value;
        tmp->next = nullptr;
        if (head == nullptr)
        {
            tail = tmp;
            head = tmp;
        }
        else
        {
            tmp->next = head;
            head = tmp;
        }
        length += 1;
    }

    void display()
    {
        if (head == nullptr)
        {
            std::cout << "List is empty" << '\n';
            return;
        }
        else
        {
            Node *temp = new Node();
            temp = head;
            while (temp != nullptr)
            {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << '\n';
        }
    }

    void insert(int index, int value)
    {
        Node *current = new Node();
        current->data = value;
        current->next = nullptr;
        if (head == nullptr)
        {
            head = current;
            tail = current;
        }
        else if (index == 0) // insert before head
        {
            current->next = head;
            head = current;
        }
        else if (index == length) // insert after tail
        {
            tail->next = current;
            tail = current;
        }
        else
        {
            Node *prev = new Node();
            Node *tmp = new Node();
            current = head;
            for (int i = 0; i < index; ++i) //0 1
            {
                prev = current;          //1stIt    prev = head = 4, 2ndIt   prev = 2
                current = current->next; //1stIT current = 2 , 2ndIt current = 1;
            }
            tmp->data = value;
            prev->next = tmp;
            tmp->next = current;
        }
        length += 1;
        // 4 -> 2 -> 1 ->5    4 -> 2 -> 6 -> 1  -> 5

        // insert(3,6):  4 -> 2 -> 1         4 -> 2 -> 1 -> 6
        // 0    1    2   3
    }
    void erase(int index)
    {
        Node *current = new Node();
        Node *prev = new Node();
        current = head;
        if (index == 0)
        {
            head = current->next;
            delete current;
            return;
        }
        else if (index < 0)
        {
            std::cout << "not valid index, maybe you use negative value or value greater than the length of the Linked list" << '\n';
            assert(index >= 0);
            return;
        }
        for (int i = 0; i < index; ++i)
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        delete current;
        length -= 1;
    }
    void reverse()
    {
        Node *current = head;
        Node *nextnode = NULL;
        Node *prevnode = NULL;
        while (current != NULL)
        {
            // Store next
            nextnode = current->next;
            // Reverse current node's pointer
            current->next = prevnode;
            // Move pointers one position ahead.
            prevnode = current;
            current = nextnode;
        }
        head = prevnode;
    } // 4 2 1 8
      //
    void get(int index)
    {

        if (head == nullptr)
        {
            std::cout << "List is empty" << '\n';
            assert(head != nullptr);
        }
        else if (index > length - 1 || index < 0)
        {
            std::cout << "Not valid index" << '\n';
            assert(index > 0 && index < length - 1);
        }
        Node *current = head;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        std::cout << current->data << '\n';
    }
};

int main()
{
    //Allocates some automatic memory, and creates an object in that
    //memory using its default constructor.
    //The memory is released automatically when the object goes out of scope.(Stack)
    LinkedList L;
    // Allocates some dynamic memory from the free store, and
    // creates an object in that memory using its default constructor.
    // Don't forget to delete it or the memory will be leaked.(Heap)
    LinkedList *L2 = new LinkedList();
    L.append(4);
    L.append(2);
    L.append(1);
    // L.append(5);
    L.insert(3, 6);
    L.append(5);
    L.display();
    L.prepend(4);
    L.display();
    // std::cout << L.length << " element = ";
    L.get(L.length - 1);
    L.reverse();
    L.display();
    std::cout << L.length << '\n';
    return 0;
}