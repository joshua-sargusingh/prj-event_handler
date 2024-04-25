// event_notifier.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "event_notifier.h"

void handler(const Event* event, const void* data, size_t size) {

}

Subscriber* sub_create() {
    //declare static so I can increment it every call
    static int counter = 0;

    Subscriber* sub_new = (Subscriber*)malloc(sizeof(Subscriber));

    //error check
    if (sub_new == NULL) {
        printf("Memory Allocation Error");
        return NULL;
    }

    //assign values to the new Subscriber node
    sub_new->sub_id = ++counter; //unique identifier
    //sub_new->handler = handler;
    sub_new->next = NULL; // Initialize next pointer to NULL

    return sub_new;
};

//initialize an event
void event_initialize(Event *event) {
    //struct already created (8 bytes)
    //declare static so I can increment it every call
    static int counter = 0;

    if (event != NULL) {
        event->event_id = ++counter; //increment event_id
        event->subs = NULL; //initialize subscribers to NULL
    } else {
        printf("Invalid event pointer\n");
        exit(1);
    }
}

// Deinitialize an event
void event_deinitialize(Event *event) {
   if (event != NULL) {
        //free memory allocated for subscribers (if any)
        Subscriber *current = event->subs;
        Subscriber *next = NULL;

        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
        
        event->subs = NULL; // Set subs pointer to NULL after freeing all nodes

        // free(event); //free event

    } else {
        printf("Invalid event pointer\n");
        exit(1);
    }
}

// Subscribe to an event
bool event_subscribe(Event *event, void (*handler)(const Event *, const void *, size_t)) {

    //error check
    if (event == NULL) { //|| handler == NULL was removed as error check to test code without function input 
        return false; //invalid arguments, unsubscription failed
    }

    //create a new Subscriber node
    Subscriber* sub_new = sub_create();

    // Link the new Subscriber node to the existing list
    if (sub_new == NULL) {
        return false; // Memory allocation failed, subscription failed
    }

    //link the new Subscriber node to the existing list
    if (event->subs == NULL) {
        event->subs = sub_new; // First subscriber in the list
    } else {
        // Find the last node in the list and link the new node
        Subscriber* current = event->subs;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = sub_new; // Link the new node to the end of the list
    }

    return true; 
}

// Unsubscribe from an event
bool event_unsubscribe(Event *event, int sub_id) {

    //error check
    if (event == NULL) {
        return false; //invalid arguments, unsubscription failed
    }

    //assign temp nodes to traverse linked list
    Subscriber* curr = event->subs; //equal to first element of linked list
    Subscriber* prev = NULL; //equal to first element of linked list

    //traverses the linked list to find the subscriber and unsubscribe
    while (curr != NULL) {
        if (curr->sub_id == sub_id) { //if equal
            if (prev == NULL) { //first element check
                event->subs = curr->next; //update head of linked list
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return true;
        }
        prev = curr;
        curr = curr->next; //move to next node
    }
    
    return false; 
}

//notify subscribers of an event
void event_notify(Event *event, const void *data, size_t length) {
    
}