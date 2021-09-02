#include<iostream>
#include<queue>
using namespace std;

void printBFS(int **edges, int noOfVertices, int startIdx){
	bool *visited = new bool[noOfVertices];
	for(int i = 0; i < noOfVertices; i++){
		visited[i] = false;
	}
	
	queue<int> pendingVertices;
	pendingVertices.push(startIdx);
	visited[startIdx] = true;
	
	while(!pendingVertices.empty()){
		int currVertex = pendingVertices.front();
		pendingVertices.pop();
		
		cout << currVertex << " ";
		for(int i = 0; i < noOfVertices; i++){
			if(i == currVertex){
				continue;
			}
			
			if(edges[currVertex][i] == 1){
				if(!visited[i]){
					pendingVertices.push(i);
					visited[i] = true;
				}
			}
		}
	}
}

int main(){
	int noOfVertices, noOfEdges;
	cin >> noOfVertices >> noOfEdges;
	
	int **edges = new int*[noOfVertices];
	for(int i = 0; i < noOfVertices; i++){
		edges[i] = new int[noOfVertices];
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
	
	int *visited = new int[noOfVertices];
	for(int i = 0; i < noOfVertices; i++){
		visited[i] = 0;
	}
	
	// For the case of BFS we will create the visited array inside the printBFS() function itself.
	printBFS(edges, noOfVertices, 0);
	
	delete [] visited;
	for(int i = 0; i < noOfVertices; i++){
		delete [] edges[i];
	}
	delete [] edges;
	
	return 0;
}
