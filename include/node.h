#ifndef DATA_STRUCTURES_NODE_H
#define DATA_STRUCTURES_NODE_H

typedef struct Node_s Node_t;

void node_delete(Node_t* pS);
Node_t* node_new(const void* data, size_t size);
const void* node_get_data(const Node_t* node);

#endif //DATA_STRUCTURES_NODE_H
