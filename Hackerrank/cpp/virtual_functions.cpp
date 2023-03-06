#include <cmath>

#include <cstdio>

#include <vector>

#include <iostream>

#include <algorithm>

using namespace std;

class Person {
  public: int age;
  string name;

  virtual void putdata() = 0;
  virtual void getdata() = 0;
};

class Professor: public Person {
  private: int publications;

  public: static int cur_id;
  void getdata() override {
    int a, p;
    string n;

    cin >> n >> a >> p;

    this -> name = n;
    this -> age = a;
    this -> publications = p;

  }

  void putdata() override {
    cout << name << " " << age << " " << publications << " " << Professor::cur_id++ << endl;
  }
};

class Student: public Person {
  private: int marks[6];

  public: static int cur_id;
  void getdata() override {
    int a;
    string n;

    cin >> n >> a;

    this -> name = n;
    this -> age = a;

    for (int i = 0; i < 6; i++) {
      int temp;
      cin >> temp;

      this -> marks[i] = temp;
    }
  }

  void putdata() override {
    int sumOfGrades = 0;

    for (int grade: marks) {
      sumOfGrades += grade;
    }

    cout << name << " " << age << " " << sumOfGrades << " " << Student::cur_id++ << endl;
  }
};

int Student::cur_id = 1;
int Professor::cur_id = 1;

int main() {

  int n, val;
  cin >> n; //The number of objects that is going to be created.
  Person * per[n];

  for (int i = 0; i < n; i++) {

    cin >> val;
    if (val == 1) {
      // If val is 1 current object is of type Professor
      per[i] = new Professor;

    } else per[i] = new Student; // Else the current object is of type Student

    per[i] -> getdata(); // Get the data from the user.

  }

  for (int i = 0; i < n; i++)
    per[i] -> putdata(); // Print the required output for each object.

  return 0;

}