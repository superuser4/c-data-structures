#include <stdio.h>
#include <stdlib.h>

typedef struct SinglyLinkedListNode {
    int data;
    struct SinglyLinkedListNode* next;
} LinkedListNode;


void insertAtPosition(LinkedListNode** head, int data, int index) {
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->data = data;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = *head;   
        *head = newNode;     
        return;               
    }

    LinkedListNode* c = *head;
    int i;
    for (i = 0; i < index && c->next != NULL; i++) {
        c = c->next;
    }
    if (index > i) {
        c->next = newNode;
    } else {
        LinkedListNode *end = c->next;
        c->next = newNode;
        newNode->next = end;
    }
}


LinkedListNode* deleteAtPosition(LinkedListNode** head, int index) {
    LinkedListNode* c = *head;
    int i;
    for (i = 0; i < index && c->next != NULL; i++) {
        c = c->next;
    }
    if (index > i) {
        // index out of bounds
        return NULL;
    } else {
        // delete at normal index
        LinkedListNode* middle = c->next;
        c->next = c->next->next;
        return middle;
    }
}

void printList(LinkedListNode* head) {
    LinkedListNode *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    puts("");
}

int main() {
    LinkedListNode* head = NULL;

    insertAtPosition(&head, 10, 0);
    insertAtPosition(&head, 20, 1);
    insertAtPosition(&head, 30, 2);
    insertAtPosition(&head, 40, 5);

    printf("Linked list after insertions:\n");
    printList(head);

    LinkedListNode* deletedNode = deleteAtPosition(&head, 2);
    if (deletedNode) {
        printf("Deleted node with value: %d\n", deletedNode->data);
        free(deletedNode);
    } else {
        printf("Deletion failed\n");
    }

    printf("Linked list after deletion:\n");
    printList(head);

}
