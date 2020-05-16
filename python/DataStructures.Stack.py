#!/usr/bin/env python
# coding: utf-8

# In[21]:


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


# In[28]:


#Initiate the linked list:
class Stack(object):
    def __init__(self, head = None):
        self.head = head
        
    #Insert at the beginning of the list
    def push(self, data):
        new_node = Node(data)
        new_node.set_next(self.head)
        self.head = new_node
               
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


# In[31]:


stack = Stack()
print(stack.size())
stack.display()
stack.push(1)
stack.push(2)
stack.push(3)
stack.push(4)
stack.push(5)
stack.push(6)
stack.display()
print(stack.peek())
stack.pop()
stack.display()
print(stack.peek())


# In[ ]:




