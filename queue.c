#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

#define debug(...) fprintf(stderr, __VA_ARGS__)

Queue *queue_create(void)
{
  Queue *queue = malloc(sizeof(Queue));
  if(queue==NULL){
    debug("[ERROR] malloc failed on queue creation\n");
    return NULL;
  }
  queue->size = 0;
  queue->capacity = QUEUE_INITIAL_CAPACITY;
  queue->data = malloc(sizeof(double) * queue->capacity);
  if(queue->data==NULL){
    free(queue);
    debug("[ERROR] malloc failed on queue capacity application\n");
    return NULL;
  }
  return queue;
}

void push(Queue *queue, double element)
{

  if (queue->size == queue->capacity)
  {
    int capacity = queue->capacity * 2;

    double *data2 = realloc(queue->data, sizeof(double) * capacity);
    if(data2==NULL){
      debug("[ERROR] realloc failed on queue push\n");
      return;
    }
    queue->data=data2;
    queue->capacity = capacity;
  }

  int insert_index = queue->size % queue->capacity;
  queue->data[insert_index] = element;
  queue->size++;
}

double back(Queue *queue)
{
  return queue->data[queue->size - 1];
}

void queue_free(Queue *queue)
{

  free(queue->data);
  free(queue);
}

