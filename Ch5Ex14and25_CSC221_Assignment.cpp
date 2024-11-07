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
#include <fstream>
using namespace std;

void openFile();
int flagValidation(string);
int countLines();
void closeFile();

ifstream fileStreamObject;

int main()
{
    openFile();
    int numberStudents = countLines();
    string front;
    string middle;
    string back;
    for (int count = 0; count < numberStudents; count++) {
        if (count == 0) {
            getline(fileStreamObject, front);
            fileStreamObject.clear();
            fileStreamObject.seekg(0, ios::beg);
        }
        getline(fileStreamObject, middle);
        if (middle < front) {
            front = middle;
        }
        if (middle > back) {
            back = middle;
        }        
    }
    cout << "\nThe first student in line is " << front << endl;
    cout << "The last student in line is " << back << "\n" << endl;
    closeFile();
    return 0;
}

void openFile() {
    string fileName;
    string localFileFlag;
    bool fileFlag;
    cout << "What is the name of the file you are opening? \t";
    cin >> fileName;
    cout << "Is the file you are trying to open in the same folder as this program? \t";
    cin >> localFileFlag;
    fileFlag = flagValidation(localFileFlag);
    if (fileFlag == false) {
        string filePath;
        cout << "Please enter the path to the folder where the file you are trying to open is located.\n";
        cout << "Use the following format:  " << R"(C:\Users\myname\Desktop)" << "\n";
        cin >> filePath;
        fileName = filePath + R"(\)" + fileName;
    }
    if (fileFlag == true) {
        cout << "Finding the file ... ";

        fileStreamObject.open(fileName);
        if (fileStreamObject) {
            cout << "file open.\n";
        }
        else {
            cout << "The file was not found or could not be opened. \n";
            cout << "Please check to see if the file is in the correct folder and rerun the program. Exiting ...\n";
            exit(0);
        }
    }
    else {
        cout << "Finding the file at the following at " << fileName << " ... ";
        fileStreamObject.open(fileName);
        if (fileStreamObject) {
            cout << "file open.\n";
        }
        else {
            cout << "the file was not found or could not be opened. \n";
            cout << "Please check to see if the file is in the correct location and rerun the program. Exiting ...\n";
            exit(0);
        }
    }
}

int flagValidation(string input) {
    int output = 2;
    do {
        if (input == "True" || input == "true" || input == "TRUE" ||
            input == "Yes" || input == "yes" || input == "YES") {
            output = 1;
        }
        else if (input == "False" || input == "false" || input == "FALSE" ||
            input == "No" || input == "no" || input == "NO") {
            output = 0;
        }
        else {
            cout << R"(You must anwser either "true / false or yes / no" to continue.)" << endl;
            cout << "Is the file you are trying to open in the same folder as this program?\t";
            cin >> input;
        }
    } while (output != 0 && output != 1);
    return output;
}

int countLines() {
    int lineCount = 0;
    string fileContents;
    while (getline(fileStreamObject, fileContents)) {
        lineCount += 1;
    }
    cout << "There are " << lineCount << " lines in this file.\n";
    fileStreamObject.clear();
    fileStreamObject.seekg(0, ios::beg);
    return lineCount;
}

void closeFile() {
    cout << "Closing file ...";
    fileStreamObject.close();
    cout << "File closed.";
}