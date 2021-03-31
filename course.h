//Heitkemper, Peter
//course.h
//3/15/2021

// DESCRIPTION: This program inputs courses into a hash table using seperate 
// chaining for collision resolution. User can print, remove, and find courses. 
// User can ask for all courses on a day of the week. Hash function splits 
// course number into 2, two digit sections, sums, divides by table size, and
// returns the remainder as the index. 
 
// DESCRIPTION: Class Course holds information for each course including
// Course number,title, date, time, and instructor.
 
// DESCRIPTION: Class CourseNode holds a Course object, next pointer, and key.

// ASSUMPTIONS: The input file must be a csv. Table size should not 
// be less than 1. Invalid inputs will prompt a re entry. Key must be 4 digit 
// number.


// SOURCES: Input files were provided by Dr.Kong. sample-schedule.csv and 
// SQ21.csv
//******************************************************************************
#include <iostream>
using namespace std;

class Course
{
public:
  //Default Constructor
  Course();
  //Parameterized constuctor
  Course(int coNo,string title, string d, string time, string instrct);

  //Getter functions
  int getCourseNo();
  string getTitle();
  string getDate();
  string getTime();
  string getInstructor();

private:
  int courseNo;
  string title, date, time, instructor;
};

class CourseNode 
{
public:
  //Parameterized Constuctor
  CourseNode(int k, Course in);

  //Default Constuctor
  CourseNode();

  //Getter Functions that use other Getter functions
  string getTitle();
  string getDate();
  string getTime();
  string getInstructor();
  int getCourseNo();
  int getKey();
  CourseNode* getNext();
  //set next pointer
  void setNext(CourseNode* n);

private: 
  int key;
  Course value;
  CourseNode* next;
};