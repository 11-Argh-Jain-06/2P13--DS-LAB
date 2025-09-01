
//ques 1
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5   // Maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Function to check if the queue is full
int isFull() {
    return (rear == SIZE - 1);
}

// Function to add an element to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("\nQueue is FULL! Cannot insert %d\n", value);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
    printf("\nInserted %d into the queue\n", value);
}

// Function to remove an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("\nQueue is EMPTY! Nothing to delete\n");
        return;
    }
    printf("\nDeleted %d from the queue\n", queue[front]);
    if (front == rear) {
        // Only one element was present
        front = rear = -1;
    } else {
        front++;
    }
}

// Function to see the front element
void peek() {
    if (isEmpty()) {
        printf("\nQueue is EMPTY! Nothing at the front\n");
    } else {
        printf("\nFront element is %d\n", queue[front]);
    }
}

// Function to display the entire queue
void display() {
    if (isEmpty()) {
        printf("\nQueue is EMPTY!\n");
        return;
    }
    printf("\nQueue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main menu-driven program
int main() {
    int choice, value;
    while (1) {
        printf("\n===== Queue Menu =====\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Peek (Front Element)\n");
        printf("4. Display Queue\n");
        printf("5. Check if Empty\n");
        printf("6. Check if Full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
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
                    printf("\nQueue is EMPTY\n");
                else
                    printf("\nQueue is NOT EMPTY\n");
                break;
            case 6:
                if (isFull())
                    printf("\nQueue is FULL\n");
                else
                    printf("\nQueue is NOT FULL\n");
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}



//ques 2
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5   // Maximum size of circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Check if queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Insert element into circular queue
void enqueue(int value) {
    if (isFull()) {
        printf("\nQueue is FULL! Cannot insert %d\n", value);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = value;
    printf("\nInserted %d into the queue\n", value);
}

// Delete element from circular queue
void dequeue() {
    if (isEmpty()) {
        printf("\nQueue is EMPTY! Nothing to delete\n");
        return;
    }
    printf("\nDeleted %d from the queue\n", queue[front]);
    if (front == rear) {
        // Queue has only one element
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// Peek front element
void peek() {
    if (isEmpty()) {
        printf("\nQueue is EMPTY! Nothing at the front\n");
    } else {
        printf("\nFront element is %d\n", queue[front]);
    }
}

// Display circular queue
void display() {
    if (isEmpty()) {
        printf("\nQueue is EMPTY!\n");
        return;
    }
    printf("\nQueue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main menu-driven program
int main() {
    int choice, value;
    while (1) {
        printf("\n===== Circular Queue Menu =====\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Peek (Front Element)\n");
        printf("4. Display Queue\n");
        printf("5. Check if Empty\n");
        printf("6. Check if Full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
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
                    printf("\nQueue is EMPTY\n");
                else
                    printf("\nQueue is NOT EMPTY\n");
                break;
            case 6:
                if (isFull())
                    printf("\nQueue is FULL\n");
                else
                    printf("\nQueue is NOT FULL\n");
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}



//ques 3

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// Queue structure
typedef struct {
    int arr[SIZE];
    int front, rear;
} Queue;

// Initialize queue
void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check empty
int isEmpty(Queue *q) {
    return (q->front == -1);
}

// Check full
int isFull(Queue *q) {
    return (q->rear == SIZE - 1);
}

// Enqueue
void enqueue(Queue *q, int val) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->arr[q->rear] = val;
}

// Dequeue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return val;
}

// Display
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Interleave function
void interleaveQueue(Queue *q) {
    int n = q->rear - q->front + 1;
    if (n % 2 != 0) {
        printf("Queue must have even number of elements\n");
        return;
    }

    int half = n / 2;

    Queue firstHalf;
    init(&firstHalf);

    // Step 1: Move first half elements into another queue
    for (int i = 0; i < half; i++) {
        enqueue(&firstHalf, dequeue(q));
    }

    // Step 2: Interleave firstHalf and secondHalf
    while (!isEmpty(&firstHalf)) {
        enqueue(q, dequeue(&firstHalf));  // Take from first half
        enqueue(q, dequeue(q));           // Take from second half
    }
}

int main() {
    Queue q;
    init(&q);

    // Sample Input
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        enqueue(&q, arr[i]);
    }

    printf("Original Queue: ");
    display(&q);

    interleaveQueue(&q);

    printf("Interleaved Queue: ");
    display(&q);

    return 0;
}



//ques 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256   // Max possible characters

// Queue structure
typedef struct {
    char arr[SIZE];
    int front, rear;
} Queue;

// Initialize queue
void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if empty
int isEmpty(Queue *q) {
    return (q->front == -1);
}

// Enqueue
void enqueue(Queue *q, char ch) {
    if (q->rear == SIZE - 1) return; // No overflow check needed here
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->arr[q->rear] = ch;
}

// Dequeue
char dequeue(Queue *q) {
    if (isEmpty(q)) return '\0';
    char val = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return val;
}

// Peek front element
char peek(Queue *q) {
    if (isEmpty(q)) return '\0';
    return q->arr[q->front];
}

// Function to find first non-repeating character
void firstNonRepeating(char *str) {
    int freq[256] = {0};  // Frequency table
    Queue q;
    init(&q);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        freq[ch]++;         // Update frequency
        enqueue(&q, ch);    // Add to queue

        // Remove repeating characters from front
        while (!isEmpty(&q) && freq[peek(&q)] > 1) {
            dequeue(&q);
        }

        // Print result
        if (isEmpty(&q)) {
            printf("-1 ");
        } else {
            printf("%c ", peek(&q));
        }
    }
    printf("\n");
}

int main() {
    char str[] = "aabc";   // Sample input
    printf("Input: %s\n", str);
    printf("Output: ");
    firstNonRepeating(str);
    return 0;
}



//ques 5
a part 
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int arr[SIZE];
    int front, rear;
} Queue;

// Queue functions
void init(Queue *q) { q->front = q->rear = -1; }
int isEmptyQ(Queue *q) { return (q->front == -1); }
void enqueue(Queue *q, int val) {
    if (q->rear == SIZE - 1) return;
    if (isEmptyQ(q)) q->front = 0;
    q->arr[++q->rear] = val;
}
int dequeue(Queue *q) {
    if (isEmptyQ(q)) return -1;
    int val = q->arr[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return val;
}
int peekQ(Queue *q) { return isEmptyQ(q) ? -1 : q->arr[q->front]; }

// Stack using 2 Queues
typedef struct {
    Queue q1, q2;
} Stack;

void initStack(Stack *s) {
    init(&s->q1);
    init(&s->q2);
}

void push(Stack *s, int x) {
    enqueue(&s->q2, x);
    while (!isEmptyQ(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    // swap q1 and q2
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

int pop(Stack *s) {
    if (isEmptyQ(&s->q1)) return -1;
    return dequeue(&s->q1);
}

int top(Stack *s) {
    return peekQ(&s->q1);
}

// Driver
int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", top(&s));
    printf("Pop: %d\n", pop(&s));
    printf("Pop: %d\n", pop(&s));
    printf("Top element: %d\n", top(&s));

    return 0;
}



b part 
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int arr[SIZE];
    int front, rear;
} Queue;

void init(Queue *q) { q->front = q->rear = -1; }
int isEmptyQ(Queue *q) { return (q->front == -1); }
int sizeQ(Queue *q) { return isEmptyQ(q) ? 0 : (q->rear - q->front + 1); }
void enqueue(Queue *q, int val) {
    if (q->rear == SIZE - 1) return;
    if (isEmptyQ(q)) q->front = 0;
    q->arr[++q->rear] = val;
}
int dequeue(Queue *q) {
    if (isEmptyQ(q)) return -1;
    int val = q->arr[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return val;
}
int peekQ(Queue *q) { return isEmptyQ(q) ? -1 : q->arr[q->front]; }

// Stack using 1 Queue
typedef struct {
    Queue q;
} Stack;

void initStack(Stack *s) { init(&s->q); }

void push(Stack *s, int x) {
    int sz = sizeQ(&s->q);
    enqueue(&s->q, x);
    // rotate previous elements behind x
    for (int i = 0; i < sz; i++) {
        enqueue(&s->q, dequeue(&s->q));
    }
}

int pop(Stack *s) {
    if (isEmptyQ(&s->q)) return -1;
    return dequeue(&s->q);
}

int top(Stack *s) {
    return peekQ(&s->q);
}

// Driver
int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", top(&s));
    printf("Pop: %d\n", pop(&s));
    printf("Pop: %d\n", pop(&s));
    printf("Top element: %d\n", top(&s));

    return 0;
}
