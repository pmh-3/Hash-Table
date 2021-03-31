//Heitkemper, Peter
//course.cpp
//3/15/2021

//******************************************************************************
#include "hash.h"

//Default Constructor
Course::Course():courseNo{-1}, title{""}, date{""}, time{""}, instructor{""}{}

//Paramaterized Constuctor
Course::Course(int coNo,string title, string d, string time, string instrct):
courseNo{coNo},title{title}, date{d}, time{time},instructor{instrct} {}

//getter functions
int Course::getCourseNo() { return courseNo; }
string Course::getTitle() { return title;}
string Course::getDate() { return date; }
string Course::getTime() { return time; }
string Course::getInstructor() { return instructor; }

//Default Constructor
CourseNode::CourseNode(): key{ -1 }, value{ Course() }, next{nullptr}{}
//Paramaterized Constuctor
CourseNode::CourseNode(int k, Course in):key{k}, value{in}, next{nullptr}{}

//getter functions that call other getter functions
string CourseNode::getTitle() { return value.getTitle(); }
string CourseNode::getDate() { return value.getDate(); }
string CourseNode::getTime() { return value.getTime(); }
string CourseNode::getInstructor() { return value.getInstructor(); }
int CourseNode::getCourseNo() { return value.getCourseNo();}
int CourseNode::getKey() { return key; }
CourseNode* CourseNode::getNext() { return next; }
void CourseNode::setNext(CourseNode* n) { next = n; }
