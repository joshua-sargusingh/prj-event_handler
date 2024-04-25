//main.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "event_notifier.h"

int main() {

    // Initiate Two Events
    Event* event_1 = event_create();
    Event* event_2 = event_create();
    event_initialize(event_1);
    event_initialize(event_2);
    printf("Initialized Event ID: %d\n", event_1->event_id);
    printf("Initialized Event ID: %d\n", event_2->event_id);

    // Subscribe Two Subscribers to Event_1
    if (event_subscribe(event_1, handler) == true) {
        printf("Subscriber %d has subscribed to Event ID: %d\n", event_1->subs->sub_id, event_1->event_id);
    } else {
        printf("Subscriber failed to subscribe to Event ID: %d\n", event_1->event_id);
    }
    if (event_subscribe(event_2, handler) == true) {
        printf("Subscriber %d has subscribed to Event ID: %d\n", event_2->subs->sub_id, event_2->event_id);
    } else {
        printf("Subscriber failed to subscribe to Event ID: %d\n", event_2->event_id);
    }

    // Subscribe One Subscriber to Event_1
    if (event_subscribe(event_1, handler) == true) {
        printf("Subscriber %d has subscribed to Event ID: %d\n", event_1->subs->sub_id, event_1->event_id);
    } else {
        printf("Subscriber failed to subscribe to Event ID: %d\n", event_1->event_id);
    }

    //notify event
    int data = 1;
    printf("Notification Received for Event ID: %d\n", event_1->event_id);
    event_notify(event_1, &data, sizeof(int));

    //unsubscribe to an event
    if (event_unsubscribe(event_1,event_1->subs->sub_id) == true) {
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