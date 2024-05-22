#ifndef FOOBAR_H
#define FOOBAR_H

#include "BloomFilter.h"
#include "IHash.h"
#include "Hash1.h"
#include "Hash2.h"
#include "BloomFilterMenu.h"
#include <iostream>
#include <vector>

class FooBar {
public:
    static void run();
    static void deleteAllHashFunction(vector <IHash*> hash);
    static std::vector<IHash*> allHashFunction(vector <int>  inputUser);
    };

#endif // FOOBAR_H