#include<bits/stdc++.h>



class HashTable {
private:
    <int>> table; // Stores the values
    int size;

    int hashFunction(int key) {
        return key % size; // Simple modulo hash function
    }

public:
    HashTable(int s) : size(s), table(s, std::nullopt) {}

    void insert(int key) {
        int index = hashFunction(key);

        // Linear probing
        while (table[index].has_value()) {
            index = (index + 1) % size; // Move to the next slot
        }

        table[index] = key;
        std::cout << "Inserted key " << key << " at index " << index << std::endl;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int start = index; // To avoid infinite loops

        while (table[index].has_value()) {
            if (table[index].value() == key) {
                return true;
            }

            index = (index + 1) % size;
            if (index == start) break; // Full cycle, key not found
        }

        return false;
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            if (table[i].has_value())
                std::cout << "Index " << i << ": " << table[i].value() << std::endl;
            else
                std::cout << "Index " << i << ": EMPTY" << std::endl;
        }
    }
};

int main() {
    HashTable ht(7); // Create a hash table of size 7

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(8);

    ht.display();

    int key = 15;
    if (ht.search(key)) {
        std::cout << "Key " << key << " found in the hash table." << std::endl;
    } else {
        std::cout << "Key " << key << " not found in the hash table." << std::endl;
    }

    return 0;
}

