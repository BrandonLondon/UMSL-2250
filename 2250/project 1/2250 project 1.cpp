//============================================================================
// Name        : 2250.cpp
// Author      : Brandon London
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

void initialize_array(int arr[], int size){
    for(int i=0; i<size; i++) {
        arr[i] = i;
    }
}

int * shuffle_array(const int arr[], int size) {
    int *newArr = new int[size];

    for(int i=0; i<size; i++) {
        newArr[i] = arr[i];
    }

    for(int i=size-1; i>=0; i--) {
        int j = rand() % (i+1);

        int temp = newArr[j];
        newArr[j] = newArr[i];
        newArr[i] = temp;
    }

    return newArr;
}

void print_array(const int arr[], int size){
    cout << "[";
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << "]"<< endl;
}

int * createOddArray(const int arr[], int size, int &newsize){
    newsize = 0;
    for(int i=0; i<size; i++) {
        if(arr[i] % 2 != 0) {
            newsize++;
        }
    }

    int *newArr = new int[newsize];
    int count = 0;
    for(int i=0; i<size; i++) {
        if(arr[i] % 2 != 0) {
            newArr[count++] = arr[i];
        }
    }
    return newArr;
}
int * createEvenArray(const int arr[], int size, int &newsize){
    newsize = 0;
    for(int i=0; i<size; i++) {
        if(arr[i] % 2 == 0) {
            newsize++;
        }
    }

    int *newArr = new int[newsize];
    int count = 0;
    for(int i=0; i<size; i++) {
        if(arr[i] % 2 == 0) {
            newArr[count++] = arr[i];
        }
    }
    return newArr;
}

void sort_array(int *arr,int size){
    int i, j, min_idx;

    for (i = 0; i < size-1; i++) {

        min_idx = i;
        for (j = i+1; j < size; j++) {
          if (arr[j] < arr[min_idx]) {
            min_idx = j;
          }
        }

        if(i != min_idx) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

void array_war(int *arr1, int size1, int *arr2, int size2){
    int size = (size1 > size2 ? size1 : size2);
    int count = 0;

    int output[size];
    int index = 0;
    for(index=0; index < size1 && index < size2; index++) {
        output[count++] = (arr1[index] > arr2[index] ? arr1[index] : arr2[index]);
    }

    if(index == size1) {
        // arr1 is done
        for(;index < size2; index++) {
            output[count++] = arr2[index];
        }
    } else {
        // arr2 is done
        for(;index < size1; index++) {
            output[count++] = arr1[index];
        }
    }

    cout << "ArrayFight winners were: ";
    print_array(output, size);

    sort_array(output, size);

    cout << "Sorted ArrayFight winners were:";
    print_array(output, size);
}


int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    while(size < 1 || size > 52) {
        cout << "Invalid size. Try again." << endl;
        cout << "Enter the size of the array: ";
        cin >> size;
    }

    int arr[size];
    initialize_array(arr, size);

    cout << "Original array is:";
    print_array(arr, size);

    initialize_array(arr, size);

    int *shuffle = shuffle_array(arr, size);
    cout << "Shuffled array is:";
    print_array(shuffle, size);

    int oddSize;
    int *oddArray = createOddArray(shuffle, size, oddSize);
    int evenSize;
    int *evenArray = createEvenArray(shuffle, size, evenSize);

    cout << "After call to create OddArray, The oddArray is:";
    print_array(oddArray, oddSize);
    cout << "After call to create EvenArray, The evenArray is:";
    print_array(evenArray, evenSize);

    array_war(oddArray, oddSize, evenArray, evenSize);
}
