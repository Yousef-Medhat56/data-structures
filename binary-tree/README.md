# Binary Search Tree
An implementation for the binary search tree.
## Attributes
1. root: a node that represents the root of the tree.

## Methods
### addLeaf & addLeafPrivate
Insert new node to the tree using the recursive approach.
### printInOrder & printInOrderPrivate
Print the keys value in ascending order using the recursive approach.
### find & findPrivate
Search for a node using its key using the recursive approach, then returns it if exists.
### findSmallest & findSmallestPrivate
Search for the smallest key in the tree using the recursive approach, then return its node.
### remove & removePrivate
Remove a node from the tree using the recursive approach.
### printChildren
Print the children keys of the given node.
### destroyTree (Private):
Delete all the tree nodes to free the allocated memory. This method is called in the destructor.
