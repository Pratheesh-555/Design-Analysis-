#include <iostream>
#include <fstream>
using namespace std;

int partition(int A[], int p, int r, int &count){
    int x = A[r];
    int i = p - 1;
    for(int j = p; j < r-1; j++){
        count++;
        if(A[j] <= x){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
   
}

void quickSort(int A[], int p, int r,int &count){
    if(p < r){
        int q = partition(A,p,r,count);
        quickSort(A,p,q-1,count);
        quickSort(A,q+1,r,count);
    }
}

int main(){
    int n, count = 0;

    cout << "Enter the number of elements: ";
    cin >> n;

    int *A = new int[n];

    ifstream fin1("file_random.txt");
	for(int i = 0; i < n; i++)
		fin1>>A[i];
	quickSort(A,0,n,count);
	cout<<"The no of times the operations excecuted for random file was: "<<count<<endl;
	
	count = 0;
	ifstream fin2("file_ascending.txt");
	for(int i =0; i < n; i++)
		fin2>>A[i];
	quickSort(A,0,n,count);
	cout<<"The no of times the operations excecuted for ascending file was: "<<count<<endl;
	
	count = 0;
	ifstream fin3("file_descending.txt");
	for(int i =1; i < n; i++)
		fin3>>A[i];
	quickSort(A,0,n,count);
	cout<<"The no of times the operations excecuted for descending file was: "<<count<<endl;
	
	count = 0;
	ifstream fin4("file_equal.txt");
	for(int i =0; i < n; i++)
		fin4>>A[i];
	quickSort(A,0,n,count);
    
	cout<<"The no of times the operations excecuted for equal file was: "<<count<<endl;
    delete[] A;
    return 0;

}