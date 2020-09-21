// Name:
// USC NetID:
// CSCI 455 PA5
// Spring 2020


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}




//*************************************************************************
// put the function definitions for your list functions below
bool addNode(ListType & list, string target, int value) {
   if(findNode(list,target)) {return false;}               //if node exist, return false
   if(!list) {
      list = new Node(target, value);      //add a node to empty list
   }
   else {
      ListType iter = list;
      while(iter->next) {
         iter = iter->next;
      }
      Node* temp = new Node(target, value);
      iter->next = temp; 
   }
   return true;
}

bool removeNode(ListType & list, std::string target) {
   if(!list) {return false;}
   if(list->key == target) {   // case when removing the first node
      ListType temp = list;
      list = list->next;
      delete temp;
      return true;
   }
   for (ListType curr = list; curr->next != NULL; curr = curr->next) {
      if(curr->next->key == target) {      //delete node
         ListType temp = curr->next;
         curr->next = curr->next->next;
         delete temp;
         return true;
      }
   }
   return false;
}


int* findNode(ListType list, string target) {
   ListType curr = list;
   while(curr) {
      if(curr->key == target) {
         return &curr->value;
      }
      curr = curr->next;
   }
   return NULL; 
}

bool updateNode(ListType & list, std::string target, int newVal) {
   ListType temp = findNode(list, target);
   if(temp) {
      temp->value = newVal;
      return true;
   }
   else {
      return false;
   }
}

void printNode(ListType list) {
   while(list) {
      cout << list->key << " " << list->value << endl;
      list = list->next;
   }
}


int numNode(ListType list) {
   int count = 0;
   ListType curr = list;
   while(curr) {
      count++;
      curr = curr->next;
   }
   return count;
}
