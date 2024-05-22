// BloomFilter.h

#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <iostream>
#include <vector>
#include <string>
#include "IHash.h"

class BloomFilter {
private:
    int arrayOfBitsSize;
    char* arrayOfBits;
    // Use vector for a dynamic array of URLs, because amount of urls we get is unknown
    vector<string> urlList;

public:
    BloomFilter(int size);

    ~BloomFilter();

    int getArrayOfBitsSize ();

    char* getArrayOfBits();

    vector<string>& getUrlList();
};

#endif // BLOOMFILTER_H
