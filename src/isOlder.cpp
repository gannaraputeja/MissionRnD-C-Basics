/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int age(char *p)
{
	long temp = 0;
	int f = 0, i = 0;
	int t[3] = { 1, 100, 10000 };
	int val = 0;
	while (*p)
	{
		if (isdigit(*p))
		{
			temp = strtol(p, &p, 10);
			if (f == 1)
			{
				if (((temp % 4 == 0) && (temp % 100 != 0)) || (temp % 400 == 0))
					f = 0;
				else
					return -1;
			}
			if (i == 1)
			{
				if (temp == 0)
					return -1;
				if (temp > 12)
					return -1;
				if (temp == 2 && val > 28)
					f = 1;
			}
			val = val + temp * t[i++];

		}
		else
		{
			p++;
		}
	}
	return val;
}

int isOlder(char *dob1, char *dob2) 
{
	int n, m;
	long valp = 0, valq = 0;
	n = strlen(dob1);
	m = strlen(dob2);
	if ((n != 10) || (m != 10))
		return -1;
	valp = age(dob1);
	valq = age(dob2);
	if ((valp == -1) || (valq == -1))
		return -1;
	if (valp < valq)
		return 1;
	else if (valp > valq)
		return 2;
	else
		return 0;
}


