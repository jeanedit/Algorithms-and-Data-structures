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

/*
int main()
{
	Dequeue*deq = new Dequeue();
	for (int i = 0; i < 5; ++i)
	{
		deq->add_tail(1+i*i*i);
	}
	printf("Head:%i\tTail:%i\n", deq->list->head->val, deq->list->tail->val);
	
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_tail(),deq->size(),deq->list->head->val,deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_tail(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_tail(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_tail(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_tail(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_tail(), deq->size(), deq->list->head, deq->list->tail);


	/*printf("Testing Front op\nHead:%i\tTail:%i\n", deq->list->head->val, deq->list->tail->val);

	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_front(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_front(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_front(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_front(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_front(), deq->size(), deq->list->head->val, deq->list->tail->val);
	printf("Delete:%i\tSize:%i\tHead:%i\tTail:%i\n", deq->remove_front(), deq->size(), deq->list->head, deq->list->tail);

}
*/
