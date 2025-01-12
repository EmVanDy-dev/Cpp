#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm> // Include this header for std::find

using namespace std;

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
            cout << "Index " << i << ": ";
            for (const auto& key : table[i]) {
                cout << key << " -> ";
            }
            cout << "nullptr" << endl;
        }
    }
};

int main() {
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

    // use for ccount char and  convert it into number of code
    // const string& key = "apple";
    // int hash = 0;
    // for(char ch : key){
    //     hash = ch;
    //     cout<<hash<<" ";
    // }
    // cout<<hash;
    return 0;
}
