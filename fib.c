#include <stdio.h>
#include <stdlib.h>

#define MAX_FIB_POSITION 93

unsigned long long memo[MAX_FIB_POSITION + 1];

// Recursive Fibonacci wrapper 
unsigned long long fib_wrapper_recursive(int fibonacci_position) {
    if (fibonacci_position == 1 || fibonacci_position == 2) {
        return 1;
    }
    return fib_wrapper_recursive(fibonacci_position - 1) + fib_wrapper_recursive(fibonacci_position - 2);
}

// Iterative Fibonacci wrapper 
unsigned long long fib_wrapper_iterative(int fibonacci_position) {
    if (fibonacci_position == 1 || fibonacci_position == 2) {
        return 1;
    }

    unsigned long long previous = 1;
    unsigned long long current = 1;
    unsigned long long next;

    for (int i = 3; i <= fibonacci_position; i++) {
        next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}

// // Recursive Fibonacci with memoization
// unsigned long long fib_r(int fibonacci_position) {
//     if (memo[fibonacci_position] != 0) {
//         return memo[fibonacci_position];
//     }

//     // Call the original recursive Fibonacci function
//     memo[fibonacci_position] = fib_wrapper_recursive(fibonacci_position);
//     return memo[fibonacci_position];
// }
unsigned long long fib_r(int fibonacci_position) {
    if (fibonacci_position == 1 || fibonacci_position == 2) {
        return 1;
    }
    // Check if the result is already memoized
    if (memo[fibonacci_position] != 0) {
        return memo[fibonacci_position];
    }

    // Compute and store the result in the memo array
    memo[fibonacci_position] = fib_r(fibonacci_position - 1) + fib_r(fibonacci_position - 2);
    return memo[fibonacci_position];
}


// Iterative Fibonacci with memoization 
unsigned long long fib_i(int fibonacci_position) {
    if (memo[fibonacci_position] != 0) {
        return memo[fibonacci_position];
    }

    // Call the original iterative Fibonacci function
    memo[fibonacci_position] = fib_wrapper_iterative(fibonacci_position);
    return memo[fibonacci_position];
}

int main(int arg_count, char *arg_values[]) {
    if (arg_count != 4) {
        printf("Usage: %s <integer> <r|i> <filename>\n", arg_values[0]);
        return 1;
    }

    int input_number = atoi(arg_values[1]);

    FILE *file = fopen(arg_values[3], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int file_number;
    fscanf(file, "%d", &file_number);
    fclose(file);

    int fibonacci_position = input_number + file_number;

    // Initialize the memo array to 0
    for (int i = 0; i <= MAX_FIB_POSITION; i++) {
        memo[i] = 0;
    }

    unsigned long long result;

    if (arg_values[2][0] == 'r') {
        result = fib_r(fibonacci_position - 1);
    } else if (arg_values[2][0] == 'i') {
        result = fib_i(fibonacci_position - 1);
    } else {
        printf("Invalid method. Use 'r' for recursive or 'i' for iterative.\n");
        return 1;
    }

    printf("%llu\n", result);

    return 0;
}