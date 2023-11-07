# Queue linked-list
An implementation for the queue using doubly linked-list.

## Attributes
1. read: a pointer to the first node in the linked list, representing the front of the queue. It points to the first element that will be dequeued.
2. write: A pointer to the last node in the linked list, representing the rear of the queue. It points to the last element that was enqueued.

## Methods
#### Constructor
Initializes an empty queue by setting both `read` and `write` to `nullptr`.

#### Destructor
Frees the allocated memory.

#### isEmpty
A method that checks whether the queue is empty. 
It returns true if both `read` and `write` are nullptr, indicating an empty queue, and false otherwise.

#### enqueue
add a new element to the back of the queue by creating a new node,
updating the `write` pointer, and linking the new node to the previous `write` node.

#### dequeue
Remove and return the element from the front of the queue. 
It checks if the queue is empty, and if not, it updates the `read` pointer and returns the data from the first node.
