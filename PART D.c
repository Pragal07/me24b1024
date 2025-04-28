#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct CNode {
    char data[10];
    struct CNode* next;
} CNode;
int main() {
    CNode* rov1 = malloc(sizeof(CNode));
    CNode* rov4 = malloc(sizeof(CNode));
    strcpy(rov1->data, "Rov1");
    strcpy(rov4->data, "Rov4");
    // Circular link
    rov1->next = rov4;
    rov4->next = rov1;
    // Traverse twice
    CNode* current = rov1;
    for (int i = 0; i < 4; i++) {
        printf("%s\n", current->data);
        current = current->next;
    }
    // Free memory
    free(rov1);
    free(rov4);
    return 0;
 }
