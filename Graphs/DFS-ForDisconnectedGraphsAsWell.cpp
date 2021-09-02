#include<iostream>
#include<vector>

using namespace std;

void dfsHelper(int **edges, int noOfVertices, int startIdx, bool *visited){
	cout << startIdx << " ";
	visited[startIdx] = true;
	
	for(int i = 0; i < noOfVertices; i++){
		if(i == startIdx){
			continue;
		}
		
		if(edges[startIdx][i] == 1){
			if(!visited[i]){
				dfsHelper(edges, noOfVertices, i , visited);
			}
		}
	}
	
	return;
}

void dfs(int **edges, int noOfVertices){
	bool *visited = new bool[noOfVertices];
	for(int i = 0; i < noOfVertices; i++){
		visited[i] = false;
	}
	
	for(int i = 0; i < noOfVertices; i++){
		if(!visited[i]){
			dfsHelper(edges, noOfVertices, i , visited);
		}
	}
}

int main(){
	int noOfVertices, noOfEdges;
	cin >> noOfVertices >> noOfEdges;
	
	int **edges = new int*[noOfVertices];
	for(int i = 0; i < noOfVertices; i++){
		edges[i]=  new int[noOfVertices];
		for(int j = 0; j < noOfVertices; j++){
			edges[i][j] = 0;
		}
	}
	
	for(int i = 0; i < noOfEdges; i++){
		int srcNode, dstNode;
		cin >> srcNode >> dstNode;
		edges[srcNode][dstNode] = 1;
		edges[dstNode][srcNode] = 1;
	}
	
	// We will break up this process into two functions:
	//		1. the main function which will call on each node and check if it is visited or not. 
	//		2. If not visited then we will call the DFS helper Function which will actually print all the vertices.
	dfs(edges, noOfVertices);
	
	return 0;
}
