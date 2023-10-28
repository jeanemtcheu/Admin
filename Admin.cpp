#include <fstream>
#include <iostream>
#include <string>
#include "Course.h" //Must include course
#include "Student.h" //Must include student
#include "Admin.h"
using namespace std;

Admin::Admin(){} //Default Constructor
  // Name - LoadStudents
  // Desc - Loads each student into m_students from file. Uses constant size.
  // Preconditions - Requires file with valid student data
  // Postconditions - m_students is populated with students
void Admin::LoadStudents(){
  //getline command to itertae throught the student file
  ifstream eyes; // object used to read students file
  eyes.open("proj2_students.txt");

  if (!eyes.is_open()){
    cerr << "Errorr: File not opened." << endl;
    exit(EXIT_FAILURE);
   }

  int counter = 0;
  string current;

  getline(eyes, current, ' ');

  while (counter < STUDENT_COUNT){

    Student student;

    for (int i = 0; i < 3; i++){
      if (i == 0){
        //cout << current << endl;
        student.SetFName(current);
        getline(eyes, current, ' ');
      }

      else if (i == 1){
        //cout << current << endl;
        student.SetLName(current);
        getline(eyes, current);
      }

      else if (i == 2){
        //cout << current << endl;
        int numid = stoi(current);
        student.SetID(numid);
        getline(eyes, current, ' ');
      }
     //getline(eyes, current);

    }
    m_students[counter] = student;
    counter++;
  }

  eyes.close();

}

  // Name - LoadCourses
  // Desc - Loads each course into m_coursess from file.
  //        Courses have comma delimiters (check proj doc for delimiter help)
  // Preconditions - Requires file with valid course data
  // Postconditions - m_courses is populated with courses
void Admin::LoadCourses(){
  //getline
  ifstream eyes; // object used to read students file                                              \
                                                                                                   \

  eyes.open("proj2_courses.txt");

  if (!eyes.is_open()){
    cerr << "Errorr: File not opened." << endl;
    exit(EXIT_FAILURE);
   }

  int counter = 0;
  string current;
getline(eyes, current, ',');

  while (counter < COURSE_COUNT){
    Course course;

    for (int i = 0; i < 3; i++){

      if (i == 0){
        //cout << current << endl;
        course.SetPrefix(current);
        getline(eyes, current, ',');
      }

      else if (i == 1){
        //cout << current << endl;
        course.SetNumber(current);
        getline(eyes, current);
      }

      else if (i == 2){
        //cout << current << endl;
        course.SetName(current);
        getline(eyes, current, ',');
      }

      //getline(eyes, current, ',');
    }

    m_courses[counter] = course;
 counter++;
  }



  eyes.close();


}
 // Name - AddCourse
  // Desc - Asks user to choose a student then a course. Adds course to specific student.
  // Preconditions - Requires m_students and m_courses to be populated
  // Postconditions - Populates m_course_list for a chosen student
void Admin::AddCourse(){
  int student;
  int course;

  //Student Roster[STUDENT_COUNT] = {};
  //Roster = LoadStudents();

  //Course Catalog[COURSE_COUNT] = {};
  //Catalog = LoadCourses();

  for (int a = 0; a < STUDENT_COUNT; a++){
    int num = a+1;
    Student name = m_students[a];
    cout << num << ". " << name.GetFName() << " " << name.GetLName() << endl;
  }

  cout << "Choose a student by the number in list" << endl;
  cin >> student;
  //cin >> course;

  for (int x = 0; x < COURSE_COUNT; x++){
    int pos = x+1;
    string title = m_courses[x].GetPrefix();
    string tnum = m_courses[x].GetNumber();
    string ct = title + " " + tnum;
    cout << pos << ". " << ct << endl;
  }

  cout << "Choose a course by the number in list"<< endl;
  cin >>  course;

  m_students[student-1].AddCourse(course-1);    
void Admin::DisplaySchedule(){

  int student;

  for (int i = 0; i < STUDENT_COUNT; i++){
    string sname = m_students[i].GetFName() + " " + m_students[i].GetLName();
    cout << i+1 << " " << sname << endl;
  }


  cout << "Choose a student by the number" << endl;
  cin >> student;

  Student current = m_students[student-1];


  for (int i = 0; i < MAX_COURSES; i++){
    int x = current.GetCourse(i);
    if (x > -1){

      //int x = current.GetCourse(i);
    string prf = m_courses[x].GetPrefix();
    string num = m_courses[x].GetNumber();
    string nam =  m_courses[x].GetName();

    string tot = prf + " " + num + " " + nam;
    cout << tot <<endl;
    }

    else {
      cout << "No course selected" << endl;
    }
  }
}
// Name - PrintCourse
  // Desc - Displays information about courses loaded into m_courses
  // Preconditions - Passed the index from m_courses to display
  // Postconditions - Displays index, prefix, number, and name of course at indexm m_courses to dis\
play
  // Postconditions - Displays index, prefix, number, and name of course at index
void Admin::PrintCourse(int index){

  string pref = m_courses[index].GetPrefix();
  string number = m_courses[index].GetNumber();
  string name = m_courses[index].GetName();

  cout << "Index: " << index << " || Course: " << pref << " " << number << " " << name << endl;
}
  // Name - PrintDetails
  // Desc - Displays information about students loaded into m_courses
  // Preconditions - Passed the index from m_students to display
  // Postconditions - Displays index, first name, last name, and id at index
void Admin::PrintDetails(int index){
  Student current = m_students[index];

  string fn = current.GetFName();
  string ln = current.GetLName();
  int id = current.GetID();

  cout << index << " " << fn << " " << ln << " " << id << endl;

}
  // Name - StartAdmin()
  // Desc - Calls AdminTitle then loads the student file by calling LoadStudents
  //        Then loads courses by calling LoadCourses.
  //        Manages the game itself continually by calling MainMenu until the
  //        user chooses 5 (and returns 5)
  // Preconditions - None
  // Postconditions - Continually checks to see if user has entered 5
void Admin::StartAdmin(){
  LoadStudents();
  LoadCourses();
  MainMenu();

  string input;  
}

void Admin::DisplayStudents(){
  for (int i = 0; i < STUDENT_COUNT; i++){
    Student current = m_students[i];

    string fn = current.GetFName();
    string ln = current.GetLName();

    cout << i+1 << ". "<< fn << " " << ln << endl;
  }
}

void Admin::PrintMenu(int &choice){
  cout << "1. Display your School's Students" << endl;
  cout << "2. Search for a Student"<< endl;
  cout << "3. Add Course to Student" << endl;
  cout << "4. Display Schedule"<< endl;
  cout << "5. Quit"<< endl;
  cin >> choice;

  if (choice == 1){
    DisplayStudents();
  }

  else if (choice == 2){
    SearchStudents();
  }

  else if (choice == 3){
    AddCourse();
  }

  else if (choice == 4){
    DisplaySchedule();
  }

}

int Admin::MainMenu(){
  string school;
  int choice;
  cout << "What is the name of your School? "<< endl;
  cin >> school;

  while (choice != 5){
    cout << "What would you like to do in " << school << "'s Admin Portal?" << endl;
    PrintMenu(choice);
  }

  return 0;
}

void Admin::SearchName(){
  string name;
  cout << "What name would you like to search for?" << endl;
  cin >> name;

  for (int i = 0; i < STUDENT_COUNT; i++){
    Student current = m_students[i];

    string fn = current.GetFName();
    string ln = current.GetLName();

    string gn = fn + " " + ln;
    int id = current.GetID();
    if (name == fn || name == ln){
      cout << i + 1 << ". " << gn << " (" << id << ")"  <<endl;
    }
  }
}

void Admin::SearchID(){
  int id;
  cout << "What ID would you like to search for?"<< endl;
  cin >> id;

  for (int i = 0; i < STUDENT_COUNT; i++){
    Student current = m_students[i];

    int sid = current.GetID();

    string fn = current.GetFName();
    string ln = current.GetLName();

    string gn = fn + " " + ln;

    if (id == sid){
      cout << i + 1 << ". " << gn << " (" << id << ")"  <<endl;
    }
  }
}

void Admin::SearchStudents(){
  int input;

  cout << "What would you like to search?" << endl;
  cout << "1. Name" << endl;
  cout << "2. ID" << endl;

  cin >> input;

  if (input == 1){
    SearchName();
  }

  else if(input == 2){
    SearchID();
  }

}
