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
int date_compare2(char *, char *);
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	/*int i = 0;
	int j = 0;
	int k = 0;
	int flag = 0;
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction *res = (struct transaction*)malloc(sizeof(struct transaction) * 3);
	while (i < ALen && j < BLen)
	{
		flag = date_compare2(A[i].date, B[i].date);
		if (flag == 1)
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
		while (i < ALen)
		{
			res[k] = A[i];
			i++;
			k++;
		}
	}
	return res;*/
	return NULL;
}
int date_compare2(char dob1[], char dob2[]){
	if (dob1[2] != '-' || dob1[5] != '-' || dob2[2] != '-' || dob2[5] != '-')
		return -1;
	int year1 = ((dob1[6] - 48) * 1000) + ((dob1[7] - 48) * 100) + ((dob1[8] - 48) * 10) + (dob1[9] - 48);
	int year2 = ((dob2[6] - 48) * 1000) + ((dob2[7] - 48) * 100) + ((dob2[8] - 48) * 10) + (dob2[9] - 48);
	int month1 = ((dob1[3] - 48) * 10) + (dob1[4] - 48);
	int month2 = ((dob2[3] - 48) * 10) + (dob2[4] - 48);
	int day1 = ((dob1[0] - 48) * 10) + (dob1[1] - 48);
	int day2 = ((dob2[0] - 48) * 10) + (dob2[1] - 48);
	if (year1 == year2 && month1 == month2 && day1 == day2)
		return 2;
	if(year1 < year2)
		return 1;
	/*if (year1 > year2)
		return 2;
	else if (year2 > year1)
		return 1;
	else{
		if (month1 > month2)
			return 2;
		else if (month2 > month1)
			return 1;
		else{
			if (day1 > day2)
				return 2;
			else if (day2 > day1)
				return 1;
			else
				return 0;
		}
	}*/
}