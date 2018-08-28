#include"Sort.h"

void swap(int, int);
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

//√∞≈›≈≈–Ú
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

//ºÚµ•—°‘Ò≈≈–Ú
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
//ºÚµ•≤Â»Î≈≈–Ú
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

//œ£∂˚≈≈–Ú/Àı–°‘ˆ¡ø≈≈–Ú
void shellSort(int* L, int len) {
	int increment=len;
	int temp,j;
	do {
		increment= increment / 3 + 1;
		for (int i = increment ; i < len-1; i++) {
			if (L[i] < L[i - increment]) {
				temp = L[i];
				for (j = i - increment; j > 0 && temp < L[j]; j -= increment) {
					L[j + increment] = L[j];
				}
				L[j + increment] = temp;
			}
		}

	} while (increment > 1);
}