//
//  main.cpp
//  Sorting
//
//  Created by Jett Sturges on 10/12/20.
//

#include <iostream>
#include <vector>
using namespace std;

// function prototypes

vector<int> bubbleSort(vector<int>);
vector<int> mergeSort(vector<int> &);
void selectionSort(vector<int> &);
void swap(int &, int &);

int main() {
    
    vector<int> arr;        // Make a new vector to hold values
    
    int input, number;
    int i = 0;
    
    cin >> input;
    
    while (cin >> number) {
        arr.push_back(number);       // fill in vector using push_back()
        i+=1;
    }
    
    switch (input) {            // Check to see if input is 0 or 1
        case 0:
            arr = bubbleSort(arr);  // If 0 do bubble sort
            break;
            
        case 1:
            arr = mergeSort(arr);   // if 1 do merge sort
            
        default:
            break;
    }
    
    for (int val : arr) {
        cout << val << " ";     // print out values
    }
    
    return 0;
}

// Make a swap function to swap two elements of a vector

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Make a bubble sort function that takes in and returns a sorted vector of ints

vector<int> bubbleSort(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {        // iterate until list is sorted
        for (int j = 0; j < a.size() - i - 1; j++) {
            if (a[j] < a[j+1]) {            // check if prev element is less than next element
                swap(a[j], a[j+1]);     // if so, swap the elements
            }
        }
    }
    return a;
}

// this function searches through a vector to check if an element is the max of a vector list. Then, it pushes it back to the frontmost index of the vector that the max can take after each iteration.

void selectionSort(vector<int> &a) {
    int max;
    for (int i = 0 ; i < a.size() - 1; i++) {
        max = i;
        for (int j = i + 1; j < a.size(); j++) {
            if (a[j] > a[max]) {        // check if index j is greater than "max"
                max = j;                // if so, set max to j
            }
        }
        int target = a[max];        // make target a "temp" variable to push to the front of the vector list
        while (max > i) {       // while max index > current i index
            a[max] = a[max - 1];    // "push" the previous element value to the next index
            max-=1;             // decrement max variable to keep pushing up all the values until max = i.
        }
        a[i] = target;      // set the value of a[i] to the temp variable target, which is the max element.
    }
}

// This function splits the vector into 2, merges them back, and sorts them. We feed the funciton a reference to a vector because we want to modify the original vector inside the function.

vector<int> mergeSort(vector<int> &a) {
    vector<int> b, c;           // create two new vectors
    for (int i = 0; i < a.size(); i++) {
        if (i < a.size()/2) {       // fill the first split vector
            b.push_back(a[i]);
        }
        else {
            c.push_back(a[i]);  // fill the second split vector
        }
    }
    selectionSort(b);   // sort the first split vector with selectionSort function
    selectionSort(c);   // sort the second split vector with selectionSort function
    
    a.clear();          // clear the original vector to fill it with new values
    
    // we start two counters, j and k, and keep track of each element in the two split vectors to compare them. This only stops once both j and k reach the sizes of their respective b and c split vectors.
    
    int j = 0; int k = 0;
    
    while (j != b.size() && k != c.size()) {
        if (b[j] > c[k]) {      // we compare the two sorted subvectors element by element.
            a.push_back(b[j]);  // if an element from b is larger, we add it first
            j+=1;
        }
        else {
            a.push_back(c[k]);      // else if an element from c is larger, we add it instead
            k+=1;
        }
    }
    
    // After one of the vectors are empty, we need to empty the rest of the elements of the other vector into the original vector.
    
    while (j < b.size()) {   // if the second vector is empty, we empty the rest of the first vector into the final vector.
        a.push_back(b[j]);
        j+=1;
    }
    
    while (k < c.size()) {  // if the first vector is empty, we empty the rest of the second vector into the final vector.
        a.push_back(c[k]);
        k+=1;
    }

    return a;       // return the new vector
}
