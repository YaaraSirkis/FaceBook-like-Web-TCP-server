#include "BloomFilter.h"
#include "IHash.h"
#include "ICommand.h"
#include "AddCommand.h"
#include "SearchCommand.h"
#include "BloomFilterMenu.h"
#include "InputCheck.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

    // this function start to run the bloomFilter menu.
    // and do the command the user whans in the bloonFilter.
    void BloomFilterMenu :: start(BloomFilter * bloomFilter, vector <IHash*> hash){
        bool foreverLoop = true;
        map <int, ICommand*> commands= BloomFilterMenu:: initCommandMenu();
        while (foreverLoop){
            string line;
            //get a line from the user.
            getline(cin,line);
            bool valid = InputCheck:: inputValidityCheck(line);
            //if the input is not valid - continue.
            if (!valid){
                continue;
            }
            istringstream iss(line);
            int number;
            string URL;
            iss >> number >> URL;
            commands[number]->execute(bloomFilter,URL,hash);
        }
        BloomFilterMenu::deleteCommands(commands);
    }


    //this function initialize a map that contains all the command that possible.
    map <int, ICommand*> BloomFilterMenu::initCommandMenu(){
        map <int, ICommand*> commands;
        ICommand * add = new AddCommand();
        commands [1] = add;
        ICommand * search = new SearchCommand();
        commands [2] = search;
        return commands;
    }

    //this function delete all the command that we create in the end.
    // it will iterate over the map using a range-based for loop.
    //'com.second' is the value
     void BloomFilterMenu:: deleteCommands(map <int, ICommand*> commands){
        for (const auto& com : commands) {
            delete com.second;
        }
    }