//
// Created by 이유준 on 2025. 5. 13..
//

#ifndef TABLE_H
#define TABLE_H

const int MAX_TABLE = 7;

template <class tableKeyType, class tableDataType>
class Table {
public:
    Table();
    void insert(const tableKeyType& key, const tableDataType& data);
    bool lookup(const tableKeyType& key, tableDataType& data);
    void deleteKey(const tableKeyType& key);
    void dump();

private:
    enum slotType { Empty, Deleted, InUse };

    struct slot {
        slotType slotStatus;
        tableKeyType key;
        tableDataType data;
    };

    slot T[MAX_TABLE];
    int entries;

    int hash(const tableKeyType& key);
    int probe(const int pos);
    bool search(int& pos, const tableKeyType& key);
};

//10장 25쪽
//20211542 이유준
#include <iostream>
#include <string>
#include <cassert>
#include "Table.h"

using namespace std;


template <class tableKeyType, class tableDataType>
Table<tableKeyType, tableDataType>::Table() {
    entries = 0;
    for (int i = 0; i < MAX_TABLE; i++)
        T[i].slotStatus = Empty;
}

template <class tableKeyType, class tableDataType>
int Table<tableKeyType, tableDataType>::hash(const tableKeyType& key) {
    return key % MAX_TABLE;
}

template <class tableKeyType, class tableDataType>
int Table<tableKeyType, tableDataType>::probe(const int pos) {
    return (pos + 1) % MAX_TABLE;
}

template <class tableKeyType, class tableDataType>
bool Table<tableKeyType, tableDataType>::search(int& pos, const tableKeyType& key) {
    int start = pos;
    do {
        if (T[pos].slotStatus == InUse && T[pos].key == key)
            return true;
        if (T[pos].slotStatus == Empty)
            return false;
        pos = probe(pos);
    } while (pos != start);
    return false;
}

template <class tableKeyType, class tableDataType>
void Table<tableKeyType, tableDataType>::insert(const tableKeyType& key, const tableDataType& data) {
    assert(entries < MAX_TABLE);
    int pos = hash(key);
    if (!search(pos, key)) {
        pos = hash(key);
        while (T[pos].slotStatus == InUse)
            pos = probe(pos);
        entries++;
    }
    T[pos].slotStatus = InUse;
    T[pos].key = key;
    T[pos].data = data;
}

template <class tableKeyType, class tableDataType>
bool Table<tableKeyType, tableDataType>::lookup(const tableKeyType& key, tableDataType& data) {
    int pos = hash(key);
    if (search(pos, key)) {
        data = T[pos].data;
        return true;
    }
    return false;
}

template <class tableKeyType, class tableDataType>
void Table<tableKeyType, tableDataType>::deleteKey(const tableKeyType& key) {
    int pos = hash(key);
    if (search(pos, key)) {
        T[pos].slotStatus = Deleted;
        entries--;
    }
}

template <class tableKeyType, class tableDataType>
void Table<tableKeyType, tableDataType>::dump() {
    for (int i = 0; i < MAX_TABLE; i++) {
        cout << i << "\t";
        switch (T[i].slotStatus) {
            case InUse: cout << "In Use\t" << T[i].key << endl; break;
            case Deleted: cout << "Deleted\t" << T[i].key << endl; break;
            case Empty: cout << "Empty" << endl; break;
        }
    }
    cout << "Entries = " << entries << "\n\n";
}

#endif //TABLE_H
