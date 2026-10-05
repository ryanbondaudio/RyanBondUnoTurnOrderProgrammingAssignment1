//
// Created by Ryan Bond on 9/15/26.
//

#pragma once
#include "List.h"
#include <iostream>

template <typename T>
class ArrayList : public List<T>
{
public:
    /** Constructor sets size to 0 by default.*/
    ArrayList() : size_{0}
                , data_{} 
    {}

    void addFront(T* value) override
    {
        if (size_ >= CAPACITY) { std::cout << "ArrayList is full.\n";  return; }

        for (int i = size_; i > 0; --i) { data_[i] = data_[i - 1]; } 
        
        data_[0] = value;
        ++size_;
    }

    void deleteFront() override
    {
        if (size_ == 0) { std::cout << "ArrayList is empty.\n"; return; }

        for (int i = 0; i < size_ - 1; ++i) { data_[i] = data_[i + 1]; }
        --size_;
    }

    void addAnywhere(int position, T* value) override
    {
        if (size_ >= CAPACITY) { std::cout << "ArrayList is full.\n"; return; }
        
        if (position > size_) { std::cout << "Position is out of bounds.\n"; return; }
        
        if (position < 0) { std::cout << "Position cannot be negative.\n"; return; }
        
        if (position == 0) { addFront(value); return; }
        
        for (int i = size_; i > position; --i) { data_[i] = data_[i - 1]; }
        
        data_[position] = value;
        ++size_;
    }
    
    void deleteAnywhere(int position) override
    {
        if (position >= size_) { std::cout << "Position is out of bounds.\n"; return; }
        
        if (size_ == 0) { std::cout << "ArrayList is empty.\n"; return; }

        if (position < 0) { std::cout << "Position cannot be negative.\n"; return; }
        
        if (position == 0) { deleteFront(); return; }
        
        for (int i = position; i < size_ - 1; ++i) { data_[i] = data_[i + 1]; }
        --size_;
    }
    
    void reverse() override
    {
        if (size_ <= 1 || size_ > CAPACITY ) { std::cout << "List cannot be reversed.\n"; return; }
        
        for (int i = 0; i < size_ / 2; ++i)
        {
            int targetIndex = (size_ - 1) -  i;
            
            T* temp = data_[i];
            data_[i] = data_[targetIndex];
            data_[targetIndex] = temp;
        }
    }

    bool search(T* value) const override
    {
        for (int i = 0; i < size_; ++i)
        {
            if (*data_[i] == *value) return true;
        }
        return false;
    }

    void print() const override
    {
        for (int i = 0; i < size_; ++i)
        {
            std::cout << *data_[i] << (i != size_ - 1? ", " : "");
        }
        std::cout << '\n';
    }

    ~ArrayList() override
    {
        for (int i = 0; i < size_; ++i)
        {
            delete data_[i];
        }
    }

private:
    static const int CAPACITY = 20;
    T* data_[CAPACITY];
    int size_;
};
