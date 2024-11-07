/*
Title: Chapter 5 Exercise 14 and 25 - Student Lineup
File Name : Ch5Ex14and25_CSC221_Assignment
Programmer : Brion Blais
Date : 11 / 2024
Requirements :
Student Line Up
A teacher has asked all her students to line up according to their first name.
For example, in one class Amy will be at the front of the line, and Yolanda will be at the end.

Write a program that prompts the user to enter the number of students in the class, then loops to read that many names.
Once all the names have been read, it reports which student would be at the front of the line and
which one would be at the end of the line. You may assume that no two students have the same name.
Input Validation: Do not accept a number less than 1 or greater than 25 for the number of students.

Using Files—Student Line Up -Create a second branch for this project and modify your program to do the following:
Create a new branch in your Exercise 14 project that modifies the Student Line Up program described in Programming 
Challenge 14 so it reads the student names from the file LineUp.txt. The program should read names from the file until 
there is no more data to read.
 */

#include <iostream>
#include <string>
using namespace std;

int validateNumber(int);

int main()
{
    int numberStudents;
    cout << "How many students are in the class? \t";
    cin >> numberStudents;
    numberStudents = validateNumber(numberStudents);
    string front;
    string middle;
    string back;
    for (int count = 0; count < numberStudents; count++) {
        if (count == 0) {
            cout << "Enter a students name in lowercase: \t";
            cin >> middle;
            front = middle;
            back = middle;
            continue;
        }
        cout << "Enter another students name in lowercase: \t";
        cin >> middle;
        if (middle < front) {
            front = middle;
        }
        if (middle > back) {
            back = middle;
        }        
    }
    cout << "The first student in line is " << front << endl;
    cout << "The last student in line is " << back << endl;
    return 0;
}

int validateNumber(int inputNumber) {
    while ((inputNumber < 1 && inputNumber > 25)) {
        cout << "Please enter a number of students between 1 and 25 inclusive.\t";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> inputNumber;
    }
    return inputNumber;
}
    