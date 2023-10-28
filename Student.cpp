#include "Student.h"
#include "Course.h"
#include "Admin.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


Student::Student(){
  for (int i = 0; i < MAX_COURSES; i++){
    m_course_list[i] = -1;
  }
  //ASK IF THIS INITIALIZATION IS CORRECT
}

string Student::GetFName(){
  return m_fName;
}

string Student::GetLName(){
  return m_lName;
}

int Student::GetID(){
  return m_id;
}

int Student::GetCourse(int loc){//NEEDS WORK
  return m_course_list[loc];
}


void Student::SetLName(string lName){
  m_lName = lName;
}

void Student::SetFName(string fName){
  m_fName = fName;
}

void Student::SetID(int id){
  m_id = id;
}

void Student::AddCourse(int index){//NEEDS WORK
