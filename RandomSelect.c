#include<stdio.h>
#include<stdlib.h>

//first, last, i and j are all indexs.
int partition(int *p, int first, int last);
void exchange(int *p, int i, int j);
int randomSelect(int *p, int n, int first, int last);
int randomSelect(int *p, int n, int length);

int main()
{
	int p[] = { 16, 0, 6, 1, 3, 8, 4, 7, 5 };
	int length = sizeof(p) / sizeof(p[0]);
	printf("answer: %d\n", randomSelect(p, length, length));
	return 0;
}

//Partition assumes first is less than last, which means the size 
//of array is greater than 1. 
//Partition didn't handle the case that the size of input array is 
//1, because randomSort will do that.
//Each partition roughly sorts the array based on the value of pivot.
//It will return the index of pivot (after the array being sorted).
int partition(int *p, int first, int last)
{
	int i = first - 1;
	int pivot = p[last];
	for (int j = first; j < last ; j++)
	{
		if (p[j] <= pivot)
		{
			i++;
			exchange(p, i, j);
		}
	}
	exchange(p, i + 1, last);
	return i + 1;
}

void exchange(int *p, int i, int j)
{
	int temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

int randomSelect(int *p, int n, int first, int last)
{
	//Base case for recursive algorithms.
	//If the size of input array is less than 2, don't
	//need to call partition.
	if (first >= last) return p[first];
	//Partition the array, get the index of pivot.
	int t = partition(p, first, last);
	if (t == n) return p[t];
	else if (t < n) return randomSelect(p, n, t + 1, last);
	else return randomSelect(p, n, first, t - 1);
}

int randomSelect(int *p, int n, int length)
{
	if (n < 1) return -1;
	return randomSelect(p, n - 1, 0, length - 1);
}