#include <bits/stdc++.h>

template <class T>
class Stack
{
private:
    inline void init_stack() {  __stack = new T [stackSize];  }
    inline void dest_stack() {  if (__stack) delete [] __stack();  __stack = NULL;  }
public:
    int stackSize, stackPointer;  T * __stack = NULL;
    Stack(int stackSize) : stackSize(stackSize), stackPointer(-1) {  init_stack();  }
    ~Stack() {  dest_stack();  }
    bool empty() {  return (stackPointer == -1);  }
    bool full() {  return (stackPointer == (stackSize - 1));  }
    bool push(T value) {  if (full()) return false;  __stack[++stackPointer] = value;  return true;  }
    bool pop() {  if (empty()) return false;  stackPointer--;  return true;}
    T top() {  return __stack[stackPointer];  }
};

int main()
{
    Stack <int> __stack(10);
    printf("%d\n", __stack.empty());
    for (int i = 0; i < 11; ++i)
    {
        printf("%d ", __stack.push(i));
    }
    printf("\n%d\n", __stack.full());
    for (int i = 0; i < 11; ++i)
    {
        printf("%d ", __stack.pop());
    }
    printf("\n%d\n", __stack.empty());
    return 0;
}
