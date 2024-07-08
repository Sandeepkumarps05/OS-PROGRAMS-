#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MIN 10

int n, ref[MAX], count, frame[MIN], temp;

void input() {
    count = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &n);
    
    printf("Enter the reference string (-1 to end): ");
    scanf("%d", &temp);
    
    while (temp != -1) {
        ref[count++] = temp;
        scanf("%d", &temp);
    }
}

void LRU() {
    int i, j, k, stack[MIN], top = 0, fault = 0, found;

   
    
    for (i = 0; i < count; i++) {
        found = 0;
        
        // Check if the reference is already in the stack
        for (j = 0; j < top; j++) {
            if (stack[j] == ref[i]) {
                // Move the referenced page to the top of the stack
                for (k = j; k < top - 1; k++) {
                    stack[k] = stack[k + 1];
                }
                stack[top - 1] = ref[i];
                found = 1;
                break;
            }
        }
        
        // If not found, add the reference to the stack
        if (!found) {
            if (top < n) {
                stack[top++] = ref[i];
            } else {
                // Remove the least recently used page (bottom of the stack)
                for (k = 0; k < n - 1; k++) {
                    stack[k] = stack[k + 1];
                }
                stack[top - 1] = ref[i];
            }
            fault++;
        }
        
        // Display the current stack status
        printf("\nAfter inserting %d the stack status is: ", ref[i]);
        for (j = 0; j < top; j++) {
            printf("%d ", stack[j]);
        }
    }
    
    printf("\n\nTotal page faults: %d\n", fault);
    printf("\n\nPress any key to continue...\n");
}

int main() {
    int x;
    
    while (1) {
        printf("\n\n\tMenu");
        printf("\n\t1. Input");
        printf("\n\t2. LRU algorithm");
        printf("\n\t0. Exit");
        
        printf("\n\nEnter your choice: ");
        scanf("%d", &x);
        
        switch (x) {
            case 1:
                input();
                break;
            case 2:
                LRU();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
