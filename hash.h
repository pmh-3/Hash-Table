//Heitkemper, Peter
//hash.h.cpp
//3/15/2021

// DESCRIPTION: This program inputs courses into a hash table using seperate 
// chaining for collision resolution. User can print, remove, and find courses. 
// User can ask for all courses on a day of the week. Hash function splits 
// course number into 2, two digit sections, sums, divides by table size, and
// returns the remainder as the index.

// ASSUMPTIONS: The input file must be a csv. Table size should not 
// be less than 1. Invalid inputs will prompt a re entry. Key must be 4 digit 
// number.

// SOURCES: Input files were provided by Dr.Kong. sample-schedule.csv and 
// SQ21.csv

//******************************************************************************

#include <iostream>
#include "course.h"
#include <fstream>
#include <string>

using namespace std;
const int TABLE_SIZE = 43;  //prime number that keeps load factor around 0.7

class HashTable {
public:
  // description: Default Constructor
  // preconditions: none
  // postconditions: Initalizes hash table to size specified in TABLE_SIZE.
  // sets each element in table to nullptrs. Initlizes all variables.
  HashTable();

  // description: Destructor
  // preconditions: none
  // postconditions: Deletes each node in each linked list in array.
  ~HashTable();

  // description: recursive function to delete linked list
  // preconditions: starting node must be passed in
  // postconditions: deletes every node in linked list
  void deleteAll(CourseNode* in);

  // description: hash Function that calculates key 
  // preconditions: key must be 4 digit number
  // postconditions: returns viable index of hashtable
  int hashKey(long key);

  // description: Adds key-value pair into table as a Course Node.
  // preconditions: Must be valid key, course number must match key.
  // postconditions: Prints load factor or indicates course is 
  //already in list.
  void insert(long key, Course value);

  //Remove the courseand return the title of the course.If the
  // course is not on the schedule, return an empty string.

  // description: Remove course and return title.
  // preconditions: key must be valid.
  // postconditions: returns empty string if not in list.
  string remove(long key);

  // If the key exists, display information about the course as
  // shown in the execution example.
  //Else, print that the course is not on the schedule.

  // description: Displays information about course.
  // preconditions: key must be valid.
  // postconditions: Indicates if course is not in list.
  void courseInfo(long key);
    
  // description: Displays course number and title of all the courses 
  // on the schedule.
  // preconditions: none.
  // postconditions: prints nothing if array is empty.
  void printAll();


  // description: Displays course number and title of all the courses 
  // at that index on the schedule.
  // preconditions: i must be within table.
  // postconditions: Indicates if index is empty.
  void printIdx(int i);

  //displays the course informationand returns the number of
  //all the courses taught on that day.
  //For example, a course taught on “MWF” should be
  //shown when the user searches for “M”

  // description: Displays course number and title of all the courses 
  // on the schedule.
  // preconditions: Should be either (M/T/W/Th/F). 
  // postconditions: No courses are found on garbage inputs such as numbers.
  // Returns zero if no coursea are found on that day.
  int taughtOn(string day);

private:
  int courseCount; //keeps track of courses in array.
  int i;  //serves as index
  long key; 
  string day;
  Course value;
  CourseNode** schedule; //array of CourseNode pointers
};