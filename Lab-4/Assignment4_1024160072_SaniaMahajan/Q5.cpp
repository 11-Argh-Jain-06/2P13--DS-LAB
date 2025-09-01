#include <iostream>
using namespace std;

#define SIZE 10

struct Queue {
    int arr[SIZE];
    int front, rear;
};

// Initialize queue
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

// -------- Stack using two queues ----------
struct Stack {
    Queue q1, q2;
};

void initStack(Stack &s) {
    initQueue(s.q1);
    initQueue(s.q2);
}

void push(Stack &s, int val) {
    enqueue(s.q1, val);
}

int pop(Stack &s) {
    if (isEmpty(s.q1)) {
        cout << "Stack Underflow\n";
        return -1;
    }

    while (s.q1.front != s.q1.rear) {
        enqueue(s.q2, dequeue(s.q1));
    }

    int popped = dequeue(s.q1);

    Queue temp = s.q1;
    s.q1 = s.q2;
    s.q2 = temp;

    initQueue(s.q2);

    return popped;
}

int main() {
    Stack s;
    initStack(s);

    push(s, 10);
    push(s, 20);
    push(s, 30);

    cout << "Popped: " << pop(s) << endl;
    cout << "Popped: " << pop(s) << endl;

    return 0;
}
