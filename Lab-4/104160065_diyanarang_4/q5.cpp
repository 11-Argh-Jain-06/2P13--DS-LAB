// (a)

#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
public:
    int arr[SIZE];
    int f, r;

    Queue() {
        f = r = -1;
    }

    bool isEmpty() {
        return f == -1;
    }

    bool isFull() {
        return r == SIZE - 1;
    }

    void enqueue(int val) {
        if (isFull()) return;
        if (isEmpty()) f = r = 0;
        else r++;
        arr[r] = val;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[f];
        if (f == r) f = r = -1;
        else f++;
        return val;
    }

    int front() {
        if (isEmpty()) return -1;
        return arr[f];
    }

    int size() {
        if (isEmpty()) return 0;
        return r - f + 1;
    }
};

class Stack {
    Queue q1, q2;

public:
    void push(int x) {
        q2.enqueue(x);
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop() {
        if (!q1.isEmpty()) q1.dequeue();
    }

    int top() {
        return q1.front();
    }

    bool isEmpty() {
        return q1.isEmpty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.top() << "\n";  // 30
    s.pop();
    cout << s.top() << "\n";  // 20
    s.pop();
    cout << s.top() << "\n";  // 10
    return 0;
}

// (b)

// #include <iostream>
// using namespace std;

// #define SIZE 100

// class Queue {
// public:
//     int arr[SIZE];
//     int f, r;

//     Queue() {
//         f = r = -1;
//     }

//     bool isEmpty() {
//         return f == -1;
//     }

//     bool isFull() {
//         return r == SIZE - 1;
//     }

//     void enqueue(int val) {
//         if (isFull()) return;
//         if (isEmpty()) f = r = 0;
//         else r++;
//         arr[r] = val;
//     }

//     int dequeue() {
//         if (isEmpty()) return -1;
//         int val = arr[f];
//         if (f == r) f = r = -1;
//         else f++;
//         return val;
//     }

//     int front() {
//         if (isEmpty()) return -1;
//         return arr[f];
//     }

//     int size() {
//         if (isEmpty()) return 0;
//         return r - f + 1;
//     }
// };

// class Stack {
//     Queue q;

// public:
//     void push(int x) {
//         q.enqueue(x);
//         int sz = q.size();
//         for (int i = 1; i < sz; i++) {
//             q.enqueue(q.dequeue());
//         }
//     }

//     void pop() {
//         if (!q.isEmpty()) q.dequeue();
//     }

//     int top() {
//         return q.front();
//     }

//     bool isEmpty() {
//         return q.isEmpty();
//     }
// };

// int main() {
//     Stack s;
//     s.push(5);
//     s.push(15);
//     s.push(25);
//     cout << s.top() << "\n";  // 25
//     s.pop();
//     cout << s.top() << "\n";  // 15
//     s.pop();
//     cout << s.top() << "\n";  // 5
//     return 0;
// }
