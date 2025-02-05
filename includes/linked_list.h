#pragma once

#include "nodes.h"

typedef struct LinkedList {
	node_t* head;
	int size;
} LinkedList, ll_t;

LinkedList* init_list();

void push_head(LinkedList* list, int val);
void push_tail(LinkedList* list, int val);
void push_index(LinkedList* list, int val, int target_index);

void pop_head(LinkedList* list);
void pop_tail(LinkedList* list);
void pop_index(LinkedList* list, int target_index);

void print_list(LinkedList* list);
void free_list(LinkedList** list);