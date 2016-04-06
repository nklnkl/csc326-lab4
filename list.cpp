#include "list.h"

List::List (bool u) {
  unique = u;
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

bool List::isEmpty () {
  // If head is not pointed at anything, return true.
  if (!head) return true;
  // If head points to a valid location, return false.
  return false;
}

int List::getLength () {
  // Start the count at zero.
  int i = 0;
  // Point temp to head.
  temp = head;
  // Loop while temp is valid. Will be invalid from start if List is empty, hence head was invalid, hence temp is invalid.
  while (temp) {
    // Point temp at the next node.
    temp = temp -> next;
    // Increment and loop.
    i++;
  }
  // Return the count.
  return i;
}

bool List::find (int k, int & x) {
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
    temp = temp -> next;
    i++;
  }
  // If we ever get there, we never reached the position provided, thus return false.
  return false;
}

int List::search (int key) {
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
    temp = temp -> next;
    i++;
  }
  // If we ever get there, we never found the key, hence return -1;
  return -1;
}

void List::insert (int x) {

  // If the unique flag was true and searching for x returns a valid value.
  if (unique && search (x) != -1) {
    // Return back to caller.
    return;
  }

  // If head is null or x is less than the head.
  if (!head || x < head -> data) {
    // Point to current head, points to null if head is null.
    Node * next = head;
    // Allocate a new head node.
    head = new Node;
    // Insert the value of x at the data set by x.
    head -> data = x;
    // Point head to the next, points to null if no next.
    head -> next = next;
    // Return to break out of function.
    return;
  }

  // Point temp to head.
  temp = head;

  // Run loop while current temp is valid.
  while (temp) {
    // If the next node is greater than or equal to x.
    if (temp -> next && temp -> next -> data >= x) {
      // Create pointer for next.
      Node * next = temp -> next;
      // Allocate space for new node and assign x.
      temp -> next = new Node;
      temp -> next -> data = x;
      // Point new node to next.
      temp -> next -> next = next;
      return;
    }
    // If next node is null. Usually used if x ends up being the largest.
    if (!temp -> next) {
      temp -> next = new Node;
      temp -> next -> data = x;
      temp -> next -> next = 0;
      return;
    }
    temp = temp -> next;
  }

}

void List::remove (int k, int & x, bool & success) {
  // Point temp to head.
  temp = head;
  // Keep track of the count.
  int i = 0;
  // Pointer for the pending deletion.
  Node * pending;
  // While temp is valid.
  while (temp) {
    // If the targeted count matches the current count minus 1. ie: before the target.
    if (i == k - 1 && temp -> next) {
      // Set x equal to the next (the target data) data.
      x = temp -> next -> data;
      // Set the pending deletion for the target.
      pending = temp -> next;
      // Set next to skip the target.
      temp -> next = temp -> next -> next;
      // Execute deletion.
      delete pending;
      // Set success for true.
      success = true;
      // Return.
      return;
    }
    // Otherwise increment count.
    temp = temp -> next;
    i++;
  }
  // Set success to false, we never reached the goal k.
  success = false;
  // Return out of function.
  return;
}
