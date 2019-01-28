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
		// ����� ����� ��� ��� �������� ������ ���� �� ��������� ��������
		return true; // ���� ���� ��� �����
	}

	void remove_all(int val)
	{
		// ����� ����� ��� ��� �������� ���� ����� �� ��������� ��������
	}

	void clear()
	{
		// ����� ����� ��� ��� ������� ����� ������
	}

	int size()
	{
		// ����� ����� ��� ��� �������� ���������� ��������� � ������
		return 0;
	}

	void insert_after(Node* nodeAfter, Node* nodeToInsert)
	{
		// ����� ����� ��� ��� ������� ���� ����� ���������

		// ���� nodeAfter = NULL � ������ ������, 
		// �������� ����� ������� ������ � ������  
	}

};