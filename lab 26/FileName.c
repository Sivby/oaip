#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* first = NULL;

void printList() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		printf("(%d) -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->next = first;
	newNode->data = value;

	first = newNode;
}

int deleteFromHead() {
	int value = first->data;
	struct Node* delNode = first;
	first = first->next;
	free(delNode);
	return value;
}

int contains(int value) {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data == value) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

void clearList() {
	while (first != NULL) {
		struct Node* delNode = first;
		first = first->next;
		free(delNode);
	}
}

int sum() {
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL) {
		s += ptr->data;
		ptr = ptr->next;
	}
	return s;
}

int everCount() {
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL) {
		if (ptr->data%2==0)
			s++;
		ptr = ptr->next;
	}
	return s;
}

void oddsX10() {
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL) {
		if (ptr->data % 2 != 0)
			ptr->data *= 10;
		ptr = ptr->next;
	}
}

void elementIx100(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index == i) {
			ptr->data = ptr->data * 100;
			return;
		}
		ptr = ptr->next;
		index++;
	}
}

void elementLeftIx10(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index == i) return;
		if (index < i) {
			ptr->data = ptr->data * 10;
		}
		ptr = ptr->next;
		index++;
	}
}

void elementRightIx10(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index > i) {
			ptr->data = ptr->data * 10;
		}
		ptr = ptr->next;
		index++;
	}
}

void main() {

	//Задача 1
	/*printList();

	struct Node node1 = { 1, NULL };
	struct Node node2 = { 2, NULL };
	struct Node node3 = { 3, NULL };
	printList();
	first = &node1;
	printList();

	node1.next = &node2;
	printList();

	node2.next = &node3;
	printList();*/



	//Задача 2
	/*printList();

	addToHead(10);
	printList();

	addToHead(20);
	printList();

	addToHead(30);
	printList();

	int x1 = deleteFromHead();
	printf("x1 = %d\n", x1);
	printList();

	int x2 = deleteFromHead();
	printf("x2 = %d\n", x2);
	printList();*/


	//Задача 3
	/*printList();

	addToHead(400);
	addToHead(300);
	addToHead(200);
	addToHead(100);
	printList();

	printf("contains(100) = %d\n", contains(100));
	printf("contains(150) = %d\n", contains(150));
	printf("contains(200) = %d\n", contains(200));

	clearList();
	printList();

	printf("contains(100) = %d\n", contains(100));
	printf("contains(150) = %d\n", contains(150));
	printf("contains(200) = %d\n", contains(200));
	{
		int x;
		scanf("%d", &x);
	}*/


	//Задача 4
	/*printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(9);
	printList();

	printf("sum = %d\n", sum());

	clearList();
	printList();
	printf("sum = %d\n", sum());
	{
		int x;
		scanf("%d", &x);
	}*/


	//Задача 5
	/*printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(8);
	printList();

	printf("even numbers = %d\n", everCount());

	clearList();
	printList();
	printf("even numbers = %d\n", everCount());
	{
		int x;
		scanf("%d", &x);
	}*/

	
	//Задача 6
	/*printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(8);
	printList();

	oddsX10();
	printList();

	clearList();
	printList();

	{
		int x;
		scanf("%d", &x);
	}*/


	//Задача 7
	/*printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(8);
	printList();

	elementIx100(0);
	printList();

	elementIx100(2);
	printList();

	elementIx100(0);
	printList();

	{
		int x;
		scanf("%d", &x);
	}*/


	//Задача 8
	/*printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(8);
	printList();

	elementLeftIx10(1);
	printList();

	elementLeftIx10(2);
	printList();

	elementLeftIx10(4);
	printList();

	{
		int x;
		scanf("%d", &x);
	}*/


	//Задача 9
	printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(8);
	printList();

	elementRightIx10(1);
	printList();

	elementRightIx10(2);
	printList();

	elementRightIx10(4);
	printList();

	{
		int x;
		scanf("%d", &x);
	}


}








