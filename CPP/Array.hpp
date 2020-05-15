//
//  DataStructure.Array.hpp
//  
//
//  Created by Macbook on 5/14/20.
//

#ifndef DataStructure_Array_hpp
#define DataStructure_Array_hpp

#include <stdio.h>

template <class T>
class DynamicArray {
public:
    DynamicArray(); //Constructor, starting an array with 1 element
    DynamicArray(const DynamicArray &originalArray);
    //~DynamicArray(); // Destructor

    void print();
    void push(T element);
    T pop();
    T remove(int position);
    void insert(T value, int position);
    int getSize();
    void reSize(int value);
    DynamicArray<int> getPosition(T value);
    T getElement(int position);
    
    bool operator==(DynamicArray a);
    bool operator!=(DynamicArray a);
    
    
private:
    int size;
    T* array;
};

//Defining the constructor
template <class T>
DynamicArray<T>::DynamicArray(){
    size = 0;
    array = new T[size];
}

//Defining the copy constructor
template <class T>
DynamicArray<T>:: DynamicArray(const DynamicArray &originalArray){
    size = originalArray.size;
    array = new T[size];
    for (int i = 0; i < originalArray.size; i++){
        array[i] = originalArray.array[i];
    }
}
//Printing all the element of the array
template <class T>
void DynamicArray<T>::print(){
    if (size == 0){
        std::cout << "There's no element in this array." << std::endl;
    }
    else{
        for (int i = 0; i < size; i++){
            std::cout << array[i] << " ";
        }
        std::cout << "\n";
    }
}

//Push_back an elemenent into the array
template <class T>
void DynamicArray<T>::push(T element){
    if (size == 0){
        array[0] = element;
        size += 1;
    }
    else{
        array[size] = element;
        size += 1;
    }
}

//Pop_back the last element of the array
template<class T>
T DynamicArray<T>::pop(){
    T temp = array[size-1];
    size-=1;
    return temp;
}

// Remove the element at specific position
template<class T>
T DynamicArray<T>::remove(int position){
    if (position >= size){
        std::cout << "Size is smaller than the index." << std::endl;
        throw "Size is smaller than the index.";
    }
    else{
        T value = array[position];
        for (int i = position; i < size-1;i++){
            array[i] = array[i+1];
        }
        size-=1;
        return value;
    }
}

// Insert and replace a number at a position
template<class T>
void DynamicArray<T>::insert(T value, int position){
    if (position >= size){
        std::cout << "Size is smaller than the index." << std::endl;
    }
    else{
        array[position] = value;
    }
}


//Return Size
template<class T>
int DynamicArray<T>::getSize(){
    return size;
}

template<class T>
T DynamicArray<T>::getElement(int position){
    if (position >= size){
        std::cout << "Size is smaller than the index." << std::endl;
        throw "Size is smaller than the index.";
    }
    else{
        T value = array[position];
        return value;
    }
}

template<class T>
void DynamicArray<T>::reSize(int value){
    T *temp;
    temp = new T[value];
    for (int i = 0; i < value; i++){
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
    size = value;
}

//Getting the position of all values matching value
template <class T>
DynamicArray<int> DynamicArray<T>::getPosition(T value){
    DynamicArray<int> MatchingPosition;
    
    for(int i = 0; i < size; i++){
        if (array[i] == value){
            MatchingPosition.push(i);
        }
    }
    return MatchingPosition;
}

// Overloading operator
template<class T>
bool DynamicArray<T>::operator==(DynamicArray a){
    if(a.size != size){
        return false;
    }
    else{
        for(int i = 0; i< a.size; i++){
            if(a.array[i]!=array[i]){
                return false;
            }
        }
        return true;
    }
}

template<class T>
bool DynamicArray<T>::operator!=(DynamicArray a){
    if(a.size != size){
        return true;
    }
    else{
        for(int i = 0; i< a.size; i++){
            if(a.array[i]!=array[i]){
                return true;
            }
        }
        return false;
    }
}
#endif /* DataStructure_Array_hpp */
