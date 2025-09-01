#include <iostream>
using namespace std;

class SimpleQueue {
private:
    int* arr;
    int front, rear, capacity;

public:
    SimpleQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~SimpleQueue() {
        delete[] arr;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int x = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return x;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

class CircularQueue {
private:
    int* arr;
    int front, rear, capacity, size;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int x = arr[front];
        front = (front + 1) % capacity;
        size--;
        return x;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << "\n";
    }

    int getSize() {
        return size;
    }

    int get(int index) {
        if (index >= size) return -1;
        return arr[(front + index) % capacity];
    }
};

class QueueForStack {
private:
    int* arr;
    int front, rear, capacity;

public:
    QueueForStack(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    ~QueueForStack() {
        delete[] arr;
    }

    void enqueue(int x) {
        if (rear == capacity - 1) return;
        arr[++rear] = x;
    }

    int dequeue() {
        if (front > rear) return -1;
        return arr[front++];
    }

    bool isEmpty() {
        return front > rear;
    }

    int size() {
        return rear - front + 1;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

class StackUsingTwoQueues {
private:
    QueueForStack q1, q2;

public:
    StackUsingTwoQueues(int size) : q1(size), q2(size) {}

    void push(int x) {
        q1.enqueue(x);
    }

    int pop() {
        if (q1.isEmpty()) return -1;
        
        while (q1.size() > 1) {
            q2.enqueue(q1.dequeue());
        }
        
        int popped = q1.dequeue();
        
        while (!q2.isEmpty()) {
            q1.enqueue(q2.dequeue());
        }
        
        return popped;
    }

    int top() {
        if (q1.isEmpty()) return -1;
        
        while (q1.size() > 1) {
            q2.enqueue(q1.dequeue());
        }
        
        int topElement = q1.getFront();
        q2.enqueue(q1.dequeue());
        
        while (!q2.isEmpty()) {
            q1.enqueue(q2.dequeue());
        }
        
        return topElement;
    }

    bool isEmpty() {
        return q1.isEmpty();
    }
};

class StackUsingOneQueue {
private:
    QueueForStack q;

public:
    StackUsingOneQueue(int size) : q(size) {}

    void push(int x) {
        int size = q.size();
        q.enqueue(x);
        
        for (int i = 0; i < size; i++) {
            q.enqueue(q.dequeue());
        }
    }

    int pop() {
        if (q.isEmpty()) return -1;
        return q.dequeue();
    }

    int top() {
        if (q.isEmpty()) return -1;
        return q.getFront();
    }

    bool isEmpty() {
        return q.isEmpty();
    }
};

void interleaveQueue() {
    cout << "Enter size of queue: ";
    int n;
    cin >> n;
    
    CircularQueue q(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.enqueue(x);
    }
    
    CircularQueue result(n);
    int half = n / 2;
    
    for (int i = 0; i < half; i++) {
        result.enqueue(q.get(i));
        result.enqueue(q.get(half + i));
    }
    
    cout << "Interleaved queue: ";
    result.display();
}

void firstNonRepeatingChar() {
    cout << "Enter string: ";
    string s;
    cin >> s;
    
    CircularQueue q(26);
    int freq[26] = {0};
    
    cout << "Output: ";
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        freq[c - 'a']++;
        
        if (freq[c - 'a'] == 1) {
            q.enqueue(c);
        }
        
        while (!q.isEmpty() && freq[q.peek() - 'a'] > 1) {
            q.dequeue();
        }
        
        if (q.isEmpty()) {
            cout << "-1 ";
        } else {
            cout << (char)q.peek() << " ";
        }
    }
    cout << "\n";
}

void generateBinaryNumbers() {
    cout << "Enter n: ";
    int n;
    cin >> n;
    
    CircularQueue q(n * 10);
    q.enqueue(1);
    
    cout << "Binary numbers from 1 to " << n << ": ";
    for (int i = 1; i <= n; i++) {
        int front = q.dequeue();
        cout << front;
        if (i < n) cout << ", ";
        
        q.enqueue(front * 10);
        q.enqueue(front * 10 + 1);
    }
    cout << "\n";
}

void sortQueue() {
    cout << "Enter size: ";
    int n;
    cin >> n;
    
    CircularQueue q(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.enqueue(x);
    }
    
    for (int i = 0; i < n; i++) {
        int minIndex = 0;
        int minVal = q.dequeue();
        q.enqueue(minVal);
        
        for (int j = 1; j < n - i; j++) {
            int curr = q.dequeue();
            if (curr < minVal) {
                minVal = curr;
                minIndex = j;
            }
            q.enqueue(curr);
        }
        
        for (int j = 0; j < n - i; j++) {
            int curr = q.dequeue();
            if (j != minIndex) {
                q.enqueue(curr);
            }
        }
        
        cout << minVal << " ";
    }
    cout << "\n";
}

bool checkQueueSortable() {
    cout << "Enter size: ";
    int n;
    cin >> n;
    
    CircularQueue inputQueue(n);
    cout << "Enter queue elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        inputQueue.enqueue(x);
    }
    
    SimpleQueue stack(n);
    CircularQueue outputQueue(n);
    int expected = 1;
    
    while (!inputQueue.isEmpty() || !stack.isEmpty()) {
        if (!stack.isEmpty() && stack.peek() == expected) {
            outputQueue.enqueue(stack.dequeue());
            expected++;
        } else if (!inputQueue.isEmpty()) {
            stack.enqueue(inputQueue.dequeue());
        } else {
            return false;
        }
    }
    
    return true;
}

int studentsUnableToEat() {
    cout << "Enter number of students: ";
    int n;
    cin >> n;
    
    CircularQueue students(n);
    SimpleQueue sandwiches(n);
    
    cout << "Enter student preferences (0 for circular, 1 for square): ";
    for (int i = 0; i < n; i++) {
        int pref;
        cin >> pref;
        students.enqueue(pref);
    }
    
    cout << "Enter sandwiches (0 for circular, 1 for square): ";
    for (int i = 0; i < n; i++) {
        int sandwich;
        cin >> sandwich;
        sandwiches.enqueue(sandwich);
    }
    
    int rotations = 0;
    while (!students.isEmpty() && !sandwiches.isEmpty() && rotations < students.getSize()) {
        if (students.peek() == sandwiches.peek()) {
            students.dequeue();
            sandwiches.dequeue();
            rotations = 0;
        } else {
            students.enqueue(students.dequeue());
            rotations++;
        }
    }
    
    return students.getSize();
}

void simpleQueueMenu() {
    SimpleQueue q(100);
    int choice, value;
    
    do {
        cout << "\n--- Simple Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check Empty\n6. Check Full\n7. Back\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                value = q.dequeue();
                if (value != -1) cout << "Dequeued: " << value << "\n";
                break;
            case 3:
                value = q.peek();
                if (value != -1) cout << "Front element: " << value << "\n";
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << "\n";
                break;
            case 6:
                cout << (q.isFull() ? "Queue is full" : "Queue is not full") << "\n";
                break;
        }
    } while (choice != 7);
}

void circularQueueMenu() {
    CircularQueue q(100);
    int choice, value;
    
    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check Empty\n6. Check Full\n7. Back\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                value = q.dequeue();
                if (value != -1) cout << "Dequeued: " << value << "\n";
                break;
            case 3:
                value = q.peek();
                if (value != -1) cout << "Front element: " << value << "\n";
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << "\n";
                break;
            case 6:
                cout << (q.isFull() ? "Queue is full" : "Queue is not full") << "\n";
                break;
        }
    } while (choice != 7);
}

void stackUsingQueuesMenu() {
    cout << "Choose implementation:\n1. Using Two Queues\n2. Using One Queue\n";
    int impl;
    cin >> impl;
    
    if (impl == 1) {
        StackUsingTwoQueues stack(100);
        int choice, value;
        
        do {
            cout << "\n--- Stack Using Two Queues ---\n";
            cout << "1. Push\n2. Pop\n3. Top\n4. Check Empty\n5. Back\n";
            cout << "Enter choice: ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> value;
                    stack.push(value);
                    break;
                case 2:
                    value = stack.pop();
                    if (value != -1) cout << "Popped: " << value << "\n";
                    break;
                case 3:
                    value = stack.top();
                    if (value != -1) cout << "Top element: " << value << "\n";
                    break;
                case 4:
                    cout << (stack.isEmpty() ? "Stack is empty" : "Stack is not empty") << "\n";
                    break;
            }
        } while (choice != 5);
    } else {
        StackUsingOneQueue stack(100);
        int choice, value;
        
        do {
            cout << "\n--- Stack Using One Queue ---\n";
            cout << "1. Push\n2. Pop\n3. Top\n4. Check Empty\n5. Back\n";
            cout << "Enter choice: ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> value;
                    stack.push(value);
                    break;
                case 2:
                    value = stack.pop();
                    if (value != -1) cout << "Popped: " << value << "\n";
                    break;
                case 3:
                    value = stack.top();
                    if (value != -1) cout << "Top element: " << value << "\n";
                    break;
                case 4:
                    cout << (stack.isEmpty() ? "Stack is empty" : "Stack is not empty") << "\n";
                    break;
            }
        } while (choice != 5);
    }
}

int main() {
    int choice;
    
    do {
        cout << "\n=== QUEUE ASSIGNMENT MENU ===\n";
        cout << "1. Simple Queue Operations\n";
        cout << "2. Circular Queue Operations\n";
        cout << "3. Interleave Queue Halves\n";
        cout << "4. First Non-Repeating Character\n";
        cout << "5. Stack Using Queues\n";
        cout << "6. Generate Binary Numbers\n";
        cout << "7. Sort Queue Without Extra Space\n";
        cout << "8. Check Queue Sortability Using Stack\n";
        cout << "9. Students Unable to Eat Lunch\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                simpleQueueMenu();
                break;
            case 2:
                circularQueueMenu();
                break;
            case 3:
                interleaveQueue();
                break;
            case 4:
                firstNonRepeatingChar();
                break;
            case 5:
                stackUsingQueuesMenu();
                break;
            case 6:
                generateBinaryNumbers();
                break;
            case 7:
                sortQueue();
                break;
            case 8:
                cout << (checkQueueSortable() ? "Yes, queue can be sorted" : "No, queue cannot be sorted") << "\n";
                break;
            case 9:
                cout << "Students unable to eat: " << studentsUnableToEat() << "\n";
                break;
            case 10:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 10);
    
    return 0;
}