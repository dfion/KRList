#include <stdio.h>
#include <stdlib.h>

struct KRNode {
	char *value;
	struct KRNode *next;
	struct KRNode *prev;
};

struct KRList {
	struct KRNode *head;
	struct KRNode *tail;
	int size;
};

struct KRNode * newNode(char *value, struct KRNode *next, struct KRNode *prev)
{
	struct KRNode *node;

	node = (struct KRNode *) malloc(sizeof(struct KRNode));
	node->value = value;
	node->next = next;
	node->prev = prev;

	return node;
}

struct KRList * newList()
{
	struct KRList *list;

	list = (struct KRList *) malloc(sizeof(struct KRList));

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}

int isEmpty(struct KRList *list)
{
	if (list->head == NULL)
		return 1;
	return 0;
}

struct KRNode * getNode(struct KRList *list, int index)
{
	if (index < 0 || index > list->size - 1)
		return NULL;

	if (index == 0)
		return list->head;

	if (index == list->size - 1)
		return list->tail;

	int i = 0;
	struct KRNode *temp = list->head;

	while (temp->next != NULL) {
		if (i == index)
			return temp;
		temp = temp->next;
		i++;
	}

	return NULL;
}

void insertFront(struct KRList *list, char *value)
{
	if (isEmpty(list)) {
		struct KRNode *node = newNode(value, NULL, NULL);
		list->head = node;
		list->tail = node;
		list->size = 1;
	}

	else {
		struct KRNode *node = newNode(value, list->head, NULL);
		list->head->prev = node;
		list->head = node;
		list->size++;
	}
}

void insertEnd(struct KRList *list, char *value)
{
	if (isEmpty(list)) {
		struct KRNode *node = newNode(value, NULL, NULL);
		list->head = node;
		list->tail = node;
		list->size = 1;
	}

	else {
		struct KRNode *node = newNode(value, NULL, list->tail);
		list->tail->next = node;
		list->tail = node;
		list->size++;
	}
}

void insertNth(struct KRList *list, char *value, int index)
{
	if (index < 0 || index >= list->size)
		return;

	else if (index == 0)
		insertFront(list, value);

	else if (index == list->size)
		insertEnd(list, value);

	else {
		struct KRNode *prev = getNode(list, index - 1);
		struct KRNode *next = getNode(list, index);
		struct KRNode *node = newNode(value, next, prev);
		prev->next = node;
		next->prev = node;
		list->size++;
	}
}

void deleteFront(struct KRList *list)
{
	struct KRNode *temp = list->head;
	list->head = temp->next;
	list->head->prev = NULL;
	list->size--;
	free(temp);
}

void deleteEnd(struct KRList *list)
{
	//TODO
	struct KRNode *temp = list->tail;
	list->tail = temp->prev;
	list->tail->next = NULL;
	list->size--;
	free(temp);
}

void deleteNth(struct KRList *list, int index)
{
	if (index < 0 || index > list->size - 1)
		return;

	else if (index == 0)
		deleteFront(list);

	else if (index == list->size - 1)
		deleteEnd(list);

	else {
		struct KRNode *prev = getNode(list, index - 1);
		struct KRNode *temp = getNode(list, index);
		struct KRNode *next = getNode(list, index + 1);
		prev->next = next;
		next->prev = prev;
		list->size--;
		free(temp);
	}
}

struct KRNode * nth(struct KRList *list, int index)
{
	return getNode(list, index);
}

void toPrint(struct KRList *list)
{
	if (list->size == 0)
		return;

	int i;
	struct KRNode *temp;

	printf("[");
	for (i = 0; i < list->size; i++) {
		if (i != 0)
			printf(" | ");
		temp = getNode(list, i);
		printf("%s", temp->value);
	}
	printf("] size = %d\n", list->size);
}

void freeList(struct KRList *list)
{
	int i = list->size - 1;
	struct KRNode *node;

	for (; 0 <= i; i--) {
		node = getNode(list, i);
		if (node != NULL)
			free(node);
	}

	free(list);
}

int main() {
	
	char *hola = "hola";
	char *mundo = "mundo";
	char *other = "other";

	struct KRList *list = newList();

	insertFront(list, hola);
	insertEnd(list, mundo);
	insertEnd(list, other);

	toPrint(list);
	printf("---\n");

	insertNth(list, hola, 2);
	toPrint(list);
	printf("---\n");

	deleteFront(list);
	toPrint(list);
	printf("---\n");

	deleteNth(list, 1);
	toPrint(list);
	printf("---\n");

	deleteEnd(list);
	toPrint(list);
	printf("---\n");

	struct KRNode *node = getNode(list, 0);
	printf("%s\n", node->value);
	printf("---\n");

	freeList(list);
}




















