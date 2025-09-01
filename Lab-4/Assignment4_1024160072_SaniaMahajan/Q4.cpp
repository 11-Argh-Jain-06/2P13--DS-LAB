#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

struct Queue {
    char arr[MAX];
    int front;
    int rear;
};

// return an initialized queue (pass-by-value style)
Queue initQueue() {
    Queue q;
    q.front = -1;
    q.rear = -1;
    return q;
}

// check empty (takes Queue by value)
bool isEmpty(Queue q) {
    return (q.front == -1);
}

// check full (takes Queue by value)
bool isFull(Queue q) {
    return (q.rear == MAX - 1);
}

// enqueue: takes Queue by value, returns updated Queue
Queue enqueue(Queue q, char ch) {
    if (isFull(q)) {
        // silent ignore if overflow (increase MAX if needed)
        return q;
    }
    if (q.front == -1) q.front = 0; // first element
    q.rear++;
    q.arr[q.rear] = ch;
    return q;
}

// dequeue: takes Queue by value, returns updated Queue
Queue dequeue(Queue q) {
    if (isEmpty(q)) return q;
    if (q.front == q.rear) {
        // after removing last element, reset to empty
        q.front = q.rear = -1;
    } else {
        q.front++;
    }
    return q;
}

// peek: returns front element (Queue passed by value)
char peek(Queue q) {
    if (isEmpty(q)) return '\0';
    return q.arr[q.front];
}

int main() {
    string line;
    cout << "Enter characters (example: a a b c  OR  aabc): ";
    getline(cin, line);

    // Build a compact string skipping spaces so both "a a b c" and "aabc" work
    string s = "";
    for (char c : line) {
        if (c != ' ') s.push_back(c);
    }

    // frequency array for ASCII chars
    int freq[256] = {0};

    // start with an empty queue
    Queue q = initQueue();

    // process characters one by one and print first non-repeating so far
    for (char ch : s) {
        unsigned char uc = (unsigned char)ch;
        freq[uc]++;          // update frequency
        q = enqueue(q, ch);  // enqueue and reassign returned queue

        // remove repeating chars from front
        while (!isEmpty(q) && freq[(unsigned char)peek(q)] > 1) {
            q = dequeue(q);
        }

        // print result for this step
        if (isEmpty(q)) cout << "-1 ";
        else cout << peek(q) << " ";
    }

    cout << endl;
    return 0;
}
