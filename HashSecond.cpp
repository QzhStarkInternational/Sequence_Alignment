//
//  HashTableSet.cpp
//  DNASequenceAlignment
//
//  Created by Zihan Qu on 6/21/21.
//  Copyright © 2021 Zihan Qu. All rights reserved.
//

#include "Set.hpp"
#include "Set.hpp"
using namespace std;

HashSecond::HashSecond(unsigned int b) {
    this->tableBUCKET = b;
    table = new list<positionPlusSixKmer*>[tableBUCKET];
    this->index = 0;
}

HashSecond::~HashSecond() {
    for (unsigned int i = 0; i < this->tableBUCKET; i += 1) {
        positionPlusSixKmer *currentPartialKmer = this->table[i].front();
        delete currentPartialKmer;
    }
}
      
void HashSecond::insertItem(positionPlusSixKmer *secondPart) {
    table[this->index].push_back(secondPart);
    this->index += 1;
}
  
void HashSecond::displayHash() {
  for (int i = 0; i < tableBUCKET; i++) {
    cout << i;
    for (auto x : table[i])
      cout << " --> " << x->position;
    cout << endl;
  }
}

