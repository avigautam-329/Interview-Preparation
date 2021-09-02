#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Edge{
	public:
		int srcNode;
		int dstNode;
		int weight;
		Edge(){
			this->srcNode = 0;
			this->dstNode = 0;
			this->weight = INT_MAX;
		}
};

int findParent(int *parent, int node){
	if(parent[node] == node){
		return parent[node];
	}
	
	return findParent(parent, parent[node]);
}


// In order to sort the array in ascending order, we need to create our own comparator.
bool comparator(Edge e1, Edge e2){
	return e1.weight < e2.weight;
}


Edge* MSTUsingKruskal(Edge *input, int v, int e){
	// The first step is to sort the input array according to the weights.
	sort(input , input + e , comparator);
	
	// Now we have the sorted array soo we can create the variable to use them for the Kruskal's algorithm.
	
	// This is the variable to keep a count of the total number of edges in out MST.
	int count = 0;
	
	// This is the variable to iterate over our input array.
	int i = 0;
	
	// We need to create a parent's array to be used in out union find algorithm.
	int *parent = new int[v];
	for(int i = 0; i < v; i++){
		
		// In the start we consider all the nodes as disconnected and their own parents.
		parent[i] = i;
	}
	
	Edge *output = new Edge[v - 1];
	
	while(count != v - 1){
		Edge currEdge = input[i];
		
		int srcParent = findParent(parent,currEdge.srcNode);
		int dstParent = findParent(parent,currEdge.dstNode);
		
		if(srcParent != dstParent){
			// If in this block, it means the current edge is safe to add to the MST.
			output[count++] = currEdge;
			
			// Now we also need to update the parent for both the nodes in the parent array.
			parent[srcParent] = dstParent;
			// OR parent[dstNode] = srcNode, both ways are ok, there is no hard or fast rule for this step.
		}
		
		i++;
	}
	return output;
}

int main(){
	int v , e;
	cin >> v >> e;
	
	// For the implementation of Kruskal's Algorithm, we will basically won't need an adjacency matrix.
	// We will create a new class to store the edges and their respective edges.
	Edge *input = new Edge[e];
	for(int i = 0; i < e; i++){
		int srcNode, dstNode, weight;
		cin >> srcNode >> dstNode >> weight;
		input[i].srcNode = srcNode;
		input[i].dstNode = dstNode;
		input[i].weight = weight;
	}
	
	// Now since the input process is complete, we can go on to use our kruskal's algorithm.
	Edge *output = MSTUsingKruskal(input , v, e);
	
	
	// After this , we can basically print the minimum spanning tree we have produced.
	cout << " Our MST would look like : " << endl;
	for(int i = 0; i < v-1; i++){
		cout << output[i].srcNode << " <--> " << output[i].dstNode << " : " <<  output[i].weight << endl;
	}
	return 0;
}
