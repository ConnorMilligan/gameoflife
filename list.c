#include "list.h"

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

void initilizeList(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
}

void push(LinkedList *list, void *data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (list->tail == NULL) {
        list->head = list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void delete(LinkedList *list, Node *node) {
    if (node == list->head) {
        if (list->head == list->tail) {
            list->head = list->tail = NULL;
        } else {
            list->head = node->next;
        }
    } else {
        Node *temp = list->head;
        while (temp != NULL && temp->next != node)
            temp = temp->next;
        
        if (temp != NULL) {
            temp->next = node->next;
            if (node == list->tail) 
                list->tail = temp;
        }
    }
    
    free(node);
    list->size--;
}

Node* pop(LinkedList *list) {
    if (list->tail == NULL)
        return NULL;

    Node *node = list->tail;

    if (list->head == list->tail) {
        list->head = list->tail = NULL;
    } else {
        Node *temp = list->head;
        while (temp->next != list->tail)
            temp = temp->next;

        list->tail = temp;
        temp->next = NULL;
    }
    list->size--;

    return node;
}

Node* getNode(LinkedList *list, COMPARE compare, void *data) {
    Node *node = list->head;
    while (node != NULL) {
        if (compare(node->data, data) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void printList(LinkedList *list, DISPLAY display) {
    printf("Linked List\n");
    Node *current = list->head;
    while (current != NULL) {
        display(current->data);
        current = current->next;
    }
}