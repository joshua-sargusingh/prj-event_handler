// event_notifier.h

#ifndef EVENT_NOTIFIER_H
#define EVENT_NOTIFIER_H

#include <stdbool.h> // For bool type
#include <stddef.h>  // For size_t

// Struct to Hold Information about a Subscriber
typedef struct {
    int sub_id;
    struct Subscriber *next;
} Subscriber;

// Struct to Represent an Event
typedef struct {
    int event_id;
    //This pointer to subscriber struct represents the subscribers subscribed to this event. By using a pointer - multiple subscribers can associate with the same event
    struct Subscriber* subs; 
} Event;



//void (*handler)(const Event *, const void *, size_t);



// Function to initialize the event system
void event_initialize(Event *event);

// Function to deinitialize the event system
void event_deinitialize(Event *event);

// Function to subscribe to an event
//bool event_subscribe(Event *event, void (*handler)(const Event*, const void *, size_t));

// Function to unsubscribe from an event
//bool event_unsubscribe(Event *event, void (*handler)(const Event*, const void *, size_t));

// Function to notify subscribers of an event
//void event_notify(Event *event, const void *data, size_t length);

#endif