#include <iostream>
#include <fstream>
using namespace std;

class MaxSubArrayBF{
		int l,h,sum,max_sum;
	public :	
		MaxSubArrayBF(){}
		MaxSubArrayBF(int l, int h, int sum){
			this->l = l;
			this->h = h;
			this->sum = sum;
		}

		MaxSubArrayBF maxSubArray(int A[], int n, int&count){
			max_sum = -99999;
			for(int i = 0; i < n; i++){
				sum = 0;
				for(int j = i; j < n; j++){
					count++;			
					sum = sum + A[j];
					if(sum > max_sum){
						max_sum = sum;
						l = i;
						h = j;
					}
				}	
			}
			return MaxSubArrayBF(l,h,max_sum);
		}
		
        void display(){
            cout<<l<<"\t"<<h<<"\t"<<sum;
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
        MaxSubArrayBF ms;
        ms = ms.maxSubArray(A,n, count);
        ms.display();
        delete[] A;
        return 0;	
}