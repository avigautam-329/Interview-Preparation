#include<iostream>
#include<vector>

using namespace std;

void dfs(int **edges, int noOfNodes, int startIdx, int *visited){
	cout << startIdx << " ";
	
	// Once we have visited this node we will mark it as visited.
	// If we dont mark this as visited, then we will get stuck in an infinite loop.
	visited[startIdx] = 1;
	
	
	// Now for the current node/vertex, we will check what all other nodes is it connected to.
	for(int i = 0; i < noOfNodes; i++){
		// We use this condition idk y.
		if(i == startIdx){
			continue;
		}
		
		if(edges[startIdx][i]){
			if(!visited[i]){
				dfs(edges, noOfNodes, i , visited);
			}
		}
	}
	return;
}

int main(){
	
	// Take the the number of vertices and edges.
	int noOfNodes;
	int noOfEdges;
	cin >> noOfNodes >> noOfEdges;
	
	// Now before taking the input of the edges we will make an adjacency matrix.
	// We will initialize the matrix with 0 by default.
	int **edges = new int*[noOfNodes];
	for(int i = 0; i < noOfNodes; i++){
		edges[i] = new int[noOfNodes];
		for(int j = 0; j < noOfNodes; j++){
			edges[i][j] = 0;
		}
	}
	
	// Now we will take the input for the edges.
	for(int i = 0; i < noOfEdges; i++){
		int srcNode, dstNode;
		cin >> srcNode >> dstNode;
		
		// As this is an undirected graph, we can consider both direction for 2 connected vertices.
		edges[srcNode][dstNode] = 1;
		edges[dstNode][srcNode] = 1;
	}
	
	// Now we will make an array which will keep track of the nodes that we have visited.
	int *visited = new int[noOfNodes];
	for(int i = 0; i < noOfNodes; i++){
		visited[i] = 0;
	}
	
	// Now we will call the dfs function to traverse the graph.
	int startingIdx = 0;
	dfs(edges, noOfNodes, startingIdx, visited);
	
	// Now to delete we need to do it in a very carefull manner as we have done before.
	delete [] visited;
	for(int i = 0; i < noOfNodes; i++){
		delete [] edges[i];
	}
	delete [] edges;
	
	return 0;
}
