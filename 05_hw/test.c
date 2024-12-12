#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"



void print_error(const char* test_name, const char* message) {
    fprintf(stderr, "Test %s failed: %s\n", test_name, message);
}


void test_init_stack() {
    Stack stack;
    initStack(&stack);
    assert(stack.top == NULL); // Убедиться, что стек пуст
    printf("Test init_stack passed\n");
}

void test_push() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    assert(stack.top != NULL); // Вершина не должна быть NULL после push
    assert(stack.top->data == 10); // Данные на вершине соответствуют добавленному элементу
    push(&stack, 20);
    assert(stack.top->data == 20); // Вершина обновляется с каждым новым элементом
    printf("Test push passed\n");
    destroyStack(&stack);
}


void test_pop() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    pop(&stack);
    assert(stack.top != NULL && stack.top->data == 10); // Удален верхний элемент
    pop(&stack);
    assert(stack.top == NULL); // Стек пуст
    pop(&stack); // Попытка удалить из пустого стека
    assert(stack.top == NULL); // Никаких изменений для пустого стека
    printf("Test pop passed\n");
    destroyStack(&stack);
}


void test_search_by_value() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    
    Node* result = searchByValue(&stack, 20);
    assert(result != NULL && result->data == 20); 

    result = searchByValue(&stack, 15);
    assert(result == NULL); 
    
    // Проверка на пустом стеке
    Stack emptyStack;
    initStack(&emptyStack);
    result = searchByValue(&emptyStack, 10);
    assert(result == NULL);
    
    printf("Test search_by_value passed\n");
    destroyStack(&stack);
}


void test_search_by_index() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    Node* result = searchByIndex(&stack, 1);
    assert(result != NULL && result->data == 20); // Элемент по индексу 1 найден

    result = searchByIndex(&stack, 0);
    assert(result != NULL && result->data == 30); // Элемент по индексу 0 найден

    result = searchByIndex(&stack, 5);
    assert(result == NULL); // Индекс вне пределов

    // Проверка на пустом стеке
    Stack emptyStack;
    initStack(&emptyStack);
    result = searchByIndex(&emptyStack, 0);
    assert(result == NULL);
    printf("Test search_by_index passed\n");
    destroyStack(&stack);
}


void test_get_top() {
    Stack stack;
    initStack(&stack);
    assert(getTop(&stack) == NULL); // Пустой стек
    push(&stack, 10);
    assert(getTop(&stack) != NULL && getTop(&stack)->data == 10); // Вершина корректна
    push(&stack, 20);
    assert(getTop(&stack)->data == 20);
    printf("Test get_top passed\n");
    destroyStack(&stack);
}


void test_is_empty() {
    Stack stack;
    initStack(&stack);
    assert(isEmpty(&stack) == true); 
    push(&stack, 10);
    assert(isEmpty(&stack) == false);
    pop(&stack);
    assert(isEmpty(&stack) == true); 
    printf("Test is_empty passed\n");
    destroyStack(&stack);
}


void test_traverse_stack() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Test traverse_stack (output check manually):\n");
    traverseStack(&stack); // Вручную проверить вывод
    destroyStack(&stack);
}


void test_destroy_stack() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    destroyStack(&stack);
    assert(stack.top == NULL); // После уничтожения вершина должна быть NULL
    printf("Test destroy_stack passed\n");
}

int main() {
    // Запуск всех тестов
    test_init_stack();
    test_push();
    test_pop();
    test_search_by_value();
    test_search_by_index();
    test_get_top();
    test_is_empty();
    test_traverse_stack();
    test_destroy_stack();


    return 0;
}