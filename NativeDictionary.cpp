
#include<stdio.h>
#include<string.h>



// Implementation of the associative array using hash-table

class NativeDictionary
{
public:
	int slots_size;
	char** slots;
	int* values; 

	NativeDictionary(int sz)
	{
		step = 3;
		slots_size = sz;
		slots = new char*[slots_size];
		for (int i = 0; i<slots_size; i++) slots[i] = NULL;
		values = new int[slots_size];
		for (int i = 0; i<slots_size; i++) values[i] = -1;
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
		else return true;
	}

	void put(char* key, int value) // adding key and value or assign new value to the existing key
	{
		
		int index = find(key);
		
		if (index != -1)
		{
			values[index] = value;
			return;
		}
		int _slot= seekSlot(key);
		
		if (_slot != -1)
		{
			slots[_slot] = key;
			values[_slot] = value;
			return;
		}
		else return;

	}

	int get(char* key) // getting value by existing key
	{
		int index = find(key);
		if (index == -1) return -1;
		else
			return values[index];
	}

private:
	int step;

	//Functions from the HashTable class which implemented in the Hash.cpp

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

	int put(char* value)
	{
		int index = seekSlot(value);

		if (index != -1)
		{
			slots[index] = value;
			return index;
		}
		else
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
