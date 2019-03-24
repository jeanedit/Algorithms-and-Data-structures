
/*
Purpose:
In computing, a cache 
is a hardware or software component 
that stores data so that future requests for that data can be served faster; 
the data stored in a cache might be the result of an earlier computation or a copy of data stored elsewhere. 
A cache hit occurs when the requested data can be found in a cache, while a cache miss occurs when it cannot.
Cache hits are served by reading data from the cache, 
which is faster than recomputing a result or reading from a slower data store; 
thus, the more requests that can be served from the cache, the faster the system performs.

   *****In my implementation, an item that is rarely hits is pushed out*****

Using:

is_key:returns true if key is exist
put:record key and value into the table, if table is full displaces an item that is rarely hits
get: returning value which corresponding to a specific key

Programmer:
Kozhin Valeriy Alexandrovich, github.com/jeanedit

Date:
24.03.2019
*/

#include<stdio.h>
#include<string.h>

class NativeCache
{
public:
	int slots_size;
	char** slots;
	int* values;
	int* hits; //number of hits of the each key 

	NativeCache(int sz)
	{
		step = 3;
		slots_size = sz;

		slots = new char*[slots_size];
		values = new int[slots_size];
		hits = new int[slots_size];

		for (int i = 0; i < slots_size; ++i) slots[i] = NULL;
		for (int i = 0; i < slots_size; ++i) values[i] = -1;
		for (int i = 0; i < slots_size; ++i) hits[i] = 0;
	}

	int hashFun(char* key) // hash function that returns index which is remainder of the dividing by slots_size
	{
		if (key == NULL) return -1;

		int index = 0;
		for (int i = 0; key[i] != 0; ++i)
		{
			index += (int)key[i];
		}
		return index % slots_size;
	}

	bool is_key(char* key) // key availability check
	{
		if (find(key) == -1)
			return false;
		else
		{
			hits[find(key)]++;
			return true;
		}

	}

	void put(char* key, int value) // adding key and value or assign new value to the existing key
	{
		int _slot = seekSlot(key);


		if (_slot != -1)
		{
			slots[_slot] = key;
			values[_slot] = value;
			return;
		}
		else if (_slot == -1) // push out rarely hitting element
		{
			slots[min_hits()] = key;
			values[min_hits()] = value;
			hits[min_hits()] = 0;
			return;
		}
		else return;
	}

	int get(char* key) // getting value by existing key
	{
		int index = find(key);
		if (index == -1) return -1;
		else
		{
			hits[index]++;
			return values[index];
		}
	}

private:
	int step;

	//Functions from the HashTable class which implemented in the Hash.cpp
	
	int min_hits()
	{
		int min = hits[0];
		int j=0;
		
		for (int i=0;i < slots_size; ++i)
		{
			if (min > hits[i])
			{
				min = hits[i];
				j = i;
			}
		}
		return j;
	}

	int seekSlot(char* value)
	{
		int index = hashFun(value);

		if (index == -1) return -1;

		for (int i = 0; i < step + 1; ++i)
		{
			while (index <slots_size)
			{
				if (slots[index] == NULL)
					return index;
				index += step;
			}
			index = index - slots_size;
		}
		return -1;
	}


	int find(char* value)
	{
		int index = hashFun(value);


		if (index == -1) return -1;

		for (int i = 0; i < step + 1; ++i)
		{
			while (index < slots_size)
			{
				if (slots[index] != NULL && strcmp(slots[index], value) == 0)
				{
					return index;
				}
				index += step;
			}
			index = index - slots_size;
		}
		return -1;
	}
};
