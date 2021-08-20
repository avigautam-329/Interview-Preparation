#include<iostream>
#include<vector>

using namespace std;

class PriorityQueue{
	vector<int> heap;
	
	public:	
		// Now we have to write 5 functions, soo lets get the easiest out pf them out of the way.
		bool isEmpty(){
			return heap.size() == 0;
		}
		
		int getSize(){
			return heap.size();
		}
		
		int getMin(){
			if(this->isEmpty()){
				return INT_MAX;
			}
			return heap[0];
		}
		
		
		void insert(int val){
			heap.push_back(val);
			
			// Now we will up heapify after insertion of the elements.
			int childIndex = heap.size() - 1;
			while(childIndex > 0){
				int parentIndex = (childIndex - 1)/ 2;
				if(heap[childIndex] < heap[parentIndex]){
					swap(heap[parentIndex] , heap[childIndex]);
				}else{
					break;
				}
				childIndex = parentIndex;
			}
		}
		
		int removeMin(){
			int ans = heap[0];
			
			heap[0] = heap[heap.size() - 1];
			heap[heap.size() - 1] = ans;
			
			heap.pop_back();
			
			// Now we have to down heapify.
			int parentIdx = 0;
			int leftChildIdx = 2 * parentIdx + 1;
			int rightChildIdx = 2 * parentIdx + 2;
			int minIdx = parentIdx;
			
			while(leftChildIdx < heap.size()){
				
				// First we compare with the left child.
				if(heap[minIdx] > heap[leftChildIdx]){
					minIdx = leftChildIdx;
				}
				
				// Before we compare with the right child.
				// We need to make sure that rightCHildIdx is not out of bounds.
				if(rightChildIdx < heap.size() && heap[minIdx] > heap[rightChildIdx]){
					minIdx = rightChildIdx;
				}
				
				// Oh yeah baby! That's the spot.
				if(minIdx == parentIdx){
					break;
				}
				
				// Now its time to swap.
				swap(heap[parentIdx] , heap[minIdx]);
				
				// Now we need to update all the values.
				parentIdx = minIdx;
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
		cout << p.removeMin() << " ";
	}
	cout << endl;
	return 0;
}
