#include<iostream>
#include<vector>
using namespace std;

// Implemention using Max Heap.
class PriorityQueue{
	vector<int> heap;
	
	public:
		
		bool isEmpty(){
			return heap.size() == 0;
		}
		
		int getSize(){
			return heap.size();
		}
		
		int getMin(){
			if(this->isEmpty()){
				return INT_MIN;
			}
			return heap[0];
		}
		
		void insert(int val){
			heap.push_back(val);
			
			int childIdx = heap.size() - 1;
			while(childIdx > 0){
				int parentIdx = (childIdx - 1)/2;
				if(heap[childIdx] > heap[parentIdx]){
					swap(heap[childIdx] , heap[parentIdx]);
				}else{
					break;
				}
				
				childIdx = parentIdx;
			}
		}
		
		int removeMax(){
			int ans = heap[0];
			
			heap[0] = heap[heap.size() - 1];
			heap.pop_back();
			
			int parentIdx = 0;
			int leftChildIdx = 2 * parentIdx + 1;
			int rightChildIdx = 2 * parentIdx + 2;
			int maxIdx = parentIdx;
			
			while(leftChildIdx < heap.size()){
				if(heap[leftChildIdx] > heap[maxIdx]){
					maxIdx = leftChildIdx;
				}
				
				if(rightChildIdx < heap.size() && heap[rightChildIdx] > heap[maxIdx]){
					maxIdx = rightChildIdx;
				}
				
				if(maxIdx == parentIdx){
					break;
				}
				
				swap(heap[maxIdx] , heap[parentIdx]);
				
				parentIdx = maxIdx;
				leftChildIdx = 2 * parentIdx + 1;
				rightChildIdx = 2 * parentIdx + 2;
			}
			
			return ans;
		}
};

int main(){

	PriorityQueue p;
	
	p.insert(12);
	p.insert(6);
	p.insert(5);
	p.insert(100);
	p.insert(1);
	p.insert(9);
	p.insert(0);
	p.insert(14);
	
	while(!p.isEmpty()){
		cout << p.removeMax() << " ";
	}
	cout << endl;
	return 0;	
	
	return 0;	
}
