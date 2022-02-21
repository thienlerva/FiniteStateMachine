/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: codex
 *
 * Created on February 10, 2022, 3:48 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

class Student {
    public:
        Student(string name, int age);
        ~Student();
        string getName();
        int getAge();
        void setName(string name);
        void setAge(int age);
        string toString();
    private:
        string name;
        int age;
};

Student::Student(string name, int age) {
    this->name = name;
    this->age = age;
}

Student::~Student() {
    cout << "deconstructor" << endl;
}

string Student::getName() {
    return this->name;
}

int Student::getAge(){
    return this->age;
}

void Student::setName(string name) {
    this->name = name;
}

void Student::setAge(int age) {
    this->age = age;
}

string Student::toString() {
    
    return this->name + " is " + to_string(this->age);
}

/*
 * 
 */
int main(int argc, char** argv) {

    Student *st = new Student("An", 5);
    cout << st->toString() << endl;
    st = nullptr;
    cout << (st ? "Not Null" : "Null Object") << endl;
    Student *st2 = NULL;
    if(st2 == NULL) {
        cout << "st2 is null" << endl;
    }
    cout << (st2 ? "Not Null" : "Null Object") << endl;
    st2 = new Student("Vy", 9);
    st2->setName("Jennifer");
    cout << st2->toString() << endl;
    
    return 0;
}

