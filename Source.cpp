#include <stdio.h>

class Node
{
public:
	int value;
	Node* next;

	Node(int valueNode) {
		value = valueNode;
		next = NULL;
	}
};

class LinkedList
{
public:
	Node * head;
	Node* tail;

	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	void add_in_tail(Node* item)
	{
		if (head == NULL) head = item;
		else tail->next = item;
		tail = item;
		tail->next = NULL;
	}

	Node* find(int val)
	{
		Node *node = head;
		while (node != NULL) {
			if (node->value == val) return node;
			node = node->next;
		}
		return NULL;
	}

	bool remove(int val)
	{
		// здесь будет ваш код удаления одного узла по заданному значению
		return true; // если узел был удалён
	}

	void remove_all(int val)
	{
		// здесь будет ваш код удаления всех узлов по заданному значению
	}

	void clear()
	{
		// здесь будет ваш код очистки всего списка
	}

	int size()
	{
		// здесь будет ваш код подсчёта количества элементов в списке
		return 0;
	}

	void insert_after(Node* nodeAfter, Node* nodeToInsert)
	{
		// здесь будет ваш код вставки узла после заданного

		// если nodeAfter = NULL и список пустой, 
		// добавьте новый элемент первым в списке  
	}

};