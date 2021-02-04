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
            tail = tail->next;
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
        Node *tmp = new Node();
        Node *current = new Node();
        Node *prev = new Node();
        current = head;
        for (int i = 0; i < index; ++i) //0 1
        {
            prev = current;          //1stIt    prev = head = 4, 2ndIt   prev = 2
            current = current->next; //1stIT current = 2 , 2ndIt current = 1;
        }
        tmp->data = value;
        prev->next = tmp;
        tmp->next = current;
        length += 1;
        // 4 -> 2 -> 1 ->5    4 -> 2 -> 6 -> 1  -> 5
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
    }
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
    LinkedList L;
    L.prepend(2);
    L.append(1);
    L.append(5);
    L.prepend(4);
    L.insert(2, 6);
    L.display();
    std::cout << L.length - 1 << " element = ";
    L.get(L.length - 1);
    L.erase(1);
    L.reverse();
    L.display();
    std::cout << L.length << '\n';
    return 0;
}