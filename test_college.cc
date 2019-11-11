#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "course.h"
#include "node.h"
#include "college.h"

using namespace std;

TEST_CASE( "Peffjarker is created and classes added to", "[College]") {
  cout << "TEST CASE 1" << endl;
  cout << "Create user and add 3 classes, show gpa and hours." << endl;
  course c;
  string coursename;
  ifstream fin;
  ofstream fout;
  string username,filename, fullname;
  username = "peffjarker";
  filename = username + ".txt";
  fullname = "Jeff Parker";
  College mycollege(fullname);
  fin.open(filename.c_str());
  c.set_course("CS2400", "A", 4);
  mycollege.add(c);
  c.set_course("CS2401", "C+", 4);
  mycollege.add(c);
  c.set_course("CS4170", "A", 3);
  mycollege.add(c);
  mycollege.display(cout);
  cout << "GPA: " << mycollege.gpa() << endl;
  cout << "Hours: " << mycollege.hours() << endl;
  cout << endl;
  fout.open(filename.c_str());
  mycollege.save(fout);
  fin.close();
}

TEST_CASE( "Add more classes to peffjarker and check gpa", "[College]") {
  cout << "TEST CASE 2" << endl;
  cout << "Add 3 more classes to previous user and check gpa and hours." << endl;
  course c;
  string coursename;
  ifstream fin;
  ofstream fout;
  string username,filename, fullname;
  username = "peffjarker";
  filename = username + ".txt";
  fullname = "Jeff Parker";
  College mycollege(fullname);
  fin.open(filename.c_str());
  mycollege.load(fin);
  c.set_course("ET2100", "B+", 4);
  mycollege.add(c);
  c.set_course("UC1900", "A", 1);
  mycollege.add(c);
  c.set_course("CS4040", "B+", 3);
  mycollege.add(c);
  mycollege.display(cout);
  cout << "GPA: " << mycollege.gpa() << endl;
  cout << "Hours: " << mycollege.hours() << endl;
  cout << endl;
  fin.close();
  mycollege.save(fout);
}

TEST_CASE( "New user and classes added", "[College]") {
  cout << "TEST CASE 3" << endl;
  cout << "Create 2nd user and add 3 classes then check gpa and hours." << endl;
  course c;
  string coursename;
  ifstream fin;
  ofstream fout;
  string username,filename, fullname;
  username = "kenny";
  filename = username + ".txt";
  fullname = "Kendall Edwards";
  College mycollege(fullname);
  fin.open(filename.c_str());
  c.set_course("QB3170", "A", 4);
  mycollege.add(c);
  c.set_course("CS2401", "C+", 4);
  mycollege.add(c);
  c.set_course("CS4170", "A", 3);
  mycollege.add(c);
  mycollege.display(cout);
  cout << "GPA: " << mycollege.gpa() << endl;
  cout << "Hours: " << mycollege.hours() << endl;
  cout << endl;
  fout.open(filename.c_str());
  mycollege.save(fout);
  fin.close();

}
