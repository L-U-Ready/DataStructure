// 옛날 시험문제 변형
// f와 r 옮기는 순서를 바꿈 (필기 참고)
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
    queueElementType elements[maxQueue];
};

int nextPos(int p) {
    return (p+1) % maxQueue;
}


template<class queueElementType>
Queue<queueElementType>::Queue() {
    f = 0;
    r = 0;
}

template<class queueElementType>
void Queue<queueElementType>::enqueue(queueElementType e) {
    assert(!isFull());
    elements[r] = e;
    r = nextPos(r);
}

template<class queueElementType>
queueElementType Queue<queueElementType>::dequeue() {
    assert(!isEmpty());
    queueElementType returnValue = elements[f];
    f = nextPos(r);
    return returnValue;
}

template<class queueElementType>
queueElementType Queue<queueElementType>::front() {
    assert(!isEmpty());
    return elements[f];
}

template<class queueElementType>
bool Queue<queueElementType>::isEmpty() {
    return bool(f == r);
}

template<class queueElementType>
bool Queue<queueElementType>::isFull() {
    return bool(nextPos(r) == f);
}
