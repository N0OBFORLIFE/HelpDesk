#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    int isUrgent; // 1 = urgent, 0 = normal
} Ticket;

#include "stack.h"
#include "queue.h"
#include "deque.h"

Queue normalQueue;
Deque urgentDeque;
Stack solvedStack;

int nextId = 1;

void init()
{
    queueArray_init(&normalQueue, 100);
    deq_init(&urgentDeque);
    stackArray_init(&solvedStack, 100);
}

int main()
{
    init();
    int choice;
    Ticket t;

    while (1)
    {
        printf("\n=== Very Useful Help Desk Ticket Manager ===\n");
        printf("1. Add Normal Ticket\n");
        printf("2. Add Urgent Ticket\n");
        printf("3. Process Next Ticket\n");
        printf("4. View Waiting Tickets\n");
        printf("5. View Solved History\n");
        printf("6. Undo Last Solved\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Add Normal
            t.id = nextId++;
            t.isUrgent = 0;
            queueArray_push(&normalQueue, t);
            printf("Normal ticket added (ID: %d)\n", t.id);
            break;

        case 2: // Add Urgent
            t.id = nextId++;
            t.isUrgent = 1;
            printf("Add to Front (1) or Back (0)? ");
            int front;
            scanf("%d", &front);
            if (front)
                deq_pushFront(&urgentDeque, t);
            else
                deq_pushBack(&urgentDeque, t);
            printf("Urgent ticket added (ID: %d)\n", t.id);
            break;

        case 3: // Process Next
            if (!deq_isEmpty(&urgentDeque))
            {
                Ticket current = deq_front(&urgentDeque);
                deq_popFront(&urgentDeque);
                stackArray_push(&solvedStack, current);
                printf("Solved URGENT ticket ID %d\n", current.id);
            }
            else if (!queueArray_isEmpty(&normalQueue))
            {
                Ticket current = queueArray_front(&normalQueue);
                queueArray_pop(&normalQueue);
                stackArray_push(&solvedStack, current);
                printf("Solved NORMAL ticket ID %d\n", current.id);
            }
            else
            {
                printf("No tickets waiting to process!\n");
            }
            break;

        case 4: // View Waiting Tickets
            printf("\n=== WAITING TICKETS ===\n");

            printf("Urgent (Deque):\n");
            if (deq_isEmpty(&urgentDeque))
                printf("  (empty)\n");
            else
            {
                DListNode *temp = urgentDeque._head;
                while (temp != NULL)
                {
                    printf("  ID:%d\n", temp->data.id);
                    temp = temp->next;
                }
            }

            printf("\nNormal (Queue):\n");
            if (queueArray_isEmpty(&normalQueue))
                printf("  (empty)\n");
            else
            {
                for (int i = normalQueue._front; i <= normalQueue._rear; i++)
                {
                    printf("  ID:%d\n", normalQueue._element[i].id);
                }
            }
            break;

        case 5: // View Solved History
            printf("\n=== SOLVED HISTORY (recent on top) ===\n");
            if (stackArray_isEmpty(&solvedStack))
            {
                printf("  (empty)\n");
            }
            else
            {
                for (int i = solvedStack._topIndex; i >= 0; i--)
                {
                    printf("  ID:%d\n", solvedStack._element[i].id);
                }
            }
            break;

        case 6: // Undo Last Solved
            if (!stackArray_isEmpty(&solvedStack))
            {
                Ticket undone = stackArray_top(&solvedStack);
                stackArray_pop(&solvedStack);
                deq_pushFront(&urgentDeque, undone);
                printf("Undid! Ticket id: %d moved back to urgent front.\n", undone.id);
            }
            else
            {
                printf("nothing solved to undo\n");
            }
            break;

        case 0:
            printf("end\n");
            return 0;
        }
    }
}