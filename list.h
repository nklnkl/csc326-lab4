#ifndef _LIST
#define _LIST

class List {

  public:

    List();
    ~List();
    bool SortedIsEmpty () const;
    int SortedGetLength () const;
    bool SortedFind (int, int &) const;
    int SortedSearch (int) const;

    struct Node {
      int data;
      Node * next;
    };


  private:

    Node * head;

};

#endif
