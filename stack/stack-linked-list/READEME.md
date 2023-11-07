# Stack Linked-list
An implementation for the stack using doubly linked-list.

## Attributes:
1. top: a pointer to the top node of the linked list, representing the top element of the stack.
2. size: the current size of the stack.

## Methods:
#### Constructor
Initialize a stack object with an empty linked list. It sets the `top` pointer to `nullptr` and the `size` to `0`.
#### Destructor
Deallocate the memory used by the linked list when the stack object is destroyed.
#### isEmpty
checks if the stack is empty.

#### getSize
returns the current size of the stack.

#### push
Add a new element to the top of the stack.
#### pop
Removes the top element from the stack.
#### peek
Returns the value of the top element without removing it.
