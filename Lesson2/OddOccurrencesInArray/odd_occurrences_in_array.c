/*

A non-empty array A consisting of N integers is given. The array contains an odd number of elements, and each element of the array can be paired with another element that has the same value, except for one element that is left unpaired.

For example, in array A such that:
  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9

        the elements at indexes 0 and 2 have value 9,
        the elements at indexes 1 and 3 have value 3,
        the elements at indexes 4 and 6 have value 9,
        the element at index 5 has value 7 and is unpaired.

Write a function:

    int solution(int A[], int N);

that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.

For example, given array A such that:
  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9

the function should return 7, as explained in the example above.

Write an efficient algorithm for the following assumptions:

        N is an odd integer within the range [1..1,000,000];
        each element of array A is an integer within the range [1..1,000,000,000];
        all but one of the values in A occur an even number of times.

*/

#include <stdio.h>

//77%
/* int solution(int A[], int N) { */
/* 	// write your code in C99 (gcc 6.2.0) */
/* 	int i; */
/* 	int B[1000000] = {0}; */
/*  */
/* 	for (i = 0; i < N; ++i)  */
/* 		B[A[i]]++; */
/*  */
/* 	for (i = 0; i < 1000000; ++i) { */
/* 		if (B[i] > 0 && B[i] % 2 != 0) */
/* 			return i; */
/* 	} */
/* 	return -1; */
/* } */

//66%
/* int solution(int A[], int N) { */
/* 	// write your code in C99 (gcc 6.2.0) */
/* 	int i; */
/* 	int j; */
/*  */
/* 	for (i = 0; i < N -1; ++i) { */
/* 		if (A[i] == 0) */
/* 			continue; */
/*  */
/* 		for (j = i + 1; j < N; ++j) { */
/* 			if (A[i] == A[j]) { */
/* 				A[i] = 0; */
/* 				A[j] = 0; */
/* 				break; */
/* 			} */
/* 		} */
/* 	} */
/*  */
/* 	for (i = 0; i < N; ++i) */
/* 		if (A[i] != 0) */
/* 			return A[i]; */
/*  */
/* 	return -1; */
/* } */

/* 100% */
int solution(int A[], int N) {
	// write your code in C99 (gcc 6.2.0)
	int i;
	int result = A[0];

	for (i = 1; i < N; ++i) {
		result ^= A[i];
	}
	return result;
}

int main ()
{
	int N   = 7;
	int A[] = {9, 3, 9, 3, 9, 7, 9};

	printf ("%d\n", solution(A, N));


	return 0;
}
