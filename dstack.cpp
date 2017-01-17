

#include <iostream>
#include "dstack.h"

using namespace std;

Dstack::Dstack()
{
    m_head = NULL;
}

Dstack::~Dstack()
{
    
    
    Node *ptr = m_head;
    while (ptr != NULL)
    {
        Node *temp;
        
        temp = ptr;
        ptr = ptr->m_next;
        delete temp;
    }
    
}


void Dstack::push(double value)
{
    m_head = new Node(value, m_head);
    m_size = m_size + 1;
}



bool Dstack::pop(double &value)
{
    if(m_head == NULL)
    {
        return false;
    }
    value = m_head->m_value;
    Node *tmp = m_head;
    m_head = m_head->m_next;
    delete tmp;
    m_size = m_size - 1;
    return true;
    
}






