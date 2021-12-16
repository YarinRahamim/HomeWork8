#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

void swap(int *num1, int *num2);
void print_array(int* ar, int n);
int *lucasSeries(int n);
int *isEvenOddArray(int *arr, int n, int isEven, int *psize);
int *vectorMulti(int *A, int *B);
void updateArrayToMulti(int *arr, int n);
int *valueNotInArray(int *arr, int n, int *newSize);
int findFrequentlyOccurringValue(int *arr, int n);
int maxSumOccurrences(int *arr, int n);
int findGreatestMissing(int *arr, int n);
void rotateRight(int *arr, int n, int amount);
int *nextBiggestArray(int *arr, int n);

void print_array(int* ar, int n)
{
	int i;
	printf("The elements of array are: ");
	for (i = 0; i < n - 1; i++)
		printf("%d ", ar[i]);
	printf("%d\n", ar[n - 1]);
}


/* ***1***
void main()
{
	int *arr,i;
	int n = 9;
	arr = lucasSeries(n);
	printf("The array is: \n");
	for (i = 0; i <= n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
}

int *lucasSeries(int n)
{
	int i;
	int *lucasArr = (int*)malloc((n + 1) * sizeof(int));
	assert(lucasArr);
	lucasArr[0] = 2;
	if (n >= 1)
		lucasArr[1] = 1;
	for (i = 2; i <= n; i++)
	{
		lucasArr[i] = lucasArr[i - 1] + lucasArr[i - 2];
	}
	return lucasArr;
}*/

/* ***2***
void main()
{
	int i,isEven, n, *arrN, *psize;
	psize = 0;
	n = 5;
	isEven = 1;
	int arr[] = { 1,8,3,6,11 };
	arrN = isEvenOddArray(arr, n, isEven, &psize);
	for (i = 0; i < psize; i++)
	{
		printf("%d ", arrN[i]);
	}
	printf("And the pointer of array is: %d", psize);
	free(arrN);
}


int *isEvenOddArray(int *arr, int n, int isEven, int *pNewSize)
{
	int *newArr = (int*)malloc(n * sizeof(int));
	assert(newArr);
	int i,count = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			if (isEven == 1)
			{
				newArr[count++] = arr[i]; // even array! 
			}
		}
		else
		{
			if (isEven != 1)
			{
				newArr[count++] = arr[i]; // odd array!
			}
		}
	}
	newArr = (int *)realloc(newArr, count * sizeof(int));
	assert(newArr);
	*pNewSize = count;
	return newArr;
}*/

/* ***3***
void main()
{
	int *arr,i;
	int A[] = { 1,2,1 };
	int B[] = { 3,3,3 };
	arr = vectorMulti(A, B);
	for (i = 0; i < 3; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
}


int *vectorMulti(int *A, int *B)
{
	int *C = (int*)malloc(3 * sizeof(int));
	assert(C);
	C[0] = (A[1] * B[2] - A[2] * B[1]);
	C[1] = (A[2] * B[0] - A[0] * B[2]);
	C[2] = (A[0] * B[1] - A[1] * B[0]);
	return C;
}*/

/* ***4***
void main()
{
	int arr[] = { 1,2,2,4,1 };
	int n = 5; //sizeof(arr) / sizeof(arr[0]);
	updateArrayToMulti(&arr, n);
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{	
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[n - 1]);
}

void updateArrayToMulti(int *arr, int n)
{
	int i;
	int *LR, *RL;
	LR = (int*)malloc(n * sizeof(int));
	RL = (int*)malloc(n * sizeof(int));

	LR[0] = arr[0];
	for (i = 1; i < n; i++)
		LR[i] = arr[i] * LR[i - 1];

	RL[n - 1] = arr[n - 1];
	for (i = n - 2; i >= 0; i--)
		RL[i] = arr[i] * RL[i + 1];

	arr[0] = RL[1];
	arr[n - 1] = LR[n - 2];
	for (i = 1; i < n - 1; i++)
		arr[i] = LR[i - 1] * RL[i + 1];

	free(LR);
	free(RL);
}*/

/* ***5***
void main()
{
	int arr[] = { 0,1,1,0,3,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int newSize = 0;
	int newArr = valueNotInArray(arr, n, &newSize);
	print_array(newArr, newSize);
}
int *valueNotInArray(int *arr, int n, int *newSize)
{
	int i;
	int *count = (int*)calloc(n + 1, sizeof(int));
	int *newArr = (int*)malloc((n + 1) * sizeof(int));

	for (i = 0; i < n; i++)
		count[arr[i]] = 1;
	for (i = 0, *newSize = 0; i < n + 1; i++)
		if (!count[i])
			newArr[(*newSize)++] = i;
	newArr = (int*)realloc(newArr, (*newSize) * sizeof(int));

	free(count);
	return newArr;
}

void print_array(int* ar, int n)
{
	int i;
	printf("The elements of array are: ");
	for (i = 0; i < n - 1; i++)
		printf("%d ", ar[i]);
	printf("%d\n", ar[n - 1]);
}*/

/* ***6***
void main()
{
	int arr[] = { 1,1,3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int ans = findFrequentlyOccurringValue(arr,n);
	printf("%d\n", ans);
}

int findFrequentlyOccurringValue(int *arr, int n)
{
	int i;
	int *count = (int*)calloc(n + 1, sizeof(int));

	for (i = 0; i < n; i++)
		count[arr[i]]++;
	for (i = 0; i < n + 1; i++)
		if (count[i] > n / 2) {
			free(count);
			return i;
		}

	free(count);
	return -1;
}*/

/* ***7***
void main()
{
	int arr[] = { 1,1,1,2};
	int n = sizeof(arr) / sizeof(arr[0]);
	int ans = maxSumOccurrences(arr, n);
	printf("%d\n", ans);
}

int maxSumOccurrences(int *arr, int n)
{
	int i, max = 0;
	int *count = (int*)calloc(n + 1, sizeof(int));

	for (i = 0; i < n; i++)
		count[arr[i]]++;
	for (i = 1; i < n + 1; i++)
		if (count[i] * i >= count[max] * max)
			max = i;


	free(count);
	return max;
}*/

/* ***8***
void main()
{
	int A[] = { 7,4,5,6,1,4,0 };
	int n = sizeof(A) / sizeof(A[0]);
	int ans = findGreatestMissing(A, n);
	printf("%d\n", ans);
}
int findGreatestMissing(int *arr, int n) // ניצור מערך חדש בגודל 8, נאפס אותו. כל איבר שמופיע נעלה את המערך החדש ל-1. כאשר נעבור על איברי המערך מלמעלה למטה כאשר נגיע לאינדקס שלא מופיע(שווה ל-0) נחזיר את המספר
{
	int i;
	int *count = (int*)calloc(n + 1, sizeof(int)); 

	for (i = 0; i < n; i++)
		count[arr[i]]++;
	for (i = n; i >= 0; i--)
		if (count[i] == 0) {
			free(count);
			return i;
		}
	return -1;	
}*/

/* ***9***
void main()
{
	int arr[] = { 1,6,2,3,4,2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int amount = 3;
	rotateRight(arr, n, amount);
	print_array(arr, n);
}

void rotateRight(int *arr, int n, int amount)
{
	int i;
	int *temp = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		temp[(i + amount) % n] = arr[i];
	for (i = 0; i < n; i++)
		arr[i] = temp[i];
	free(temp);
}*/

/* ***10***
void main()
{
	int arr[] = { 6,3,9,10,11,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int *newArr = nextBiggestArray(arr, n);
	print_array(newArr, n);
}

int *nextBiggestArray(int *arr, int n)
{
	int i, j;
	int *newArr = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		newArr[i] = -1;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (arr[j] > arr[i]) {
				newArr[i] = arr[j];
				break;
			}
		}
	}
	return newArr;
}*/
