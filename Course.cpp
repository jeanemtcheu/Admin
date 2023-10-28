#include "Course.h" //Loads course class
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;



//Course::Course(){
  //m_prefix = "";
  //m_number = "";
  //m_name = "";
  //}

void Course::SetPrefix(string prefix){
    m_prefix = prefix;
}

void Course::SetNumber(string number){
    m_number = number;
}

void Course::SetName(string name){
    m_name = name;
}

string Course::GetPrefix(){
    return m_prefix;
}

string Course::GetNumber(){
    return m_number;
}

string Course::GetName(){
    return m_name;
  }
