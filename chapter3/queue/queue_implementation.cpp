#include <bits/stdc++.h>

template <class T>
class Queue
{
private:
    void init_queue() {  __queue = new T [queueSize];  }
    void dest_queue() {  if (__queue) delete [] __queue;  __queue = NULL;  }
    void shift()
    {
        for (int i = 0; i < tailPointer; ++i)
        {
            __queue[i] = __queue[i + 1];
        }
        tailPointer -= 1;
    }
public:
    int queueSize, headPointer, tailPointer;  T * __queue = NULL;
    Queue(int queueSize) : queueSize(queueSize), headPointer(-1), tailPointer(-1) {  init_queue();  }
    ~ Queue() {  dest_queue();  }
    bool empty() {  return (headPointer == -1);  }
    bool full() {  return (tailPointer == (queueSize - 1));  }
    T head() {  return (__queue[headPointer]);  }
    bool enqueue(T value)
    {
        if (full()) return false;
        if (empty())
        {
            headPointer = tailPointer = 0;
        }
        else
        {
            tailPointer += 1;
        }
        __queue[tailPointer] = value;
        return true;
    }
    bool dequeue()
    {
        if (empty()) return false;
        if (tailPointer == 0)
        {
            headPointer = tailPointer = -1;
        }
        else
        {
            shift();
        }
        return true;
    }
};

int main()
{
    Queue <int> __queue(10);
    printf("%d\n", __queue.empty());
    int a, b, c, d;
    for (int i = 10; i < 21; ++i)
    {
        a = i;
        b = __queue.enqueue(i);
        c = __queue.headPointer;
        d = __queue.tailPointer;
        printf("(%d %d %d %d) ", a, b, c, d);
    }
    printf("\n%d\n", __queue.full());
    for (int i = 10; i < 21; ++i)
    {
        a = __queue.head();
        b = __queue.dequeue();
        c = __queue.headPointer;
        d = __queue.tailPointer;
        printf("(%d %d %d %d) ", a, b, c, d);
    }
    printf("\n%d\n", __queue.empty());
    return 0;
}
