//Develop a menu driven program demonstrating the following operations on simple Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
#include <iostream>
#include <queue>
using namespace std;
#define MAX 10
class Queue{
    private:
        int arr[MAX];
        int front, rear;
    public:
        Queue(){
            front = -1;
            rear = -1;
        }  
        bool isEmpty(){
            return front == -1 && rear == -1;
        }
        bool isFull(){
            return rear == MAX - 1;
        }
        void enqueue(int x){
            if(isFull()){
                cout << "Overflow" << endl;
            } else {
                if(isEmpty()){
                    front = 0;
                    rear = 0;
                } else {
                    rear = rear + 1;
                }
                arr[rear] = x;
            }
        }
        void dequeue(){
            if(isEmpty()){
                cout << "Underflow" << endl;
            } else if(front == rear){
                front = -1;
                rear = -1;
            } else {
                front = front + 1;
            }
        }
        void peek(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
            } else {
                cout << "Front element is: " << arr[front] << endl;
            }
        }
        void display(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
            } else {
                cout << "Queue elements are: ";
                for(int i = front; i <= rear; i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};
int main(){
    Queue q;
    int choice,value;
    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
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
            q.display();
            break;
        case 5:
            if (q.isEmpty())
                cout << "Queue is empty." << endl;
            else
                cout << "Queue is not empty." << endl;
            break;
        case 6:
            if (q.isFull())
                cout << "Queue is full." << endl;
            else
                cout << "Queue is not full." << endl;
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}

