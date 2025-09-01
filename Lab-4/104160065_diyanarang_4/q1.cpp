#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
private:
    int arr[SIZE];
    int f, r;

public:
    Queue() {
        f = -1;
        r = -1;
    }

    bool isEmpty() {
        return f == -1 || f>r;
    }

    bool isFull() {
        return r==SIZE-1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL. Cannot enqueue.\n";
            return;
        }
        if (isEmpty()) {
            f = 0;
        }
        r++;
        arr[r] = value;
        cout << value << " enqueued to queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY. Cannot dequeue.\n";
            return;
        }
        cout << arr[f] << " dequeued from queue.\n";
        f++;
        if (f>r) {
            f = r = -1;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY.\n";
        } else {
            cout << "Front element is: " << arr[f] << "\n";
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = f; i <= r; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n----- Queue Menu -----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                if (q.isEmpty())
                    cout << "Queue is EMPTY.\n";
                else
                    cout << "Queue is NOT EMPTY.\n";
                break;
            case 5:
                if (q.isFull())
                    cout << "Queue is FULL.\n";
                else
                    cout << "Queue is NOT FULL.\n";
                break;
            case 6:
                q.display();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
