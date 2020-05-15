//
//  LinkedList.h
//  
//
//  Created by Macbook on 5/15/20.
//

#ifndef LinkedList_h
#define LinkedList_h

template <class T>
struct Node{
    T data;
    struct Node *next;
};

template <class T>
class SinglyLinkedList{
public:
    SinglyLinkedList(){
        head = NULL;
        tail = NULL;
    }
    
    void createnode(T value); //Creating the node
    void display();
    int size();

    void insert_start(T value);
    void insert_position(T value, int position);
    T delete_first();
    T delete_last();
    T delete_position(int position);
    
private:
    Node<T> *head;
    Node<T> *tail;
};

//Creating a node in the linked list and push_back
template <class T>
void SinglyLinkedList<T>::createnode(T value){
    Node<T> *temp = new Node<T>;
    temp->data = value;
    temp->next = NULL;
    
    if(head==NULL){
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

//Displaying the entire linked list
template <class T>
void SinglyLinkedList<T>::display(){
    Node<T> *temp = new Node<T>;
    temp = head;
    if(temp == NULL){
        std::cout << "There's no node on the list" << std::endl;
    }
    while (temp!=NULL){
        std::cout << temp->data << "\t";
        temp = temp->next;
    }
}

//Returns  the size of the linkedlist
template<class T>
int SinglyLinkedList<T>::size(){
    if(head == NULL){
        return 0;}
    Node<T> *temp = new Node<T>;
    temp = head;
    int a = 0;
    while(temp!=NULL){
        temp = temp->next;
        a+=1;
    }
    return a;
}

//Insert at the start of the linked list
template <class T>
void SinglyLinkedList<T>::insert_start(T value){
    Node<T> *temp = new Node<T>;
    temp->data = value;
    temp->next = head;
    head = temp;
}

//Insert at a position
template <class T>
void SinglyLinkedList<T>::insert_position(T value, int position){
    if(position == 0){
        insert_start(value);
    }
    
    if(position >= size()){
        std::cout << "Size is smaller than the index." << std::endl;
        throw "Size is smaller than the index.";
    }
    
    Node<T> *pre = new Node<T>;
    Node<T> *post = new Node<T>;
    Node<T> *temp = new Node<T>;
    post = head;
    
    temp->data = value;
    
    for (int i = 1; i <= position; i++){
        pre = post;
        post = post->next;
    }
    
    pre->next = temp;
    temp->next = post;
}

//Delete the first element of the link list
template<class T>
T SinglyLinkedList<T>::delete_first(){
    Node<T> *temp = new Node<T>;
    temp = head;
    head = head->next;
    T a = temp->data;
    delete temp;
    return a;
}

//Delete the last element of the linked list
template<class T>
T SinglyLinkedList<T>::delete_last(){
    Node<T> *curr = new Node<T>;
    Node<T> *prev = new Node<T>;
    curr = head;
    
    while (curr->next!=NULL){
        prev = curr;
        curr = curr->next;
    }
    T a = curr->data;
    tail = prev;
    prev->next = NULL;
    delete curr;
    return a;
}

//Delete the element at a specific edition
template<class T>
T SinglyLinkedList<T>::delete_position(int position){
    Node<T> *curr = new Node<T>;
    Node<T> *prev = new Node<T>;
    curr = head;
    for (int i = 1; i <= position; i++){
        prev = curr;
        curr = curr->next;
    }
    T a = curr->data;
    prev->next = curr->next;
    delete curr;
    return a;
}
#endif /* LinkedList_h */
