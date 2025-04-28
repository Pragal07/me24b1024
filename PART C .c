#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Singly Linked List Node
typedef struct SNode {
    char data[10];
    struct SNode* next;
} SNode;

// Doubly Linked List Node
typedef struct DNode {
    char data[10];
    struct DNode* next;
    struct DNode* prev;
} DNode;

int main() {
    // Create singly linked list
    SNode* faulty = malloc(sizeof(SNode));
    strcpy(faulty->data, "Rov3");
    faulty->next = malloc(sizeof(SNode));
    strcpy(faulty->next->data, "Rov6");
    faulty->next->next = NULL;

    // Remove Rov3 and add to doubly linked list
    DNode* repaired = malloc(sizeof(DNode));
    strcpy(repaired->data, "Rov3");
    repaired->next = NULL;
    repaired->prev = NULL;

    printf("Repaired Rovers (Forward): %s\n", repaired->data);
    printf("Repaired Rovers (Backward): %s\n", repaired->data);

    // Free memory
    free(faulty->next);
    free(faulty);
    free(repaired);

    return 0;
}
