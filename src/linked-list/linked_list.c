#include "nodes.h"
#include "linked_list.h"
#include <stdio.h>

// Initializes empty linked list
LinkedList* init_list() {
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	CHECK_ALLOC(list);
	list->head = NULL;
	list->size = 0;
	return list;
}

// Insert new head node
void push_head(LinkedList* list, int val) {
	node_t* new_node = _create_node(list->head, val);
	list->head = new_node;
	list->size++;
}

// Insert new tail node
void push_tail(LinkedList* list, int val) {
	// Special case: empty list
	node_t* new_node = _create_node(NULL, val);
	if (!list->head) {
		list->head = new_node;
		list->size++;
		return;
	}
	// Fetching last node in list
	node_t* curr_node = list->head;
	for (int i = 1; i < list->size; i++) {
		curr_node = curr_node->next;
	}
	// Attach new tail node
	curr_node->next = new_node;
	list->size++;
}

// Insert a node at a given position
void push_index(LinkedList* list, int val, int target_index) {
	// Checking bounds
	if (target_index < 0 || target_index > list->size) return;
	// Creating new node
	node_t* new_node = _create_node(NULL, val);
	// Special case: inserting at head
	if (target_index == 0) {
		new_node->next = list->head;
		list->head = new_node;
		list->size++;
		return;
	}
	// Fetching node before target index
	node_t* curr_node = list->head;
	for (int i = 1; i < target_index; i++) {
		curr_node = curr_node->next;
	}
	//  Inserting new node at target index
	new_node->next = curr_node->next;
	curr_node->next = new_node;
	list->size++;
}

// Delete the head node
void pop_head(LinkedList* list) {
	// Checking for empty list
	if (!list || !list->head) return;
	// Popping head
	node_t* temp = list->head;
	list->head = list->head->next;
	free(temp);
	list->size--;
}

// Delete the tail node
void pop_tail(LinkedList* list) {
	// Checking for empty list
	if (!list || !list->head) return;
	// Special case: only one node in list
	if (list->size == 1) {
		free(list->head);
		list->head = NULL;
		list->size = 0;
		return;
	}
	// Fetching penultimate node in list
	node_t* curr_node = list->head;
	for (int i = 1; i < list->size - 1; i++) {
		curr_node = curr_node->next;
	}
	// Remove tail node
	free(curr_node->next);
	curr_node->next = NULL;
	list->size--;
}

// Delete a node at a given position
void pop_index(LinkedList* list, int target_index) {
	// Check bounds and if list is empty
	if (!list || !list->head || target_index < 0 || target_index >= list->size) return;
	// Special case: removing head
	if (target_index == 0) {
		pop_head(list);
		return;
	}
	// Fetching node before target node
	node_t* curr_node = list->head;
	for (int i = 1; i < target_index; i++) {
		curr_node = curr_node->next;
	}
	// Remove target node
	node_t* temp = curr_node->next;
	curr_node->next = temp->next;
	free(temp);
	list->size--;
}

// Print the linked list
void print_list(LinkedList* list) {
	// Special cases: no list existing & empty list
	if (!list) {
		printf("This list does not exist!\n");
		return;
	}
	if (!list->head) {
		printf("This list is empty.\n");
		return;
	}
	// Printing each nodes data
	node_t* curr_node = list->head;
	for (int i = 0; i < list->size; i++) {
		printf("%d -> ", curr_node->data);
		curr_node = curr_node->next;
	}
	printf("NULL\n");
}

// Free the linked list
void free_list(LinkedList** list) {
	// Checking that linked list exists
	if (!list || !(*list)) return;
	// Freeing all nodes
	node_t* curr_node = (*list)->head;
	for (int i = 0; i < (*list)->size; i++) {
		node_t* temp = curr_node;
		curr_node = curr_node->next;
		free(temp);
	}
	// Freeing linked list structure
	free(*list);
	*list = NULL; // prevent dangling pointer
}