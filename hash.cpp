//Heitkemper, Peter
//hash.cpp
//3/15/2021

//******************************************************************************
#include "hash.h"
#include <string>

//Default constuctor
HashTable::HashTable() {
  courseCount = 0; //keeps track of courses in schedule
  i = 0;  //initilization not necessary
  key = 0;
  day ="";
  //dynamically create array of courseNode pointers 
  schedule = new CourseNode * [TABLE_SIZE];
  //initialize all pointers to null
  for (int i = 0; i < TABLE_SIZE; i++) {
  schedule[i] = nullptr;
  }
}

HashTable::~HashTable() {
  //delete every linked list at each index 
  for (int i = 0; i < TABLE_SIZE; i++) {
    deleteAll(schedule[i]);
  }
  delete [] schedule;
}

void HashTable::deleteAll(CourseNode* in) {
  if (!in) {  //base case
    delete in;
    in = nullptr;
    return;
  }else {
    deleteAll(in->getNext()); //recursive call
    delete in;
    in = nullptr;
  }
}

int HashTable::hashKey(long key) {
  //calculate index based on key
  //split 4 digit key into 2, two digit components, 
  //sum, divide by size of table, return remainder
  return ((key / 100 + key % 100) % TABLE_SIZE);
}

void HashTable::insert(long key, Course value) {
  int i = hashKey(key); //get hash table index
  CourseNode* current = schedule[i];
  while (current) {    //loop until nullptr is reached at end of list
    if (current->getKey() == key) { 
      std::cout << "The course is already on the schedule." << endl;
      return;
    }
    else if (!(current->getNext())) { //insert node if next is nullptr
      current->setNext(new CourseNode(key, value));//link new node
      courseCount++;
      //calculate and Print load factor
      float loadFactor = (float)courseCount / (float)TABLE_SIZE;
      std::cout << "The load factor is " << loadFactor << endl;
      return;
    } 
    else {
      current = current->getNext();//move forward in list
    }
  }  
  //Create courseNode at first index
  schedule[i] = new CourseNode(key, value);
  courseCount++;
  //calculate and Print load factor
  float loadFactor = (float)courseCount / (float)TABLE_SIZE;
  cout << "The load factor is " << loadFactor << endl;
}

string HashTable::remove(long key) {
  int i = hashKey(key);             //get hash table index
  if (schedule[i] == nullptr) {     //index empty
    return "";
  } else {
    CourseNode* current = schedule[i];
    CourseNode* nxtPtr = schedule[i]->getNext();
    //Occurs if course is head
    if (current->getKey() == key) {
      string removed = current->getTitle();//store title
      delete current; //remove
      schedule[i] = nxtPtr;
      courseCount--;
      return removed;
    } else {
      while (nxtPtr != nullptr) {    //course is within linked list
        if (nxtPtr->getKey() == key) {         
          string removed = nxtPtr->getTitle();
          current->setNext(nxtPtr->getNext());
          delete nxtPtr;
          nxtPtr = nullptr;
          courseCount--;
          return removed;
        } else {
          nxtPtr = nxtPtr->getNext();
        }
      }
     return "";//course not found
    }
  }
}

void HashTable::courseInfo(long key) {
  int i = hashKey(key);//get hash key
  CourseNode* current = schedule[i];
  while (current) {
    if (current->getKey() == key) {
      cout<<"CPSC "<<current->getCourseNo()<<" - "<<current->getTitle()<<endl;
      cout << current->getDate() << " " << current->getTime() << endl;
      cout << "Instructor: Prof. " << current->getInstructor() << endl;
      return;
    } else {
      current = current->getNext();//move forward in list
    }
  }
  cout<<"That course is not on the schedule." << endl;
  return;
}

void HashTable::printAll() {
  for (int i = 0; i < TABLE_SIZE; i++) { //loop through array
    CourseNode* current = schedule[i];
    while (current) {                    //print every node in list
      cout << "CPSC " << current->getCourseNo();
      cout << " " << current->getTitle() << endl;
      current = current->getNext();
      cout << endl;
    }   
  }
  return;
}

void HashTable::printIdx(int i) {
  if (!schedule[i]) {
    cout << "No courses at index " << i << endl;
  }
  CourseNode* current = schedule[i];
  while (current) {
    //cout << "break3";
    cout<<"CPSC "<<current->getCourseNo()<<" - "<<current->getTitle()<<endl;
    cout << endl;
    current = current->getNext();
  }
  return;
}

int HashTable::taughtOn(string day) {
  int count = 0;
  for (int i = 0; i < TABLE_SIZE; i++) {
    CourseNode* current = schedule[i];
    while (current) {
      bool check = true;
      string date = current->getDate();
      size_t found = date.find(day);
      //checks if T is followed by an h, dont confuse Tuesday with Thursday
      if (day == "T" && current->getDate()[found + 1] == 'h') {
        check = false;//not Tuesday
      }//if day found, print info
      if (found != string::npos && check) {
        count++;//number of courses on day
        cout<<"CPSC "<<current->getCourseNo()<<" - "<<current->getTitle()<<endl;
        cout <<  current->getDate() <<" "<< current->getTime()<< endl;
        cout << "Instructor: Prof. " << current->getInstructor() << endl;
      }
      current = current->getNext();
    }
  }
  return count;
}
