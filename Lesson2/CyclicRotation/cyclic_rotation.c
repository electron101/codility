/*

   An array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place. For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).

   The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

   Assume that the following declarations are given:

   struct Results {
   int * A;
   int N; // Length of the array
   };

   Write a function:

   struct Results solution(int A[], int N, int K);

   that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.

   For example, given
   A = [3, 8, 9, 7, 6]
   K = 3

   the function should return [9, 7, 6, 3, 8]. Three rotations were made:
   [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
   [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
   [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]

   For another example, given
   A = [0, 0, 0]
   K = 1

   the function should return [0, 0, 0]

   Given
   A = [1, 2, 3, 4]
   K = 4

   the function should return [1, 2, 3, 4]

   Assume that:

   N and K are integers within the range [0..100];
   each element of array A is an integer within the range [−1,000..1,000].

   In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.

*/

#include <stdio.h>

struct Results {
	int * A;
	int N; // Length of the array
};

//25%
/* struct Results solution(int A[], int N, int K) { */
/* 	struct Results result; */
/* 	// write your code in C99 (gcc 6.2.0) */
/* 	result.A = A; */
/* 	result.N = N; */
/*  */
/* 	int i; */
/*  */
/* 	#<{(| if (K == N + 1 || K == 0 || K % N == 0) |)}># */
/* 	if (K == N + 1 || K == 0) */
/* 		return result; */
/* 	 */
/* 	int count = A[0]; */
/* 	int tmp_result = 0; */
/* 	for (i = 0; i < N; ++i) { */
/* 		if (A[i] == count) */
/* 			count++; */
/* 		else { */
/* 			tmp_result = 1; */
/* 			break; */
/* 		} */
/* 	} */
/* 	if (K == N) */
/* 		if (tmp_result == 0) */
/* 			return result; */
/* 		else  */
/* 			goto res; */
/*  */
/* 	int all = 0; */
/* 	for (i = 0; i < N; ++i) { */
/* 		if (A[i] == A[0]) {	 */
/* 			all++; */
/* 			continue; */
/* 		} */
/* 		else */
/* 			break; */
/* 	} */
/* 	if (all == N) */
/* 		return result; */
/*  */
/* 	if (K > N) */
/* 		K = K % N; */
/*  */
/* res: { */
/* 	     int B[N]; */
/* 	     int j; */
/* 	     for (i = 0, j = 0; i < N; ++i) { */
/* 		     if (i + K > N) { */
/* 			     B[i] = A[j]; */
/* 			     j++; */
/* 		     } */
/* 		     else  */
/* 			     B[i] = A[i + K - 1]; */
/* 	     } */
/* 	     for (i = 0; i < N; ++i)  */
/* 		     result.A[i] = B[i]; */
/* 	     result.N = N; */
/*      } */
/*  */
/* 	return result; */
/* } */

//100%
struct Results solution(int A[], int N, int K) {
        struct Results result;
        // write your code in C99 (gcc 6.2.0)
        result.A = A;
        result.N = N;

        if (K == N)
                return result;
                
        if (N == 1)
                return result;

        if (K == 0 || N == 0)
                return result;

        if (K > N)
                K = K % N;

        int i;
        int j;
        int B[N];

        for (j = 0; j < K; ++j) {
                B[0] = A[N - 1];

                for (i = 0; i < N - 1; ++i)
                        B[i + 1] = A[i];

                for (i = 0; i < N; ++i) 
                        A[i] = B[i];
        }

        for (i = 0; i < N; ++i) 
                result.A[i] = B[i];
        result.N = N;

        return result;
}

int main()
{
	int i;
	int N = 5;
	int K = 3;
	/* int A[] = {-1, 1500}; */
	/* int A[] = {1, 2, 3, 4}; */
	int A[] = {3, 8, 9, 7, 6};
	/* int A[] = {3, 8, 9, 7, 6, 24}; */

	struct Results result2;

	result2 = solution(A, N, K);

	printf ("A = [ ");
	for (i = 0; i < result2.N; ++i)
		printf ("%d ", result2.A[i]);
	printf ("]\n");
	printf ("N = %d\n", result2.N);


	/* printf ("20 \% 3 = %d", 3 % 20); */

	return 0;
}
