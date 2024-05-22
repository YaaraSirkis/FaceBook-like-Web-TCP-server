
#include "ICommand.h"
#include "BloomFilter.h"
#include "AddCommand.h"
#include <vector>
using namespace std;

//this function run all the hash function and add the URL to the list.
//also the function update the bloomFilter acoording to the result of the hash function.
    void AddCommand :: execute(BloomFilter* bloomFilter, string URL, vector <IHash*> hash )  {
        int hashResult;
        for (int i = 0; i< hash.size(); i++){
            hashResult = hash[i]->startHashing(URL, bloomFilter->getArrayOfBitsSize());
            bloomFilter->getArrayOfBits()[hashResult]='1';
        }

        bloomFilter->getUrlList().push_back(URL);
    }