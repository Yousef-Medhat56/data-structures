# Linked list
An implementation for the double linked list.

## Attributes
1. capacity: the maximum number of elements the queue can hold.
2. read: the index of the front element in the queue. It points to the first element that will be dequeued.
3. write:  the index of the rear element in the queue. It points to the last element that was enqueued.
4. array: a pointer to an array of the queue elements.

## Methods
#### Constructor
 Iinitializes the queue with a given capacity. 
 It allocates memory for the `array` and sets the initial values of `read` and `write` to -1 to represent an empty queue.

#### Destructor
Frees the allocated memory.

#### isEmpty
Checks whether the queue is empty. It returns true if `read` is -1, indicating an empty queue, and false otherwise.

#### isFull
 It returns true if `write` is at the last index of the array, indicating a full queue, and false otherwise.

#### enqueue
Add new element to the back of the queue. 
It checks if the queue is full, and if not, it increments `write` and stores the item in the array at the `write` index.

#### dequeue
 Remove and return the element from the front of the queue. 
 It checks if the queue is empty, and if not, it increments `read` and returns the element at the `read` index. 
 If the `read` and `write` pointers meet, indicating that the queue is now empty, they are reset to -1.
