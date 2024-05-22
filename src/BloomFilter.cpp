#include <iostream>
#include <vector>
#include <string>
#include "IHash.h"
#include "BloomFilter.h"
using namespace std;


    //constructor
   BloomFilter :: BloomFilter(int size): arrayOfBitsSize(size) {
        arrayOfBits = new char[size];
        // Initialize arrayOfBits with '0'
        for (int i = 0; i < size; ++i) {
            arrayOfBits[i] = '0';        }

    }

    //destructor
   BloomFilter::~BloomFilter() {
        delete[] arrayOfBits;
        // No need to delete urlList, as std::vector handles its own memory
    }

    // Returns the bloomFilter array size.
    int BloomFilter:: getArrayOfBitsSize() {
        return arrayOfBitsSize;
    }

    // Returns the bloomFilter array.
    char* BloomFilter:: getArrayOfBits() {
        return arrayOfBits;
    }

    // Returns the dynamic URL list.
    vector<string>& BloomFilter:: getUrlList() {
        return urlList;
    }
