#include <iostream>
#define MAX 5
using namespace std;

// Structure for Circular Queue
struct Queue {
    int arr[MAX];
    int front;
    int rear;
};
//initialize the queue
struct Queue init ()
{  struct Queue Q;
Q.front = Q.rear = -1;
return Q; }


// Function to check if queue is empty (Underflow)
bool isEmpty(Queue q) {
    return (q.front == q.rear && q.rear == -1);
}

// Function to check if queue is full (Overflow)
bool isFull(Queue q) {
    return (q.front == (q.rear + 1) % MAX);
}

// Function to add an element to the queue
Queue enqueue(Queue q, int value) {
    if (isFull(q)) {
        cout << "Queue Overflow! Cannot insert " << value << endl;
    } else {
        if (isEmpty(q)) { // first element
            q.front = 0;
            q.rear = 0;
        } else {
            q.rear = (q.rear + 1) % MAX;
        }
        q.arr[q.rear] = value;
        cout << value << " inserted into queue." << endl;
    }
    return q;
}

// Function to remove an element from the queue
Queue dequeue(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue Underflow! Nothing to delete." << endl;
    } else {
        cout << q.arr[q.front] << " deleted from queue." << endl;
        if (q.front == q.rear) {
            // only one element, reset queue
            q.front = -1;
            q.rear = -1;
        } else {
            q.front = (q.front + 1) % MAX;
        }
    }
    return q;
}

// Function to see the front element
void peek(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue is empty! Nothing to peek." << endl;
    } else {
        cout << "Front element is: " << q.arr[q.front] << endl;
    }
}

// Function to display all elements of queue
void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Queue elements: ";
        int i = q.front;
        while (true) {
            cout << q.arr[i] << " ";
            if (i == q.rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}

int main() {
    Queue q;
    q=init();

    int choice, value;
    while (true) {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Delete)\n";
        cout << "3. Peek (Front element)\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                q = enqueue(q, value);
                break;
            case 2:
                q = dequeue(q);
                break;
            case 3:
                peek(q);
                break;
            case 4:
                display(q);
                break;
            case 5:
                if (isEmpty(q))
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;
            case 6:
                if (isFull(q))
                    cout << "Queue is full.\n";
                else
                    cout << "Queue is not full.\n";
                break;
            case 7:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
