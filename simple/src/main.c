//main.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "event_notifier.h"

int main() {

    // Dynamically allocate an Event object and Initialize the Event
    Event* event_1 = (Event*)malloc(sizeof(Event));
    if (event_1 == NULL) {
        printf("Memory Allocation Error\n");
        return 1;
    }
    event_initialize(event_1);
    printf("Initialized Event ID: %d\n", event_1->event_id);

    // Subscribe to an event
    if (event_subscribe(event_1, handler) == true) {
        printf("Subscriber has subscribed to Event ID: %d\n", event_1->event_id);
    } else {
        printf("Subscriber failed to subscribe to Event ID: %d\n", event_1->event_id);
    }

    // Notify event
    int data = 1;
    printf("Notification Received for Event ID: %d\n", event_1->event_id);
    event_notify(event_1, &data, sizeof(int));

    // Unsubscribe from an event
    if (event_unsubscribe(event_1,1) == true) {
        printf("Subscriber has unsubscribed to Event ID: %d\n", event_1->event_id);
    } else {
        printf("Subscriber failed to unsubscribe to Event ID: %d\n", event_1->event_id);
    }    

    // Call event_deinitialize to clean up
    event_deinitialize(event_1);
    free(event_1);

    // Print message to indicate cleanup
    printf("Event deinitialized\n");

    return 0;
}