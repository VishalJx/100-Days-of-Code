/*
    Uses the similiar concept of Square root problem we solved on Day1;
*/


#include <bits/stdc++.h>
using namespace std;

bool isSolution(int arr[], int students, int books, int mid){

    int studentCount = 1; //number of students starting from 1 student
    int pageSum = 0; //shows how many pages are alloted for each studentCount.

    for(int i=0; i<books; i++){
        if(pageSum + arr[i] <= mid){  //if adding pages of each book(each index) does not sum up to mid value then following.

        //keep adding the books for studentCount.
            pageSum += arr[i]; //pageSum = pageSum + arr[i] 
        }
        else{
            //if sum of pages exceeds mid value; then start alloting other pages to next student.
            //Hence increase studentCount by 1;
            studentCount++;

            //if studentCount that we are keeping exceeds more than the given students then the solution does not exists.
            // Also if value of mid is less than the number of pages, then also solution does not exists.
            if(studentCount > students || arr[i] > mid){
                return false;
            }

            //else, start assigning the pages from 'i-th' book to the next student(studentCount++)
            pageSum = arr[i];
        }

    }
    return true;
}

//Simply applying Binary Search below
int allocateBook(int arr[], int m, int n){
    int start, end, mid;
    int sum = 0;
    int ans = -1;
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }

    start = 0;
    end = sum;
    mid = start + (end - start)/2;

    while(start<end){

        //if this mid gives possible solution then store it then discard all the value right to the mid
        if(isSolution(arr,m,n,mid)){ 
            ans = mid;
            end = mid - 1; //we're going to the left part of the array because we need to find the minimum pages.
                           // Similarily if we need to find maximum something then we'll search in right part: start = mid + 1.
        }
        //else discard all the values left to the mid
        else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;

    }
    return ans;
}
 
int main() {

    int book[3] = {22, 23, 67};
    int size = sizeof(book)/sizeof(book[0]);
    int students = 1;

    cout << allocateBook(book, students, size);
    return 0;
}