//
// Created by Ryan Bond on 9/17/26.
//

#pragma once
#include "Node.h"

template <typename T>
class LinkedList : public List<T>
{
public:
    LinkedList() : head_{nullptr}
                 , size_{0} 
    {}

    void addFront(T* value) override
    {
        Node<T>* fresh {new Node<T>(value)};
        fresh->next = head_;
        head_ = fresh;
        
        ++size_;
    }

    void deleteFront() override
    {
        if (head_ == nullptr) { std::cout << "LinkedList is empty.\n"; return; }
        
        Node<T>* doomed{head_};
        head_ = head_->next;
        
        delete doomed->data;
        delete doomed;
        
        --size_;
    }
    
    void addAnywhere(int position, T* value) override
    {
        if (position == 0) { addFront(value); return; }
        
        if (position < 0) { std::cout << "Position cannot be negative \n"; return; }
        
        Node<T>* current {head_};

        for (int i = 0; i < position - 1 && current != nullptr; i++) { current = current->next; }
        
        if (current == nullptr) { std::cout<< "Position out of bounds \n"; return; }
        
        Node<T>* fresh {new Node<T>(value)};
        fresh->next = current->next;
        current->next = fresh;
        
        ++size_;
    }
    
    void deleteAnywhere(int position) override
    {
        if (head_ == nullptr) { std::cout << "LinkedList is empty \n"; return; }
        
        if (position < 0) { std::cout << "Position cannot be negative \n"; return; }
        
        if (position == 0) { deleteFront(); return; }
        
        Node<T>* current {head_};

        for (int i = 0; i < position - 1 && current != nullptr; i++) { current = current->next; }

        if (current == nullptr || current->next == nullptr) { std::cout << "Position out of bounds \n"; return; }
        
        Node<T>* doomed{current->next};
        current->next = current->next->next;
        
        delete doomed->data;
        delete doomed;
        
        --size_;
    }

    bool search(T* value) const override
    {
        Node<T>* current = head_;
        while (current != nullptr)
        {
            if (*current->data == *value) return true;
            current = current->next;
        }
        return false;
    }
    
    void print() const override
    {
        Node<T>* current = head_;
        while (current != nullptr)
        {
            std::cout << *current->data << (current->next != nullptr ? ", " : "");
            
            current = current->next;
        }
        
        std::cout << '\n';
    }

    ~LinkedList() override
    {
        while (head_ != nullptr)
        {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }

private:
    Node<T>* head_;
    int size_;
};
