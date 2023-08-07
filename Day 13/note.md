# What is "cin.getline()" ?
1. Similar to cin, it is particularly useful **when you want to read an entire line of text, including spaces, and store it as a single string**. This function helps avoid issues with spaces breaking up the input when using cin directly.

        cin.getline(charArray, sizeof(charArray));

3. ex. 
```c++
#include <iostream>
using namespace std;

int main() {
    char name[50];

    cout << "Enter your name: ";
    cin.getline(name, sizeof(name));

    std::cout << "Hello, " << name << "!" <<endl;

    return 0;
}
```
        Output: Enter your name: Vishal Jaiswal
                Hello, Vishal Jaiswal

# The key differences between cin and getline() are:

### Reading Behavior:

- cin reads input until a whitespace character is encountered.
- getline() reads input until a newline character is encountered.

### Handling Spaces:

- cin doesn't read spaces and stops at the first space or newline.
- getline() reads the entire line, including spaces.

### Usage:

- Use cin when you want to read individual words or numbers separated by spaces.
- Use getline() when you want to read entire lines of text, including spaces.


# What are "Custom Delimeters" ?
1. Delimiters(also known as separators) are commonly **used to divide a string into smaller parts**, making it easier to process or analyze the content.
2. In programming, delimiters are often used with functions like getline() and parsing functions to break down input into meaningful pieces. 
3. **By default, functions like getline() use newline characters ('\n') as delimiters to separate lines of text**. However, in some cases, you might want to use a different character or sequence of characters as the delimiter.
4.  However, in some cases, you might want to use a different character or sequence of characters as the delimiter.
5. ex. In this example, we're using a custom delimiter (a comma ,) to split the input string into individual items. 
```c++
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string input = "apple,orange,banana,grape";
    char delimiter = ',';

    //istringstream("input string stream") is used for reading formatted input from a string.
    //"iss" is simply a variable name used in the example to represent an instance of the istringstream class.
    istringstream iss(input);
    string item;

    while (std::getline(iss, item, delimiter)) {
        std::cout << "Item: " << item << std::endl;
    }

    return 0;
}
```
        Output: Word: Hello
                Word: world
                Word: this
                Word: is
                Word: a
                Word: custom
                Word: delimiter
                Word: example

# find() and remove() functions

1. part of \<string> header.
2. **find()** Function:
The find() function is used to locate the position (index) of a substring within a string. It **returns the position of the first occurrence of the substring**.
```c++
#include <iostream>
#include <string>
using namespace std;

int main() {

    string sentence = "Hello, world!";
    //size_t is an unsigned int--> only positive values
    size_t position = sentence.find("world"); // Find the position of "world"

    if (position != -1) {
        cout << "Found 'world' at position: " << position << endl;
    } else {
        cout << "'world' not found in the sentence." << endl;
    }

    return 0;
}
```
       Output: Found 'world' at position: 7 
3. **remove()** Function:
The remove() function is used to **erase characters from a string**. It takes two arguments: the starting position and the number of characters to remove.
(*It doesn't actually remove the characters from memory; it simply shifts the characters after the specified range to fill the gap.*)
```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "OpenAI GPT-3 is amazing!";

    text.erase(12, 10); // Remove characters starting from index 12, removing 10 characters

    cout << "Modified text: " << text <<endl;

    return 0;
}
```
        Output: OpenAI is amazing!