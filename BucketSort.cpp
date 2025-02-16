#include <iostream>

using namespace std;

long int count = 0;

class BucketSort {
private:
    class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    class Bucket {
    public:
        Node* head;

        Bucket() {
            head = nullptr;
        }

        void insertOrder(int value) {
            Node* newNode = new Node(value);

            if (!head || value < head->data) {
                newNode->next = head;
                head = newNode;
                return;
            }

            Node* current = head;
            while (current->next && current->next->data < value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        void getSortedValues(int A[], int& index) {
            Node* current = head;
            while (current) {
                A[index++] = current->data;
                current = current->next;
            }
        }
    };

public:
    void bucketSort(int A[], int n) {
        count++; // Counting function call

        if (n <= 0) return;

        int maxValue = A[0];
        for (int i = 1; i < n; i++) {
            if (A[i] > maxValue) {
                maxValue = A[i];
            }
        }
        count++; // Counting max finding loop

        int bucketCount = 10;
        Bucket* buckets = new Bucket[bucketCount];

        for (int i = 0; i < n; i++) {
            int index = (A[i] * bucketCount) / (maxValue + 1);
            buckets[index].insertOrder(A[i]);
        }
        count++; // Counting bucket insertion loop

        int index = 0;
        for (int i = 0; i < bucketCount; i++) {
            buckets[i].getSortedValues(A, index);
        }
        count++; // Counting sorting retrieval loop

        delete[] buckets;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* A = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    BucketSort BS;
    BS.bucketSort(A, n);

    cout << "Sorted elements: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Count: " << count << endl;

    delete[] A;
    return 0;
}
