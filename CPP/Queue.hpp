//
//  Queue.h
//  DataStructures
//
//  Created by Macbook on 5/16/20.
//  Copyright © 2020 Anh Nguyen. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

template <class T>
struct Node{
    T data;
    struct Node *next;
};

template <class T>
class Queue{
public:
    Queue(){
        head = NULL;
        tail = NULL;
    }
    
    void enqueue(T value);
    void display();
    T dequeue();
    T peek();
    bool isEmpty();
    int size();
    
    
private:
    Node<T> *head; //Removing at head
    Node<T> *tail; //Adding to tail
};

//Pushing one value onto the top of the stack
template <class T>
void Queue<T>:: enqueue(T value){
    Node<T> *newNode = new Node<T>;
    newNode->data = value;
    newNode->next = NULL;
    
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}
//
//Displaying the entire queue
template <class T>
void Queue<T>:: display(){
    if(head == NULL){
        std::cout << "There is no element here"<< std::endl;
    }
    else{
        Node<T> *temp = new Node<T>;
        temp = head;
        while(temp){
            std::cout << temp->data << "\t";
            temp = temp->next;
        }
        std::cout << std::endl;
    }}

//Removing the top element
template <class T>
T Queue<T>:: dequeue(){
    if(head == nullptr){
        throw "There is no element here";
    }
    else{
        T temp = head->data;
        head = head->next;
        return temp;
    }
}
//
//Looking at the top element
template <class T>
T Queue<T>:: peek(){
    if(head == nullptr){
        throw "There is no element here";
    }
    else{
        return head->data;}
}
//
//seeing whether the stack is empty
template <class T>
bool Queue<T>:: isEmpty(){
    return !head;
}
//
//Returning the size of the stacc
template <class T>
int Queue<T>:: size(){
    if(head == NULL){
        return 0;
    }
    else{
        int size = 0;
        Node<T> *temp = new Node<T>;
        temp = head;
        while(temp){
            size += 1;
            temp = temp->next;
        }
        return size;
    }}
#endif /* Queue_h */
