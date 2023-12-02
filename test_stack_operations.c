#include <stdio.h>
#include "stack_operations.c"

int main() {
    // Test Case 1: Empty stack
    t_head stack1;
    stack1.top = NULL;
    stack1.bottom = NULL;
    stack1.name = 'a';
    reverse_rotate(&stack1);
    // Expected output: No output (stack remains empty)

    // Test Case 2: Single element stack
    t_head stack2;
    t_node node2;
    node2.value = 42;
    node2.next = NULL;
    node2.prev = NULL;
    stack2.top = &node2;
    stack2.bottom = &node2;
    stack2.name = 'b';
    reverse_rotate(&stack2);
    // Expected output: No output (stack remains unchanged)

    // Test Case 3: Multiple element stack
    t_head stack3;
    t_node node3_1, node3_2, node3_3;
    node3_1.value = 1;
    node3_2.value = 2;
    node3_3.value = 3;
    node3_1.next = &node3_2;
    node3_2.next = &node3_3;
    node3_3.next = NULL;
    node3_1.prev = NULL;
    node3_2.prev = &node3_1;
    node3_3.prev = &node3_2;
    stack3.top = &node3_3;
    stack3.bottom = &node3_1;
    stack3.name = 'a';
    reverse_rotate(&stack3);
    // Expected output: "rra" (printed by ft_printf)

    return 0;
}