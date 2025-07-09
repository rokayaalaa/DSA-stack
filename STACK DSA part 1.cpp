#include <iostream>
using namespace std;

class Stack {
    int size, top;
    int* a;
public:
    Stack(int size) {
        this->size = size;
        top = -1;
        a = new int[size];
    }

    ~Stack() {
        delete[] a; 
    }

    bool push(int n) {
        if (top >= size - 1) {
            cout << "This stack is overflowed\n";
            return false;
        }
        a[++top] = n;
        return true;
    }

    int pop() {
        if (top < 0) {
            cout << "This stack is underflowed\n";
            return 0;
        }
        return a[top--];
    }

    int peek() {
        if (top < 0) {
            cout << "This stack is empty\n";
            return 0;
        }
        return a[top];
    }

    bool isEmpty() {
        return top < 0;
    }

    bool change(int x, int I) {
        if (top - I + 1 < 0) {
            cout << "this stack is underflowed to change";
                return false;
        }
        a[top - I + 1] = x;
        return true;
    }


};

int main() {
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.change(99, 1);
    cout << s.pop() << " popped from the stack\n";
    cout << "Top element is: " << s.peek() << "\n";
    cout << "Elements present in stack: ";
    while (!s.isEmpty()) {
        cout << s.peek() << " ";
        s.pop();
    }

    return 0;
}
