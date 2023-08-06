#include <iostream>
using namespace std;

// Function to reverse a word given its start and end indices
void reverseWord(string s, int start, int end) {
    while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

string reversedWords(string s) {
    int start = 0;
    int end = 0;
    int n = s.length();

    while (end < n) {
        if (s[end] == ' ') {
            // If a space is found, reverse the word
            reverseWord(s, start, end - 1);
            start = end + 1; // Move the start index to the next word
        }
        end++;
    }

    // Reverse the last word (if it exists) since the loop won't handle it
    reverseWord(s, start, end - 1);

    return s;
}

int main() {
    string s = "Hello World";
    cout << "Original sentence: " << s << endl;
    s = reversedWords(s);
    cout << "Reversed sentence: " << s << endl;
    return 0;
}
