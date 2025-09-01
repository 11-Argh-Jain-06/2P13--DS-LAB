#include <iostream>
#include <queue>
#include <string>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    int freq[256] = {0}; 

    for (char ch : str) {
        q.push(ch);

        freq[ch]++;

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter characters separated by space: ";
    getline(cin, input);

    string cleaned = "";
    for (char c : input) {
        if (c != ' ')
            cleaned += c;
    }

    cout << "Output: ";
    firstNonRepeating(cleaned);

    return 0;
}
