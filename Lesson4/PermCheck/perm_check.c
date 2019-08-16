/*

A non-empty array A consisting of N integers is given.

A permutation is a sequence containing each element from 1 to N once, and only once.

For example, array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2

is a permutation, but array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3

is not a permutation, because value 2 is missing.

The goal is to check whether array A is a permutation.

Write a function:

    int solution(int A[], int N);

that, given an array A, returns 1 if array A is a permutation and 0 if it is not.

For example, given array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2

the function should return 1.

Given array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3

the function should return 0.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [1..1,000,000,000].

*/
    
#include<stdio.h>
#include<math.h>

//66%
/* int solution(int A[], int N) { */
/* 	int i; */
/* 	int B[N + 1]; */
/*  */
/* 	if (N == 1) { */
/* 		if (A[0] == 1) */
/* 			return 1; */
/* 		else  */
/* 			return 0; */
/* 	} */
/*  */
/* 	if (N == 2) { */
/* 		if (fabs(A[0] - A[1]) == 1) */
/* 			return 1; */
/* 		else  */
/* 			return 0; */
/* 	} */
/*  */
/* 	for (i = 0; i < N; ++i)  */
/* 		B[A[i]] = 1; */
/*  */
/* 	for (i = 1; i < N; ++i) { */
/* 		if (B[i] != 1) */
/* 			return 0; */
/* 	} */
/* 	return 1; */
/* } */

//83%
/* int solution(int A[], int N) { */
/*         int i; */
/*         int B[100000] = {0}; */
/*  */
/*         if (N == 1) { */
/*                 if (A[0] == 1) */
/*                         return 1; */
/*                 else  */
/*                         return 0; */
/*         } */
/*  */
/*         if (N == 2) { */
/*                 if ( (fabs(A[0] - A[1]) == 1) && (A[0] == 1 || A[1] == 1) ) */
/*                         return 1; */
/*                 else  */
/*                         return 0; */
/*         } */
/*  */
/*         for (i = 0; i < N; ++i)  */
/*                 B[A[i]] = 1; */
/*  */
/*         for (i = 1; i < N; ++i) { */
/*                 if (B[i] == 0) */
/*                         return 0; */
/*         } */
/*         return 1; */
/* } */

//91%
/* int solution(int A[], int N) { */
/*         int i; */
/*         int B[100001] = {0}; */
/*  */
/*         if (N == 1) { */
/*                 if (A[0] == 1) */
/*                         return 1; */
/*                 else  */
/*                         return 0; */
/*         } */
/*  */
/*         if (N == 2) { */
/*                 if ( (fabs(A[0] - A[1]) == 1) && (A[0] == 1 || A[1] == 1) ) */
/*                         return 1; */
/*                 else  */
/*                         return 0; */
/*         } */
/*  */
/*         for (i = 0; i < N; ++i)  */
/*                 B[A[i]]++; */
/*  */
/*         for (i = 1; i < N + 1; ++i) { */
/*                 if (B[i] != 1) */
/*                         return 0; */
/*         } */
/*         return 1; */
/* } */


//100%
int solution(int A[], int N) {
	int i;
	int result_a = A[0];
	int result_i = 1;

	for (i = 1; i < N; ++i) {
		result_a ^= A[i];
		result_i ^= i + 1;
	}

	result_i = result_i ^ result_a;

	if (result_i == 0)
		return 1;
	else 
		return 0;
}

int main() 
{
	int i;
	int N = 9;
	/* int A[] = {9, 3, 9, 3, 9, 7, 9}; */
	/* int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; */
	/* int A[] = {1, 3, 4, 2, 7, 5, 6, 9, 8}; */
	int A[] = {1, 3, 2, 2, 9, 5, 6, 9, 8};
	/* int A[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; */

	/* int A[] = {1}; */
	/* int A[] = {4, 3}; */
	/* int A[] = {4, 1, 3, 2}; */


	printf ("%d\n", solution(A, N));

	return 0;
}
