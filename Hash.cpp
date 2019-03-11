
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>



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
				//printf("Index!!!:%i\n", index);
				if (slots[index] == NULL)
					return index;
				index += step;
			}
			index = index - size;
		}
			return -1;
	}

	int put(char* value)
	{
		int index = seekSlot(value);
		//printf("seekSLot:%i\n", index);
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
		//printf("hashFUn:%i\n", index);
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


int test_hash(HashTable* Table, HashTable* Table2)
{
//HashTable* Table = new HashTable(17, 3);
	const char*value = "dark";
	char val[5];
	char*j_val = strcpy(val, value);
	const char* value2 = "Itos";
	char val2[5];
	char*j_val2 = strcpy(val2, value2);
	const char* value3= "Itos better to light a candle than curse the darkness";
	char val3[56];
	char*j_val3 = strcpy(val3, value3);
	const char* value4 = "darkness";
	char val4[9];
	char*j_val4 = strcpy(val4, value4);
	const char* val_2 = "You canot make bricks without straw";
	char val_22[50];
	char*j_val22 = strcpy(val_22, val_2);
	int step = Table->step;
	int test = 0;
// FIND
	if (Table->find(NULL) != -1) test++;// checking the filling of the empty table
// if (Table->find(0) != -1) test++;       // this value is not in the table - don't work
// PUT
	int index = Table->hashFun(j_val); 
	//printf("Index:%i\n", index);
	for (int i = 0; i < Table->size - 2; i++) // fill the entire array except for one cell
	{
		index = (index <= Table->size - 1) ? index : index - Table->size;
		printf("Index:%i\n", index);
		Table->put(j_val);
		index += step;
	}
	index = (index <= Table->size - 1) ? index : index - Table->size;
	if (Table->put(j_val3) != index) test++;
	//printf("Test after Table->put(Itos better to light a candle than curse the darkness)!=index\n%i\n", test);
	if (Table->find(j_val3) != index) test++;
	//printf("Test after Table->find(Itos better to light a candle than curse the darkness)!=index\n%i\n", test);
	if (Table->put(j_val2) != 7) test++;
	if (Table->put(j_val22) != -1) test++;
	if (Table->find(j_val22) != -1) test++;
	if (Table->put(j_val4) != -1) test++;    //the table is full
	if (Table->find(j_val4) != -1) test++;
	char t[3] = "0E";
	char* _t = t+1;
	for (int i = 0; i <= Table2->size-1; i++) // fill the entire array except for one cell
	{
		*_t = 49 + i;
		printf("%c", t[0]);
		printf("%c\n", t[1]);
		//printf("Table2->put(t): %i\n",Table2->put(t));
	}
	char en[3] = "en";
	char*en1 = en;

	const char*en2 = "02";
	char en22[3];
	char* en3 = strcpy(en22, en2);
	printf("%c\n", en3[1]);

	if (Table2->put(en1) != -1) test++;    //the table is full
	if (Table2->find(en1) != -1) test++;
	if (Table2->find(en3) != Table2->hashFun(en3)) test++;
	printf("Table->find(j_val3):%i\n", Table2->find(en3));
	return test;
}


int main()
{
	char a[4] = "Kek";
	char*s = a;

	const char*kek1 = "Suk";
	char a1[4];
	char*s1 = strcpy(a1, kek1);
	
	const char*kek2 = "Shrek";
	char a2[6];
	char*s2= strcpy(a2, kek2);


	HashTable* Table = new HashTable(17, 3);
	HashTable* Table2 = new HashTable(11, 5);
	//int test = test_hash(Table, Table2);

	//printf("Test:%i\n", test);
	printf("%i\n", Table->put(s));
	printf("%i\n", Table->put(s1));
	printf("%i\n", Table->put(s2));
	printf("%i\n", Table->put(s));
	printf("%i\n", Table->put(s1));
	printf("%i\n", Table->put(s2));
	printf("%i\n", Table->put(s));
	printf("%i\n", Table->put(s1));
	printf("%i\n", Table->put(s2));
	printf("%i\n", Table->put(s));
	printf("%i\n", Table->put(s1));
	printf("%i\n", Table->put(s2));
	printf("%i\n", Table->put(s));
	printf("%i\n", Table->put(s1));
	printf("%i\n", Table->put(s2));
	printf("%i\n", Table->put(s));
	printf("%i\n", Table->put(s1));
	printf("%i\n", Table->find(s));
	//printf("%i\n", Table->put(s2));

	return 0;
}
