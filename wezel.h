#ifndef WEZEL_H
#define WEZEL_H

#include<iostream>
#include <new>
#include <stdexcept>

template<class T>
class ListNode
{
private:
     template <class Type > friend class List;
// Konstructor
    ListNode (const T &data,ListNode *priorPtr, ListNode *nextPtr );//: dataItem(data), prior(priorPtr), next(nextPtr) {};

// Pola sk³adowe
    T dataItem;
    ListNode *prior;
    ListNode *next;

};

template <class T >
ListNode<T>::ListNode(const T &data,ListNode *priorPtr, ListNode *nextPtr )
{
    dataItem = data;
    prior = priorPtr;
    next = nextPtr;
}
#endif
