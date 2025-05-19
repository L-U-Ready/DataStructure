//10장 51p
//20211542 이유준

#include "CPhone.h"
#include "LinkedListHash.h"

using namespace std;

int main() {
    Table<int, CPhone> myTable;

    // 3개 데이터 추가
    myTable.insert(101001, CPhone("Alice", 101001));
    myTable.insert(120530, CPhone("Bob", 120530));
    myTable.insert(230105, CPhone("Charlie", 230105));

    cout << "[초기 테이블 상태]" << endl;
    myTable.dump();

    // 이름을 숫자로 변환하여 key로 사용
    Table<int, CPhone> nameTable;
    nameTable.insert(stringToInt("Alice"), CPhone("Alice", 101001));
    nameTable.insert(stringToInt("Bob"), CPhone("Bob", 120530));
    nameTable.insert(stringToInt("Charlie"), CPhone("Charlie", 230105));

    cout << "[이름 기반 테이블 상태]" << endl;
    nameTable.dump();

    // 이름으로 검색
    cout << "검색할 이름 입력: ";
    string inputName;
    cin >> inputName;
    int key = stringToInt(inputName);

    CPhone result;
    if (nameTable.lookup(key, result)) {
        cout << "검색 성공: ";
        result.display();
    } else {
        cout << "검색 실패: 해당 이름 없음" << endl;
    }

    cout << "20211542 이유준";
    return 0;
}


