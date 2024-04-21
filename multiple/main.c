// event_notifier.c

#include <stdlib.h>
#include "event_notifier.h"

// Initialize an event
void event_initialize(Event *event) {
    event->event_id = 0; // Initialize event ID to 0 or any default value
    // Additional initialization as needed
}

// Deinitialize an event
void event_deinitialize(Event *event) {
    // Clean up any resources if needed
}

// Subscribe to an event
bool event_subscribe(Event *event, void (*handler)(const Event *, const void *, size_t)) {
    int event_id = event->event_id;
    if (event_id >= 0 && event_id < MAX_SUBSCRIBERS) {
        EventQueue *queue = &event_queues[event_id];
        if (queue->num_subscribers < MAX_SUBSCRIBERS) {
            EventQueueNode *newNode = (EventQueueNode *)malloc(sizeof(EventQueueNode));
            if (newNode == NULL) {
                return false; // Memory allocation failed
            }
            newNode->handler = handler;
            newNode->next = NULL;

            if (queue->rear == NULL) {
                queue->front = newNode;
                queue->rear = newNode;
            } else {
                queue->rear->next = newNode;
                queue->rear = newNode;
            }

            queue->num_subscribers++;
            return true; // Subscription successful
        }
    }
    return false; // Subscription failed
}

// Unsubscribe from an event
bool event_unsubscribe(Event *event, void (*handler)(const Event *, const void *, size_t)) {
    int event_id = event->event_id;
    if (event_id >= 0 && event_id < MAX_SUBSCRIBERS) {
        EventQueue *queue = &event_queues[event_id];
        EventQueueNode *curr = queue->front;
        EventQueueNode *prev = NULL;

        while (curr != NULL) {
            if (curr->handler == handler) {
                if (prev == NULL) {
                    queue->front = curr->next;
                    if (queue->front == NULL) {
                        queue->rear = NULL;
                    }
                } else {
                    prev->next = curr->next;
                    if (prev->next == NULL) {
                        queue->rear = prev;
                    }
                }

                free(curr);
                queue->num_subscribers--;
                return true; // Unsubscription successful
            }

            prev = curr;
            curr = curr->next;
        }
    }
    return false; // Unsubscription failed
}

// Notify subscribers of an event
void event_notify(Event *event, const void *data, size_t length) {
    int event_id = event->event_id;
    if (event_id >= 0 && event_id < MAX_SUBSCRIBERS) {
        EventQueue *queue = &event_queues[event_id];
        EventQueueNode *curr = queue->front;

        while (curr != NULL) {
            curr->handler(event, data, length);
            curr = curr->next;
        }
    }
}