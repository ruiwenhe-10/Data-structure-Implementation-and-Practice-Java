// Name:
// USC NetID:
// CSCI 455 PA5
// Spring 2020

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
   hashSize = HASH_SIZE; 
   hashTable = new ListType[hashSize];
   numWord = 0;
}


Table::Table(unsigned int hSize) {
   hashSize = hSize; 
   hashTable = new ListType[hashSize];
   numWord = 0;
}


int * Table::lookup(const string &key) {
   return findNode(hashTable[hashCode(key)],key);
}

bool Table::remove(const string &key) {
   --numWord;
   return removeNode(hashTable[hashCode(key)],key);  
}

bool Table::insert(const string &key, int value) {
   numWord++;      
   return addNode(hashTable[hashCode(key)],key,value);  
}

bool Table::update(const std::string &key, int value) {
   return updateNode(hashTable[hashCode(key)], key, value);
}

int Table::numEntries() const {
   return numWord;
}


void Table::printAll() const {
   for (unsigned int i = 0; i < hashSize; i++) {
      if(hashTable[i]) {   //if list is not null
         printNode(hashTable[i]);
      }
   }
}

void Table::hashStats(ostream &out) const {
   int longest_chain = 0;
   int nonem_buckets = 0;
   for (unsigned int i = 0; i < hashSize; i++) {
      if(hashTable[i]) {   //if list is not null
         nonem_buckets++;
         if(numNode(hashTable[i])>longest_chain) {
            longest_chain=numNode(hashTable[i]);
         }
      }
   }
   out << "number of buckets: " << hashSize << endl;
   out << "number of entries: " << numWord << endl;
   out << "number of non-empty buckets: " << nonem_buckets << endl;
   out << "longest chain: " << longest_chain << endl;
}


// add definitions for your private methods here
