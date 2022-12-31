#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Node.cpp"

#ifndef NULL
#define NULL    0
#endif // NULL

#ifndef BUCKET
#define BUCKET

class Bucket: public Node {
    private:
        Node* first;    //Pointer to first node in bucket.
        Node* last;     //Pointer to last node in bucket.

    public:

        //Default constructor - initializes pointer first to NULL.
        Bucket() {
            first = NULL;
            last = NULL;
        }

        //pre - takes in a node pointer.
        //post - reassigns first node; returns nothing.
        Bucket(Node* f, Node* l) {
            first = f;
            last = l;
        }

        //pre - takes in a node pointer.
        //post - reassigns first node; returns nothing.
        void setFirst(Node* f) {
            first = f;
        }

        //pre - Nothing.
        //post - returns first.
        Node* getFirst() {
            return first;
        }

        //pre - takes in a pointer to a node which represents the first node.
        //post - returns the value of the first Node.
        string getFirstValue(Node* n) {
            return n->name;
        }


        //pre - takes in a pointer to a node which represents the node.
        //post - returns the price of the Node.
        float getFirstPrice(Node* n) {
            return n->price;
        }


        //pre - takes in a string that represents the word typed by the user.
        //post - appends the new made node to the end within a certain bucket in the hashtable; returns nothing.
        void appendToEnd(string n, float p) {
            Node* newNode = new Node();
            newNode->name = n;
            newNode->next = NULL;
            newNode->price = p;

            if(first == NULL) {
                first = newNode;
                first->next = NULL;
            }
            else {
                Node* current = first;
                while(current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
};

#endif // BUCKET
