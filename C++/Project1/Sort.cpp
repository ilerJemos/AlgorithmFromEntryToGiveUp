#include"Sort.h"

void swap(int*,int, int);
int max(int, int);
int min(int, int);

int max(int a, int b) {
	return (a + b + abs(a - b)) / 2;
}
int min(int a, int b) {
	return(a + b - abs(a - b)) / 2;
}
void swap(int* L,int a, int b) {
	int temp = L[a];
	L[a] = L[b];
	L[b] = temp;
}

//???????
void bubbleSort(int* L, int len) {
	for (int j = 0; j < len - 1; j++) {
		for (int i = 0; i < len - 1-j; i++) {
			if (L[i] > L[i + 1])
			{
				int temp = L[i];
				L[i] = L[i + 1];
				L[i + 1] = temp;
			}
		}
	}
}

//?????????
void sampleSelectSort(int *L, int len) {
	int minIndex;
	for (int i = 0; i < len - 1; i++) {
		minIndex = i;
		for (int j = i; j < len;j++) {
			if (L[j] < L[minIndex]) 
				minIndex = j;
		}
		swap(L,i, minIndex);
	}
}
//?????????
void sampleInsertSort(int*L, int len) {
	int preIndex, current;
	for (int i = 1; i < len; i++) {
		preIndex = i - 1;
		current = L[i];
		//while (preIndex >= 0 && L[preIndex] > current) {
		//	L[preIndex + 1] = L[preIndex];
		//	preIndex--;
		//}
		for (preIndex; L[preIndex] > current&&preIndex >= 0; preIndex--) {
			L[preIndex + 1] = L[preIndex];
		}
		L[preIndex + 1] = current;
	}
}
void insertSort(int* L, int len) {
		for (int i = 1; i < len; i++) {
			for (int j = i; L[j] < L[j - 1]&&j>0; j--)
				swap(L, j, j - 1);
		}
}

//???????/??��????????
//???????????
//nlogn**2
void shellSort(int* L, int len) {
	int increment = 1;
	while (increment < len / 3)			//?????????????
		increment = increment * 3 + 1;

	while (increment >= 1) {
		//?????????
		for (int i = increment; i < len; i++) {
			for (int j = i; j >= increment && L[j] < L[j - increment]; j -= increment)
				swap(L, j, j - increment);
		}
		increment = increment / 3;
	}
}

//?��????
//???��??? Divide and Conquer
//??��?��
//???
//nlogn
void merge(int* L,int left,int m,int right) {
	int tr[100];

	int i, j,k;
	for (k = 0, i = left, j = m + 1; i <= m&&j <= right;k++) {
		if (L[i] <= L[j]) {
			tr[k] = L[i];
			i++;
		}
		else {
			tr[k] = L[j];
			j++;
		}
	}
	//k++;
	while (i != m+1) {
		tr[k] = L[i];
		i++;
		k++;
	}
	while (j != right+1) {
		tr[k] = L[j];
		j++;
		k++;
	}
	for (int i = 0; i <= right - left; i++)
		L[left+i] = tr[i];
}
void MSort(int* L,int left,int right) {
	if (left == right)
		return;
	int m = (left + right) / 2;
	MSort(L, left, m);
	MSort(L, m + 1, right);
	merge(L, left, m, right);
}
void mergeSort(int* L, int len) {
	MSort(L,0,len-1);
}

//????????
//nlogn
int partition(int* L,int left,int right) {
	int key = L[left];
	while (left < right) {
		while (left<right&&L[right]>=key)
			right--;
		swap(L, left, right);
		while (left < right&&L[left] <= key)
			left++;
		swap(L, left, right);
	}
	return left;
}
void qSort(int* L,int left,int right) {
	int pivot;
	if (left < right) {
		pivot = partition(L,left,right);
		qSort(L,left,pivot-1);
		qSort(L, pivot + 1,right);
	}
}
void quickSort(int* L, int len) {
	qSort(L, 0, len - 1);
}

//??????
void heapAdjust(int* L,int s,int m) {
	int temp;
	temp = L[s];
	for (int j = s * 2; j <= m; j *= 2) {
		if (j < m&&L[j] < L[j + 1])
			j++;
		if (temp >= L[j])
			break;
		L[s] = L[j];
		s = j;
	}
	L[s] = temp;
}
void heapAjd(int* L, int m,int len) {
	int left = 2 * m +1;
	int right = 2 * m + 2;
	int large = m;
	if (left<len&&L[left]>L[large])
		large = left;
	if (right<len&&L[right]>L[large])
		large = right;
	if (large != m) {
		swap(L, m, large);
		heapAjd(L, large, len);
	}
}
void heapSort(int* L,int len) {
	int i;  
	for (i = len / 2; i >= 0; i--)
		heapAjd(L, i, len-1);
		//heapAdjust(L, i, len - 1);
	for (i = len - 1; i >= 0; i--) {
		swap(L, 0, i);
		//heapAdjust(L, 0, i - 1);
		heapAjd(L, i, --len);
	}
}