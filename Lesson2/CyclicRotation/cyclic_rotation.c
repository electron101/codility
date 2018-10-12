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

struct Results solution(int A[], int N, int K) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    result.A = A;
    result.N = N;

    int i;

    if (K % N == 0 || K == 0)
	    return result;

    int all;
    for (i = 0; i < N; ++i) 
    {
	    if (A[i] == A[0]) 
	    {	
		    all++;
		    continue;
	    }
	    else
		    break;
    }
    if (all == N)
	    return result;



    return result;
}

int main()
{
	int i;
	int N = 5;
	int K;
	int A[] = {9, 7, 6, 3, 8};

	struct Results result2;

	result2 = solution(A, N, K);

	printf ("A = [ ");
	for (i = 0; i < result2.N; ++i)
		printf ("%d ", result2.A[i]);
	printf ("]\n");
	printf ("N = %d", result2.N);

	return 0;

}
