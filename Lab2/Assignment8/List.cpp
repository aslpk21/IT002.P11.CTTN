#include "List.h"
#include<iostream>
using namespace std;

List::List(){
    arr = NULL;
    size = 0;
}
List::~List(){
    delete[] arr;
}

void List::push_back(double x){
    double* newArr = new double[size + 1];
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    newArr[size] = x;
    delete[] arr;
    arr = newArr;
    ++size;
}

void List::pop_first(double x){
    int idx = -1;
    for(int i = 0; i<size; i++){
        if(arr[i] == x){
            idx = i;
            break;
        }
    }

    if(idx != -1){
        double *newArr = new double[size - 1];
        for(int i = 0, j = 0; i<size; i++){
            if(i != idx){
                newArr[j++] = arr[i];
            }
        }
        delete[] arr;
        arr = newArr;
        size--;
    }
}

void List::pop_all(double x){
    unsigned int newSize = 0;
    for (unsigned int i = 0; i < size; ++i) {
        if (arr[i] != x) {
            ++newSize;
        }
    }

    double* newArr = new double[newSize];
    for (unsigned int i = 0, j = 0; i < size; ++i) {
        if (arr[i] != x) {
            newArr[j++] = arr[i];
        }
    }
    
    delete[] arr;
    arr = newArr;
    size = newSize;
}

void List::replace(int x, double y){
    if (x >= 0 && x < size) {
        arr[x] = y;
    }
    else 
        return;
}

void List::printL(){
    cout << "[";
    for(int i=0; i<size; i++){
        cout << arr[i];
        if(i < size - 1) cout << ", ";
    }
    cout << "]" << "\n";
}