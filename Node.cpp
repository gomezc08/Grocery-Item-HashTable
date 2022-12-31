#include <iostream>
#include<string>
using namespace std;

#ifndef NULL
#define NULL    0
#endif // NULL

#ifndef NODE
#define NODE

class Node {
    public:
        string name;   //Name of grocery item.
        float price;    //Price of grocery item.
        Node* next;     //Pointer to the next node.

        //Default constructor - initializes public variables name and next.
        Node() {
            name = "?";
            next = NULL;
            price = 0.0;
        }

        //pre - takes in a string, a price, and a pointer to a node.
        //post - reassigns the public variables name and next; returns nothing.
        Node(string na, Node* ne, float p) {
            name = na;
            next = ne;
            price = p;
        }
};

#endif // NODE