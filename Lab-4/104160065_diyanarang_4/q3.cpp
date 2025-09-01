#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
private:
    int arr[SIZE];
    int f, r;

public:
    Queue() {
        f = r = -1;
    }

    bool isEmpty() {
        return f == -1;
    }

    bool isFull() {
        return r == SIZE - 1;
    }

    void enqueue(int value) {
        if (isFull()) return;
        if (isEmpty())
            f = r = 0;
        else
            r++;
        arr[r] = value;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[f];
        if (f == r)
            f = r = -1;
        else
            f++;
        return val;
    }

    void display() {
        if (isEmpty()) return;
        for (int i = f; i <= r; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    int size() {
        if (isEmpty()) return 0;
        return r - f + 1;
    }
};

int main() {
    Queue q;
    int n;

    cin >> n;
    if (n <= 0 || n % 2 != 0) return 1;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        q.enqueue(val);
    }

    int half = n / 2;
    int first[SIZE], second[SIZE];

    for (int i = 0; i < half; i++) {
        first[i] = q.dequeue();
    }
    for (int i = 0; i < half; i++) {
        second[i] = q.dequeue();
    }

    for (int i = 0; i < half; i++) {
        q.enqueue(first[i]);
        q.enqueue(second[i]);
    }

    q.display();
    return 0;
}
