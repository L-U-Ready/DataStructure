// 9장 24쪽 실습
// 20211542 이유준

#include <cassert>

template<class queueElementType>
class Queue {
public:
    Queue();
    ~Queue();
    void enqueue(queueElementType e);
    queueElementType dequeue();
    queueElementType front();
    bool isEmpty();
private:
    struct Node;
    typedef Node * nodePtr;
    struct Node {
        queueElementType data;
        nodePtr next;
    };
    nodePtr f;
    nodePtr r;
};


template<class queueElementType>
Queue<queueElementType>::Queue() {
    f = 0;
    r = 0;
}

template<class queueElementType>
Queue<queueElementType>::~Queue() {
    while (f != 0) {
        nodePtr delNode = f;
        f = f->next;
        delete delNode;
    }
}

template<class queueElementType>
void Queue<queueElementType>::enqueue(queueElementType e) {
    nodePtr n = new Node;
    assert(n);
    n->next = 0;
    n->data = e;
    if (f != 0) {
        r->next = n;
        r = n;
    } else {
        // f = r = n;
        f = n;
        r = n;
    }
}

template<class queueElementType>
queueElementType Queue<queueElementType>::dequeue() {
    assert(!isEmpty()); // assert(f);
    nodePtr delNode = f;
    queueElementType returnValue = f->data;
    f = f->next;
    delete delNode;
    if (f == 0) {
        r = 0;
    }
    return returnValue;
}

template<class queueElementType>
queueElementType Queue<queueElementType>::front() {
    assert(!isEmpty()); //assert(f);
    return f->data;
}

template<class queueElementType>
bool Queue<queueElementType>::isEmpty() {
    return bool(f == 0);
}

// main.cpp
#include <iostream>
using namespace std;

int main() {
    Queue<char> queue;

    queue.enqueue('a');
    queue.enqueue('b');
    queue.enqueue('c');

    while (!queue.isEmpty()) {
        cout << queue.dequeue() << endl;
    }
    cout << "20211542 이유준";

    return 0;
}