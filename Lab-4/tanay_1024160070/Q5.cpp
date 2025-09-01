// Q(5) Write a program to implement a stack using (a) Two queues and (b) One Queue. 
// (a)
// #include <iostream>
// #include <queue>
// using namespace std;

// class StackUsingTwoQueues {
//     queue<int> q1, q2;

// public:
//     void push(int x) {
//         q2.push(x);

//         while (!q1.empty()) {
//             q2.push(q1.front());
//             q1.pop();
//         }

//         swap(q1, q2);
//     }

//     void pop() {
//         if (q1.empty()) {
//             cout << "Stack Underflow!\n";
//             return;
//         }
//         cout << "Popped: " << q1.front() << endl;
//         q1.pop();
//     }

//     void top() {
//         if (q1.empty()) {
//             cout << "Stack is empty!\n";
//             return;
//         }
//         cout << "Top: " << q1.front() << endl;
//     }

//     void display() {
//         if (q1.empty()) {
//             cout << "Stack is empty!\n";
//             return;
//         }
//         cout << "Stack elements (top to bottom): ";
//         queue<int> temp = q1;
//         while (!temp.empty()) {
//             cout << temp.front() << " ";
//             temp.pop();
//         }
//         cout << endl;
//     }
// };

// //(b)
// class StackUsingOneQueue {
//     queue<int> q;

// public:
//     void push(int x) {
//         int size = q.size();
//         q.push(x);

//         // rotate elements before new element to back
//         for (int i = 0; i < size; i++) {
//             q.push(q.front());
//             q.pop();
//         }
//     }

//     void pop() {
//         if (q.empty()) {
//             cout << "Stack Underflow!\n";
//             return;
//         }
//         cout << "Popped: " << q.front() << endl;
//         q.pop();
//     }

//     void top() {
//         if (q.empty()) {
//             cout << "Stack is empty!\n";
//             return;
//         }
//         cout << "Top: " << q.front() << endl;
//     }

//     void display() {
//         if (q.empty()) {
//             cout << "Stack is empty!\n";
//             return;
//         }
//         cout << "Stack elements (top to bottom): ";
//         queue<int> temp = q;
//         while (!temp.empty()) {
//             cout << temp.front() << " ";
//             temp.pop();
//         }
//         cout << endl;
//     }
// };
    
// int main() {
//     StackUsingTwoQueues s2;
//     StackUsingOneQueue s1;

//     int choice, value, mode;
//     cout << "Choose mode: 1 for Two Queues, 2 for One Queue: ";
//     cin >> mode;

//     do {
//         cout << "\n--- Stack Menu ---\n";
//         cout << "1. Push\n";
//         cout << "2. Pop\n";
//         cout << "3. Top\n";
//         cout << "4. Display\n";
//         cout << "0. Exit\n";
//         cout << "Enter choice: ";
//         cin >> choice;

//         switch (choice) {
//         case 1:
//             cout << "Enter value: ";
//             cin >> value;
//             if (mode == 1) s2.push(value);
//             else s1.push(value);
//             break;
//         case 2:
//             if (mode == 1) s2.pop();
//             else s1.pop();
//             break;
//         case 3:
//             if (mode == 1) s2.top();
//             else s1.top();
//             break;
//         case 4:
//             if (mode == 1) s2.display();
//             else s1.display();
//             break;
//         case 0:
//             cout << "Exiting...\n";
//             break;
//         default:
//             cout << "Invalid choice!\n";
//         }
//     } while (choice != 0);

//     return 0;
// }
