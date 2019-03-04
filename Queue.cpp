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
	~Node()
	{
		delete next;
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

	~List()
	{
		delete head;
		delete tail;
	}

};


class Queue
{
public:
	List*list;
	int queuesize;
	Queue()
	{
		list = new List();
		queuesize = 0;
	}

	void enqueue(int item)
	{
		Node*node = new Node(item);
		if (list->head == NULL)
		{
			list->head = node;
		}
		else
		{
			list->tail->next = node;
		}
		list->tail = node;
		list->tail->next = NULL;
		++queuesize;
	}

	int dequeue()
	{
		Node*node = list->head;
		if (list->head == NULL) return -1;
		list->head = node->next;
		return node->val;
	}

	int size()
	{
		return queuesize;
	}
	void rotate(int N)
	{
		for (int i = 0; i < N; ++i)
		{
			enqueue(dequeue());
		}
	}
};


int main()
{
	Queue*queue = new Queue();
	printf("%i\n", queue->dequeue());
	int i = 0;
	queue->enqueue(102);
	printf("%i\n", queue->list->head->val);
	while (i < 10)
	{
		queue->enqueue(i);
		++i;
	}
	printf("%i\n", queue->list->tail->val);
	printf("%i\n", queue->dequeue());
	printf("%i\n", queue->dequeue());

}