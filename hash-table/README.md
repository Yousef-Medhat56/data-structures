# Hash Table
An implementation for the hash table with the chaining approach.

## Attributes
1. table_size: the capacity of the hash table array.
2. table: an array of linked lists.

## Methods
### hash
The hashing function, it gets a string key and return the item index.

### insert
Add new item to the table.

### numberOfNodesInBucket
Return rhe numder of elements at the given index(bucket).

### find
Search for an element by its key, then return it if exists.

### remove
Removes an element by its given key if exists.
