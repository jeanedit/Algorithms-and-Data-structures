#include<stdio.h>

class Node
{
public:
	int val;
	Node*next;
	Node(int value)
	{
		val = value;
		next = NULL;
	}

};

class List
{
public:
	Node*head;
	Node*tail;
	List()
	{
		head = NULL;
		tail = NULL;
	}

};


class Deque
{
public:
	List * list;
	int deqsize;
	Deque()
	{
		list = new List();
		deqsize = 0;
	}

	void add_front(int item)
	{
		Node*node = new Node(item);
		if (list->head == NULL)
		{
			list->head = node;
			list->tail = node;
		}
		node->next = list->head;
		list->head = node;
		list->tail->next = NULL;
		deqsize++;
	}

	void add_tail(int item)
	{
		Node*node = new Node(item);
		if (list->tail == NULL)
		{
			list->head = node;
			list->tail = node;
		}
		list->tail->next = node;
		list->tail = node;
		deqsize++;
	}

	int remove_front()
	{
		Node*node = new Node(0);
		if (list->head == NULL) return -1;
		if (list->head == list->tail)
		{
			node = list->head;
			list->head = NULL;
			list->tail = NULL;
			deqsize--;
			return node->val;
		}
		node = list->head;
		list->head = list->head->next;
		deqsize--;
		return node->val;
	}

	int remove_tail()
	{
		Node*node = new Node(0);
		Node*node1 = new Node(0);
		if (list->tail == NULL) return -1;
		node = list->head;
		if (list->head == list->tail)
		{
			node = list->tail;
			list->head = NULL;
			list->tail = NULL;
			deqsize--;
			return node->val;
		}
		while (node->next != list->tail)
		{
			node = node->next;
		}
		node1 = list->tail;
		list->tail = node;
		deqsize--;
		return node1->val;
	}

	int size()
	{
		return deqsize;
	}
};
