//10장 25쪽
//20211542 이유준
#include <iostream>
#include <string>

#ifndef CPHONE_H
#define CPHONE_H
using namespace std;

class CPhone {
public:
    string name;
    int birthday;

    CPhone(string n = "", int b = 0) : name(n), birthday(b) {}

    void display() const {
        cout << "Name: " << name << ", Birthday: " << birthday << endl;
    }
};

int stringToInt(const string& strName) {
    int nSum = 0;
    for (char c : strName)
        nSum += c;
    return nSum;
}
#endif //CPHONE_H