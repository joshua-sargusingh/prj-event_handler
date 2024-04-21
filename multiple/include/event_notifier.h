// event_notifier.h

#ifndef EVENT_NOTIFIER_H
#define EVENT_NOTIFIER_H

#include <stdbool.h> // For bool type
#include <stddef.h>  // For size_t

// Define Event Data Structure
typedef struct {
    int event_id;
    // Add more fields as needed for event-specific data
} Event;

// Define a Linked List Node For Event Subscribers
typedef struct {
    struct Event *event;
    struct Subscriber *next;
} Subscriber;








// Define the 
typedef struct {
    void (*handler)(const Event *, const void *, size_t);
    struct Event_Queue_Node *next;
} Event_Queue_Node;

// Function to initialize the event system
void event_initialize(Event *event);

// Function to deinitialize the event system
void event_deinitialize(Event *event);

// Function to subscribe to an event
bool event_subscribe(Event *event, void (*handler)(const event *, const void *, size_t));

// Function to unsubscribe from an event
bool event_unsubscribe(Event *event, void (*handler)(const event *, const void *, size_t));

// Function to notify subscribers of an event
void event_notify(Event *event, const void *data, size_t length);

#endif