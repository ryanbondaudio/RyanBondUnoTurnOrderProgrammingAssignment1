1. Why does concat only need to work between two lists of the same representation? What would
you have to do differently, or what would go wrong, if you tried to make it work between a
LinkedList and an ArrayList?

Concat only needs to work with two lists of the same representation because concatenating two lists of the same type
does not require any extra conversions or memory handling from type Linked List to ArrayList. Since an ArrayList is 
stored in memory as a continuous block and a linked list is stored as pointers to an address, one way to be able to
concatenate two lists of different types is to iterate through a list to copy the elements of one list and store them in
temp variables, then add the elements to the new list of a different type. This breaks our current time complexity, 
concatonating two linked lists goes from O(n) to O(n^2) and the arraylist changes from O(n) to O(n^2).

2. Walk through reverse() on your linked list: name the three pointers you need alive at once,
and explain why losing track of any one of them mid-loop corrupts the list.

We have a previous pointer, which represents the "current pointer" of the reversed list, current,
which walks through the list forward, and next, which saves the current->next value so the current knows where to point 
next. In each iteration, the current pointer’s next is set to point backward to the previous pointer, and the current 
pointer moves forward. While saving the list in reverse order, if the list is 1->2->3->nullptr, the 1st iteration
changes it to 1->nullptr 2->3, then, 2->1->nullptr 3, then finally 3->2->1->nullptr.

3.  addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for
position in each, and what does your implementation do if a caller passes a position outside
it?

For both implementations in arraylist and linked list, the valid range is 0 to size_ for addAnywhere and the valid
range is 0 to size_ - 1 for deleteAnywhere. If the caller exceeds these bounds, an error message is printed to the
console.

4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront
and deleteFront never needed to? What would change about concat’s performance if
LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere
if you added one back?
   
deleteFront and addFront always have access to the head_ pointer as a private field, so insertions only take O(1), since
there is no tail pointer in this implementation, the walking is necessary to get from the head to the item at size_ - 1
to insert the head of the other list. This takes O(n) time, but a tail pointer would make it O(1).

5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what
has to shift and in which direction, and why shifting in the wrong direction would overwrite
data you still need.

For addAnywhere, all the data at positions after it must be shifted to the right by one; this must be done from the end 
of the list to avoid overwriting the new element. If you shift the wrong way, it will overwrite the data at the position
and would  be the same as deleting the item at the position because all elements are shifted to the left.

6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of
play, and explain what would visibly break in the game if that call were missing.

Line 135. The order would remain the same and the order of my scene would be completely broken and in the wrong order.



