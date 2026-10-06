#include <iostream>
#include "List.h"
#include "Player.h"

int main()
{
    // ---- Part 1: required test harness, do not modify ----
    // std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
    //     << std::endl;
    // std::unique_ptr<List<int>> nums = makeList<int>();
    // nums->addFront(new int(10));
    // nums->addFront(new int(20));
    // nums->addFront(new int(30));
    // nums->print();
    // nums->addAnywhere(1, new int(99));
    // nums->print();
    // nums->deleteAnywhere(2);
    // nums->print();
    // nums->reverse();
    // nums->print();
    //
    //  std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    // std::unique_ptr<List<int>> more = makeList<int>();
    // more->addFront(new int(2));
    // more->addFront(new int(1));
    // more->print();
    // nums->concat(more.get());
    // nums->print();
    // more->print();
    
    // ---- Part 2: your Uno scene goes below ----
    
    std::unique_ptr<List<Player>> unoGame1 = makeList<Player>();
    
    std::cout << "Uno game initial order:\n";
    unoGame1->addAnywhere(0, new Player(1, "Mathew"));
    unoGame1->addAnywhere(1, new Player(2, "Mark"));
    unoGame1->addAnywhere(2, new Player(3, "Luke"));
    unoGame1->print();
    std::cout << '\n';
    
    std::cout<< "John wants to play Uno with the others, but he wants to go 3rd.\n";
    unoGame1->addAnywhere(2, new Player(4, "John"));
    unoGame1->print();
    std::cout << '\n';
    
    std::cout << "Mark plays a reverse card!\n";
    std::cout << "Order before mark reverses:\n";
    unoGame1->print();
    std::cout << '\n';
    std::cout << "Order after Mark Reverses:\n";
    unoGame1->reverse();
    unoGame1->print();
    std::cout << '\n';
    
    std::cout << "Luke plays a wild draw 4 card, so John rage quits.\n";
    unoGame1->deleteAnywhere(1);
    unoGame1->print();
    std::cout << '\n';
    
    std::cout << "Second Uno game wants to join:\n";
    std::unique_ptr<List<Player>> unoGame2 = makeList<Player>();
    unoGame2->addAnywhere(0, new Player(5, "Paul"));
    unoGame2->addAnywhere(1, new Player(6, "Silas"));
    unoGame2->addAnywhere(2, new Player(7, "Timmothy"));
    unoGame2->print();
    std::cout << '\n';
    
    std::cout << "The two lists before concat:\n";
    unoGame1->print();
    std::cout << '\n';
    unoGame2->print();
    std::cout << '\n';
    
    std::cout << "The two lists after concat:\n";
    unoGame1->concat(unoGame2.get());
    unoGame1->print();
    unoGame2->print();
    
    return 0;
}
