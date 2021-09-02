#include<iostream>
#include<climits>
using namespace std;

int findMinVertexIdx(int *weights, bool *visited, int v){
	
	// We will take an arbritrary value for minVertexIdx.
	int minVertexIdx = -1;
	
	for(int i = 0; i < v; i++){
		
		// If the first condition of the OR statement is correct, then the second or remaining conditions will not be checked.
		if(!visited[i] && (minVertexIdx == -1 || weights[i] < weights[minVertexIdx])){
			minVertexIdx = i;
		}
	}
	
	return minVertexIdx;
}


void MSTUsingPrism(int **graph , int v){
	// The first step is to create the 3 arrays that we require.
	int *weights = new int[v];
	int *parent = new int[v];
	bool *visited = new bool[v];
	for(int i = 0; i < v; i++){
		visited[i] = false;
		weights[i] = INT_MAX; // positive infinity.
	}
	
	// Now as our arbritrary source node is 0, soo for 0 , we need to change the weight and parent value.
	parent[0] = -1;
	weights[0] = 0;
	
	// Now we need to find the edges of the MST by visiting every vertex of our graph.
	for(int i = 0; i < v; i++){
		
		// The fisrt step is to find the minimum weighted vertex which has not been visited before.
		// We will write a function which returns the index of the min vertex.
		int minVertexIdx = findMinVertexIdx(weights, visited, v);
		visited[minVertexIdx] = true;
		
		// Now for the minVertex, we will basically check its neighbor, using the adjacency matrix.
		for(int j = 0; j < v; j++){
			
			// If an edge exists between the minVertex and it's neighbors:
			if(graph[minVertexIdx][j] && !visited[j]){
				
				// We shall check if a better option exists or not.
				if(graph[minVertexIdx][j] < weights[j]){
					weights[j] = graph[minVertexIdx][j];
					parent[j] = minVertexIdx;
				}
			}
		}
	}
	
	// The parent list will contain the edges of our MST.
	// We will start from vertex 1, because vertex 0 has not parent.
	cout << endl;
	cout << " Our minimum spanning tree is : " << endl;
	for(int i = 1; i < v; i++){
		if(i < parent[i]){
			cout << i << " <--> " << parent[i] << endl;
		}else{
			cout << parent[i] << " <--> " << i << endl;
		}
	}
	
	return;
}

int main(){
	int v , e;
	cin >> v >> e;
	
	// For the prism's algorithm, we will use an adjacency matrix.
	int **graph = new int*[v];
	for(int i = 0; i < v; i++){
		graph[i] = new int[v];
		for(int j = 0; j < v; j++){
			graph[i][j] = 0;
		}
	}
	
	// Now we will take int the input for the edges and there weights.
	for(int i = 0; i < e; i++){
		int srcNode, dstNode, weight;
		cin >> srcNode >> dstNode >> weight;
		
		graph[srcNode][dstNode] = weight;
		graph[dstNode][srcNode] = weight;
		
	}
	
	// Now as we have our the graph ready, we will call the prism function.
	MSTUsingPrism(graph , v);
	
	return 0;
}
