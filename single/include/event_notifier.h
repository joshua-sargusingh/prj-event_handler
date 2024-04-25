// event_notifier.h

#ifndef EVENT_NOTIFIER_H
#define EVENT_NOTIFIER_H

#include <stdbool.h> // For bool type
#include <stddef.h>  // For size_t

// Forward declarations
struct Event;

// Struct to Hold Information about a Subscriber
typedef struct{
    int sub_id;
    struct Subscriber *next;
    void (*handler)(const struct Event *, const void *, size_t);
}Subscriber;

// Struct to Represent an Event
typedef struct{
    int event_id;
    //This pointer to subscriber struct represents the subscribers subscribed to this event. By using a pointer - multiple subscribers can associate with the same event
    Subscriber* subs; 
}Event;

// Placeholder Function: We declare it so that the compiler knows that it exists
// This handler function points to a function that knows how to handle incoming data from the event
// It can either update the data or display a msg
// When calling it from a void function, I am saying "handler, I have an event that I need handled."
// This function then takes the input and outputs the data from the event so I can use it.
void handler(const Event* event, const void* data, size_t size);

// Function to initialize the event system
void event_initialize(Event *event);

// Function to deinitialize the event system
void event_deinitialize(Event *event);

// Function to subscribe to an event
bool event_subscribe(Event *event, void (*handler)(const Event*, const void *, size_t));

// Function to unsubscribe from an event
bool event_unsubscribe(Event *event, int sub_id);

// Function to notify subscribers of an event
//void event_notify(Event *event, const void *data, size_t length);

#endif