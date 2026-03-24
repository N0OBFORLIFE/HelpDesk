/**
 * Implementasi ADT Queue (Queue menggunakan array)
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

/* Struktur ADT Queue */

typedef struct queuearr_t
{
    Ticket *_element;
    int _front,
        _rear;
    unsigned _size, _capacity;
} Queue;

void queueArray_init(Queue *queue, unsigned queueSize);
bool queueArray_isEmpty(Queue *queue);
void queueArray_push(Queue *queue, Ticket value);
void queueArray_pop(Queue *queue);
Ticket queueArray_front(Queue *queue);
unsigned queueArray_size(Queue *queue);

void queueArray_init(Queue *queue, unsigned queueSize)
{
    queue->_element = (Ticket *)malloc(sizeof(Ticket) * queueSize);
    queue->_front = -1;
    queue->_rear = -1;
    queue->_size = 0;
    queue->_capacity = queueSize;
}

bool queueArray_isEmpty(Queue *queue)
{
    return (queue->_front == -1);
}

void queueArray_push(Queue *queue, Ticket value)
{
    if (queue->_size + 1 <= queue->_capacity)
    {
        if (queue->_front == -1)
            queue->_front = 0;
        queue->_rear = (queue->_rear + 1) % queue->_capacity;
        queue->_element[queue->_rear] = value;
        queue->_size++;
    }
}

void queueArray_pop(Queue *queue)
{
    if (!queueArray_isEmpty(queue))
    {
        if (queue->_front == queue->_rear)
            queue->_front = queue->_rear = -1;
        else
            queue->_front = (queue->_front + 1) % queue->_capacity;
        queue->_size--;
    }
}

Ticket queueArray_front(Queue *queue)
{
    if (!queueArray_isEmpty(queue))
    {
        return queue->_element[queue->_front];
    }
    Ticket emptyTicket = {0, 0};
    return emptyTicket;
}

unsigned queueArray_size(Queue *queue)
{
    return (queue->_size);
}