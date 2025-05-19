// nCount 적용해서 비교
// 20211542 이유준

#include <cassert>
const int maxQueue = 200;

template<class queueElementType>
class Queue {
public:
    Queue();
    void enqueue(queueElementType e);
    queueElementType dequeue();
    queueElementType front();
    bool isEmpty();
    bool isFull();
private:
    int f;
    int r;
    int nCnt;
    queueElementType elements[maxQueue];
};

int nextPos(int p) {
    return (p+1) % maxQueue;
}


template<class queueElementType>
Queue<queueElementType>::Queue() {
    f = 0;
    r = 0;
    nCnt = 0;
}

template<class queueElementType>
void Queue<queueElementType>::enqueue(queueElementType e) {
    assert(!isFull());
    r = nextPos(r);
    elements[r] = e;
    nCnt++;
}

template<class queueElementType>
queueElementType Queue<queueElementType>::dequeue() {
    assert(!isEmpty());
    f = nextPos(r);
    nCnt--;
    return elements[f];
}

template<class queueElementType>
queueElementType Queue<queueElementType>::front() {
    assert(!isEmpty());
    return elements[nextPos(f)];
}

template<class queueElementType>
bool Queue<queueElementType>::isEmpty() {
    return bool(nCnt == 0);
}

template<class queueElementType>
bool Queue<queueElementType>::isFull() {
    return bool(nCnt == maxQueue);
}
