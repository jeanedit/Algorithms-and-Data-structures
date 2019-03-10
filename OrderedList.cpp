#include <stdio.h>
#include <typeinfo.h>


template <class T>
class Node
{
public:
	T value;
	Node* next;
	Node* prev;

	Node(T valueNode)
	{
		value = valueNode;
		next = NULL;
		prev = NULL;
	}
};

template <class T>
class OrderedList
{
private:
	bool _ascending;

public:
	Node<T>* head;
	Node<T>* tail;

	OrderedList(bool asc)
	{
		head = NULL;
		tail = NULL;
		_ascending = asc;
	}

	int compare(T v1, T v2)
	{
			if (v1 < v2)  return -1;
			if (v1 == v2) return  0;
			if (v1 > v2)  return  1;
	}

	void add(T value)
	{
		Node<T>*node = new Node<T>(value);

		if (head == NULL)
		{
			head = node;
			tail = node;
			return;
		}

		Node<T>*curr = head;

			while (curr != NULL)
			{
				int comp = compare(node->value, curr->value);
	
				if (_ascending&&(comp == 0 || comp == -1)
					|| !_ascending&&(comp == 0 || comp == 1))
				{
					if (curr == head)
					{
						node->next = curr;
						curr->prev = node;
						head = node;
						return;
					}
					else
					{
						node->prev = curr->prev;
						node->next = curr;
						curr->prev->next = node;
						curr->prev = node;
						return;
					}
				}
				curr = curr->next;
			}
			node->prev = tail;
			tail->next = node;
			tail = node;
			tail->next = NULL;
			return;
	}

	Node<T>* find(T val)
	{
		Node<T>*node = head;
		while (node != NULL)
		{
			if (_ascending)
			{
				if (compare(node->value, val) == 1)
					return NULL;

				if (node->value == val) return node;

			}
			else if (!_ascending)
			{
				if (compare(node->value, val) == -1)
					return NULL;

				if (node->value == val) return node;

			}
			else
			{
				return NULL;
			}
			node = node->next;
		}
		return NULL; 
	}

	void del(T val)
	{
		Node<T>*node = head;

		if (node == NULL) return;

		if (head->value == val && tail->value == val)
		{
			head = NULL;
			tail = NULL;
			return;
		}
		if (head->value == val)
		{
			head = node->next;
			head->prev=NULL;
			return;
		}
		if (tail->value == val)
		{
			tail = tail->prev;
			tail->next = NULL;
			return;
		}
		while (node->value != val)
		{
			node = node->next;
			if (node == NULL) return;
		}
		if (node->prev)
			node->prev->next = node->next;
		if (node->next)
			node->next->prev = node->prev;
		return;
	}

	void clear(bool asc)
	{
		_ascending = asc;
		Node<T>*node = head;
		while (node != NULL)
		{
			head = node->next;
			delete node;
			node = head;
		}
		head = NULL;
		tail = NULL;
	}

	int size()
	{
		Node<T>*node = head;
		int count = 0;
		
		while (node != NULL)
		{
			count++;
			node = node->next;
		}
		return count;
	}


	T* get_all()
	{
		
		Node<T>*node = head;
		T*list = new T[size()];

		for (int i = 0; node != NULL; ++i)
		{
			list[i] = node->value;
			node = node->next;
		}
		return list;
	}

};
