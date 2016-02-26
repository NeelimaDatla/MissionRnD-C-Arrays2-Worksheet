/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int date_compare(char *, char *);
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int flag = 0;
	int new_flag = 0;
	int count = 0;
	for (int i = 0; i < len; i++){
		flag = date_compare(Arr[i].date, date);
		if (flag == 1){
			count = i + 1;
			new_flag = 1;
		}
	}
	if (new_flag == 0)
		return 0;
	return len - count;
}
int date_compare(char dob1[], char dob2[]){
	if (dob1[2] != '-' || dob1[5] != '-' || dob2[2] != '-' || dob2[5] != '-')
		return -1;
	int year1 = ((dob1[6] - 48) * 1000) + ((dob1[7] - 48) * 100) + ((dob1[8] - 48) * 10) + (dob1[9] - 48);
	int year2 = ((dob2[6] - 48) * 1000) + ((dob2[7] - 48) * 100) + ((dob2[8] - 48) * 10) + (dob2[9] - 48);
	int month1 = ((dob1[3] - 48) * 10) + (dob1[4] - 48);
	int month2 = ((dob2[3] - 48) * 10) + (dob2[4] - 48);
	int day1 = ((dob1[0] - 48) * 10) + (dob1[1] - 48);
	int day2 = ((dob2[0] - 48) * 10) + (dob2[1] - 48);
	if (year1 == year2 && month1 == month2 && day1 == day2)
		return 1;
	else
		return 0;
}