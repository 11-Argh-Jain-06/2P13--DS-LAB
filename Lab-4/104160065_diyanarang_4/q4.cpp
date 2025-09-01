#include <iostream>
using namespace std;

#define SIZE 1000

class Queue {
private:
    char arr[SIZE];
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

    void enqueue(char ch) {
        if (isFull()) return;
        if (isEmpty())
            f = r = 0;
        else
            r++;
        arr[r] = ch;
    }

    char dequeue() {
        if (isEmpty()) return '\0';
        char val = arr[f];
        if (f == r)
            f = r = -1;
        else
            f++;
        return val;
    }

    char front() {
        if (isEmpty()) return '\0';
        return arr[f];
    }
};

int main() {
    char str[SIZE];
    cin.getline(str, SIZE);

    int freq[256] = {0};
    Queue q;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        freq[ch]++;
        q.enqueue(ch);

        while (!q.isEmpty() && freq[q.front()] > 1) {
            q.dequeue();
        }

        if (q.isEmpty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }

    cout << "\n";
    return 0;
}
