#include <stdio.h>

class DynArray
{
public:
	int count;
	int capacity;
	int* array;  // хранит неотрицательные значения
	DynArray()
	{
		count = 0;
		make_array(16);
	}

	void make_array(int new_capacity)
	{
		if (new_capacity < 16) new_capacity = 16;

		int*new_arr = new int[new_capacity];

		for (int i = 0; i < new_capacity; ++i) new_arr[i] = 0; //initialize new_arr with non-negative

		for (int i = 0; i < count; ++i) new_arr[i] = array[i]; //copy from arr to new_arr

		for (int i = count; i < new_capacity; ++i) new_arr[i] = 0; //assignment non-negative to left elements

		delete[] array;

		array = new_arr;
		
		capacity = new_capacity;
	}

	int get_item(int index)
	{
			if (index >= capacity || index < 0) throw "out_of_range";//exception
			if (index >= count) return -1;

			return array[index];
	}

	void append(int value)
	{
		if (count == capacity)
		{
			make_array(2*capacity);
		}
			array[count] = value;
			++count;
	}

	void insert(int value, int index)
	{
		if (index == count)
		{
			append(value);
			return;
		}

		if (get_item(index) == -1) throw "out_of_range";

		if (count == capacity) make_array(2 * capacity);

		for (int i = index; i < count; ++i)
		{
			array[i + 1] = array[i];
		}
		array[index] = value;
		++count;
	}

	void remove(int index)
	{
		if (get_item(index) == -1) throw "out_of_range";

		for (int i = index; i < count; ++i)
		{
			array[i] = array[i + 1];
		}
		--count;
		if (count < capacity / 2&&capacity!=16)
		{
			int cap = (2 * capacity) / 3;
			make_array(cap);
		}
	}

};

/*
void print(DynArray*n)
{
	for (int i = 0; i < n->count; ++i)
	{
		printf("%i\n", n->get_item(i));
	}
}



int main()
{
	DynArray*n = new DynArray();
	for (int i = 0; i < 16; ++i)
	{
		n->append(1);
	}
	n->append(16);
	print(n);
	printf("****************\ncount:%i\ncapacity:%i\n",n->count,n->capacity);
	//n->insert(2, 17);
	n->remove(0);
	//n->remove(15);
	print(n);
	//n->make_array(21);
	printf("****************\ncount:%i\ncapacity:%i\n", n->count, n->capacity);
	//printf("%i\n",n->get_item(16));
}
*/