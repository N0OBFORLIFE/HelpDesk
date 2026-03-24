/**
 * Implementasi ADT Stack (Stack menggunakan static Array)
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

/* Struktur ADT Stack */
typedef struct stackarr_t
{
    Ticket *_element;
    int _topIndex;
    unsigned int _size, _capacity;
} Stack;

void stackArray_init(Stack *stack, unsigned stackSize);
bool stackArray_isEmpty(Stack *stack);
void stackArray_push(Stack *stack, Ticket value);
void stackArray_pop(Stack *stack);
Ticket stackArray_top(Stack *stack);

void stackArray_init(Stack *stack, unsigned int stackSize)
{
    stack->_element = (Ticket *)malloc(sizeof(Ticket) * stackSize);
    stack->_size = 0;
    stack->_topIndex = -1;
    stack->_capacity = stackSize;
}

bool stackArray_isEmpty(Stack *stack)
{
    return (stack->_topIndex == -1);
}

void stackArray_push(Stack *stack, Ticket value)
{
    if (stack->_size + 1 <= stack->_capacity)
    {
        stack->_element[++stack->_topIndex] = value;
        stack->_size++;
    }
}

void stackArray_pop(Stack *stack)
{
    if (!stackArray_isEmpty(stack))
    {
        stack->_topIndex--;
        stack->_size--;
    }
}

Ticket stackArray_top(Stack *stack)
{
    if (!stackArray_isEmpty(stack))
    {
        return stack->_element[stack->_topIndex];
    }

    Ticket empty = {0, 0};
    return empty;
}