# Assignment 1

## Table of Contents
- [Insertion Operations](#insertion-operations-1)
  - [addWaypointAtBeginning](#addwaypointatbeginning-11)
  - [addWaypointAtEnd](#addwaypointatend-12)
  - [addWaypointAtIndex](#addwaypointatindex-13)
- [Deletion Operations](#deletion-operations-2)
  - [removeWaypointAtBeginning](#removewaypointatbeginning-21)
  - [removeWaypointAtEnd](#removewaypointatend-22)
  - [removeWaypointAtIndex](#removewaypointatindex-23)
- [Traversal Operations](#traversal-operations-3)
  - [traverseForward](#traverseforward-31)
  - [traverseBackwards](#traversebackwards-32)
- [Modification and Retrival Operations](#modification-and-retrival-operations-4)
  - [getWaypoint](#getwaypoint-41)
  - [setWaypoint](#setwaypoint-42)
- [Misc/Print function](#miscprint-function-5)
  - [print](#print-51)
  - [SpaceRoute](#spaceroute-52)
  - [~SpaceRoute](#spaceroute-53)

## Insertion Operations 1
Overview of linked list insertion operations

### addWaypointAtBeginning 1.1
Creates a new node (pointer ref), and a temp pointer to head->next. We then swap around next and prev and insert between head and temp.

No edge cases because there will always be a head and head->next (head and tail)

**O(1) time**

6 lines, no loops or conditionals

### addWaypointAtEnd 1.2
Creates a new node (pointer ref), and a temp pointer to tail->prev. We then swap around next and prev and insert between temp and prev.

No edge cases because there will always be a tail and tail->prev (tail and head)

**O(1) time**

6 lines, no loops or conditionals

### addWaypointAtIndex 1.3
Creates a curr pointer, and moves through the list to position n - 1 (starting from the head we loop from 0 to n). We then create a new node (pointer ref) and a temp pointer to curr->next and swap around next and prev to insert the new node between curr and temp.

**We have 1 edge case:**

Index out of bounds

- We can mitigate this by ensuring if index is < 0, we throw an error.
Since we do not have a length of the list, we have to check that curr->next exists on each traversal. If it does not, we throw an error because we know we have reached the tail node without getting to our index. (This is kind of like a lookahead)

**O(n) time**

We loop through the list until we arrive at index

## Deletion Operations 2
Overview of linked list deletion operations

### removeWaypointAtBeginning 2.1
Creates a toRemove pointer at head->next, and a temp pointer to toRemove->next. We then update the next and prev of the new first node and head. Finally, we delete toRemove.

**We have 1 edge case:**

List is empty

- We want to make sure that our pointer to the node after the one to be removed is not null, if it is we know that the list is empty and we cannot remove anything.

**O(1) time**

No loops

### removeWaypointAtEnd 2.2
Creates a toRemove pointer at tail->prev, and a temp pointer to toRemove->prev. We then update the next and prev of the new last node and tail. Finally, we delete toRemove.

**We have 1 edge case:**

List is empty

- We want to make sure that our pointer to the node before the one to be removed is not null, if it is we know that the list is empty and we cannot remove anything.

**O(1) time**

No loops

### removeWaypointAtIndex 2.3
Creates a curr pointer, and moves through the list to position n - 1 (starting from the head we loop from 0 to n). We then create a pointer to the node after the one to be removed, then one to the one to be removed. Lastly, we swap around next a prev to the nodes surrounding the one to be removed, and delete the node to be removed.

**We have 1 edge case:**

Index out of bounds

- We can mitigate this by ensuring if index is < 0, we throw an error.
Since we do not have a length of the list, we have to check that curr->next exists on each traversal. If it does not, we throw an error because we know we have reached the tail node without getting to our index. (This is kind of like a lookahead)

**O(n) time**

We loop through the list until we arrive at index

## Traversal Operations 3
Overview of traversal operations

### traverseForward 3.1
Creates a curr pointer starting at head->next, and loops through the list printing each nodes data while curr->next is not null (not the tail). Once we reach the tail, the function ends.

No edge cases, we have no user inputs

**O(n) time**

We loop through each node in the list

### traverseBackwards 3.2
Creates a curr pointer starting at tail->prev, and loops through the list printing each nodes data while curr->prev is not null (not the head). Once we reach the head, the function ends.

No edge cases, we have no user inputs

**O(n) time**

We loop through each node in the list

## Modification and Retrival Operations 4
Overview of modification and retrieval operations

### getWaypoint 4.1
Creates a curr pointer starting at head->next, and loops through until the we reach the desired index. Lastly, we return the pointer to the node at index.

**We have 1 edge case:**

Index out of bounds

- We can mitigate this by ensuring if index is < 0, we throw an error.
Since we do not have a length of the list, we have to check that curr->next exists on each traversal. If it does not, we throw an error because we know we have reached the tail node without getting to our index. (This is kind of like a lookahead)

**O(n) time**

We loop through the list until we arrive at index

### setWaypoint 4.2
Creates a curr pointer starting at head->next, and loops through until we reach the desired index. Lastly, we set the value of curr->data to the data given by the user.

**We have 1 edge case:**

Index out of bounds

- We can mitigate this by ensuring if index is < 0, we throw an error. Since we do not have a length of the list, we have to check that curr->next exists on each traversal. If it does not, we throw an error because we know we have reached the tail node without getting to our index. (This is kind of like a lookahead)

**O(n) time**

We loop through the list until we arrive at index

## Misc/Print function 5
Overview of print function and constructor/destructor

### print 5.1
Creates a curr pointer starting at head->next, and loops through the list, calling curr->print for each node until it reaches the end.

No edge cases

**O(n) time**

We loop through the list

### SpaceRoute 5.2
Creates 2 new pointers to new T objects (these will be strings in main testing). We then create 2 new nodes with the data created in the previous step, and set the next and prev pointers for each (these will be the head and tail). We then delete the objects created, giving us nullpointers as values to the desired type specified in the template.

No edge cases

**O(1) time**

No loops

### ~SpaceRoute 5.3
Creates a curr pointer starting at head->next, and loops through the list. We then create/set the pointer temp to curr->next, so we can safely delete curr and then set curr to temp to restart the loop. When curr->next is nullptr (tail) then we end the loop.

No edge cases

**O(n) time**

We loop through the list
