/*

This is a demo task.

Write a function:

    int solution(int A[], int N);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [−1,000,000..1,000,000].


*/



//66% 

/* // функция сравнения элементов массива */
/* int compare(const void * x1, const void * x2)    */
/* { */
/* 	// если результат вычитания равен 0,  */
/* 	// то числа равны, < 0: x1 < x2; > 0: x1 > x2 */
/* 	return ( *(int*)x1 - *(int*)x2 );               */
/* } */
/*  */
/* int solution(int A[], int N) { */
/* 	// write your code in C99 (gcc 6.2.0) */
/* 	int i; */
/* 	int max; */
/* 	 */
/* 	qsort(A, N, sizeof(int), compare);      // сортируем массив чисел */
/* 	 */
/* 	max = A[N-1]; */
/*  */
/* 	if (max <= 0) */
/* 		return 1; */
/*  */
/* 	int j; */
/* 	int result; */
/* 	int counter = A[0]; */
/*  */
/* 	for (i = 0; i <= N; i++) */
/* 	{ */
/* 		if (counter == A[i]) */
/* 			continue; */
/* 		else  */
/* 			return counter; */
/* 		 */
/* 		counter++; */
/* 	} */
/*  */
/* 	return max+1; */
/* } */



//100%


int solution(int A[], int N) {
	// write your code in C99 (gcc 6.2.0)
	int i;
	int binary[1000000]={0};

	for (i = 0; i < N; ++i) 
		if (A[i] > 0)
			binary[A[i]] = 1;

	for (i = 1; i < 1000000; ++i) {
		if ( binary[i] == 1 )
			continue;
		else
			return i;
	}
}


