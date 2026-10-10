#pragma once
#include <ostream>
#include <string>

#include "Card.h"
#include "Stack.h"

class Player
{
public:
    Player(int id, const std::string& name)
    : id_(id)
    , name_(name)
    {}
    
    Stack<Card>& getDeck()
    {
        return deck_;
    };
    
    bool operator==(const Player& other) const
    {
        return id_ == other.id_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& p)
    {
        return out << p.id_ << " " << p.name_;
    }

private:
    int id_;
    std::string name_;
    Stack<Card> deck_;
};
