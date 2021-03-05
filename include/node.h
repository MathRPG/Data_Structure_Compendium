#ifndef DATA_STRUCTURES_NODE_H
#define DATA_STRUCTURES_NODE_H

#include <stdlib.h>

typedef struct Node_s Node_t;

Node_t* node_new(const void* data, size_t data_size);
void node_delete(Node_t*);

const void* node_data(const Node_t*);
Node_t** node_next(Node_t*);

#endif //DATA_STRUCTURES_NODE_H
