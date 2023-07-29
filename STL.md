# C++ - STL
<hr>

## Basic Flow
![STL Topics](./utils/Screenshot%20from%202023-07-29%2016-18-05.png)

<hr>

## 1. STL Array
- Static array
- Does not used frequently
- Operations on the STL array:
```c++
#include <array> //Library includes array
using namespace std;

int main(){

array<int,5> a={1,2,3,4,5}; //Basic implementation

// To print each element:-
int size = a.size();  //finding size of array using .size()
for (int i=0; i<size; i++){
    cout<<a[i]<<endl;
}

//To check whether array is empty or not:-
cout <<a.empty()<<endl;  //returns boolean(true or false)

//To print first and last element:-
cout<<"First Element"<<a.front()<<endl;
cout<<"Last Element"<<a.back()<<endl;

//To access any element:-
cout<<"Element at index 2: "<< a.at(2) <<endl;
}

```
<hr>

## 2. STL Vector
- Dynamic array.
- It can increase/decrease its size on its own if needed.
- Operations on the STL Vector:
```c++
#include <vector>
using namespace std;

int main(){
    // Initialisation
    vector<int> v;

    //Checking its capacity
    //Capacity shows how much space is allocated to the vector
    cout<< v.capacity()<<endl; //will show zero for now

    //To put elements in it;
    v.push_back(1); //inserting 1 inside vector
    v.push_back(2);

    //To show size
    //Size shows how many elements are present inside vector
    v.size();

    //To show first and last element :same as stl array
    v.front();  //first element
    v.back();   // last element

    //To pop element(pop can only be performed from the end)
    v.pop_back(); //this will remove the end element

    //To empty vector. Only clears the size of the vector and not the capacity of the vector.
    v.clear();

    //To initialise the vector with size;
    vector<int> a(5); //vector having size 5
    vector<int> b(5,1);} //vector having size 5 and all elements initialised to be 1: {1,1,1,1,1}

```
<hr>

## 3. STL Deque
- We can perform insertion and deletion from both the end of the deque.
- It is dynamic

```c++
#include <deque>
using namespace std;

int main(){

    //initialisation
    deque<int> d;

    //inserting elements from front and back
    d.push_front(1);
    d.push_back(2);

    //deleting elements from front and back
    d.pop_front();
    d.pop_back();

    //print random index element
    d.at(1); //element at index 1.

    //deleting specified range of elements
    d.erase(d.begin(), d.begin()+1); //deleting very first element. here its works as .erase(from, till)

    //size of deque
    d.size();

}

```
<hr>

## 4. STL List
- Implememented using doubly linked list
- we cannot access any random element from middle, we need to traverse to reach that element.
- Operations are:-
```c++
#include <list>
using namespace std;

int main(){

    //initialise
    list<int> l;

    //we can insert elements both from front and back
    l.push_front(1);
    l.push_back(2);
    
    // To print whole list
    for(int i:l){
        cout<<i;
    }

    // Size of list
    l.size();

    //copy list into another list
    list<int> a(l); //list "l" is copied into new list "a"
    //above is valid for vectors also.

}
```
<hr>

## 5. STL Stack
- Last in First Out principle.
- Operations performed are:-
```c++
#include <stack>
using namespace std;

int main(){

    //initialisation (randomly with strings)
    stack<string> s;

    //inserting elements;
    //can only be inserted from top side.(same for deleting)
    s.push("apple");
    s.push("ball");

    //deleting elements;
    s.pop();  //"ball" will be removed first as it was inserted at last.

    //size
    s.size();

    //To check if empty or not
    s.empty() //boolean

}
```
<hr>

## 6. STL Queue
- First in First Out principle
- Operations performed are:-
```c++
#include <queue>
using namespace std;

int main(){

    //initialisation
    queue<string> q;

    //insertion
    q.push("cat");
    q.push("dog");  
    q.push("rat");

    //To check the first element
    cout<<q.first() // "cat"
    
    //To remove elememts
    q.pop() //first element will be removed at first i.e."cat"

    //Size
    q.size();

}
```
<hr>

## 7.STL Priority Queue

