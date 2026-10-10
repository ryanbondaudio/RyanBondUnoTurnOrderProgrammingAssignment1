#include <iostream>
#include <string>
#include "List.h"
#include "Player.h"
#include "Card.h"
#include "Stack.h"

using namespace std;


void playCard(const string& name, Stack<Card>& deck)
{
    cout << name << " plays ";
    Card* poppedCard1 = deck.pop(); 
    if (poppedCard1 != nullptr)
    {
        cout << *poppedCard1 << "\n\n";
        delete poppedCard1;
    }
    
}

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
    
    // Create List of players
    unique_ptr<List<Player>> unoGame1 = makeList<Player>();
    
    // Mathew is the first player
    unoGame1->addAnywhere(0, new Player(1, "Mathew"));
    
    // Create Mathew’s Deck of Uno Cards
    Stack<Card> mathewDeck;
    mathewDeck.push(new Card("Blue", "2"));
    mathewDeck.push(new Card("Red", "4"));
    mathewDeck.push(new Card("Blue", "Draw 2"));
    mathewDeck.push(new Card("Green", "8"));
    mathewDeck.push(new Card("Red", "9"));
    mathewDeck.push(new Card("Red", "5"));
    mathewDeck.push(new Card("Yellow", "7"));
    
    // Mark is the 2nd player
    unoGame1->addAnywhere(1, new Player(2, "Mark"));
    
    // Create Mark's deck
    Stack<Card> markDeck;
    markDeck.push(new Card("Blue", "1"));
    markDeck.push(new Card("Blue", "Reverse"));
    markDeck.push(new Card("Red", "3"));
    markDeck.push(new Card("Yellow", "3"));
    markDeck.push(new Card("Blue", "9"));
    markDeck.push(new Card("Green", "5"));
    markDeck.push(new Card("Red", "7"));
    
    // Luke is the 3rd player
    unoGame1->addAnywhere(2, new Player(3, "Luke"));
    
    // Create Luke's Deck
    Stack<Card> lukeDeck;
    lukeDeck.push(new Card("Yellow", "5"));
    lukeDeck.push(new Card("Red", "6"));
    lukeDeck.push(new Card("Blue", "Draw 2"));
    lukeDeck.push(new Card("Green", "8"));
    lukeDeck.push(new Card("Wild", "Draw 4"));
    lukeDeck.push(new Card("Green", "Skip"));
    lukeDeck.push(new Card("Red", "2"));
    
    cout << "Uno game initial order:\n";
    unoGame1->print();
    
    cout << "Mathews Deck: \n";
    mathewDeck.print();
    cout << "Mark's Deck: \n";
    markDeck.print();
    cout << "Luke's Deck: \n";
    lukeDeck.print();
    
    cout << "Begin Game: \n";
    playCard("Mathew", mathewDeck);
    playCard("Mark", markDeck);
    playCard("Luke", lukeDeck);
    
    // John joins Uno game and wants to go 3rd
    cout<< "John wants to play Uno with the others, but he wants to go 3rd.\n";
    
    // Initialize player John
    unoGame1->addAnywhere(2, new Player(4, "John"));
    
    // Initialize John's deck
    Stack<Card> johnDeck;
    
    johnDeck.push(new Card("Green", "2"));
    johnDeck.push(new Card("Red", "9"));
    johnDeck.push(new Card("Blue", "1"));
    johnDeck.push(new Card("Yellow", "Draw 2"));
    johnDeck.push(new Card("Yellow", "2"));
    johnDeck.push(new Card("Yellow", "Skip"));
    johnDeck.push(new Card("Blue", "Skip"));
    
    unoGame1->print();
    
    playCard("Mathew", mathewDeck);
    playCard("Mark", markDeck);
    
    cout << "Mark reverses the order! \n";
    std::cout << "Order before mark reverses:\n";
    unoGame1->print();
    std::cout << '\n';
    std::cout << "Order after Mark Reverses:\n";
    unoGame1->reverse();
    unoGame1->print();
    
    cout << "Luke's turn!\n";
    playCard("Luke", lukeDeck);
    
    cout << "--Skip John-- \n\n";
    playCard("Mark", markDeck);
    playCard("Mathew", mathewDeck);
    
    
    
    
    
    cout << "Luke plays a wild draw 4 card, so John rage quits.\n";
    unoGame1->deleteAnywhere(1);
    unoGame1->print();
    
    cout << "Second Uno game wants to join:\n";
    std::unique_ptr<List<Player>> unoGame2 = makeList<Player>();
    unoGame2->addAnywhere(0, new Player(5, "Paul"));
    unoGame2->addAnywhere(1, new Player(6, "Silas"));
    unoGame2->addAnywhere(2, new Player(7, "Timothy"));
    unoGame2->print();
    std::cout << "The two games before concat:\n";
    unoGame1->print();
    unoGame2->print();
    
    std::cout << "The two lists after concat:\n";
    unoGame1->concat(unoGame2.get());
    unoGame1->print();
    unoGame2->print();
    
    return 0;
}
