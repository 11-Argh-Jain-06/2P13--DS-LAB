#include <iostream>
using namespace std;

#define SIZE 10

struct Queue {
    int arr[SIZE];
    int front, rear;
};

void initQueue(Queue &q) {
    q.front = q.rear = -1;
}

bool isEmpty(Queue q) {
    return (q.front == -1);
}

bool isFull(Queue q) {
    return (q.rear == SIZE - 1);
}

void enqueue(Queue &q, int val) {
    if (isFull(q)) {
        cout << "Queue Overflow\n";
        return;
    }
    if (isEmpty(q)) q.front = 0;
    q.arr[++q.rear] = val;
}

int dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue Underflow\n";
        return -1;
    }
    int val = q.arr[q.front];
    if (q.front == q.rear) {
        q.front = q.rear = -1;
    } else {
        q.front++;
    }
    return val;
}

// -------- Stack using one queue ----------
struct Stack {
    Queue q;
};

void initStack(Stack &s) {
    initQueue(s.q);
}

void push(Stack &s, int val) {
    enqueue(s.q, val);

    int size = s.q.rear - s.q.front;
    for (int i = 0; i < size; i++) {
        enqueue(s.q, dequeue(s.q));
    }
}

int pop(Stack &s) {
    if (isEmpty(s.q)) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return dequeue(s.q);
}

int main() {
    Stack s;
    initStack(s);

    push(s, 5);
    push(s, 15);
    push(s, 25);

    cout << "Popped: " << pop(s) << endl;
    cout << "Popped: " << pop(s) << endl;

    return 0;
}
