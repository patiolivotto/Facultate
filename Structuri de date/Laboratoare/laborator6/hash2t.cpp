#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

template <typename T>
class SimpleHash {
private:
    // data
    T* m_pData;
    // hash table size
    unsigned int m_size;

    // djb2 hash function
    unsigned int djb2(const char* key) {
        unsigned int hash = 5381;

        for (unsigned int i = 0; i < strlen(key); i++)
            hash = ((hash << 5) + hash) + (unsigned int)key[i];

        return hash % m_size;
    }

public:
    SimpleHash(unsigned int size): m_size(size) {
        // init hash table data given table size
        m_pData = new T[m_size];
    }

    ~SimpleHash() {
        delete[] m_pData;
    }

    void set(const char* key, const T& value) {
        unsigned int index = djb2(key);
        std::cout << "set " << index << ": " << value  << std::endl;
        m_pData[index] = value;
    }

    T get(const char* key) {
        unsigned int index = djb2(key);
        std::cout << "get " << index << std::endl;
        return m_pData[index];
    }
};

int main() {

    SimpleHash<float> hash(50);

    hash.set("Hello", 12.5);
    hash.set("World", 22.5);

    std::cout << hash.get("Hello") << std::endl;
    std::cout << hash.get("World") << std::endl;

    return 0;
}
