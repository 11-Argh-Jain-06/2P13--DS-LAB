/*Develop a menu driven program demonstrating the following operations on a Stack using array: (i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().*/

#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 5   //size

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    void push(int val) {
        if (isFull()) {
            cout << "overflow" << val << endl;
        } else {
            arr[++top] = val;
            cout << "\n" << val << " pushed"<<endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "underflow"<<endl;
        } else {
            cout << arr[top--] << "popped"<<endl;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "stack empty"<<endl;
        } else {
            cout << "top element is: " << arr[top] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "stack is empty"<<endl;
        } else {
            cout << "stack elements are: "<<endl;
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, val;

    while (true) {
        cout << "1.push"<<endl;
        cout << "2.pop"<<endl;
        cout << "3.peek"<<endl;
        cout << "4.display"<<endl;
        cout << "5.isEmpty"<<endl;
        cout << "6.isFull"<<endl;
        cout << "7.exit"<<endl;
        cout << "choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "enter value to push: ";
            cin >> val;
            s.push(val);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        case 5:
            if (s.isEmpty())
                cout << "stack is empty"<<endl;
            else
                cout << "stack is not empty"<<endl;
            break;
        case 6:
            if (s.isFull())
                cout << "stack is full"<<endl;
            else
                cout << "stack is not full"<<endl;
            break;
        case 7:
            exit(0);
        default:
            cout << "invalid choice"<<endl;
        }
    }

    return 0;
}




/*Given a string, reverse it using STACK. For example “DataStructure” should be output as “erutcurtSataD.”*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string str) {
    stack<char> s;
    
    for (char ch : str) {
        s.push(ch);
    }

    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return reversed;
}

int main() {
    string input;
    cout << "enter a string: ";
    getline(cin, input); 
    cout << "reversed String: " << reverseString(input) << endl;

    return 0;
}


//Write a program that checks if an expression has balanced parentheses.

#include <iostream>
#include <stack>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')');
}

bool isBalanced(string expr) {
    stack<char> s;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty() || !isMatching(s.top(), ch)) {
                return false;  
            }
            s.pop();
        }
    }

    return s.empty();  
}

int main() {
    string expr;
    cout << "enter an expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "balanced expression " << endl;
    else
        cout << "unbalanced expression" << endl;

    return 0;
}


//Write a program to convert an Infix expression into a Postfix expression.

#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) postfix += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix = "A*(B*C+D/E^F)";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}


//Write a program for the evaluation of a Postfix expression.

#include <iostream>
#include <stack>
#include <cctype> 
using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> s;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        else {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(b + a); break;
                case '-': s.push(b - a); break;
                case '*': s.push(b * a); break;
                case '/': s.push(b / a); break;
                case '^': {
                    int result = 1;
                    for (int i = 0; i < a; i++) result *= b;
                    s.push(result);
                    break;
                }
            }
        }
    }
    return s.top();
}

int main() {
    string postfix = "376+/9^8"; 

    cout << "Postfix Expression: " << postfix << endl;
    cout << "Result: " << evaluatePostfix(postfix) << endl;

    return 0;
}
