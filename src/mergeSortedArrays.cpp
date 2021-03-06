/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i = 0;
	int j = 0;
	int k = 0;
	int flag = 0;
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction *res = (struct transaction*)malloc(sizeof(struct transaction) * 9);
	while (i < ALen && j < BLen)
	{
		if (A[i].amount < B[j].amount)
		{
			res[k] = A[i];
			i++;
		}
		else
		{
			res[k] = B[j];
			j++;
		}
		k++;
	}
	if (i >= ALen)
	{
		while (j < BLen)
		{
			res[k] = B[j];
			j++;
			k++;
		}
	}
	if (j >= BLen)
	{
		while (i<ALen)
		{
			res[k] = A[i];
			i++;
			k++;
		}
	}
	return res;
}
