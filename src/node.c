#include <string.h>
#include <stdlib.h>

#include "node.h"

struct Node_s
{
	void* data;
	Node_t* next;
};

Node_t* node_new(const void* data, const size_t data_size)
{
	Node_t* new_node = malloc(sizeof(*new_node));

	*new_node = (struct Node_s){
			.data = malloc(data_size),
			.next = NULL,
	};

	memcpy(new_node->data, data, data_size);
	return new_node;
}

void node_delete(Node_t* const node)
{
	free(node->data);
	free(node);
}

const void* node_data(const Node_t* const node)
{
	return node->data;
}

Node_t** node_next(Node_t* const node)
{
	return &node->next;
}


