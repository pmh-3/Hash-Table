//Heitkemper, Peter
//pa5.cpp
//3/15/2021

//******************************************************************************
#include "hash.h"

int main(){
  //Default constructor
  HashTable h;

  string fileName = "SQ21.csv";
  string first, title, date, time, instructor,courseIn,day;
  int courseNo, option, index, x;
  bool exit = false;

  cout << "Welcome! Processing the " << fileName << " file..." << endl;
  cout << endl;

  //reading in file
  ifstream file(fileName);
  if (!file.is_open()) {
    cout << "ERROR";
    return -1;
  }
  //first line discarded
  getline(file, first);
  //extract all data
  while (file.good())
  {
    getline(file, courseIn, ',');
    //cout << courseIn << endl;
    courseNo = stoi(courseIn.erase(0, 5));
    //cout << courseNo << endl;
    getline(file, title, ',');
    //cout << title << endl;
    getline(file, date, ',');
    //cout << date << endl;
    getline(file, time, ',');
    //cout << time << endl;
    getline(file, instructor, '\n');
    //cout << instructor << endl;
    h.insert(courseNo, Course(courseNo, title, date, time, instructor));
    // cout << "inserted " << courseIn << endl;
  }
  cout << endl;
  cout << endl;
  cout << "Hello! What would you like to do with the SQ21 schedule? " << endl;
  cout << endl;
  while(!exit) {
    cout << "1. Print schedule, 2. Remove a course," << endl;
    cout << "3. View course info, 4. Find a course by day," << endl;
    cout << "5. Print index, 6. Exit program : ";
    cin >> option;
    cout << endl;
    cout << endl;
    if (option == 1) {
      cout << endl;
      cout << endl;
      h.printAll();
      cout << endl;
      cout << "*************************" << endl;
    } 
    else if (option == 2) {
      cout << "Enter the course number of the course you want to remove: ";
      cin >> courseNo;
      while(courseNo < 1||cin.fail()) {     //check for valid input
        cout << "Please enter a valid course number: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> courseNo;
      }
      title = h.remove(courseNo);
      if(title == "") {     //check if course in schedule
        cout << "That course is not on the schedule." << endl;
      } else {
        cout << "Removing \"" << title << "\" from the schedule." << endl;
      }
      cout << endl;
      cout << "*************************" << endl;
    }
    else if (option == 3) {
      cout << "Enter the course number of the course: ";
      cin >> courseNo;
      while (courseNo < 1 || cin.fail()) {    //check for valid input
        cout << "Please enter a valid course number: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> courseNo;
      }
      cout << endl;
      h.courseInfo(courseNo);
      cout << endl;
      cout << "*************************" << endl;
    }
    else if (option == 4) {
      cout << "Enter a day of the week (M/T/W/Th/F): ";
      cin >> day;
      x = h.taughtOn(day);
      cout << endl;
      cout << x << " course(s) taught on " << day;
      cout << endl;
      cout << "*************************" << endl;
    }
    else if (option == 5) {
      cout << "Which index do you want to print? ";
      cin >> index;   //check for valid idex within table
      while ( index < 0 || index > TABLE_SIZE - 1||cin.fail()) {
        cout << "Please enter an index from 0 to " << TABLE_SIZE - 1 
        << ": ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> index;
      }
      cout << endl;
      h.printIdx(index);
      cout << endl;
      cout << "*************************" << endl;
    }
    else if (option == 6) {
      cout << "GoodBye!" << endl;
      exit = true;
    }
    else {
      cout << "Please enter a valid option. " << endl;
      cout << endl;
    }
  }

  /*Begin Testing*************************
  Course k;
  CourseNode p;
  cout << "Default Course constuctor " << endl;
  cout << k.getTime() << endl;
  cout << k.getDate() << endl;
  cout << k.getCourseNo() << endl;
  cout << "Default CourseNode constuctor " << endl;
  cout << p.getKey() << endl;
  cout << p.getInstructor() << endl;
  *************************End Testing*/
  return 0;
}