#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Bucket.cpp"

#ifndef NUM_BUCKET
#define NUM_BUCKET  100
#endif // NUM_BUCKET

#ifndef NULL
#define NULL    0
#endif // NULL

#ifndef HASH_TABLE
#define HASH_TABLE

class Hash_table: public Bucket {
    private:
        Bucket b[NUM_BUCKET];    //Creating an array with each bucket an index of the array

    public:

        //Default constructor - nothing performed here.
        Hashtable() {

        }

        //pre - takes in a string variable.
        //post - performs an algorithm by turning each character of the inputed string as it's corresponding Unicode value and returns its sum.
        int sumOfCharacters(string str) {
            char j;
            int i = 0;
            int sum = 0;
            while(i != str.length()) {
                j = str[i];
                sum += int(j);
                j = ' ';
                i++;
            }
            return sum;
        }

        //pre - takes in an integer representing the value or sum of a particular string or character.
        //post - returns the value based on the length of the hashtable.
        int bucketIndex(int sku) {
            return (sku % NUM_BUCKET);
        }

        //pre - takes in a string and its corresponding hashtable value.
        //post - Inserts a new node into a bucket in the array; returns nothing.
        void insertNode(string newName, float p, int sku) {
            b[sku].appendToEnd(newName, p);
        }

        //pre - Nothing.
        //post - loops through entire hashtable and prints its content; returns nothing.
        void displayHashtable() {
            int i = 0;
            while(i < (NUM_BUCKET + 1)) {
                cout << (i) << ": ";
                int j = i;
                Node* current = b[j].getFirst();     //Node of first
                while(current != NULL) {     //while there is an item...
                    string valueOfCurrent = b[j].getFirstValue(current);
                    float priceOfCurrent = b[j].getFirstPrice(current);
                    cout << valueOfCurrent << "($" << priceOfCurrent << ") -> ";
                    current = current->next;
                    //j++;
                }
                cout << endl;
                i++;
            }
        }
};

#endif // HASH_TABLE
