/**
 * Implementasi ADT Deque (Double-ended Queue)
 *
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 *
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */
typedef struct dnode_t
{
    Ticket data;
    struct dnode_t
        *next,
        *prev;
} DListNode;

/* Struktur ADT Deque */
/* Implementasi didasarkan pada Doubly-Linked List */
typedef struct deque_t
{
    DListNode
        *_head,
        *_tail;
    unsigned _size;
} Deque;

/* DAFTAR FUNGSI YANG TERSEDIA */
DListNode *__dlist_createNode(Ticket value);
void deq_init(Deque *deque);
bool deq_isEmpty(Deque *deque);
void deq_pushFront(Deque *deque, Ticket value);
void deq_pushBack(Deque *deque, Ticket value);
Ticket deq_front(Deque *deque);
Ticket deq_back(Deque *deque);
void deq_popFront(Deque *deque);
void deq_popBack(Deque *deque);

DListNode *__dlist_createNode(Ticket value)
{
    DListNode *newNode =
        (DListNode *)malloc(sizeof(DListNode));

    if (!newNode)
        return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void deq_init(Deque *deque)
{
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned)0;
}

bool deq_isEmpty(Deque *deque)
{
    return (deque->_head == NULL &&
            deque->_tail == NULL);
}

void deq_pushFront(Deque *deque, Ticket value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode)
    {
        deque->_size++;
        if (deq_isEmpty(deque))
        {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        newNode->next = deque->_head;
        deque->_head->prev = newNode;
        deque->_head = newNode;
    }
}

void deq_pushBack(Deque *deque, Ticket value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode)
    {
        deque->_size++;
        if (deq_isEmpty(deque))
        {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}

Ticket deq_front(Deque *deque)
{
    if (!deq_isEmpty(deque))
    {
        return deque->_head->data;
    }

    Ticket empty = {0, 0};
    return empty;
}

Ticket deq_back(Deque *deque)
{
    if (!deq_isEmpty(deque))
    {
        return deque->_tail->data;
    }

    Ticket empty = {0, 0};
    return empty;
}

void deq_popFront(Deque *deque)
{
    if (!deq_isEmpty(deque))
    {
        DListNode *temp = deque->_head;
        if (deque->_head == deque->_tail)
        {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else
        {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void deq_popBack(Deque *deque)
{
    if (!deq_isEmpty(deque))
    {
        DListNode *temp;
        if (deque->_head == deque->_tail)
        {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else
        {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}