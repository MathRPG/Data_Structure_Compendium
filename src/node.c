#include <string.h>
#include <stdlib.h>
#include <node.h>

#include "node.h"

struct Node_s
{
	void* data;
};

void node_delete(Node_t* pS)
{
	free(pS->data);
	free(pS);
}

Node_t* node_new(const void* data, size_t size)
{
	Node_t* new_node = malloc(sizeof(*new_node));
	new_node->data = malloc(size);
	memcpy(new_node->data, data, size);
	return new_node;
}

const void* node_get_data(const Node_t* node)
{
	return node->data;
}


