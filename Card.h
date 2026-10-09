//
// Created by Ryan Bond on 10/5/26.
//

#pragma once

#pragma once
#include <ostream>
#include <string>

class Card
{
public:
    Card(std::string& color, std::string& rank)
        : color_(color)
        , rank_(rank)
    {}
    
    friend std::ostream& operator<<(std::ostream& out, const Card& c)
    {
        return out << c.rank_ << " " << c.color_;
    }
    
private:
    std::string color_;
    std::string rank_;
};