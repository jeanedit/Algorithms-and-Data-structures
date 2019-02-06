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
	Node* head;
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

	bool remove(int val) // deleting node by value(my code)
	{
		Node*current = head;
		if (current == NULL) return false;
		else if (current->value== val)
		{
			head =current->next;
			return true;
		}
		else {
			while (current->next->value != val)
			{
				current = current->next;
				if (current->next == NULL) return false;
			}
			if (current->next = tail)
			{
				tail = current;
				tail->next = NULL;
				return true;
			}
			current->next = current->next->next;
			return true;
		}              // åñëè óçåë áûë óäàë¸í
	}

	void remove_all(int val)
	{
		Node *node = head;
		if (node == NULL) return;
		while (node->next != NULL) {
			if (node->value == val)
			{
				head = node->next;
				node = node->next;
			}
			else if (node->next->value == val) {
				node->next = node->next->next;
			}
			else {
				node = node->next;
			}
		}
		tail = node;
		tail->next = NULL;
		return;
	}

	void clear()
	{
		Node*current = head;
		if (current == NULL) return;
		while (current!= NULL)
		{
			head = current->next;
			delete current;
			current = head;
		}
	}

	int size()
	{
		Node*node = head;
		int i = 0;
		if (node == NULL) return i;
		while (node != NULL)
		{
			node = node->next;
			++i;
		}
		return i;
	}

	void insert_after(Node* nodeAfter, Node* nodeToInsert)
	{
		Node*node = head;
		if (nodeAfter == NULL)
		{
			head = nodeToInsert;
			tail = nodeToInsert;
			return;
		}
		else if (nodeToInsert == NULL)
		{
			printf("Node to Insert is NULL\n");
			return;
		}
		else if (nodeAfter == tail)
		{
			tail->next= nodeToInsert;
			tail = nodeToInsert;
			tail->next = NULL;
		}
		else {
			while (node != NULL)
			{
				if (node->value == nodeAfter->value)
				{
					nodeToInsert->next = node->next;
					node->next = nodeToInsert;
					node = node->next;
				}
				else
					node = node->next;

			}
		}
	}

	LinkedList*find_all(int value)
	{
		LinkedList*find_all = new LinkedList();
		Node*curr = head;
		if (curr == NULL)
		{
			printf("List is empty\n");
			return find_all;
		}
		else {
			while (curr != NULL)
			{
				if (curr->value ==value)
				{
					find_all->add_in_tail(curr);
					curr = curr->next;
				}
				else
					curr = curr->next;
			}
			if (find_all->size() == 0)
			{
				printf("List doesn't have nodes with the given value\n");
				return find_all;
			}
			else
			{
				return find_all;
			}
		}
	}
};



void print(LinkedList*list)
{
	Node*current = list->head;
	while (current != NULL)
	{
		printf("%i\n", current->value);
		current = current->next;
	}
}


// TEST FOR REMOVE OPERATION FUNC
void check_remove_op()
{
	LinkedList*empty_list = new LinkedList();
	LinkedList*one_elem_list = new LinkedList();
	one_elem_list->add_in_tail(new Node(1));
	LinkedList* s_list = new LinkedList();
	//adding elements in the list
	Node*n1 = new Node(24);
	Node*n2 = new Node(55);
	
	s_list->add_in_tail(n1);
	s_list->add_in_tail(n2);
	s_list->add_in_tail(new Node(128));
	s_list->add_in_tail(new Node(256));
	for (int i = 0; i < 10; ++i)
	{
		s_list->add_in_tail(new Node(i*i));
	}
	

	//removing operation
	if (s_list->remove(81)) // if true print the list without this node
	{
		print(s_list);
		printf("%i\n", s_list->tail->value);
	}
}

//TEST FOR REMOVE_ALL OPERATION FUNC
void check_remove_all_op()
{
	LinkedList*empty_list = new LinkedList();
	LinkedList*one_elem_list = new LinkedList();
	one_elem_list->add_in_tail(new Node(1));
	LinkedList* test_list = new LinkedList();
	test_list->add_in_tail(new Node(4));
	test_list->add_in_tail(new Node(1));
	test_list->add_in_tail(new Node(1));
	test_list->add_in_tail(new Node(2));
	test_list->add_in_tail(new Node(2));
	test_list->add_in_tail(new Node(1));
	test_list->add_in_tail(new Node(1));
	test_list->add_in_tail(new Node(4));
	test_list->add_in_tail(new Node(2));
	test_list->add_in_tail(new Node(4));
	test_list->add_in_tail(new Node(4));
	test_list->add_in_tail(new Node(4));


	//one_elem_list->remove_all(2);
	//empty_list->remove_all(2);
	test_list->remove_all(4);
	print(test_list);
	printf("Head: " "%i\t" "Tail: " "%i\n", test_list->tail->value,test_list->head->value);
}

//TEST FOR CLEAR OPERATION FUNC
void check_clear_func()
{
	LinkedList*empty_list = new LinkedList();
	LinkedList*one_elem_list = new LinkedList();
	one_elem_list->add_in_tail(new Node(1));
	LinkedList* test_list = new LinkedList();
	test_list->add_in_tail(new Node(1));
	test_list->add_in_tail(new Node(1));
	test_list->add_in_tail(new Node(2));
	test_list->add_in_tail(new Node(2));
	test_list->add_in_tail(new Node(1));
	test_list->add_in_tail(new Node(1));
	test_list->add_in_tail(new Node(2));
	test_list->add_in_tail(new Node(4));

	empty_list->clear();
	one_elem_list->clear();
	test_list->clear();
}

//TEST FOR SIZE OPERATION FUNC
void check_size_func()
{
	LinkedList*one_elem_list = new LinkedList();
	one_elem_list->add_in_tail(new Node(1));
	LinkedList* test_list = new LinkedList();
	test_list->add_in_tail(new Node(1));
	test_list->add_in_tail(new Node(1));
	test_list->add_in_tail(new Node(2));
	test_list->add_in_tail(new Node(2));
	test_list->add_in_tail(new Node(1));
	test_list->add_in_tail(new Node(1));
	test_list->add_in_tail(new Node(2));
	test_list->add_in_tail(new Node(4));

	LinkedList*empty_list = new LinkedList();

	int i=test_list->size();
	int c = empty_list->size();
	printf("%i\n", c);
}

//TEST FOR INSERT OPERATION FUNC
void check_insert_op()
{
	LinkedList*empty_list = new LinkedList();
	LinkedList*one_elem_list = new LinkedList();
	one_elem_list->add_in_tail(new Node(1));
	LinkedList*test_list = new LinkedList();
	for (int i = 1; i <= 10; ++i)
	{
		test_list->add_in_tail(new Node(i*i));
	}
	Node*n1 = new Node(5);
	test_list->insert_after(test_list->tail, n1);
	print(test_list);
	printf("%i\n", test_list->tail->value);
}

// Func which sum up the elements of two linked lists
LinkedList*sum_of_elem(LinkedList*first, LinkedList*second)
{
	LinkedList*sum = new LinkedList();
	if (first->size() == 0 || second->size() == 0)
	{
		printf("List is empty\n");
		return sum;
	}
	else if (first->size() == second->size())
	{
		Node*fir = first->head;
		Node*sec = second->head;
		while (fir != NULL && sec != NULL)
		{
			Node*s = new Node(0);
			s->value = fir->value + sec->value;
			sum->add_in_tail(s);
			fir=fir->next;
			sec = sec->next;
		}
		delete fir;
		delete sec;
		return sum;
	}
	else
	{
		printf("First and second sizes doesn't match\n");
		return sum;
	}
}


void check_sum()
{
	LinkedList*empty = new LinkedList();
	LinkedList*one_el = new LinkedList();
	one_el->add_in_tail(new Node(1));
	LinkedList*first = new LinkedList();
	LinkedList*second = new LinkedList();
	for (int i = 1; i <= 10; ++i)
	{
		first->add_in_tail(new Node(i*i));
		second->add_in_tail(new Node(i + i));
	}
	first->add_in_tail(new Node(1));

	LinkedList*sum = sum_of_elem(one_el, one_el);
	if (sum->head!= NULL)
	{
		print(sum);
	}
}


void check_find_all()
{
	LinkedList*empty = new LinkedList();
	LinkedList*one_el = new LinkedList();
	one_el->add_in_tail(new Node(1));
	LinkedList*test_list = new LinkedList();
	for (int i = 0; i <= 10; ++i)
	{
		test_list->add_in_tail(new Node(3*i - i));
	}
	print(test_list);
	print(empty->find_all(1));
}
