#include <iostream>
#include <fstream>
using namespace std;

int heapSize;

int LEFT(int i) {
    return (2 * i) + 1;
}

int RIGHT(int i) {
    return (2 * i) + 2;
}

void maxHeapify(int A[], int i, int &count) {
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest = i;

    count++;
    if (l <= heapSize && A[l] > A[i])
        largest = l;

    count++;
    if (r <= heapSize && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(A, largest, count);
    }
}

void buildMaxHeap(int A[], int n, int &count) {
    heapSize = n - 1;
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(A, i, count);
    }
}

void heapSort(int A[], int n, int &count) {
    buildMaxHeap(A, n, count);
    for (int i = n - 1; i >= 1; i--) {
        swap(A[0], A[i]);
        heapSize--;
        maxHeapify(A, 0, count);
    }
}

int main() {
    int n, count = 0;

    cout << "Enter the number of elements: ";
    cin >> n;

    int *A = new int[n];

    ifstream fin1("file_random.txt");
	for(int i = 0; i < n; i++)
		fin1>>A[i];
	heapSort(A,n,count);
	cout<<"The no of times the operations excecuted for random file was: "<<count<<endl;
	
	count = 0;
	ifstream fin2("file_ascending.txt");
	for(int i =0; i < n; i++)
		fin2>>A[i];
	heapSort(A,n,count);
	cout<<"The no of times the operations excecuted for ascending file was: "<<count<<endl;
	
	count = 0;
	ifstream fin3("file_descending.txt");
	for(int i =1; i < n; i++)
		fin3>>A[i];
	heapSort(A,n,count);
	cout<<"The no of times the operations excecuted for descending file was: "<<count<<endl;
	
	count = 0;
	ifstream fin4("file_equal.txt");
	for(int i =0; i < n; i++)
		fin4>>A[i];
	heapSort(A,n,count);
    
	cout<<"The no of times the operations excecuted for equal file was: "<<count<<endl;
    delete[] A;
    return 0;
}