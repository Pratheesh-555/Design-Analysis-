#include <iostream>
#include <fstream>
using namespace std;

class MaxSubArray{
		int low,high,sum;
	public :
		MaxSubArray(){
			sum = low = high = 0;	
		}

		MaxSubArray(int low, int high, int sum){
			this->low = low;
			this->high = high;
			this->sum = sum;
		}
		
		MaxSubArray maxSubArray(int A[], int low, int high, int &count){
			if(low == high)
				return MaxSubArray(low, high, A[low]);
			else{
				int mid = (low + high) / 2;
				MaxSubArray L = maxSubArray(A, low, mid, count);
				MaxSubArray R = maxSubArray(A, mid+1, high, count);	
				MaxSubArray C = maxCrossSubArray(A, low, mid, high, count);
				
				if(L.sum >= R.sum && L.sum >= C.sum)
					return L;
				else if(L.sum <= R.sum && R.sum >= C.sum)
					return R;
				else
					return C;
			}	
		}

		MaxSubArray maxCrossSubArray(int A[], int low, int mid, int high, int &count){
			int left_sum = -99999;
			int right_sum = -99999;
			int sum = 0;
			int max_left, max_right;
			for(int i = mid; i >= low; i--){
				count++;
				sum = sum + A[i];
				if(sum > left_sum){
					left_sum = sum;
					max_left = i;
				}
			}
			sum = 0;
			for(int i = mid+1; i<=high; i++){
				count++;	
				sum = sum + A[i];
				if(sum > right_sum){
					right_sum = sum;
					max_right = i;
				}
			}
			return MaxSubArray(max_left, max_right, left_sum + right_sum);
		}	
		void display(){
			cout<<low<<"\t"<<high<<"\t"<<sum;
		}

};


int main(){
	
	int n;
	int count = 0;
	cout<<"Enter the number of element : " ;
	cin>>n;
	int *A = new int[n];
	ifstream fin("inputMaxSubArray.txt");
	for(int i = 0; i < n; i++)
		fin>>A[i];	
	MaxSubArray ms;
	ms = ms.maxSubArray(A, 0, n-1, count);
	ms.display();
	delete[] A;
	return 0;
}	
