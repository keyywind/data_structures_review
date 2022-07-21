#include <bits/stdc++.h>

template <class T>
class Queue
{
private:
    void init_queue() {  __queue = new T [queueSize];  }
    void dest_queue() {  if (__queue) delete [] __queue;  __queue = NULL;  }
    int next(int index) {  return ((index + 1) % queueSize);  }
public:
    /// default : 0, empty : 1, full : 2
    int queueSize, headPointer, tailPointer, state;  T * __queue = NULL;
    Queue(int queueSize) : queueSize(queueSize), headPointer(0), tailPointer(0), state(1) {  init_queue();  }
    ~Queue() {  dest_queue();  }
    T head() {  return __queue[headPointer];  }
    bool empty() {  return (state == 1);  }
    bool full() {  return (state == 2);  }
    bool enqueue(T value)
    {
        if (full()) return false;
        if (next(tailPointer) == headPointer)
        {
            state = 2;
        }
        else
        {
            state = 0;
        }
        __queue[tailPointer] = value;
        tailPointer = next(tailPointer);
        return true;
    }
    bool dequeue()
    {
        if (empty()) return false;
        if (next(headPointer) == tailPointer)
        {
            state = 1;
        }
        else
        {
            state = 0;
        }
        headPointer = next(headPointer);
        return true;
    }
};

int main()
{
    Queue <int> __queue(10);
    printf("%d\n", __queue.empty());
    int a, b, c, d, e;
    for (int i = 0; i < 11; ++i)
    {
        a = i;
        b = __queue.enqueue(i);
        c = __queue.headPointer;
        d = __queue.tailPointer;
        e = __queue.state;
        printf("(%d %d %d %d %d) ", a, b, c, d, e);
    }
    printf("\n%d\n", __queue.full());
    for (int i = 0; i < 11; ++i)
    {
        a = __queue.head();
        b = __queue.dequeue();
        c = __queue.headPointer;
        d = __queue.tailPointer;
        e = __queue.state;
        printf("(%d %d %d %d %d) ", a, b, c, d, e);
    }
    printf("\n%d\n", __queue.empty());
    return 0;
}
