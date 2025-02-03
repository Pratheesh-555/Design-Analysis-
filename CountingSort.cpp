#include <iostream>
#include <fstream>
using namespace std;
long int count= 0;

void countSort(int A[], int n, int k){
    int *C = new int[k+1];
    int *B = new int[n];
    for(int i = 0; i <= k; i++){
        count++;
        C[i] = 0;
    }
    for(int j = 0; j < n; j++){
        count++;
        C[A[j]] = C[A[j]] + 1;
    }
    for(int i = 1; i <= k; i++){
        count++;
        C[i] = C[i-1] + C[i];
    }

    for(int j = n-1; j >= 0; j--){
        count++;
        B[C[A[j]] -1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    for(int i = 0; i < n; i++){
       A[i] = B[i];
    }
    delete[] C;
    delete[] B;
}

int max(int A[], int n){
    int largest = A[0];
    for(int i = 1; i < n; i++){
        if(largest < A[i])
            largest = A[i];
    }
    return largest;
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *A = new int[n];
    int *B = new int[n];

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    countSort(A,n,max(A,n));
    cout<< "Count: " << count<<endl;
    for(int i = 0; i < n; i++){
        cout << A[i]<<" ";
    }
    delete[] A;
    return 0;
}