// event_notifier.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "event_notifier.h"

// Initialize an event
void event_initialize(Event *event) {
    //declare static so I can increment it every call
    static int counter = 0;

    if (event != NULL) {
        event->event_id = ++counter; //increment event_id
        event->subs = NULL; // Initialize subscribers to NULL
    } else {
        printf("Invalid event pointer\n"); // Print error
        exit(1);
    }
}

// Deinitialize an event
void event_deinitialize(Event *event) {
   if (event != NULL) {
        // Free memory allocated for subscribers (if any)
        if (event->subs != NULL) {
            free(event->subs);
            event->subs = NULL;
        }
        
        event->event_id = 0; // Reset event ID to 0
    } else {
        printf("Invalid event pointer\n");
        exit(1);
    }
}

// Subscribe to an event
bool event_subscribe(Event *event, void (*handler)(const Event *, const void *, size_t)) {
    
    //error check
    if (event == NULL || handler == NULL) {
        return false; // Invalid arguments, Unsubscription failed
    }




    return true; 
}

// Unsubscribe from an event
bool event_unsubscribe(Event *event, void (*handler)(const Event *, const void *, size_t)) {

    //error check
    if (event == NULL || handler == NULL) {
        return false; // Invalid arguments, Unsubscription failed
    }




    return true; 
}

// Notify subscribers of an event
void event_notify(Event *event, const void *data, size_t length) {
    
}