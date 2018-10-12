/*

A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

    int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..2,147,483,647].

*/


#include <stdio.h>
/* int main() */
/* { */
/* 	int n=255; */
/* 	int i; */
/* 	for (i = sizeof(n)*8-1; i>=0; i--) */
/* 	{ */
/* 		    printf("%d", (n >> i) % 2); */
/* 	} */
/* 	    return(0); */
/* } */

/* //100% */
/* int solution(int N) { */
/* 	// write your code in C99 (gcc 6.2.0) */
/*  */
/* 	int i; */
/* 	int arch_size = sizeof(int)*8;; */
/* 	int binary_arr[arch_size]; */
/* 	int one       = 0; */
/* 	int tmp_count = 0; */
/* 	int count     = 0; */
/*  */
/* 	for (i = arch_size - 1; i >= 0; --i) */
/* 		binary_arr[i]=(N >> i) % 2; */
/*  */
/* 	for (i = 0; i < arch_size; ++i) { */
/* 		if (binary_arr[i] == 1) { */
/* 			if (tmp_count > 0) { */
/* 				if(tmp_count > count)  */
/* 					count = tmp_count; */
/* 				tmp_count = 0; */
/* 			} */
/* 			one = 1; */
/* 			continue; */
/* 		} */
/*     	if (binary_arr[i] == 0 && one == 1) */
/* 			tmp_count++; */
/* 	} */
/* 	return count; */
/* } */


int main()
{
	int N, i;
	int arch_size = sizeof(N)*8;
	int binary_arr[arch_size];

	printf("Enter integer N: ");
	scanf("%d", &N);

	for (i = arch_size - 1; i >= 0; --i)
	{
		/* printf ("%d     ", x >> i); */
		/* printf ("%d\n", (x >> i) % 2); */
		binary_arr[i]=(N >> i) % 2;
		printf("%d", binary_arr[i]);
	}

	int one = 0;
	int tmp_count = 0;
	int count     = 0;
	for (i = 0; i < arch_size; ++i)
	{
		if (binary_arr[i] == 1)
		{
			if (tmp_count > 0)
			{
				if(tmp_count > count)
					count = tmp_count;
				tmp_count = 0;
			}
			one = 1;
			continue;
		}

		if (binary_arr[i] == 0 && one == 1)
			tmp_count++;

	}
	
	printf ("count = %d", count);

}
