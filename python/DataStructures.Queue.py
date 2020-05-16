#!/usr/bin/env python
# coding: utf-8

# In[17]:


#A single node in the python
class Node(object):
    def __init__(self, data = None, next_node = None):
        self.data = data
        self.next_node = next_node

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next_node

    def set_next(self, new_next):
        self.next_node = new_next


# In[18]:


#Initiate the linked list:
class Queue(object):
    def __init__(self, head = None, tail = None):
        self.head = head
        self.tail = head
        
    #Insert at the beginning of the list
    def enqueue(self, data):
        new_node = Node(data)
        new_node.next_node = None
        
        pointer = self.head
        prev = None
        if(self.head == None):
            self.head = new_node
        else:
            while pointer.next_node is not None:
                prev = pointer
                pointer = pointer.next_node
            pointer.next_node = new_node
            self.tail = new_node
        
        
    #Delete the final element of the list
    def pop(self):
        pointer = self.head
        if(self.head == None):
            return
        self.head = self.head.next_node
        return pointer.data
    
        #Determining the size of the linked List
    def size(self):
        if(self.isEmpty()):
            return 0
        pointer = self.head
        a = 1
        while(pointer.next_node):
            a += 1
            pointer = pointer.next_node
        return a
    
       #Display the entire list
    def display(self):
        pointer = self.head
        if (self.head == None):
            print("There is no element in the list")
        while pointer is not None:
            print(pointer.data)
            pointer = pointer.next_node
    
    def isEmpty(self):
        return (self.head== None)
    
    def peek(self):
        return (self.head.data)


# In[27]:


queue = Queue()
#print(stack.size())
queue.display()
queue.enqueue(1)
queue.enqueue(2)
queue.enqueue(3)
queue.enqueue(4)
queue.enqueue(5)
queue.display()
print("The head of the queue is: " + str(queue.peek()))
print("The size is: " + str(queue.size()))

queue.pop()
queue.pop()
queue.display()
print("The head of the queue is: " + str(queue.peek()))
print("The size is: " + str(queue.size()))





# In[ ]:




