#!/usr/bin/env python
# coding: utf-8

# In[1]:


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


# In[98]:


#Initiate the linked list:
class LinkedList(object):
    def __init__(self, head = None):
        self.head = head

    #Insert at the beginning of the list
    def insert_first(self, data):
        new_node = Node(data)
        new_node.set_next(self.head)
        self.head = new_node
    
    #Insert at the position
    def insert_at(self, position, new_data): 
        curr = self.head
        prev = None
        new_node = Node(new_data)
        new_node.next_node = None

        if(position >= self.size()):
            print("The position exceeds the size")
            return
        if(position == 0):
            insert_first(new_data)
        for i in range(position):
            prev = curr
            curr = curr.next_node
        prev.next_node = new_node
        new_node.set_next(curr)
   
    #Push back 1 element into the linked list
    def push_back(self, newdata): 
        new_node = Node(newdata)
        new_node.next_node = None
        
        pointer = self.head
        prev = None
        if(self.head == None):
            return
        while pointer.next_node is not None:
            prev = pointer
            pointer = pointer.next_node
        pointer.next_node = new_node
    
    #Determining the size of the linked List
    def size(self):
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
            
    #Delete a node at a specific position
    def delete(self, position):
        curr = self.head
        prev = None
        if(position >= self.size()):
            print("The position exceeds the size")
            return
        if(position == 0):
            self.head = curr.next_node
            return
        for i in range(position):
            prev = curr
            curr = curr.next_node
        prev.next_node = curr.next_node
        
    #Delete the final element of the list
    def pop_back(self):
        pointer = self.head
        prev = None
        if(self.head == None):
            return
        while pointer.next_node is not None:
            prev = pointer
            pointer = pointer.next_node
        prev.next_node = None
        return pointer.data


# In[99]:


list = LinkedList()
list.insert_first(1)
list.insert_first(3)
list.insert_first(9)
list.insert_first(5)
list.insert_first(6)
list.insert_first(2)
list.insert_at(3,20)
list.push_back(31)
list.display()
print("\n")
#list.delete(5)
#list.display()
#print("The size of the list is " + str(list.size()))
#print(list.pop_back())
#list.display()


# In[ ]:





# In[ ]:




