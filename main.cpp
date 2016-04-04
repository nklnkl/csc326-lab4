#include <iostream>
#include "list.cpp"
using namespace std;

int main () {
  // The list object.
  List * list;

  int command = -1;
  while (command != 0) {
    cout << "0) Exit." << endl << "1) Allow duplicate elements." << endl << "2) Don't allow duplicate elements." << endl;
    cout << "$: ";
    cin >> command;
    switch (command) {
      case 0:
        cout << "Exiting." << endl;
        return 0;
        break;
      case 1:
        list = new List(false);
        command = 0;
        break;
      case 2:
        list = new List(true);
        command = 0;
        break;
      default:
        break;
        // do nothing.
    }
  }

  // The buffer to use for i/o.
  int x;

  list -> insert(5);
  list -> insert(7);
  list -> insert(9);
  list -> insert(11);
  list -> insert(5);

  cout << endl << "List" << endl;
  for ( int i = 0; i < list -> getLength (); i++) {
    if (list -> find(i, x))
      cout << x << endl;
  }

  list -> insert(7);
  cout << endl << "List" << endl;
  for ( int i = 0; i < list -> getLength (); i++) {
    if (list -> find(i, x))
      cout << x << endl;
  }

  cout << endl << "3rd element: ";
  list -> find (2, x);
  cout << x << endl;

  cout << endl << "Search for 7: ";
  cout << "#" << list -> search (7)  << endl;

  cout << endl << "Length of list: " << list -> getLength () << endl;

  cout << endl << "Deleting for value 7. ";
  int toBeDeleted = list -> search (7);
  cout << "Element #" << toBeDeleted << endl;
  bool success;
  list -> remove (toBeDeleted, x, success);
  if (success) {
    cout << x << " successfully deleted at #" << toBeDeleted << "." << endl;
  } else {
    cout << x << " unsuccessfully deleted." << endl;
  }

  cout << endl << "List" << endl;
  for ( int i = 0; i < list -> getLength (); i++) {
    if (list -> find(i, x))
      cout << x << endl;
  }

  cout << endl << "Search for 7: ";
  cout << "#" << list -> search (7)  << endl;

  delete list;
  return 0;
}
