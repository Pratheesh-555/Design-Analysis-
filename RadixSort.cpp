    #include <iostream>
    using namespace std;

    long int count = 0;

    void countSort(int A[], int n, int exp) {
        int C[10] = {0};
        int *B = new int[n];

        for (int j = 0; j < n; j++) {
            count++;
            C[(A[j] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count++;
            C[i] += C[i - 1];
        }

        for (int j = n - 1; j >= 0; j--) {
            count++;
            B[C[(A[j] / exp) % 10] - 1] = A[j];
            C[(A[j] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++) {
            A[i] = B[i];
        }

        delete[] B;
    }

    void radixSort(int A[], int n) {
        int maxVal = A[0];

        for (int i = 1; i < n; i++) {
            if (A[i] > maxVal) {
                maxVal = A[i];
            }
        }

        for (int exp = 1; maxVal / exp > 0; exp *= 10) {
            countSort(A, n, exp);
        }

        for (int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
    }

    int main() {
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;
        int *A = new int[n];

        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        radixSort(A, n);
        cout << "\nCount: " << count << endl;

        delete[] A;
        return 0;
    }
        