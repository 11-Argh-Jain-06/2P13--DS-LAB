/*Develop a menu driven program demonstrating the following operations on simple
Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5   //size of queue

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (rear == MAX - 1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is FULL! Cannot insert %d\n", value);
        return;
    }
    if (front == -1) front = 0; 
    rear++;
    queue[rear] = value;
    printf("%d enqueued into queue.\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY! Cannot dequeue.\n");
        return;
    }
    printf("%d dequeued from queue.\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void peek() {
    if (isEmpty()) {
        printf("Queue is EMPTY! No front element.\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Menu\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.PeekFront\n");
        printf("4. Display Queue\n");
        printf("5. Check ifEmpty\n");
        printf("6. Check ifFull\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            if (isEmpty())
                printf("Queue is EMPTY.\n");
            else
                printf("Queue is NOT EMPTY.\n");
            break;
        case 6:
            if (isFull())
                printf("Queue is FULL.\n");
            else
                printf("Queue is NOT FULL.\n");
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}


/*Develop a menu driven program demonstrating the following operations on Circular Queues:
enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5 

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((rear + 1) % MAX == front);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is FULL! Cannot insert %d\n", value);
        return;
    }
    if (front == -1) 
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("%d enqueued into queue.\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY! Cannot dequeue.\n");
        return;
    }
    printf("%d dequeued from queue.\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void peek() {
    if (isEmpty()) {
        printf("Queue is EMPTY! No front element.\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Check if Empty\n");
        printf("6. Check if Full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            if (isEmpty())
                printf("Queue is EMPTY.\n");
            else
                printf("Queue is NOT EMPTY.\n");
            break;
        case 6:
            if (isFull())
                printf("Queue is FULL.\n");
            else
                printf("Queue is NOT FULL.\n");
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

/*Write a program interleave the first half of the queue with second half.
Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9*/

#include <stdio.h>
#define MAX 100

void interleaveQueue(int arr[], int n) {
    if (n % 2 != 0) {
        printf("Queue size must be even to interleave.\n");
        return;
    }

    int half = n / 2;
    int result[MAX];
    int idx = 0;

    for (int i = 0; i < half; i++) {
        result[idx++] = arr[i];      
        result[idx++] = arr[i + half];
    }

    printf("Interleaved Queue: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 7, 11, 20, 5, 9}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Queue: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    interleaveQueue(arr, n);

    return 0;
}

/*Write a program to find first non-repeating character in a string using Queue.
Sample I/P: a a b c Sample O/P: a -1 b b*/

#include <stdio.h>
#include <string.h>
#define MAX 256  

#define SIZE 1000
char queue[SIZE];
int front = 0, rear = -1;

void enqueue(char c) {
    if (rear < SIZE - 1) {
        queue[++rear] = c;
    }
}

void dequeue() {
    if (front <= rear) {
        front++;
    }
}

int isEmpty() {
    return (front > rear);
}

char getFront() {
    return queue[front];
}

void resetQueue() {
    front = 0;
    rear = -1;
}

int main() {
    char str[] = "aabc";   
    int freq[MAX] = {0};
    int n = strlen(str);

    printf("Input: %s\n", str);
    printf("Output: ");

    resetQueue();

    for (int i = 0; i < n; i++) {
        char ch = str[i];
        freq[ch]++;
        enqueue(ch);

        while (!isEmpty() && freq[getFront()] > 1) {
            dequeue();
        }

        if (isEmpty())
            printf("-1 ");
        else
            printf("%c ", getFront());
    }

    printf("\n");
    return 0;
}

/*Write a program to implement a stack using (a) Two queues and (b) One Queue*/

a. Using two queues:

#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2; // two queues

// Push operation
void push(int x) {
    q2.push(x);

    // move all elements of q1 into q2
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }

    // swap q1 and q2
    swap(q1, q2);
}

// Pop operation
void pop() {
    if (q1.empty()) {
        cout << "Stack is empty\n";
        return;
    }
    q1.pop();
}

// Top element
int top() {
    if (q1.empty()) return -1;
    return q1.front();
}

// Current size
int size() {
    return q1.size();
}

int main() {
    push(1);
    push(2);
    push(3);

    cout << "Current size: " << size() << endl;

    cout << top() << endl; // 3
    pop();
    cout << top() << endl; // 2
    pop();
    cout << top() << endl; // 1

    cout << "Current size: " << size() << endl;
    return 0;
}

b. Using one queue

#include <iostream>
#include <queue>
using namespace std;

queue<int> q; //one queue

// Push operation
void push(int x) {
    int s = q.size();
    q.push(x);

    // Rotate previous elements behind x
    for (int i = 0; i < s; i++) {
        q.push(q.front());
        q.pop();
    }
}

// Pop operation
void pop() {
    if (q.empty()) {
        cout << "Stack is empty\n";
        return;
    }
    q.pop();
}

// Top element
int top() {
    if (q.empty()) return -1;
    return q.front();
}

// Current size
int size() {
    return q.size();
}

int main() {
    push(1);
    push(2);
    push(3);

    cout << "Current size: " << size() << endl;

    cout << top() << endl;
    pop();
    cout << top() << endl; 
    pop();
    cout << top() << endl; 

    cout << "Current size: " << size() << endl;
    return 0;
}
