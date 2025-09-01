#include <iostream>
using namespace std;

#define MAX 100

struct Queue {
    int arr[MAX];
    int front;
    int rear;
    int size;
};

// initialize queue
Queue initQueue(int n) {
    Queue q;
    q.front = 0;
    q.rear = -1;
    q.size = n;
    return q;
}

// enqueue
Queue enqueue(Queue q, int x) {
    if (q.rear == q.size - 1) {
        cout << "Queue is full" << endl;
    } else {
        q.rear++;
        q.arr[q.rear] = x;
    }
    return q;
}

// display
void display(Queue q) {
    for (int i = q.front; i <= q.rear; i++) {
        cout << q.arr[i] << " ";
    }
    cout << endl;
}

// interleave function
Queue interleave(Queue q) {
    int n = q.rear - q.front + 1;  // total elements
    int half = n / 2;

    int firstHalf[MAX], secondHalf[MAX];
    int f1 = 0, f2 = 0;

    // divide into two halves
    for (int i = 0; i < half; i++) {
        firstHalf[i] = q.arr[i];
    }
    for (int i = half; i < n; i++) {
        secondHalf[i - half] = q.arr[i];
    }

    // put back interleaved
    Queue newQ = initQueue(n);
    for (int i = 0; i < half; i++) {
        newQ = enqueue(newQ, firstHalf[i]);
        newQ = enqueue(newQ, secondHalf[i]);
    }

    return newQ;
}

int main() {
    int n;
    cout << "Enter number of elements (even): ";
    cin >> n;

    Queue q = initQueue(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q = enqueue(q, x);
    }

    cout << "Original Queue: ";
    display(q);

    q = interleave(q);

    cout << "Interleaved Queue: ";
    display(q);

    return 0;
}
