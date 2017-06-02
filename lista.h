#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <new>
#include <stdexcept>
#include "wezel.h"

using namespace std;

template<class Type>
class List
{
private:
    ListNode<Type> *ptr;
    ListNode<Type> *head;
public:
    List(): ptr(NULL), head(NULL) {};
    ~List()
    {
        clear();
    }
    void insert(const Type &newDataItem) throw(bad_alloc);      //Wk³ada  newDataItem do  listy. Je¿eli lista nie jest pusta to wk³ada  newDataItem za pozycj¹ kursora,
                                                                // w p.p  wk³ada  newDataItem jako pierwszy  (i jedyny ) element do listy. W obu przypadkach  kursor jest ustawiany na  newDataItem.
    void remove() throw(logic_error);
    void replace (const Type &newDataItem) throw(logic_error);
    void clear ();
    bool isEmpty () const;
    bool isFull () const;
    void gotoBeginning () throw ( logic_error );
    void gotoEnd () throw ( logic_error );
    bool gotoNext () throw ( logic_error );
    bool gotoPrior () throw ( logic_error );
    Type getCursor () const throw ( logic_error );
    void showStructure () const;
};

template<class Type>
void List<Type>::insert(const Type &newDataItem) throw (bad_alloc)
{


        if(head==NULL)
        {
            ListNode<Type> *newNode= new ListNode<Type>(newDataItem, head, head);
            head= newNode;
            ptr= newNode;
            head->next=head;
            head->prior=head;
        }
        else
        {
            ListNode<Type> *newNode= new ListNode<Type>(newDataItem, ptr, ptr->next);   //bylo head zamiast ptr->next
            ptr= newNode;
        }

}

template<class Type>
void List<Type>::remove() throw(logic_error)        //Usuwa to, co wskazuje ptr
{
  //  logic_error exception("Nie da sie usunac czegos czego nie ma!");
    if(ptr==NULL)
        throw logic_error("blad");

    ListNode<Type> *temp=ptr->prior;
    temp->next=ptr->next;
    (ptr->next)->prior=temp;
    delete &ptr;
    ptr=temp;

}

template<class Type>
void List<Type>::replace(const Type &newDataItem) throw(logic_error)
{
    logic_error exception("Nie da sie zast¹pic czegos czego nie ma!");
    if(ptr==NULL)
        throw exception;

    try
    {
        remove();
        insert(newDataItem);
    }
    catch(logic_error &e)
    {
        throw e;
    }
}

template<class Type>
void List<Type>::clear()
{
    while(ptr!=NULL)
    {
        remove();
    }
}

template<class Type>
bool List<Type>::isEmpty () const
{
    if(head==NULL) return true;
    return false;
}

template<class Type>
bool List<Type>::isFull () const
{
    return !isEmpty();
}

template<class Type>
void List<Type>::gotoBeginning() throw(logic_error)
{
    logic_error exception("Lista nie istnieje, wiec nie ma poczatku!");
    if(head==NULL)
        throw exception;

    else ptr=head;
}

template<class Type>
void List<Type>::gotoEnd() throw(logic_error)
{
    logic_error exception("Lista nie istnieje wiec nie ma konca!");
    if(head==NULL)
        throw exception;

    ptr=head->prior;
}

template<class Type>
bool List<Type>::gotoNext() throw (logic_error)
{
    logic_error exception("Lista nie istnieje wiec nie ma nastepnego!");
    if(head==NULL)
    {
        throw exception;
        return false;
    }

    ptr=ptr->next;
    return true;
}

template<class Type>
bool List<Type>::gotoPrior() throw (logic_error)
{
    logic_error exception("Lista nie istnieje wiec nie ma poprzedniego!");
    if(head==NULL)
    {
        throw exception;
        return false;
    }

    ptr=ptr->prior;
}

template<class Type>
Type List<Type>::getCursor() const throw(logic_error)
{
    logic_error exception("Lista nie istnieje wiec nie ma wskaznika!");
    if(head==NULL)
        throw exception;

    return ptr->dataItem;
}


template<class Type>
void List<Type>::showStructure() const
{
    logic_error exception("Lista nie istnieje wiec nie ma czego pokzac!");
    if(head==NULL)
    {
        throw exception;
    }

    ListNode<Type> *temp;
    for(temp=head; temp->next!=head; temp=temp->next)
    {
        cout<<temp->dataItem<<endl;
    }
}

#endif
