/*
Max Cravetchi
Mr. Galbraith
C++ Programming

This program is a student list.
It displays a list of student names, gpas, and ids.
Implemented with structs, pointers, vectors.
 */

#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>

using namespace std;
// struct which stores each student list
struct studentList{
  char firstName[20];
  char lastName[20];
  int studentID;
  float studentGPA;
};

studentList* add(){ //add function, which points to the struct
  studentList* student = new studentList();

  //asks for all the contents needed for a student, stores into the memory address of the struct pointed to by the struct pointer function
  
  cout << "FIRST NAME?" << endl;
  cin >> student -> firstName;
  cin.ignore(100, '\n');
  
  cout<<"LAST NAME?" << endl;
  cin >> student -> lastName;
  cin.ignore(100, '\n');

  
  cout << "STUDENT ID?" << endl;
  cin >> student -> studentID;
  cin.ignore(100, '\n');

  
  cout << "GPA?" << endl;
  cin >> student -> studentGPA;
  cin.ignore(100, '\n');

  return student;
}

void print(vector<studentList*> studentListing) {
  vector<studentList*>::iterator printer; //creates an iterator for the vector
  for(printer = studentListing.begin(); printer != studentListing.end(); ++printer){ //runs through the vector
    cout << "NAME: " << (*printer)->firstName << " " << (*printer)->lastName; //prints all contents of vector
    cout << " STUDENT ID: " << (*printer)->studentID;
    cout << " STUDENT GPA: " << fixed << setprecision(2) <<  (*printer)->studentGPA<<endl; //fixed specifies the precision, displays float exactly to precision of decimal place
    cout << endl;
  }
}

void deleteFunction(vector<studentList*>* studentListing, int idDelete) {
  vector<studentList*>::iterator deleteThru;
  for(deleteThru = studentListing->begin(); deleteThru != studentListing->end(); ++deleteThru){
    if((*deleteThru)->studentID == idDelete){ //if the vector iterates through the id which matches with the inputted one
      studentListing->erase(deleteThru); //erases the student from vector
      delete *deleteThru; //deletes the student the iterator went through from the memory
      return;
    }
  }
}

int main(){
  bool quit = true; //for the quit function

  vector<studentList*> studentListing;

  //declares a vector of type struct pointer, dynamic array which holds the addresses to the struct

  while(quit==true) {
    char user[7];
    int studentIdDelete; //for the delete function
    cout << "ADD, PRINT, DELETE, OR QUIT?"<<endl;
    cin.get(user,7);
    cin.ignore(100, '\n'); //these clear out the stream, removes previous bugs
    
    if(strcmp(user, "ADD") == 0){      //compares input to the string of options, returns bool val, continues if true
      studentListing.push_back(add());
      
      
    }
    else if(strcmp(user, "PRINT") == 0) {
      print(studentListing);
      
    }
    else if(strcmp(user, "DELETE") == 0) {
      cout << "INPUT THE STUDENT ID YOU WOULD LIKE TO DELETE" << endl;
      cin >> studentIdDelete;
      cin.ignore(100, '\n');

      deleteFunction(&studentListing, studentIdDelete);
      
    }
    else if(strcmp(user, "QUIT") == 0) {
      quit = false;
      
      
    }
    else{
      cout << "PLEASE DO A VALID OPERATION" << endl;
    }
  }
  return 0;
}

  
