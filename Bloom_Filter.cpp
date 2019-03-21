/*

Purpose:
A Bloom filter is a space-efficient probabilistic data structure, 
conceived by Burton Howard Bloom in 1970, 
that is used to test whether an element is a member of a set.

Using:
add: adds elements to the Bloom filter
is_value: checks if filter contains a given value

Programmer:
Kozhin Valeriy Alexandrovich, github.com/jeanedit
Date:
21.03.2019
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


class BloomFilter
{
public:
	int filter_len; //length of the filter
	int filter; //32 bit representation (int, long 32 bit, long long 64 bit)

	BloomFilter(int f_len)
	{
		filter_len = f_len; // better to take 32 bit in this implementation
		filter = 0; // all 32 bits are 0
	}

	// hash functions
	int hash1(char* str1)
	{
		int result = 0;
		for (int i = 0; i<strlen(str1); i++)
		{
			int code = str1[i];
			result = (17 * result + code) % filter_len; // random number here is 17
		}
		return 1<<result; // 00.....01 <- 32 bit, just shifting this 1 on "result" slots left
	}
	int hash2(char* str1)
	{
		int result = 0;
		for (int i = 0; i<strlen(str1); i++)
		{
			int code = str1[i];
			result = (223 * result + code) % filter_len; // random number here is 223
		}
		return 1 << result; // 00.....01 <- 32 bit, just shifting this 1 on "result" slots left
	}

	void add(char* str1)
	{
		filter |= hash1(str1); // adds 1 to the filter at the same place as in the returned value by hash1
		filter |= hash2(str1); //adds 1 to the filter at the same place as returned value by hash1
	}

	bool is_value(char* str1)
	{
		int sec_filter = hash1(str1)+hash2(str1); // summarize bits of the two hash function
	
		if ((filter&sec_filter)==sec_filter) 
			return true;

		return false;
	}
};

void reverse(char*str)
{
	char c = str[0];
	
	for (int i = 1; i < strlen(str); ++i)
	{
		str[i-1] = str[i];
	}
	str[strlen(str) - 1] = c;
}


int main()
{
	BloomFilter*filter = new BloomFilter(32);
	
	char a[32] = "9012345678";
	char*pa = a;

	char b[32] = "0123456789";
	char*pb = b;

	for (int i = 0; i < 10; ++i)
	{
		reverse(pb);
		filter->add(pb);
		printf("%c%c%c%c%c%c%c%c%c%c\n", pb[0], pb[1], pb[2], pb[3], pb[4], pb[5], pb[6], pb[7], pb[8], pb[9]);
	}
	
	if(filter->is_value(pa)) printf("YEE,BOII\n");
}