#include <bits/stdc++.h>
template <class T>

class Stack
{
public:
    std::stack <T> __stack;
    T pop() {  T topVal = __stack.top();  __stack.pop();  return topVal;  }
    void push(T newVal) {  __stack.push(newVal);  }
    int size() {  return __stack.size();   }
};

void hanoi_recursive(int n, Stack <int> & platformA, Stack <int> & platformB, Stack <int> & platformC)
{
    if (n == 1)
    {
        platformC.push(platformA.pop());
    }
    else
    {
        hanoi_recursive(n - 1, platformA, platformC, platformB);
        hanoi_recursive(1, platformA, platformB, platformC);
        hanoi_recursive(n - 1, platformB, platformA, platformC);
    }
}

void print_stack(Stack <int> & targetStack)
{
    Stack <int> tempStack;
    for (int i = 0, n = targetStack.size(); i < n; ++i)
    {
        tempStack.push(targetStack.pop());
    }
    for (int i = 0, top, n = tempStack.size(); i < n; ++i)
    {
        top = tempStack.pop();
        printf("%d ", top);
        targetStack.push(top);
    }
    printf("\n");
}

int main()
{
    Stack <int> platformA, platformB, platformC;
    int n = 5;
    for (int i = n; i > 0; --i)
    {
        platformA.push(i);
    }
    print_stack(platformA);
    hanoi_recursive(n, platformA, platformB, platformC);
    print_stack(platformC);

    return 0;
}
