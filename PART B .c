 
B) Assembly Storage Unit
#include <stdio.h>
#include <string.h>
#define STORAGE 5
int main() {
    char* storage[STORAGE];
    char* rovers[] = {"Rov1", "Rov2", "Rov3", "Rov4", "Rov5", "Rov6", "Rov7"};

    // Insert first 5 rovers
    for (int i = 0; i < STORAGE; i++) storage[i] = rovers[i];

    // Handle overflow
    for (int i = STORAGE; i < 7; i++) {
        // Deploy oldest
        for (int j = 0; j < STORAGE - 1; j++) storage[j] = storage[j + 1];
        storage[STORAGE - 1] = rovers[i];
    }
    printf("Final Rovers in Storage:\n");
    for (int i = 0; i < STORAGE; i++) printf("%s\n", storage[i]);

    return 0;                                                       
}
