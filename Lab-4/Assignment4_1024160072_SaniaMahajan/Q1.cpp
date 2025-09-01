#include <iostream>
#define MAX 5
using namespace std;

// Structure for Queue
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

// Function to check if queue is empty
bool isEmpty(Queue q) {
    return (q.front == -1 || q.front > q.rear);
}

// Function to check if queue is full
bool isFull(Queue q) {
    return (q.rear == MAX - 1);
}

// Function to add an element to the queue
Queue enqueue(Queue q, int value) {
    if (isFull(q)) {
        cout << "Queue is full! Cannot insert " << value << endl;
    } else {
        if (q.front == -1)  // inserting first element
            q.front = 0;
        q.rear++;
        q.arr[q.rear] = value;
        cout << value << " inserted into queue." << endl;
    }
    return q; // return updated queue
}

// Function to remove an element from the queue
Queue dequeue(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue is empty! Nothing to delete." << endl;
    } else {
        cout << q.arr[q.front] << " deleted from queue." << endl;
        q.front++;
    }
    return q; // return updated queue
}

// Function to see the first element (peek)
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
        for (int i = q.front; i <= q.rear; i++) {
            cout << q.arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    struct Queue q;
    q=init();

    int choice, value;
    while (true) {
        cout << "\n--- Queue Menu ---\n";
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
