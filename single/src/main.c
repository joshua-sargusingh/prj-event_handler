//main.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "event_notifier.h"

int main() {

    // Declare an Event struct 1
    Event event_1;  

    // Initialize the Event struct using event_initialize function
    event_initialize(&event_1);

    // Perform actions with the Event object (e.g., print event ID)
    printf("Initialized Event ID: %d\n", event_1.event_id);

    // Call event_deinitialize to clean up
    event_deinitialize(&event_1);

    // Print message to indicate cleanup
    printf("Event deinitialized\n");

    return 0;
}