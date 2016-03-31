#include "list.h"

List::List () {
}
List::~List () {
  // Point temp to head.
  Node * temp = head;
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

bool List::SortedIsEmpty () const {
  // If head is not pointed at anything, return true.
  if (!head) return true;
  // If head points to a valid location, return false.
  return false;
}

int List::SortedGetLength () const {
  // Start the count at zero.
  int i = 0;
  // Point temp to head.
  Node * temp = head;
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

bool List::SortedFind (int k, int & x) const {
  // Start count at zero.
  int i = 0;
  // Point temp to head.
  Node * temp = head;
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

int List::SortedSearch (int key) const {
  // Start the count at zero.
  int i = 0;
  // Point temp to the head.
  Node * temp = head;
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
