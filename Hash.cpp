
#include<stdio.h>


class HashTable
{
public:
	int size;
	int step;
	char** slots;

	HashTable(int sz, int stp)
	{
		size = sz;
		step = stp;
		slots = new char*[size];
		for (int i = 0; i<size; i++) slots[i] = NULL;
	}

	int hashFun(char* value)
	{
		if (value == NULL) return -1;
		int index = 0;
		
		for (int i=0;value[i]!=0;++i) 
			index += (int)value[i];
		
		return index % size;
	}

	int seekSlot(char* value)
	{
		int index = hashFun(value);

		for (int i = 0; i < step+1; ++i)
		{
			while (index <size)
			{
				if (slots[index] == NULL) return index;
				index += step;
			}
			index = index - size;
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
		else return -1;
	}

	int find(char* value)
	{
		int index = hashFun(value);
		
		if (index == -1) return -1;

		for (int i = 0; i < step+1; ++i)
		{
			while (index < size)
			{
				if (slots[index]==value)
					return index;
				index += step;
			}
			index =index-size;
		}
		return -1;
	}
};
