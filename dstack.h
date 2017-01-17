#ifndef DSTACK_H
#define DSTACK_H

using namespace std;


class Dstack
{
public:
    Dstack();
    ~Dstack();
    void push(double value);
    bool pop(double &value);
    int size() {return m_size;}
    bool empty() {return m_head == NULL;}
    
private:
    struct Node
    {
        Node (double value, Node*next)
        {m_value = value; m_next=next;}
        
        double m_value;
        Node *m_next;
    };
    
    Node *m_head;
    int m_size = 0;
};

#endif