#include "BloomFilter.h"
#include "IHash.h"
#include "Hash1.h"
#include "Hash2.h"
#include "BloomFilterMenu.h"
#include "FooBar.h"
#include "InputCheck.h"
#include <iostream>
#include <vector>

using namespace std;


    //this function runs FooBar and initialize the bloom filter.
     void FooBar::run(){
        vector <int> inputUser = InputCheck::firstInputCheck();
        BloomFilter* bloomFilter = new BloomFilter(inputUser[0]);
        vector <IHash*> hash= allHashFunction(inputUser);
        BloomFilterMenu::start(bloomFilter,hash);

        //in the end delete all hash function
        deleteAllHashFunction(hash);
        //in the end - delete bloomFilter that was created on the heap.
        delete bloomFilter;

    }

    //this function delete all the function that we create in the end.
    // it will iterate over the vector using a range-based for loop.
     void FooBar:: deleteAllHashFunction(vector <IHash*> hash){
        for (auto& function : hash) {
            delete function;
        }
    }



    // this function initialize the hash vector with the hash function we eill use in
    // the corrent bloomFilter.
     vector <IHash*> FooBar::allHashFunction (vector <int> inputUser){
        vector <IHash*> hash;
        for (int i =1; i<inputUser.size();i++){
            if (inputUser.at(i)==1){
                hash.push_back(new Hash1());
                continue;
            }
            if (inputUser.at(i)==2){
                hash.push_back(new Hash2());
            }
        }

        return hash;
    }

