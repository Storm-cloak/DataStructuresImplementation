#include <iostream>
#include <assert.h>
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
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
        tmp->prev = nullptr;
        if (head == nullptr)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tmp->prev = tail;
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
        tmp->prev = nullptr;
        if (head == nullptr)
        {
            tail = tmp;
            head = tmp;
        }
        else
        {
            tmp->next = head;
            head->prev = tmp;
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
        if (index < 0 || index > length)
        {
            std::cout << "not valid index, maybe you use negative value or value greater than the length of the Linked list" << '\n';
            assert(index >= 0);
            return;
        }
        Node *current = new Node();
        current->data = value;
        current->next = nullptr;
        current->prev = nullptr;
        if (head == nullptr)
        {
            head = current;
            tail = current;
        }
        else if (index == 0) // insert before head
        {
            current->next = head;
            head->prev = current;
            head = current;
        }
        else if (index == length) // insert after tail
        {
            tail->next = current;
            current->prev = tail;
            tail = current;
        }
        else
        {
            current = head;
            for (int i = 0; i < index; i++) // 0  1
            {
                current = current->next;
            }
            Node *tmp = new Node();
            tmp->data = value;
            tmp->next = current;
            tmp->prev = current->prev;
            current->prev->next = tmp;
            current->prev = tmp;
        }
        length++;
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
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        length -= 1;
    }

    void reverse()
    {
        Node *temp = NULL;
        Node *current = new Node();
        current = head;
        while (current != NULL)
        {
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = temp;
        }
        temp = head;
        head = tail;
        tail = temp;
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
        //choose best option to search (from head or from tail)
        if (index + 1 <= length / 2)
        {
            Node *current = head;
            for (int i = 0; i < index; ++i)
            {
                current = current->next;
            }
            std::cout << current->data << '\n';
        }
        else
        {
            Node *current = tail;
            for (int i = length - 1; i > index; --i)
            {
                current = current->prev;
            }
            std::cout << current->data << '\n';
        }
    }
};

int main()
{
    LinkedList L;
    L.append(4);
    L.append(2);
    L.append(1);
    L.prepend(8);
    L.prepend(10);
    L.insert(3, 6);
    L.erase(2);
    L.get(4);
    L.display();
    L.reverse();
    L.display();
    // std::cout << L.length << '\n';
    return 0;
}