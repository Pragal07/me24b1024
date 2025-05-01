#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARTS 6
#define MAX_SLOTS 5
#define MAX_NAME 20

// Structure for Linked List Nodes
typedef struct Node {
    char name[MAX_NAME];
    struct Node *next;
    struct Node *prev; // For doubly linked list
} Node;

// Structure for Circular Linked List
typedef struct CNode {
    char name[MAX_NAME];
    struct CNode *next;
} CNode;

//Part a) Part Delivery and Arm (Queue + Stack)

// Queue Implementation
typedef struct {
    char parts[MAX_PARTS][MAX_NAME];
    int front, rear;
} Queue;

// Stack Implementation
typedef struct {
    char parts[MAX_PARTS][MAX_NAME];
    int top;
} Stack;

// Queue Functions
void enqueue(Queue *q, char *part) {
    if (q->rear == MAX_PARTS - 1) {
        printf("Queue is full.\n");
        return;
    }
    strcpy(q->parts[++q->rear], part);
}

char* dequeue(Queue *q) {
    if (q->front > q->rear) {
        printf("Queue is empty.\n");
        return NULL;
    }
    return q->parts[q->front++];
}

// Stack Functions
void push(Stack *s, char *part) {
    if (s->top == MAX_PARTS - 1) {
        printf("Stack overflow.\n");
        return;
    }
    strcpy(s->parts[++s->top], part);
}

char* pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow.\n");
        return NULL;
    }
    return s->parts[s->top--];
}

//Part b) Assembly Storage Unit (Array)
typedef struct {
    char rovers[MAX_SLOTS][MAX_NAME];
    int count;
} AssemblyStorage;

void addRover(AssemblyStorage *storage, char *rover) {
    if (storage->count == MAX_SLOTS) {
        printf("Storage full. Deploying oldest rover: %s\n", storage->rovers[0]);
        for (int i = 1; i < MAX_SLOTS; i++) {
            strcpy(storage->rovers[i-1], storage->rovers[i]);
        }
        storage->count--;
    }
    strcpy(storage->rovers[storage->count++], rover);
}

//Part c) Faulty Rover Tracker (Linked Lists)

// Singly Linked List Functions
Node* insertSingly(Node *head, char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = head;
    newNode->prev = NULL;
    return newNode;
}

// Delete from Singly List
Node* deleteSingly(Node *head, char *name) {
    Node *temp = head, *prev = NULL;
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return head;
    if (prev == NULL) head = temp->next;
    else prev->next = temp->next;
    free(temp);
    return head;
}

// Doubly Linked List Functions
Node* insertDoubly(Node *head, char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
        head->prev = newNode;
    return newNode;
}

void traverseDoubly(Node *head) {
    Node *temp = head;
    printf("Forward: ");
    while (temp) {
        printf("%s -> ", temp->name);
        if (temp->next == NULL) break;
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Backward: ");
    while (temp) {
        printf("%s -> ", temp->name);
        temp = temp->prev;
    }
    printf("NULL\n");
}

//Part d) Priority Upgrades (Circular Linked List)

CNode* insertCircular(CNode *last, char *name) {
    CNode *newNode = (CNode *)malloc(sizeof(CNode));
    strcpy(newNode->name, name);

    if (last == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = last->next;
    last->next = newNode;
    return newNode;
}

void traverseCircular(CNode *last) {
    if (last == NULL) return;
    CNode *temp = last->next;
    do {
        printf("%s -> ", temp->name);
        temp = temp->next;
    } while (temp != last->next);
    printf("(repeat)\n");
}

//Main Function
int main() {
    Queue q = {.front = 0, .rear = -1};
    Stack s = {.top = -1};
    char *parts[MAX_PARTS] = {"Drill", "Wheel", "Camera", "Arm", "Battery", "Sonar"};

    printf("Part a) Part Delivery and Arm\n");
    for (int i = 0; i < MAX_PARTS; i++) {
        enqueue(&q, parts[i]);
    }
    for (int i = 0; i < MAX_PARTS; i++) {
        char *part = dequeue(&q);
        if (part) push(&s, part);
    }
    printf("Repair Order (LIFO):\n");
    for (int i = 0; i < MAX_PARTS; i++) {
        char *part = pop(&s);
        if (part) printf("%s\n", part);
    }

    printf("\nPart b) Assembly Storage Unit\n");
    AssemblyStorage storage = {.count = 0};
    char *rovers[] = {"Rov1", "Rov2", "Rov3", "Rov4", "Rov5", "Rov6", "Rov7"};
    for (int i = 0; i < 7; i++) {
        addRover(&storage, rovers[i]);
    }
    printf("Current Storage:\n");
    for (int i = 0; i < storage.count; i++) {
        printf("%s\n", storage.rovers[i]);
    }

    printf("\nPart c) Faulty Rover Tracker\n");
    Node *faultyHead = NULL, *repairedHead = NULL;
    faultyHead = insertSingly(faultyHead, "Rov3");
    faultyHead = insertSingly(faultyHead, "Rov6");

    printf("Faulty Rovers:\n");
    for (Node *temp = faultyHead; temp != NULL; temp = temp->next) {
        printf("%s -> ", temp->name);
    }
    printf("NULL\n");

    faultyHead = deleteSingly(faultyHead, "Rov3");
    repairedHead = insertDoubly(repairedHead, "Rov3");

    printf("Repaired Rovers (Doubly Linked List):\n");
    traverseDoubly(repairedHead);

    printf("\nPart d) Priority Upgradesn");
    CNode *priorityLast = NULL;
    priorityLast = insertCircular(priorityLast, "Rov1");
    priorityLast = insertCircular(priorityLast, "Rov4");

    printf("Priority Rovers (Circular List Traversal Twice):\n");
    traverseCircular(priorityLast);
    traverseCircular(priorityLast);

    return 0;
}
