#ifndef _LIST
#define _LIST

#include <string>
using namespace std;

class List {

  public:
    List();
    ~List();
    bool isEmpty ();
    int getLength ();
    bool find (int, int &);
    int search (int);
    void insert (int);
    void remove (int, int &, bool &);

  private:
    struct Node {
      int data;
      Node * next;
    };
    Node * head;
    Node * temp;
};

#endif
