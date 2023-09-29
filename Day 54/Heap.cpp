//What is Complete Binary Tree?
//A complete binary tree is a binary tree in which every level, 
//except possibly the last, 
//is completely filled.
//Or Last level is partially filled. (Right cnnot be filled before left)
//Ex. 
/*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
      / \   
     8   9
Can be complete binary tree       
*/ 
/*
            1
          /   \
         2     3
        / \   / 
       4   5 6   
      /     \
     8       10
Not a complete binary tree
*/
/*
    Rule: All the levels must be filled from left to right except the last level
    Rule: Last level must be filled from left to right
        //(if there is right child then there must be left child)
*/


//What is Heap?
//Heap is a complete binary tree
//Min Heap: Every node is smaller than its children
//Max Heap: Every node is greater than its children

#include <bits/stdc++.h>
using namespace std;

//When Heap is represented using array(leave 0th index and start from 1st index)
//Left Child: 2*i
//Right Child: 2*i+1
//Parent: (i)/2
class heap{
    public:
        int arr[100];
        int size;

        //constructor
        heap(){
            size = 0;
            arr[0] = -1;
        }

        //insertion in maxheap
        void insert(int val){
            size = size + 1; //size++
            int index = size; //last index
            arr[index] = val; //insert at last index

            //Compare with parent
            while(index > 1){
                int parent = index/2;
                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        }

        //deletion in maxheap
        void deleteFromHeap(){
            if(size == 0){
                cout<<"Heap is empty"<<endl;
                return;
            }
                //swap root with last element
                arr[1] = arr[size]; //replace root with last element
                size = size - 1; //size--

                //taking the root to its correct position
                int index = 1; //root index
                while(index < size){
                    int left = 2*index;
                    int right = 2*index + 1;

                    if(arr[left] > arr[index] && left <= size){
                        swap(arr[left], arr[index]);
                        index = left;
                    }
                    if(right <= size && arr[right] > arr[index]){
                        swap(arr[right], arr[index]);
                        index = right;
                    }
                    else{
                        return; //everthing is at its correct position
                    }
                }
        }

        //print
        void print(){
            for(int i=1; i<=size; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

//Insertion in Heap(Max Heap)
/*Algorithm
    1. Insert the element at the end of the array
    2. Compare the element with its parent, 
        if the element is greater than its parent, swap them.
*/

//Deletion in Heap(Max Heap)
/*Algorithm
    1. Replace the root of the heap with the last node on the last level.
    2. Delete the last node.
    3. Compare the new root with its children; 
        if found largest node among children, swap;
*/

int main(){

    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);


    h.print();
    h.deleteFromHeap();

    h.print();
    
    return 0;
}