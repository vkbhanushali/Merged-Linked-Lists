#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
typedef struct SinglyLinkedListNode {
    int data;
    struct SinglyLinkedListNode* next;
} SinglyLinkedListNode;

// Function to create a new node
SinglyLinkedListNode* create_node(int data) {
    SinglyLinkedListNode* new_node = (SinglyLinkedListNode*) malloc(sizeof(SinglyLinkedListNode));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the end of the linked list
void insert_node(SinglyLinkedListNode** head, int data) {
    SinglyLinkedListNode* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        SinglyLinkedListNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print the linked list
void print_linked_list(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to merge two sorted linked lists
SinglyLinkedListNode* merge_lists(SinglyLinkedListNode* l1, SinglyLinkedListNode* l2) {
    // Create a dummy node to simplify the merge process
    SinglyLinkedListNode* dummy = create_node(0);
    SinglyLinkedListNode* current = dummy;

    // Merge the two lists
    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    // If there are any nodes left in l1 or l2, append them
    if (l1 != NULL) {
        current->next = l1;
    } else {
        current->next = l2;
    }

    // The head of the merged list is the next of dummy node
    SinglyLinkedListNode* merged_head = dummy->next;
    free(dummy);  // Free the dummy node
    return merged_head;
}

int main() {
    int tests;
    scanf("%d", &tests);  // Read the number of test cases

    for (int t = 0; t < tests; t++) {
        int l1_count, l2_count;
        scanf("%d", &l1_count);  // Read the number of elements in list 1

        SinglyLinkedListNode* l1 = NULL;
        for (int i = 0; i < l1_count; i++) {
            int value;
            scanf("%d", &value);
            insert_node(&l1, value);  // Insert nodes into list 1
        }

        scanf("%d", &l2_count);  // Read the number of elements in list 2

        SinglyLinkedListNode* l2 = NULL;
        for (int i = 0; i < l2_count; i++) {
            int value;
            scanf("%d", &value);
            insert_node(&l2, value);  // Insert nodes into list 2
        }

        // Merge the two sorted lists
        SinglyLinkedListNode* merged_list = merge_lists(l1, l2);

        // Print the merged list
        print_linked_list(merged_list);
    }

    return 0;
}