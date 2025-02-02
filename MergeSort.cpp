//MergeSort
#include <iostream>
#include <fstream>
using namespace std;

void merge(int A[], int p, int q, int r, int &count){
	int nL,nR;
	nL = q - p + 1;
	nR = r - q;
	int *L = new int[nL];
	int *R = new int[nR];
	for(int i = 0; i < nL; i++)
		L[i] = A[p+i];
	for(int i = 0; i < nR; i++)
		R[i] = A[q+i+1];
	int i = 0;
	int j = 0;
	int k = p;
	while(i< nL && j < nR){
		count++;
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	
	while(i < nL){
		count++;
		A[k] = L[i];
		i++;
		k++;
	}
	while(j < nR){
		count++;
		A[k] = R[j];
		j++;
		k++;
	}
	
}

void mergeSort(int A[], int p, int r, int &count){
	if(p < r){
		int q = (p + r )/ 2;
		mergeSort(A, p , q,count);
		mergeSort(A, q+1, r, count);
		merge(A, p , q, r, count);
	}
}

int main(){ 
	int n;
	int count=0;
	int *A = new int[n];
	cout<<"Enter the no of elements: " ;
	cin>>n;
	
	ifstream fin1("file_random.txt");
	for(int i = 0; i < n; i++)
		fin1>>A[i];
	mergeSort(A,0,n-1,count);
	cout<<"The no of times the operations excecuted for random file was: "<<count<<endl;
	
	count = 0;
	ifstream fin2("file_ascending.txt");
	for(int i =0; i < n; i++)
		fin2>>A[i];
	mergeSort(A,0,n-1,count);
	cout<<"The no of times the operations excecuted for ascending file was: "<<count<<endl;
	
	count = 0;
	ifstream fin3("file_descending.txt");
	for(int i =1; i < n; i++)
		fin3>>A[i];
	mergeSort(A,0,n-1,count);
	cout<<"The no of times the operations excecuted for descending file was: "<<count<<endl;
	
	count = 0;
	ifstream fin4("file_equal.txt");
	for(int i =0; i < n; i++)
		fin4>>A[i];
	mergeSort(A,0,n-1,count);
	cout<<"The no of times the operations excecuted for equal file was: "<<count<<endl;


	delete[] A;
return 0;
}

