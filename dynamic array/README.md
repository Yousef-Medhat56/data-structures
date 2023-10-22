# Dynamic Array
An implementation for the dynamic array.

## Attributes
1. capacity: the full capacity of the array.
2. size: the current size of the array.
3. arr: a pointer to the array.

## Methods
#### Constructor
Sets up size and capacity. I made the initial capacity equal 5. Size is zero, since on creation there`s no data on the array. Also, space for the array is allocated.

#### Destructor
Frees the allocated memory, arr.

#### Push
Pushes a new element to the array. Must ensure that there’s space available in the array before pushing!

#### Pop
Removes the last element from the array, by diminishing the size of it by one.

#### Remove
Remove an element from the array by its index.

#### Display
Print the array elements.

#### GetElm
Returns an element by its index.

#### [] operator
Returns an element by its index. It calls the [GetElm method](#GetElm)

#### GetCapacity
Returns the array capacity.

#### GetSize
Returns the array size.

### Note
I have overloaded the insertion operator `<<` to print the array elements. It calls the [Display method](#Display)
```
std::cout << dynamicArr;
```
