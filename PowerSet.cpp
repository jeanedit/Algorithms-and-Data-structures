/*
Purpose: 
	Implement data structure named as "Set"  using  for efficiency in the specific tasks

Using: 
	size: returns size of the set
	put: puts elements inside the set
	get: checks element existing
	remove: removes element from the set
	intersection: finds intersection between two sets
	_union: finds union of the two sets
	differences: finds differences between two set
	is_subset: determines is this set a subset of another set 

Programmer: 
		Kozhin Valeriy Alexandrovich, github.com/jeanedit
Date: 
	18.03.2019

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;


class PowerSet
{
public:
	int set_size;
	char**slots;

	PowerSet()
	{
		set_size = 6;
		step = 1;
		slots = new char*[set_size];
		for (int i = 0; i < set_size; ++i) slots[i] = NULL;
	}

	int size()
	{
		int count = 0;
		for (int i = 0; i < set_size; ++i)
		{
			if (slots[i] != NULL)
			{
				count++;
			}
		}
		return count;
	}

	// Puts new element at the set, if size is equal to six increase size of the array of slots

	void put(char* value)
	{
		int index = seekSlot(value);

		if (find(value) != -1) return;

		if (index == -1)
		{
			char**new_slots = new char*[set_size+1];
			for (int i = 0; i < set_size; ++i) new_slots[i] = slots[i];
			for (int i = set_size; i <set_size+1; ++i) new_slots[i] = NULL;
			delete[] slots;
			slots = new_slots;
			set_size =  set_size+1;
			slots[seekSlot(value)] = value;
		}
		else slots[index] = value;
	}

	bool get(char* value)
	{
		if (find(value) != -1) return true;
		else return false;
	}

	bool remove(char* value)
	{
		int index = find(value);
		if (index != -1)
		{
			delete slots[index];
			slots[index] = NULL;
			return true;
		}
		return false;
	}

	PowerSet* intersection(PowerSet* set2)
	{
		PowerSet*set = new PowerSet();

		if (set2 == NULL || this == NULL) return NULL;

		//Finds equal elements of two set and adds this to the created set;

		for (int j = 0; j < set_size; ++j)
		{
				if (set2->get(slots[j]))
					set->put(slots[j]);
		}
		return set;
	}

	PowerSet* _union(PowerSet* set2)
	{
		PowerSet*set = new PowerSet();

		if (set2 == NULL || this == NULL) return NULL;

		if (set2->size() == 0) return this;

		else if (size() == 0) return set2;

		//Just adds elements of both set to the created set

		for (int j = 0; j < set_size; ++j)
		{
			if (slots[j] != NULL)
			{
				set->put(slots[j]);
			}
		}
		for (int i = 0; i < set2->set_size; ++i)
		{
			if (set2->slots[i] != NULL)
			{
				set->put(set2->slots[i]);
			}
		}
		return set;
	}

	PowerSet* difference(PowerSet* set2)
	{
		PowerSet*set = new PowerSet();

		if (set2 == NULL||this==NULL) return NULL;

		if (this->size()==0) return set;
		if (set2->size()==0) return this;
		
		//Checks containing  the elements of the set2  in the set, if not adds to the created set;

		for (int j = 0; j < set_size; ++j)
		{
			if (slots[j] != NULL)
			{
				if (!set2->get(slots[j]))
					set->put(slots[j]);
			}
		}
		return set;
	}

	bool is_subset(PowerSet* set2)
	{
		if (set2 == NULL) return false;
		//Just checks is the elements of the set2 are contained in the set

		for (int i = 0; i < set2->set_size; ++i)
		{
			if (set2->slots[i] != NULL)
			{
				if (!get(set2->slots[i])) return false;
			}
		}
		return true;
	}

private:
		int step;

		int hashFun(char* value)
		{
			if (value == NULL) return -1;

			int index = 0;

			for (int i = 0; value[i] != 0; ++i)
				index += (int)value[i];

			return index % set_size;
		}

		int seekSlot(char* value)
		{
			int index = hashFun(value);

			if (index == -1) return -1;

			for (int i = 0; i < step + 1; ++i)
			{
				while (index < set_size)
				{
					if (slots[index] == NULL)
						return index;
					index += step;
				}
				index = index - set_size;
			}
			return -1;
		}

		int find(char* value)
		{
			int index = hashFun(value);

			if (index == -1) return -1;

			for (int i = 0; i < step + 1; ++i)
			{
				while (index < set_size)
				{
					if (slots[index] != NULL && strcmp(slots[index], value) == 0)
						return index;
					index += step;
				}
				index = index - set_size;
			}
			return -1;
		}
};


//=========================TEST=======================//
void test()
{
	PowerSet*set = new PowerSet();
	PowerSet*set1 = new PowerSet();
	PowerSet*set4 = new PowerSet();
	PowerSet*set5 = new PowerSet();

	for (int i = 0; i < 12; ++i)
	{
		char*s = new char[32];
		sprintf(s, "%i", i);
		set->put(s);
	}

	for (int i = 0; i <2; ++i)
	{
		char*s = new char[32];
		sprintf(s, "%i", i );
		set1->put(s);
	}
	char z[5] = "212";
	char*z1 = z;
	//set->put(z);
	PowerSet*set3 = set->difference(set1);

	if (set->is_subset(set1)) printf("Set1 is a subset of the set\n");
	else printf("Set1 isn't a subset of the set\n");

	

	char a[5] = "212";
	char*a1 = a;	//set->put(a1);
	if (set->get(a1)) printf("%c in the set\n", a1[0]);
	printf("size: %i\tset_cap: %i\n", set3->size(),set3->set_size);
	//if (set->remove(a1)) printf("size: %i\tset_cap: %i\n", set->size(), set->set_size);
	//if (set3->get(a1)) printf("%c in the set\n", a1[0]);
}

int main()
{
	test();
}