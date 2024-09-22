// no file reading 

#include <stdio.h>
#include <stdlib.h>

#define MAX_FIB_POSITION 93

unsigned long long memo[MAX_FIB_POSITION + 1];

// Recursive Fibonacci with memoization
unsigned long long fib_recursive(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    
    // Check if the result is already memoized
    if (memo[n] != 0) {
        return memo[n];
    }

    // Compute and store the result in the memo array
    memo[n] = fib_recursive(n - 1) + fib_recursive(n - 2);
    return memo[n];
}

// Iterative Fibonacci with memoization
unsigned long long fib_iterative(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    
    if (memo[n] != 0) {
        return memo[n];
    }

    unsigned long long prev = 1, current = 1, next;
    for (int i = 3; i <= n; i++) {
        next = prev + current;
        prev = current;
        current = next;
    }

    // Store the result in the memo array
    memo[n] = current;
    return current;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <integer> <r|i>\n", argv[0]);
        return 1;
    }

    // Convert first argument to an integer
    int N = atoi(argv[1]);

    // Initialize the memo array to 0
    for (int i = 0; i <= MAX_FIB_POSITION; i++) {
        memo[i] = 0;
    }

    // Determine Fibonacci number
    unsigned long long result;
    if (argv[2][0] == 'r') {
        result = fib_recursive(N - 1);
    } else if (argv[2][0] == 'i') {
        result = fib_iterative(N - 1);
    } else {
        printf("Invalid method. Use 'r' for recursive or 'i' for iterative.\n");
        return 1;
    }

    // Output the result 
    printf("%llu\n", result);

    return 0;
}

