//Write a program interleave the first half of the queue with second half. 
// Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9 
#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) return;

    queue<int> firstHalf;
    for (int i = 0; i < n / 2; ++i) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int x;
    while (cin >> x) {
        q.push(x);
    }

    interleaveQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}