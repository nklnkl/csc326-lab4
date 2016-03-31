#include "list.h"

List::List () {
}
List::~List () {
  // Point temp to head.
  temp = head;
  Node * pending;
  // Loop while temp is valid. Will be invalid from start if List is empty, hence head was invalid, hence temp is invalid.
  while (temp) {
    // Set pending for the current node.
    pending = temp;
    // Set temp to the next node.
    temp = temp -> next;
    // Delete the pending.
    delete pending;
  }
}

bool List::isEmpty () const {
  // If head is not pointed at anything, return true.
  if (!head) return true;
  // If head points to a valid location, return false.
  return false;
}

int List::getLength () const {
  // Start the count at zero.
  int i = 0;
  // Point temp to head.
  temp = head;
  // Loop while temp is valid. Will be invalid from start if List is empty, hence head was invalid, hence temp is invalid.
  while (temp) {
    // Point temp at the next node.
    temp = head -> next;
    // Increment and loop.
    i++;
  }
  // Return the count.
  return i;
}

bool List::find (int k, int & x) const {
  // Start count at zero.
  int i = 0;
  // Point temp to head.
  temp = head;
  // Loop while temp is valid. Will be invalid from start if List is empty, hence head was invalid, hence temp is invalid.
  while (temp) {
    // If the current count is equal to the position provided.
    if (i == k) {
      // Set x equal to the data.
      x = temp -> data;
      // Return true that we found the value of the given position.
      return true;
    }
    // Otherwise increment and loop.
    i++;
  }
  // If we ever get there, we never reached the position provided, thus return false.
  return false;
}

int List::search (int key) const {
  // Start the count at zero.
  int i = 0;
  // Point temp to the head.
  temp = head;
  // Loop while temp is valid. Will be invalid from start if List is empty, hence head was invalid, hence temp is invalid.
  while (temp) {
    // If the data in the current temp is equal to the searched key.
    if (temp -> data == key)
      // Return the current count.
      return i;
    // Otherwise just increment and loop.
    i++;
  }
  // If we ever get there, we never found the key, hence return -1;
  return -1;
}

void List::insert (int x) {
  // Point temp to head.
  temp = head;
  // If temp is null.
  if (!temp) {
    // Allocate a Node at the address pointed.
    temp = new Node;
    // Insert the value of x at the data set by x.
    temp -> data = x;
    // Return to break out of function.
    return;
  }
  // Run loop while current temp is valid.
  while (temp) {
    // If the next node is null.
    if (!temp -> next) {
      // Create new node from the 'next' pointer.
      temp -> next = new Node;
      // Set the data of the next new node.
      temp -> next -> data = x;
      // Return to break out of loop and end function.
      return;
    }
    // Otherwise go to the next node.
    temp = temp -> next;
  }
}

void List::remove (int k, int & x, bool & success) {
  // Point temp to head.
  temp = head;
  // Keep track of the count.
  int i = 0;
  // While temp is valid.
  while (temp) {
    // If the targeted count matches the current count.
    if (i == k) {
      // Set x equal to the current data.
      x = temp -> data;
      // Set success for true.
      success = true;
      // Return.
      return;
    }
    // Otherwise increment count.
    i++;
  }
  // Set success to false, we never reached the goal k.
  success = false;
  // Return out of function.
  return;
}
