#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 6
// Stack and Queue Implementation
char* parts[] = {"Drill", "Wheel", "Camera", "Arm", "Battery", "Sonar"};
char* queue[SIZE];
char* stack[SIZE];
int front = 0, rear = 0, top = -1;

void enqueue(char* part) {
    queue[rear++] = part;
}

char* dequeue() {
    return queue[front++];
}

void push(char* part) {
    stack[++top] = part;
}

char* pop() {
    return stack[top--];
}

int main() {
    printf("Part Delivery and Repair Order:\n");

    // Enqueue parts
    for (int i = 0; i < SIZE; i++) enqueue(parts[i]);

    // Dequeue and push to stack
    while (front < rear) push(dequeue());

    // Pop from stack to show repair order
    while (top >= 0) printf("%s\n", pop());

    return 0;
}
