#ifndef _LIST
#define _LIST

class List {

  public:
    List();
    ~List();
    bool isEmpty () const;
    int getLength () const;
    bool find (int, int &) const;
    int search (int) const;
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
