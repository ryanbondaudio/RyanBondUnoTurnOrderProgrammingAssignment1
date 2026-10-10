1. Why does concat only need to work between two lists of the same representation? What would
you have to do differently, or what would go wrong, if you tried to make it work between a
LinkedList and an ArrayList?

Concat only needs to work with two lists of the same representation because concatenating two lists of the same type
does not require any extra conversions or memory handling from type Linked List to ArrayList. Since an ArrayList is 
stored in memory as a continuous block and a linked list is stored as pointers to an address, one way to be able to
concatenate two lists of different types is to iterate through a list to copy the elements of one list and store them in
temp variables, then add the elements to the new list of a different type. This breaks our current time complexity, 
concatonating two linked lists goes from O(n) to O(n^2) and the arraylist changes from O(n) to O(n^2).




