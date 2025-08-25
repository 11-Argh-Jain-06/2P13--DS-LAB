#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
     int *arr;
     int top;
     int capacity;

public:
     Stack(int size)
     {
          arr = new int[size];
          capacity = size;
          top = -1;
     }

     ~Stack()
     {
          delete[] arr;
     }

     void push(int x)
     {
          if (isFull())
          {
               cout << "Stack Overflow\n";
               return;
          }
          arr[++top] = x;
     }

     int pop()
     {
          if (isEmpty())
          {
               cout << "Stack Underflow\n";
               return -1;
          }
          return arr[top--];
     }

     bool isEmpty()
     {
          return top == -1;
     }

     bool isFull()
     {
          return top == capacity - 1;
     }

     int peek()
     {
          if (isEmpty())
          {
               cout << "Stack is empty\n";
               return -1;
          }
          return arr[top];
     }

     void display()
     {
          if (isEmpty())
          {
               cout << "Stack is empty\n";
               return;
          }
          cout << "Stack elements: ";
          for (int i = 0; i <= top; i++)
          {
               cout << arr[i] << " ";
          }
          cout << "\n";
     }
};

class CharStack
{
private:
     char *arr;
     int top;
     int capacity;

public:
     CharStack(int size)
     {
          arr = new char[size];
          capacity = size;
          top = -1;
     }

     ~CharStack()
     {
          delete[] arr;
     }

     void push(char x)
     {
          if (top < capacity - 1)
          {
               arr[++top] = x;
          }
     }

     char pop()
     {
          if (top >= 0)
          {
               return arr[top--];
          }
          return '\0';
     }

     bool isEmpty()
     {
          return top == -1;
     }

     char peek()
     {
          if (top >= 0)
          {
               return arr[top];
          }
          return '\0';
     }
};

class MinStack
{
private:
     int *arr;
     int *minArr;
     int top;
     int capacity;

public:
     MinStack(int size)
     {
          arr = new int[size];
          minArr = new int[size];
          capacity = size;
          top = -1;
     }

     ~MinStack()
     {
          delete[] arr;
          delete[] minArr;
     }

     void push(int x)
     {
          if (top < capacity - 1)
          {
               arr[++top] = x;
               if (top == 0)
               {
                    minArr[top] = x;
               }
               else
               {
                    minArr[top] = (x < minArr[top - 1]) ? x : minArr[top - 1];
               }
          }
     }

     int pop()
     {
          if (top >= 0)
          {
               return arr[top--];
          }
          return -1;
     }

     int getMin()
     {
          if (top >= 0)
          {
               return minArr[top];
          }
          return -1;
     }

     bool isEmpty()
     {
          return top == -1;
     }
};

void problem1()
{
     cout << "\n=== Problem 1: Stack Operations ===\n";
     Stack s(5);
     int choice, value;

     while (true)
     {
          cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check Empty\n6. Check Full\n7. Exit\n";
          cout << "Enter choice: ";
          cin >> choice;

          switch (choice)
          {
          case 1:
               cout << "Enter value to push: ";
               cin >> value;
               s.push(value);
               break;
          case 2:
               value = s.pop();
               if (value != -1)
                    cout << "Popped: " << value << "\n";
               break;
          case 3:
               value = s.peek();
               if (value != -1)
                    cout << "Top element: " << value << "\n";
               break;
          case 4:
               s.display();
               break;
          case 5:
               cout << "Stack is " << (s.isEmpty() ? "empty" : "not empty") << "\n";
               break;
          case 6:
               cout << "Stack is " << (s.isFull() ? "full" : "not full") << "\n";
               break;
          case 7:
               return;
          default:
               cout << "Invalid choice\n";
          }
     }
}

string reverseString(string str)
{
     CharStack s(str.length());
     string result = "";

     for (int i = 0; i < str.length(); i++)
     {
          s.push(str[i]);
     }

     while (!s.isEmpty())
     {
          result += s.pop();
     }

     return result;
}

bool isBalanced(string expr)
{
     CharStack s(expr.length());

     for (int i = 0; i < expr.length(); i++)
     {
          char ch = expr[i];

          if (ch == '(' || ch == '{' || ch == '[')
          {
               s.push(ch);
          }
          else if (ch == ')' || ch == '}' || ch == ']')
          {
               if (s.isEmpty())
                    return false;

               char top = s.pop();
               if ((ch == ')' && top != '(') ||
                   (ch == '}' && top != '{') ||
                   (ch == ']' && top != '['))
               {
                    return false;
               }
          }
     }

     return s.isEmpty();
}

int precedence(char op)
{
     switch (op)
     {
     case '+':
     case '-':
          return 1;
     case '*':
     case '/':
          return 2;
     case '^':
          return 3;
     default:
          return -1;
     }
}

string infixToPostfix(string infix)
{
     CharStack s(infix.length());
     string postfix = "";

     for (int i = 0; i < infix.length(); i++)
     {
          char ch = infix[i];

          if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
          {
               postfix += ch;
          }
          else if (ch == '(')
          {
               s.push(ch);
          }
          else if (ch == ')')
          {
               while (!s.isEmpty() && s.peek() != '(')
               {
                    postfix += s.pop();
               }
               if (!s.isEmpty())
                    s.pop();
          }
          else
          {
               while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch))
               {
                    postfix += s.pop();
               }
               s.push(ch);
          }
     }

     while (!s.isEmpty())
     {
          postfix += s.pop();
     }

     return postfix;
}

int evaluatePostfix(string postfix)
{
     Stack s(postfix.length());

     for (int i = 0; i < postfix.length(); i++)
     {
          char ch = postfix[i];

          if (ch >= '0' && ch <= '9')
          {
               s.push(ch - '0');
          }
          else
          {
               int val2 = s.pop();
               int val1 = s.pop();

               switch (ch)
               {
               case '+':
                    s.push(val1 + val2);
                    break;
               case '-':
                    s.push(val1 - val2);
                    break;
               case '*':
                    s.push(val1 * val2);
                    break;
               case '/':
                    s.push(val1 / val2);
                    break;
               }
          }
     }

     return s.pop();
}

void nearestSmallerElement(int arr[], int n)
{
     Stack s(n);
     cout << "Nearest smaller elements: ";

     for (int i = 0; i < n; i++)
     {
          while (!s.isEmpty() && s.peek() >= arr[i])
          {
               s.pop();
          }

          if (s.isEmpty())
          {
               cout << -1 << " ";
          }
          else
          {
               cout << s.peek() << " ";
          }

          s.push(arr[i]);
     }
     cout << "\n";
}

void nextGreaterElement(int arr[], int n)
{
     Stack s(n);
     int result[n];

     for (int i = n - 1; i >= 0; i--)
     {
          while (!s.isEmpty() && s.peek() <= arr[i])
          {
               s.pop();
          }

          if (s.isEmpty())
          {
               result[i] = -1;
          }
          else
          {
               result[i] = s.peek();
          }

          s.push(arr[i]);
     }

     cout << "Next greater elements: ";
     for (int i = 0; i < n; i++)
     {
          cout << result[i] << " ";
     }
     cout << "\n";
}

void dailyTemperatures(int temps[], int n)
{
     Stack s(n);
     int result[n];

     for (int i = n - 1; i >= 0; i--)
     {
          while (!s.isEmpty() && temps[s.peek()] <= temps[i])
          {
               s.pop();
          }

          if (s.isEmpty())
          {
               result[i] = 0;
          }
          else
          {
               result[i] = s.peek() - i;
          }

          s.push(i);
     }

     cout << "Days to wait for warmer temperature: ";
     for (int i = 0; i < n; i++)
     {
          cout << result[i] << " ";
     }
     cout << "\n";
}

bool canSort(int arr[], int n)
{
     Stack s(n);
     int expected = 1;

     for (int i = 0; i < n; i++)
     {
          s.push(arr[i]);

          while (!s.isEmpty() && s.peek() == expected)
          {
               s.pop();
               expected++;
          }
     }

     return s.isEmpty();
}

int main()
{
     int choice;

     while (true)
     {
          cout << "\n=== Stack Lab Assignment ===\n";
          cout << "1. Stack Operations Menu\n";
          cout << "2. Reverse String\n";
          cout << "3. Balanced Parentheses\n";
          cout << "4. Infix to Postfix\n";
          cout << "5. Evaluate Postfix\n";
          cout << "6. Nearest Smaller Element\n";
          cout << "7. Min Stack Demo\n";
          cout << "8. Next Greater Element\n";
          cout << "9. Daily Temperatures\n";
          cout << "10. Stack Sort Check\n";
          cout << "11. Exit\n";
          cout << "Enter choice: ";
          cin >> choice;

          switch (choice)
          {
          case 1:
               problem1();
               break;

          case 2:
          {
               string str;
               cout << "Enter string to reverse: ";
               cin >> str;
               cout << "Reversed string: " << reverseString(str) << "\n";
               break;
          }

          case 3:
          {
               string expr;
               cout << "Enter expression: ";
               cin >> expr;
               cout << "Expression is " << (isBalanced(expr) ? "balanced" : "not balanced") << "\n";
               break;
          }

          case 4:
          {
               string infix;
               cout << "Enter infix expression: ";
               cin >> infix;
               cout << "Postfix expression: " << infixToPostfix(infix) << "\n";
               break;
          }

          case 5:
          {
               string postfix;
               cout << "Enter postfix expression: ";
               cin >> postfix;
               cout << "Result: " << evaluatePostfix(postfix) << "\n";
               break;
          }

          case 6:
          {
               int n;
               cout << "Enter array size: ";
               cin >> n;
               int *arr = new int[n];
               cout << "Enter array elements: ";
               for (int i = 0; i < n; i++)
               {
                    cin >> arr[i];
               }
               nearestSmallerElement(arr, n);
               delete[] arr;
               break;
          }

          case 7:
          {
               MinStack ms(10);
               ms.push(3);
               ms.push(5);
               cout << "Min: " << ms.getMin() << "\n";
               ms.push(2);
               ms.push(1);
               cout << "Min: " << ms.getMin() << "\n";
               ms.pop();
               cout << "Min after pop: " << ms.getMin() << "\n";
               break;
          }

          case 8:
          {
               int n;
               cout << "Enter array size: ";
               cin >> n;
               int *arr = new int[n];
               cout << "Enter array elements: ";
               for (int i = 0; i < n; i++)
               {
                    cin >> arr[i];
               }
               nextGreaterElement(arr, n);
               delete[] arr;
               break;
          }

          case 9:
          {
               int n;
               cout << "Enter number of days: ";
               cin >> n;
               int *temps = new int[n];
               cout << "Enter temperatures: ";
               for (int i = 0; i < n; i++)
               {
                    cin >> temps[i];
               }
               dailyTemperatures(temps, n);
               delete[] temps;
               break;
          }

          case 10:
          {
               int n;
               cout << "Enter array size: ";
               cin >> n;
               int *arr = new int[n];
               cout << "Enter array elements: ";
               for (int i = 0; i < n; i++)
               {
                    cin >> arr[i];
               }
               cout << "Can be sorted using stack: " << (canSort(arr, n) ? "Yes" : "No") << "\n";
               delete[] arr;
               break;
          }

          case 11:
               return 0;

          default:
               cout << "Invalid choice\n";
          }
     }

     return 0;
}
