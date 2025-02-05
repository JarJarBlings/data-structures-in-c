# pragma once

#include <stdio.h>
#include <stdlib.h>

// Macro for checking memory allocation
#define CHECK_ALLOC(ptr) \
	if (!(ptr)) { \
		fprintf(stderr, "Memory allocation failed in %s at line %d\n", __FILE__, __LINE__); \
		perror("Error"); \
		exit(EXIT_FAILURE); \
	}

// Defines a singly-linked node
typedef struct OneWayNode {
	int data;
	struct OneWayNode* next;
} OneWayNode, node_t; // Use 'OneWayNode' for clarity or 'node_t' for convenience

// Defines a doubly-linked list node
typedef struct TwoWayNode {
	int data;
	struct TwoWayNode* next;
	struct TwoWayNode* prev;
} TwoWayNode, twnode_t; // Use 'TwoWayNode' for clarity or 'twnode_t' for convenience

// Function for initializing a singly-linked node
static inline node_t* _create_node(node_t* next_node, int val) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	CHECK_ALLOC(node);
	node->data = val;
	node->next = next_node;
	return node;
}

// Function for initializing a doubly-linked node
static inline twnode_t* _create_twnode(twnode_t* prev_node, twnode_t* next_node, int val) {
	twnode_t* twnode = (twnode_t*)malloc(sizeof(twnode_t));
	CHECK_ALLOC(twnode);
	twnode->data = val;
	twnode->next = next_node;
	twnode->prev = prev_node;
	return twnode;
}