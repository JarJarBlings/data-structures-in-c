#include "unity.h"
#include "linked_list.h"

LinkedList* list;

void setUp(void) {
	list = init_list();
}
void tearDown(void) {
	free_list(&list);
}

void test_init_list(void) {
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_EQUAL_INT(0, list->size);
}

void test_push_head(void) {
	push_head(list, 10);
	TEST_ASSERT_NOT_NULL(list->head);
	TEST_ASSERT_EQUAL_INT(10, list->head->data);
	TEST_ASSERT_EQUAL_INT(1, list->size);

	push_head(list, 20);
	TEST_ASSERT_EQUAL_INT(20, list->head->data);
	TEST_ASSERT_EQUAL_INT(2, list->size);
}

void test_push_tail(void) {
	push_tail(list, 30);
	TEST_ASSERT_EQUAL_INT(30, list->head->data);
	TEST_ASSERT_EQUAL_INT(1, list->size);

	push_tail(list, 40);
	TEST_ASSERT_EQUAL_INT(40, list->head->next->data);
	TEST_ASSERT_EQUAL_INT(2, list->size);
}

void test_push_index(void) {
	push_tail(list, 10);
	push_tail(list, 20);
	push_index(list, 15, 1);

	TEST_ASSERT_EQUAL_INT(3, list->size);
	TEST_ASSERT_EQUAL_INT(10, list->head->data);
	TEST_ASSERT_EQUAL_INT(15, list->head->next->data);
	TEST_ASSERT_EQUAL_INT(20, list->head->next->next->data);
}

void test_pop_head(void) {
	push_head(list, 50);
	push_head(list, 60);
	pop_head(list);

	TEST_ASSERT_EQUAL_INT(50, list->head->data);
	TEST_ASSERT_EQUAL_INT(1, list->size);
}

void test_pop_tail(void) {
	push_head(list, 70);
	push_tail(list, 80);
	pop_tail(list);

	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_EQUAL_INT(70, list->head->data);
	TEST_ASSERT_EQUAL_INT(1, list->size);
}

void test_pop_index(void) {
	push_tail(list, 100);
	push_tail(list, 200);
	push_tail(list, 300);
	pop_index(list, 1);

	TEST_ASSERT_EQUAL_INT(2, list->size);
	TEST_ASSERT_EQUAL_INT(100, list->head->data);
	TEST_ASSERT_EQUAL_INT(300, list->head->next->data);
}

void test_print_list(void) {
	push_tail(list, 5);
	push_tail(list, 15);
	push_tail(list, 25);
	print_list(list);
}

void test_free_list(void) {
	push_tail(list, 5);
	push_tail(list, 10);
	free_list(&list);

	TEST_ASSERT_NULL(list);
}

int main(void) {
	UNITY_BEGIN();

	RUN_TEST(test_init_list);
	RUN_TEST(test_push_head);
	RUN_TEST(test_push_tail);
	RUN_TEST(test_push_index);
	RUN_TEST(test_pop_head);
	RUN_TEST(test_pop_tail);
	RUN_TEST(test_pop_index);
	RUN_TEST(test_print_list);
	RUN_TEST(test_free_list);

	return UNITY_END();
}