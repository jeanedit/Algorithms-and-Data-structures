#include <stdio.h>
class Node
{
public:
	int value;
	Node* next;
	Node* prev;

	Node(int valueNode) {
		value = valueNode;
		next = NULL;
		prev = NULL;
	}
};

class LinkedList2
{
public:
	Node * head;
	Node* tail;

	LinkedList2()
	{
		head = NULL;
		tail = NULL;
	}

	void add_in_tail(Node* item)
	{
		if (head == NULL) {
			head = item;
			head->next = NULL;
			head->prev = NULL;
		}
		else {
			tail->next = item;
			item->prev = tail;
		}
		tail = item;
	}

	Node* find(int val)
	{
		Node*node = head;
		while (node != NULL)
		{
			if (node->value == val) return node;
			else
			{
				node = node->next;
				//node->prev = node;
			}
		}
		return NULL;
	}

	bool remove(int val)
	{
		Node*node = head;
		if (node == NULL) //if list is empty
		{
			printf("List is empty\n");
			return false;
		}
		else if (head->value == val) // if head value is equal to the given
		{
			if (head == tail)
			{
				head = NULL;
				tail = NULL;
				return true;
			}
			else
				head = node->next;

			return true;
		}
		else if (node->next == NULL) //if list consist of one node
		{
			return false;
		}
		else if (tail->value == val) // if list tail is equil to the given value
		{
			node = tail;
			tail = node->prev;
		}
		else
		{
			while (node != NULL)
			{
				if (node->value == val)
				{
					node->prev->next = node->next;
					node->next->prev = node->prev;
					return true;
				}
				else
					node = node->next;
			}

		}
		return false; // если узел был удалён
	}

	void remove_all(int val)
	{
		Node*node = head;
		if (node == NULL)
		{
			return;
		}
		while (node != NULL)
		{
			if (head->value == val)
			{
				head = node->next;
			}
			if (tail->value == val)
			{
				tail = tail->prev;
			}
			if (node->value == val)
			{
				if(node->prev) node->prev->next = node->next;
				if(node->next) node->next->prev = node->prev;
				node = node->next;
			}
			else
				node = node->next;
		}
	}

	void clear()
	{
		Node*node = head;
		if (node == NULL)
		{
			printf("List is empty\n");
			return;
		}
		while (node != NULL)
		{
			head = node->next;
			delete node;
			node=head;
		}
		tail = NULL;
	}

	int size()
	{
		Node*node = head;
		int i = 0;
		if (node == NULL)
		{
			return 0;
		}
		else
		{
			while (node != NULL)
			{
				++i;
				node = node->next;
			}
		}
		return i;
	}

	void insert_after(Node* nodeAfter, Node* nodeToInsert)
	{
		Node*node = head;
		if (nodeAfter == NULL) // if nodeAfter is NULL, add new element first on the list
		{
			if (head == NULL)
			{
				head = nodeToInsert;
				tail = nodeToInsert;
				return;
			}
			else
			{
				head->prev = nodeToInsert;
				nodeToInsert->next = head;
				head = nodeToInsert;
				return;
			}
		}
		while (node != nodeAfter)
		{
			node = node->next;
		}
		if (nodeAfter == tail)//adding new element after tail
		{
			tail->next = nodeToInsert;
			nodeToInsert->prev = tail;
			tail = nodeToInsert;
		}
		else //adding new element inside the list
		{
			nodeToInsert->next = node->next;
			node->next = nodeToInsert;
			nodeToInsert->prev = node;
			node->next->next->prev = nodeToInsert;
		}
	}

	LinkedList2*find_all(int val)
	{
		LinkedList2*l = new LinkedList2();
		Node*node = head;
		if (node == NULL)
		{
			printf("List is empty\n");
			return NULL;
		}
		while (node != NULL)
		{
			Node*n = new Node(val);
			if (node->value==val)
			{
				l->add_in_tail(n);
				node = node->next;
			}
			else node = node->next;
		}
		return l;
	}
};

void print(LinkedList2*list)
{
	Node*node =list-> head;
	while (node != NULL)
	{
		printf("%i\n", node->value);
		node = node->next;
	}
}

//**************************************************************************************
void find_test()
{
	LinkedList2*empty_list = new LinkedList2();
	LinkedList2*one_elem_list = new LinkedList2();
	one_elem_list->add_in_tail(new Node(1));
	LinkedList2*test_list = new LinkedList2();
	for (int i = 1; i <= 10; ++i)
	{
		test_list->add_in_tail(new Node(i));
	}
	Node*find = test_list->find(11);
	Node*find1 = one_elem_list->find(2);
	Node*find2 = empty_list->find(1);
	printf("Head: %i\t Tail: %i\t Prev: %i\n", one_elem_list->head->value, one_elem_list->tail->value, find1);
	print(test_list);
	printf("Found: %i\n", find);
}

//************************************************************************************************
void remove_test()
{
	LinkedList2*empty_list = new LinkedList2();
	LinkedList2*one_elem_list = new LinkedList2();
	one_elem_list->add_in_tail(new Node(1));
	LinkedList2*test_list = new LinkedList2();
	for (int i = 1; i <= 10; ++i)
	{
		test_list->add_in_tail(new Node(i));
	}
	if (empty_list->remove(10))
	{
		print(test_list);
	}
	printf("Head: %i\tTail: %i\nPrev: %i\n", test_list->head->value, test_list->tail->value, test_list->tail->prev->value);
}
//*****************************************************************************************************
void remove_all_test()
{
	LinkedList2*empty_list = new LinkedList2();
	LinkedList2*one_elem_list = new LinkedList2();
	one_elem_list->add_in_tail(new Node(1));
	LinkedList2*test_list = new LinkedList2();

	test_list->add_in_tail(new Node(2));
	test_list->add_in_tail(new Node(2));
	for (int i = 1; i <= 10; ++i)
	{
		test_list->add_in_tail(new Node(i));
		test_list->add_in_tail(new Node(2));
	}
	test_list->add_in_tail(new Node(11));
	test_list->add_in_tail(new Node(2));
	test_list->add_in_tail(new Node(2));
	print(one_elem_list);
	printf("**********\n");
	test_list->remove_all(2);
	//print(one_elem_list);
	printf("%i\n", test_list->tail->value);
}
//********************************************************************
void clear_test()
{
	LinkedList2*empty_list = new LinkedList2();
	LinkedList2*one_elem_list = new LinkedList2();
	one_elem_list->add_in_tail(new Node(1));
	LinkedList2*test_list = new LinkedList2();

	test_list->add_in_tail(new Node(2));
	test_list->add_in_tail(new Node(2));
	for (int i = 1; i <= 10; ++i)
	{
		test_list->add_in_tail(new Node(i));
		test_list->add_in_tail(new Node(2));
	}
	test_list->add_in_tail(new Node(11));
	test_list->add_in_tail(new Node(2));
	test_list->add_in_tail(new Node(2));

	empty_list->clear();
	printf("%i\n", one_elem_list->tail->prev);
	//print(test_list);
	printf("%i\n", test_list->head->next->value);
}
//***********************************************************************************
void size_test()
{
	LinkedList2*empty_list = new LinkedList2();
	LinkedList2*one_elem_list = new LinkedList2();
	one_elem_list->add_in_tail(new Node(1));
	LinkedList2*test_list = new LinkedList2();

	test_list->add_in_tail(new Node(2));
	test_list->add_in_tail(new Node(2));
	for (int i = 1; i <= 10; ++i)
	{
		test_list->add_in_tail(new Node(i));
		//test_list->add_in_tail(new Node(2));
	}
	test_list->add_in_tail(new Node(11));
	test_list->add_in_tail(new Node(2));
	test_list->add_in_tail(new Node(2));

	int c = empty_list->size();
	print(test_list);
	printf("%i\n", c);
}
//*****************************************************************
void insert_test()
{
	LinkedList2*empty_list = new LinkedList2();
	LinkedList2*one_elem_list = new LinkedList2();
	one_elem_list->add_in_tail(new Node(1));
	LinkedList2*test_list = new LinkedList2();

	test_list->add_in_tail(new Node(2));
	test_list->add_in_tail(new Node(2));
	for (int i = 1; i <= 10; ++i)
	{
		test_list->add_in_tail(new Node(i));
		//test_list->add_in_tail(new Node(2));
	}
	empty_list->insert_after(empty_list->head, new Node(47));
	print(empty_list);
	printf("%i\n%i\n", empty_list->head->value, empty_list->tail->value);
	printf("*****************************\n");
	one_elem_list->insert_after(one_elem_list->head->prev, new Node(47));
	print(one_elem_list);
	printf("%i\n%i\n", one_elem_list->head->next->value, one_elem_list->tail->prev->value);
	printf("*****************************\n");
	//*******
	test_list->insert_after(test_list->tail->next, new Node(13));
	print(test_list);
	printf("%i\n%i\n", test_list->head->next->value, test_list->tail->value);
}
//***************************************************************************
void find_all_test()
{
	LinkedList2*empty_list = new LinkedList2();
	LinkedList2*one_elem_list = new LinkedList2();
	one_elem_list->add_in_tail(new Node(1));
	LinkedList2*test_list = new LinkedList2();

	test_list->add_in_tail(new Node(2));
	test_list->add_in_tail(new Node(2));
	for (int i = 1; i <= 10; ++i)
	{
		test_list->add_in_tail(new Node(i));
		//test_list->add_in_tail(new Node(2));
	}
	//LinkedList2*found = test_list->find_all(2);
	print(test_list);
	printf("******************************\n");
	printf("Head next: %i\n", test_list->head->next->next->next->next->value);
	LinkedList2*k = test_list->find_all(10);
	LinkedList2*s = one_elem_list->find_all(2);
	LinkedList2*j = empty_list->find_all(2);
	print(k);
	print(s);
	//print(j);
}

/*int main()
{
	//remove_all_test();
	
}*/