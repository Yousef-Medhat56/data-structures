# Stack array
An implementation for the stack using dynamic array.

## Attributes:
1. arr: a dynamically allocated array that holds the elements of the stack.
2. capacity: It represents the current capacity of the stack, which determines the size of the dynamic array.
3. top: top element in the stack.

## Methods:
#### Constructor
Initializes a stack object. It can accept an optional initialCapacity parameter to set the initial capacity of the stack. The constructor also allocates memory for the dynamic array.

#### Destructor
Free the dynamically allocated memory for the array when the stack object is destroyed.

#### isEmpty
This method checks whether the stack is empty by examining the value of the top attribute. It returns true if the stack is empty, and false otherwise.

#### getSize
This method returns the current size of the stack by adding 1 to the top attribute. The size is the number of elements in the stack.

#### push
Adds a new element with the value val to the top of the stack. It also checks if the stack is full and resizes the array if necessary to accommodate more elements.
#### pop
Removes the top element from the stack. It decreases the top index to simulate the removal of the top element. It also checks if the stack is empty and throws an exception if it is.
#### peek
Returns the value of the top element without removing it. It checks if the stack is empty and throws an exception if it is.
#### resize
a private helper method used to increase the capacity of the dynamic array. It creates a new array with the specified newCapacity, copies the elements from the old array to the new one, and deallocates the memory of the old array.
