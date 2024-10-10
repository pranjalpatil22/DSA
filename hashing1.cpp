#include <iostream>
#include <vector>
using namespace std;

// Hash Table class for Linear Probing
class HashTableProbing {
    int bucketSize;
    vector<pair<int, int>> table; // Vector to store <StudentID, Score>
    vector<bool> isOccupied; // To track if a slot is occupied

    // Hash function
    int hashFunction(int key) {
        return key % bucketSize;
    }

public:
    // Constructor to initialize hash table
    HashTableProbing(int size) {
        bucketSize = size;
        table.resize(bucketSize, {-1, -1}); // Initialize table
        isOccupied.resize(bucketSize, false);
    }

    // Insert a new student record into the hash table
    void insertItem(int key, int value) {
        int index = hashFunction(key);
        int originalIndex = index;

        // Find next available slot
        while (isOccupied[index]) {
            index = (index + 1) % bucketSize;
            if (index == originalIndex) {
                cout << "Hash table is full!" << endl;
                return;
            }
        }
        table[index] = {key, value};
        isOccupied[index] = true;
    }

    // Delete a student record by key
    void deleteItem(int key) {
        int index = hashFunction(key);
        while (isOccupied[index]) {
            if (table[index].first == key) {
                table[index] = {-1, -1};
                isOccupied[index] = false;
                return;
            }
            index = (index + 1) % bucketSize;
        }
        cout << "Record not found!" << endl;
    }

    // Display the hash table
    void displayHash() {
        for (int i = 0; i < bucketSize; i++) {
            cout << i << ": ";
            if (isOccupied[i]) {
                cout << "[ID: " << table[i].first << ", Score: " << table[i].second << "]";
            } else {
                cout << "Empty";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "prepared by 23ce114 pranjal" << endl;
    // Hash table with size 7 (prime number larger than 6)
    HashTableProbing htp(7);

    // Insert student records
    htp.insertItem(231, 123);
    htp.insertItem(326, 432);
    htp.insertItem(212, 523);
    htp.insertItem(321, 43);
    htp.insertItem(433, 423);
    htp.insertItem(262, 111);

    cout << "Hash Table after insertion (Probing):" << endl;
    htp.displayHash();

    // Delete a student record
    htp.deleteItem(212);

    cout << "\nHash Table after deletion (Probing):" << endl;
    htp.displayHash();

    return 0;
}
