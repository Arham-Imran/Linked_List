#ifndef __Linked_List__
#define __Linked_List__
#include <iostream>

namespace ll
{
    template <class T>
    struct Node
    {
        T val;
        Node<T>* next;
        Node(T a) : val(a), next(nullptr) {}
    };

    template <class T>
    class Linked_List
    {
        private:
        Node<T>* head;

        public:
        Linked_List();
        ~Linked_List();
        void insert_at_start(T);
        void insert_at_end(T);
        void insert_at_pos(T, int);
        void delete_at_start();
        void delete_at_end();
        void delete_at_pos(int);
        Node<T>* search(T);
        int list_length();
        T& operator[](int);
        void print();
    };

    template <class T>
    Linked_List<T>::Linked_List() : head(nullptr) {}

    template <class T>
    Linked_List<T>::~Linked_List()
    {
        if(head == NULL)
        {
            return;
        }
        else
        {
            Node<T>* temp = NULL;
            while(head != NULL)
            {
                temp = head;
                head = head->next;
                delete temp;
            }
        }
    }

    template <class T>
    void Linked_List<T>::insert_at_start(T new_data)
    {
        Node<T>* temp = new Node(new_data);
        temp->next = head;
        head = temp;
    }

    template <class T>
    void Linked_List<T>::insert_at_end(T new_data)
    {
        if(head == NULL)
        {
            Node<T>* temp = new Node(new_data);
            temp->next = head;
            head = temp;
        }
        else
        {
            Node<T>* temp = head; 
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = new Node(new_data);
        }
    }

    template <class T>
    void Linked_List<T>::insert_at_pos(T new_data, int pos)
    {
        if(head == NULL)
        {
            Node<T>* temp = new Node(new_data);
            temp->next = head;
            head = temp;
        }
        else if(pos == 0)
        {
            insert_at_start(new_data);
        }
        else if(pos > 0)
        {
            Node<T>* temp = head; 
            for(int i = 1; i < pos; i++)
                temp = temp->next;
            Node<T>* temp1 = temp->next;
            temp->next = new Node(new_data);
            (temp->next)->next = temp1;
        }
    }

    template <class T>
    void Linked_List<T>::delete_at_start()
    {
        if(head == NULL)
            return;
        else
        {
            Node<T>* temp = head->next;
            delete head;
            head = temp;
        }
    }

    template <class T>
    void Linked_List<T>::delete_at_end()
    {
        if(head == NULL)
            return;
        else if(head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node<T>* temp = head;
            while((temp->next)->next != NULL)
                temp = temp->next;
            delete temp->next;
            temp->next = NULL;
        }
    }

    template <class T>
    void Linked_List<T>::delete_at_pos(int pos)
    {
        if(head == NULL)
            return;
        else if(pos == 0)
        {
            delete_at_start();
        }
        else
        {
            Node<T>* temp = head;
            for(int i = 1; i < pos; i++)
                temp = temp->next;
            Node<T>* temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
        }
    }

    template <class T>
    Node<T>* Linked_List<T>::search(T search_val)
    {
        if(head == NULL)
        {
            return NULL;
        }
        else
        {
            Node<T>* temp = head;
            while(temp->next != NULL)
            {
                if(temp->val == search_val)
                    return temp;
                temp = temp->next;
            }
            return NULL;
        }
    }

    template <class T>
    int Linked_List<T>::list_length()
    {
        int length = 0;
        Node<T>* temp = head;
        while(temp != NULL)
        {
            temp = temp->next;
            length++;
        }
        return length;
    }

    template<class T>
    T& Linked_List<T>::operator[](int index)
    {
        Node<T>* temp = head;
        for(int i = 0; i < index; i++)
            temp = temp->next;
        return temp->val;
    }

    template <class T>
    void Linked_List<T>::print()
    {
        Node<T>* temp = head;
        while(temp != NULL)
        {
            std::cout << temp->val << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
}

#endif