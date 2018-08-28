#include"head.h"
#include"Sort.h"

void printL(int*, int);


int main() {
	int L[] = {10, 3, 4, 5, 6, 2, 6, 3, 2, 6, 1,8,7};
	int len = sizeof(L) / sizeof(L[0]);
	cout << "the length of the array is " << len << endl;
	cout << "Right Sorted List: "<<endl;
	cout << "1,2,2,3,3,4,5,6,6,6,7,8,10" << endl;

	//bubbleSort(L, len);
	//cout << "bubbleSort:" << endl;
	//printL(L, len);

	//sampleSelectSort(L, len);
	//cout << "sampleSelectSort:" << endl;
	//printL(L, len);

	//sampleInsertSort(L,len);
	//cout << "sampleInsertSort" << endl;
	//printL(L, len);
	
	shellSort(L, len);
	cout << "shellSort" << endl;
	printL(L, len);
	return 0;
}
void printL(int* L, int len) {
	for (int i = 0; i < len; i++)
		cout << L[i] << ",";
	cout << endl;
}