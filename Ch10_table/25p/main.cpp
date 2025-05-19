
#include <iostream>
#include <string>
#include "Table.h"
#include "CPhone.h"

using namespace std;
int main() {
    Table<int, CPhone> phoneTable;

    cout << "[6] 이름 + 생일 3명 입력\n";
    for (int i = 0; i < 3; ++i) {
        string name;
        int birthday;
        cout << "이름: ";
        cin >> name;
        cout << "생일 (yyyymmdd): ";
        cin >> birthday;
        CPhone person(name, birthday);
        phoneTable.insert(birthday, person);  // 6번: 생일을 key로
    }

    phoneTable.dump();

    cout << "[7] 이름 기반 입력 2명 추가\n";
    for (int i = 0; i < 2; ++i) {
        string name;
        int birthday;
        cout << "이름: ";
        cin >> name;
        cout << "생일 (yyyymmdd): ";
        cin >> birthday;
        CPhone person(name, birthday);
        int key = stringToInt(name);  // 이름 → int
        phoneTable.insert(key, person);
    }

    phoneTable.dump();

    cout << "[8] 이름으로 검색\n";
    string searchName;
    cout << "이름: ";
    cin >> searchName;
    int searchKey = stringToInt(searchName);
    CPhone result;
    if (phoneTable.lookup(searchKey, result)) {
        cout << "검색 결과:\n";
        result.display();
    } else {
        cout << "이름을 찾을 수 없습니다.\n";
    }

    cout << "20211542 이유준\n";
    return 0;
}