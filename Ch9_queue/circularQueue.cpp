// 9장  16쪽
// 20211542 이유준

#include <cassert>

const int maxQueue = 200;

template<class queueElementType>
class Queue {
public:
    Queue();
    ~Queue();
    void enqueue(queueElementType e);
    queueElementType dequeue();
    queueElementType front();
    bool isEmpty();
    bool isFull();
private:
    int f; // front
    int r; // rear
    int m_nElement;
    queueElementType elements[maxQueue];
};

int nextPos(int p) {
    return (p + 1) % maxQueue;
}

// Constructor
template<class queueElementType>
Queue<queueElementType>::Queue() {
    f = 0;
    r = 0;
    m_nElement = 0;
}

// Destructor
template<class queueElementType>
Queue<queueElementType>::~Queue() {
    f = 0;
    r = 0;
    m_nElement = 0;
}

// Enqueue
template<class queueElementType>
void Queue<queueElementType>::enqueue(queueElementType e) {
    assert(!isFull());
    r = nextPos(r);
    elements[r] = e;
    m_nElement++;
}

// Dequeue
template<class queueElementType>
queueElementType Queue<queueElementType>::dequeue() {
    assert(!isEmpty());
    f = nextPos(f);
    m_nElement--;
    return elements[f];
}

// Front: 다음에 나올 요소를 확인
template<class queueElementType>
queueElementType Queue<queueElementType>::front() {
    assert(!isEmpty());
    return elements[nextPos(f)];
}

// isEmpty: front와 rear가 같으면 비어있음
template<class queueElementType>
bool Queue<queueElementType>::isEmpty() {
    return m_nElement == 0;
}

// isFull: rear 다음 위치가 front이면 가득 참
template<class queueElementType>
bool Queue<queueElementType>::isFull() {
    return m_nElement == maxQueue;
}

//main.cpp
#include <iostream>
using namespace std;

int main() {
    Queue<char> queue;

    // 'a'부터 'e'까지 enqueue
    for (char c = 'a'; c <= 'e'; ++c) {
        queue.enqueue(c);
        cout << "Enqueued: " << c << endl;
    }

    // queue가 빌 때까지 dequeue
    cout << "Dequeuing all elements:" << endl;
    while (!queue.isEmpty()) {
        char front = queue.front();
        cout << "Front: " << front << ", Dequeued: " << queue.dequeue() << endl;
    }

    cout << "20211542 이유준";
    return 0;
}