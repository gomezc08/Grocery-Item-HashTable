#include <iostream>
#include <string>
using namespace std;

#include "Node.cpp"
#include "Bucket.cpp"
#include "Hash_table.cpp"

int main()
{
    //Instances of classes
    Hash_table H;
    //Set-up
    cout << "Fixed size HashTable of 100" << endl;
    cout << "\nYou will be entering a list of grocery items and it's corresponding price, which will be placed into a hashtable (sku) based on the characters of the item.";
    cout << "\nType \"stop\" at any point to end the simulation." << endl;

    //user interactive part
    string word;
    float price;
    bool cont = true;
    do {
        cout << "\n\tEnter a grocery item: ";
        cin >> word;
        int sku = 0;
        if(word != "stop") {
            int sum = H.sumOfCharacters(word);
            sku = H.bucketIndex(sum);
        }
        else {
            cont = false;
            break;
        }
        cout << "\tEnter price of " << word << ": $";
        cin >> price;
        cout << "\t\tPlaced into bucket " << sku << endl;
        H.insertNode(word, price, sku);
    }
    while(cont == true);

    H.displayHashtable();

    return 0;
}
