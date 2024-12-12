#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

#define BENCHMARK_SIZE 1000000

void benchmark_push() {
    Stack stack;
    initStack(&stack);
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (int i = 0; i < BENCHMARK_SIZE; i++) {
        push(&stack, i);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Benchmark push: %f seconds\n", cpu_time_used);
    destroyStack(&stack);
}

void benchmark_pop() {
    Stack stack;
    initStack(&stack);
     for(int i = 0; i < BENCHMARK_SIZE; i++) {
        push(&stack, i);
    }
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (int i = 0; i < BENCHMARK_SIZE; i++) {
        pop(&stack);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Benchmark pop: %f seconds\n", cpu_time_used);
    destroyStack(&stack);
}