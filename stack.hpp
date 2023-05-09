class Node {
    friend class Stack;
    Node* next;
    int value;
    virtual int getValue();
    virtual Node* getNext();
    virtual void set(Node*);
    virtual void set(int);
    Node(int);
};

class Stack {
    Node* stackPointer;
    int elCount;
    public:
      Stack();
      virtual void push(int value);
      virtual int pop();
      virtual void print();
      virtual int size();
      virtual void clear();
};