/*

An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

    int solution(int A[], int N);

that, given an array A, returns the value of the missing element.

For example, given array A such that:
  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5

the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..100,000];
        the elements of A are all distinct;
        each element of array A is an integer within the range [1..(N + 1)].

*/

#include <stdio.h>

//50%
/* int solution(int A[], int N) { */
/*     // write your code in C99 (gcc 6.2.0) */
/*     int i; */
/*     #<{(| int B[N + 1]; |)}># */
/*     int B[100000] = {0}; */
/*  */
/*     for (i = 0; i < N; ++i)  */
/* 	    B[A[i]] = 1; */
/*     */
/*     for (i = 1; i < N + 1; ++i) { */
/* 	    if (B[i] == 0) */
/* 		    return i; */
/*     } */
/*     return -1; */
/* } */

//100%
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

//100%
int solution(int A[], int N) {
        // write your code in C99 (gcc 6.2.0)
        int i;
        int tmp_count = 0;
        int tmp_zero  = -1;
        int B[1000000] = {0};

        for (i = 0; i < N; ++i) 
                B[A[i]] = 1;

        for (i = 1; i < 1000000; ++i) {
                if (tmp_count == N) {
                    if (tmp_zero == -1)
                        tmp_zero = N + 1;
                    return tmp_zero;
                }
       
       		if (B[i] == 1)
                        tmp_count++;
                
		if (B[i] == 0)
                        tmp_zero = i;
        }
        return tmp_zero;
} 

int main ()
{
	int N   = 4;
	int A[] = {2, 3, 1, 5};

	printf ("%d\n", solution(A, N));

	return 0;
}
