/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

int findSingleOccurenceNumber(int *A, int len) {
	int a = 0, b = 0;
	int c;
	if (!A)
		return -1;
	for (int i = 0; i< len; i++)
	{

		b = b | (a & A[i]);
		a = a ^ A[i];
		c = ~(a & b);
		a &= c;
		b &= c;
	}
	return a;
}