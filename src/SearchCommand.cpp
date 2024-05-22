#include "BloomFilter.h"
#include "IHash.h"
#include "ICommand.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "SearchCommand.h"
    //this function search if a givin url is in the bloomFilter, then check that
    // it is not a false=positive.
    void SearchCommand :: execute(BloomFilter* bloomFilter, string URL, vector <IHash*> hash){
        int hashResult;
        for (int i = 0; i< hash.size(); i++){
            hashResult = hash[i]->startHashing(URL, bloomFilter->getArrayOfBitsSize());
            if (bloomFilter->getArrayOfBits()[hashResult]=='0'){
                cout << "false" << endl;
                return;
            }
        }
        cout << "true";

        //if all the bits are 1 then print true and check for false positive:
        bool found = SearchCommand::searchInURLList(URL, bloomFilter->getUrlList());
        if(found){
            //true true
            cout << " true" << endl;
        }
        else {
            //true false
            cout << " false" << endl;
        }
    }


    //searching a url in the url's list, returns true if he was found. works good
    bool SearchCommand::searchInURLList(const string& URL, vector <string> urlList) {
        return find(urlList.begin(), urlList.end(), URL) != urlList.end();
    }
