Q1.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue* q);
bool enqueue(Queue* q, int value);
bool dequeue(Queue* q, int* value);
bool isEmpty(Queue* q);
bool isFull(Queue* q);
void display(Queue* q);
bool peek(Queue* q, int* value);
void printMenu();

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot add element %d\n", value);
        return false;
    }
    
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
    q->size++;
    printf("Element %d added to queue successfully\n", value);
    return true;
}

bool dequeue(Queue* q, int* value) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Queue is empty\n");
        return false;
    }
    
    *value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    printf("Element %d removed from queue successfully\n", *value);
    return true;
}

bool isEmpty(Queue* q) {
    return (q->size == 0);
}

bool isFull(Queue* q) {
    return (q->size == MAX_SIZE);
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue contents (front to rear): ");
    int i = q->front;
    for (int count = 0; count < q->size; count++) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
    printf("Queue size: %d/%d\n", q->size, MAX_SIZE);
}

bool peek(Queue* q, int* value) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to peek\n");
        return false;
    }
    
    *value = q->data[q->front];
    printf("Front element: %d\n", *value);
    return true;
}

void printMenu() {
    printf("\n QUEUE OPERATIONS MENU\n");
    printf("1. Enqueue (Add element)\n");
    printf("2. Dequeue (Remove element)\n");
    printf("3. Peek (View front element)\n");
    printf("4. Display queue\n");
    printf("5. Check if empty\n");
    printf("6. Check if full\n");
    printf("7. Exit\n");
    printf("\n");
    printf("Enter your choice: ");
}

int main() {
    Queue queue;
    int choice, value;
    
    initQueue(&queue);
    
    printf("Welcome to Queue Operations Program!\n");
    printf("Maximum queue size: %d\n", MAX_SIZE);
    
    while (1) {
        printMenu();
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                if (scanf("%d", &value) == 1) {
                    enqueue(&queue, value);
                } else {
                    printf("Invalid input! Please enter a valid number.\n");
                    while (getchar() != '\n');
                }
                break;
                
            case 2:
                if (dequeue(&queue, &value)) {
                }
                break;
                
            case 3:
                peek(&queue, &value);
                break;
                
            case 4:
                display(&queue);
                break;
                
            case 5:
                if (isEmpty(&queue)) {
                    printf("Queue is EMPTY\n");
                } else {
                    printf("Queue is NOT empty (contains %d elements)\n", queue.size);
                }
                break;
                
            case 6:
                if (isFull(&queue)) {
                    printf("Queue is FULL\n");
                } else {
                    printf("Queue is NOT full (%d/%d elements)\n", queue.size, MAX_SIZE);
                }
                break;
                
            case 7:
                printf("Thank you for using Queue Operations Program!\n");
                printf("Final queue state:\n");
                display(&queue);
                exit(0);
                
            default:
                printf("Invalid choice! Please select a valid option (1-7).\n");
                break;
        }
        
        printf("\nPress Enter to continue...");
        while (getchar() != '\n');
        getchar();
    }
    
    return 0;
}
// Q2.
// #include <iostream>
// using namespace std;

// #define MAX_SIZE 5

// class CircularQueue {
// private:
//     int arr[MAX_SIZE];
//     int front, rear;
//     int size;

// public:
//     CircularQueue() {
//         front = -1;
//         rear = -1;
//         size = 0;
//     }

//     bool isEmpty() {
//         return size == 0;
//     }

//     bool isFull() {
//         return size == MAX_SIZE;
//     }

//     void enqueue(int value) {
//         if (isFull()) {
//             cout << "Queue is full! Cannot enqueue " << value << endl;
//             return;
//         }
        
//         if (isEmpty()) {
//             front = 0;
//         }
        
//         rear = (rear + 1) % MAX_SIZE;
//         arr[rear] = value;
//         size++;
//         cout << value << " enqueued successfully" << endl;
//     }

//     int dequeue() {
//         if (isEmpty()) {
//             cout << "Queue is empty! Cannot dequeue" << endl;
//             return -1;
//         }
        
//         int value = arr[front];
//         if (front == rear) {
//             front = -1;
//             rear = -1;
//         } else {
//             front = (front + 1) % MAX_SIZE;
//         }
//         size--;
//         return value;
//     }

//     int peek() {
//         if (isEmpty()) {
//             cout << "Queue is empty! Cannot peek" << endl;
//             return -1;
//         }
//         return arr[front];
//     }

//     void display() {
//         if (isEmpty()) {
//             cout << "Queue is empty!" << endl;
//             return;
//         }
        
//         cout << "Queue elements: ";
//         int count = 0;
//         int i = front;
//         while (count < size) {
//             cout << arr[i] << " ";
//             i = (i + 1) % MAX_SIZE;
//             count++;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     CircularQueue queue;
//     int choice, value;

//     while (true) {
//         cout << "\nCircular Queue Menu:\n";
//         cout << "1. Enqueue\n";
//         cout << "2. Dequeue\n";
//         cout << "3. Peek\n";
//         cout << "4. Display\n";
//         cout << "5. Check if Empty\n";
//         cout << "6. Check if Full\n";
//         cout << "7. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter value to enqueue: ";
//                 cin >> value;
//                 queue.enqueue(value);
//                 break;

//             case 2:
//                 value = queue.dequeue();
//                 if (value != -1)
//                     cout << "Dequeued value: " << value << endl;
//                 break;

//             case 3:
//                 value = queue.peek();
//                 if (value != -1)
//                     cout << "Front element: " << value << endl;
//                 break;

//             case 4:
//                 queue.display();
//                 break;

//             case 5:
//                 cout << (queue.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
//                 break;

//             case 6:
//                 cout << (queue.isFull() ? "Queue is full" : "Queue is not full") << endl;
//                 break;

//             case 7:
//                 cout << "Exiting program..." << endl;
//                 return 0;

//             default:
//                 cout << "Invalid choice! Please try again." << endl;
//         }
//     }

//     return 0;
// }
// Q3.
// #include <iostream>
// using namespace std;

// #define MAX_SIZE 100

// class CircularQueue {
// private:
//     int arr[MAX_SIZE];
//     int front, rear;
//     int size;

// public:
//     CircularQueue() {
//         front = -1;
//         rear = -1;
//         size = 0;
//     }

//     bool isEmpty() {
//         return size == 0;
//     }

//     void enqueue(int value) {
//         if (size == MAX_SIZE) {
//             cout << "Queue is full!" << endl;
//             return;
//         }
//         if (isEmpty()) {
//             front = 0;
//         }
//         rear = (rear + 1) % MAX_SIZE;
//         arr[rear] = value;
//         size++;
//     }

//     int dequeue() {
//         if (isEmpty()) {
//             cout << "Queue is empty!" << endl;
//             return -1;
//         }
//         int value = arr[front];
//         if (front == rear) {
//             front = -1;
//             rear = -1;
//         } else {
//             front = (front + 1) % MAX_SIZE;
//         }
//         size--;
//         return value;
//     }

//     void interleaveQueue() {
//         if (size % 2 != 0) {
//             cout << "Queue size must be even to interleave!" << endl;
//             return;
//         }

//         int halfSize = size / 2;
//         int firstHalf[halfSize], secondHalf[halfSize];

//         for (int i = 0; i < halfSize; i++) {
//             firstHalf[i] = dequeue();
//         }

//         for (int i = 0; i < halfSize; i++) {
//             secondHalf[i] = dequeue();
//         }

//         for (int i = 0; i < halfSize; i++) {
//             enqueue(firstHalf[i]);
//             enqueue(secondHalf[i]);
//         }
//     }

//     void display() {
//         if (isEmpty()) {
//             cout << "Queue is empty!" << endl;
//             return;
//         }
//         cout << "Queue elements: ";
//         int count = 0;
//         int i = front;
//         while (count < size) {
//             cout << arr[i] << " ";
//             i = (i + 1) % MAX_SIZE;
//             count++;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     CircularQueue queue;
//     int n, value;

//     cout << "Enter the number of elements (must be even): ";
//     cin >> n;

//     if (n % 2 != 0 || n <= 0 || n > MAX_SIZE) {
//         cout << "Please enter a valid even number of elements (1 to " << MAX_SIZE << ")!" << endl;
//         return 1;
//     }

//     cout << "Enter " << n << " elements for the queue:" << endl;
//     for (int i = 0; i < n; i++) {
//         cout << "Element " << i + 1 << ": ";
//         cin >> value;
//         queue.enqueue(value);
//     }

//     cout << "\nOriginal ";
//     queue.display();

//     queue.interleaveQueue();

//     cout << "Interleaved ";
//     queue.display();

//     return 0;
// }
// Q4.
// #include <iostream>
// using namespace std;

// class Queue {
//     char* arr;
//     int front, rear, size, capacity;

// public:
//     Queue(int cap) {
//         capacity = cap;
//         arr = new char[capacity];
//         front = 0;
//         rear = -1;
//         size = 0;
//     }

//     bool isEmpty() { return size == 0; }
//     bool isFull() { return size == capacity; }

//     void enqueue(char c) {
//         if (isFull()) return;
//         rear = (rear + 1) % capacity;
//         arr[rear] = c;
//         size++;
//     }

//     char dequeue() {
//         if (isEmpty()) return '\0';
//         char c = arr[front];
//         front = (front + 1) % capacity;
//         size--;
//         return c;
//     }

//     char getFront() {
//         if (isEmpty()) return '\0';
//         return arr[front];
//     }
// };

// int main() {
//     char s[100];
//     cout << "Enter a string: ";
//     cin >> s;

//     int freq[256] = {0};
//     int len = 0;
//     while (s[len] != '\0') len++;

//     Queue q(len);

//     for (int i = 0; i < len; i++) {
//         char c = s[i];
//         freq[(int)c]++;
//         q.enqueue(c);

//         while (!q.isEmpty() && freq[(int)q.getFront()] > 1) {
//             q.dequeue();
//         }

//         if (q.isEmpty()) cout << -1 << " ";
//         else cout << q.getFront() << " ";
//     }

//     cout << endl;
//     return 0;
// }
// Q5.
// #include <iostream>
// #include <queue>
// using namespace std;

// class StackUsingTwoQueues {
// private:
//     queue<int> q1, q2;

// public:
//     void push(int value) {
//         q2.push(value);
//         while (!q1.empty()) {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         swap(q1, q2);
//     }

//     int pop() {
//         if (q1.empty()) {
//             cout << "Stack is empty!" << endl;
//             return -1;
//         }
//         int value = q1.front();
//         q1.pop();
//         return value;
//     }

//     int top() {
//         if (q1.empty()) {
//             cout << "Stack is empty!" << endl;
//             return -1;
//         }
//         return q1.front();
//     }

//     bool isEmpty() {
//         return q1.empty();
//     }
// };

// class StackUsingOneQueue {
// private:
//     queue<int> q;

// public:
//     void push(int value) {
//         q.push(value);
//         int size = q.size();
//         for (int i = 0; i < size - 1; i++) {
//             q.push(q.front());
//             q.pop();
//         }
//     }

//     int pop() {
//         if (q.empty()) {
//             cout << "Stack is empty!" << endl;
//             return -1;
//         }
//         int value = q.front();
//         q.pop();
//         return value;
//     }

//     int top() {
//         if (q.empty()) {
//             cout << "Stack is empty!" << endl;
//             return -1;
//         }
//         return q.front();
//     }

//     bool isEmpty() {
//         return q.empty();
//     }
// };

// int main() {
//     StackUsingTwoQueues stackTwo;
//     StackUsingOneQueue stackOne;
//     int choice, value, stackType;

//     cout << "Choose stack implementation (1 for Two Queues, 2 for One Queue): ";
//     cin >> stackType;

//     while (true) {
//         cout << "\nStack Menu:\n";
//         cout << "1. Push\n";
//         cout << "2. Pop\n";
//         cout << "3. Top\n";
//         cout << "4. Check if Empty\n";
//         cout << "5. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         if (stackType == 1) {
//             switch (choice) {
//                 case 1:
//                     cout << "Enter value to push: ";
//                     cin >> value;
//                     stackTwo.push(value);
//                     cout << value << " pushed to stack" << endl;
//                     break;

//                 case 2:
//                     value = stackTwo.pop();
//                     if (value != -1)
//                         cout << "Popped value: " << value << endl;
//                     break;

//                 case 3:
//                     value = stackTwo.top();
//                     if (value != -1)
//                         cout << "Top value: " << value << endl;
//                     break;

//                 case 4:
//                     cout << (stackTwo.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
//                     break;

//                 case 5:
//                     cout << "Exiting program..." << endl;
//                     return 0;

//                 default:
//                     cout << "Invalid choice!" << endl;
//             }
//         } else {
//             switch (choice) {
//                 case 1:
//                     cout << "Enter value to push: ";
//                     cin >> value;
//                     stackOne.push(value);
//                     cout << value << " pushed to stack" << endl;
//                     break;

//                 case 2:
//                     value = stackOne.pop();
//                     if (value != -1)
//                         cout << "Popped value: " << value << endl;
//                     break;

//                 case 3:
//                     value = stackOne.top();
//                     if (value != -1)
//                         cout << "Top value: " << value << endl;
//                     break;

//                 case 4:
//                     cout << (stackOne.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
//                     break;

//                 case 5:
//                     cout << "Exiting program..." << endl;
//                     return 0;

//                 default:
//                     cout << "Invalid choice!" << endl;
//             }
//         }
//     }

//     return 0;
// }
