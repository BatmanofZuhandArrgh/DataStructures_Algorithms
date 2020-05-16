
//
//  Stack.h
//  DataStructures
//
//  Created by Macbook on 5/16/20.
//  Copyright © 2020 Anh Nguyen. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

template <class T>
struct Node{
    T data;
    struct Node *next;
};

template <class T>
class Stack{
public:
    Stack(){
        top = NULL;
    }
    
    void push(T value);
    void display();
    T pop();
    T peek();
    bool isEmpty();
    int size();
    
    
private:
    Node<T> *top;
};

//Pushing one value onto the top of the stack
template <class T>
void Stack<T>:: push(T value){
    Node<T> *newNode = new Node<T>;
    newNode->data = value;
    newNode->next = top;
    
    top = newNode;
}

//Displaying the entire stack
template <class T>
void Stack<T>:: display(){
    if(top == NULL){
        std::cout << "There is no element here"<< std::endl;
    }
    else{
        Node<T> *temp = new Node<T>;
        temp = top;
        while(temp){
            std::cout << temp->data << "\t";
            temp = temp->next;
        }
        std::cout << std::endl;
    }}

//Removing the top element
template <class T>
T Stack<T>:: pop(){
    if(top == nullptr){
        throw "There is no element here";
    }
    else{
        T temp = top->data;
        top = top->next;
        return temp;
    }
}

//Looking at the top element
template <class T>
T Stack<T>:: peek(){
    if(top == nullptr){
        throw "There is no element here";
    }
    else{
        return top->data;}
}

//seeing whether the stack is empty
template <class T>
bool Stack<T>:: isEmpty(){
    return !top;
}

//Returning the size of the stacc
template <class T>
int Stack<T>:: size(){
    if(top == NULL){
        return 0;
    }
    else{
        int size = 0;
        Node<T> *temp = new Node<T>;
        temp = top;
        while(temp){
            size += 1;
            temp = temp->next;
        }
        return size;
    }}


#endif /* Stack_h */
