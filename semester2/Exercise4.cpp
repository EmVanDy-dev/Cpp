#include<bits/stdc++.h>
#include <vector>
#include <list>
#include <string>
#include <algorithm> // Include this header for std::find
// #include<iostream>
using namespace std;
class Hash{
    // No. of buckets
    int BUCKET;
    // Pointer to an array containing buckets
    list<int> *table;
    public:
    // Constructor
    Hash(int v);
    // inserts a key into hash table
    void insertItem(int x);
    // deletes a key from hash table 
    void deleteItem(int key);
    // hash function to map values to key
    int hashFunction(int x){
        return (x % BUCKET);
    }
    // function to display the hash table 
    void displayHash();
};
Hash::Hash(int b){ 
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}
void Hash::insertItem(int key){
    int index = hashFunction(key);
    table[index].push_back(key);
}
void Hash::deleteItem(int key){
    // get the hash index of key
    int index = hashFunction(key);
    // find the key in (index)th list
    list<int> :: iterator i;
    for(i = table[index].begin();
    i != table[index].end(); i ++){
        if(*i == key)
        break;
    }
    // if key is found in hash table , remove it
    if(i != table[index].end())
        table[index].erase(i);
}
void Hash::displayHash(){
    for (int i = 0 ; i< BUCKET ; i++){
        cout<<i;
        for(auto x : table[i])
            cout<<" -->"<<x;
        cout<<endl;
    }
}

// String

class HashTable {
private:
    vector<list<string>> table;
    int size;

    // Simple hash function
    int hashFunction(const string& key) const {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % size;
        }
        return hash;
    }

public:
    // Constructor to initialize the hash table with a specific size
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size);
    }

    // Function to insert a string into the hash table
    void insert(const string& key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Function to delete a string from the hash table
    void deleteKey(const string& key) {
        int index = hashFunction(key);
        auto& cell = table[index];
        auto it = std::find(cell.begin(), cell.end(), key); // Use std::find here
        if (it != cell.end()) {
            cell.erase(it);
        } else {
            cout << "Key not found: " << key << endl;
        }
    }

    // Function to display all strings in the hash table
    void display() const {
        for (int i = 0; i < size; ++i) {
            cout  << i << ": ";
            for (const auto& key : table[i]) {
                cout << key << " -> ";
            }
            cout << "nullptr" << endl;
        }
    }
};

int main(){
    Hash hash1(10);
    // insert
    hash1.insertItem(20);
    hash1.insertItem(11);
    hash1.insertItem(12);
    hash1.insertItem(23);
    hash1.insertItem(5);
    hash1.insertItem(17);
    hash1.insertItem(8);
    hash1.insertItem(9);
    // delete
    hash1.deleteItem(12);
    // insert data at the collision event
    hash1.insertItem(13);
    hash1.insertItem(57);
    hash1.displayHash();


    // string 
     HashTable hashTable(10);  // Create a hash table with 10 buckets

    // Insert some strings
    hashTable.insert("apple");
    hashTable.insert("banana");
    hashTable.insert("grape");
    hashTable.insert("orange");
    hashTable.insert("pear");

    // Display the hash table
    cout << "Hash Table:" << endl;
    hashTable.display();

    // Delete a string
    hashTable.deleteKey("banana");
    
    // Display the hash table again to see the result
    cout << "Hash Table after deletion:" << endl;
    hashTable.display();

    // Try to delete a string that does not exist
    hashTable.deleteKey("kiwi");


    return 0;
}