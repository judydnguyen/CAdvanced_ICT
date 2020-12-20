// C++ implementation to find the 
// shortest path in a directed 
// graph from source vertex to 
// the destination vertex 

#include<iostream>
#include<vector>
#include<unordered_set>
#define infi 1000000000 
using namespace std; 
int N, M;
// Class of the node 
class Node { 
public: 
	int vertexNumber; 

	// Adjacency list that shows the 
	// vertexNumber of child vertex 
	// and the weight of the edge 
	vector<pair<int, int> > children; 
	Node(int vertexNumber) 
	{ 
		this->vertexNumber = vertexNumber; 
	} 

	// Function to add the child for 
	// the given node 
	void add_child(int vNumber, int length) 
	{ 
		pair<int, int> p; 
		p.first = vNumber; 
		p.second = length; 
		children.push_back(p); 
	} 
}; 

// Function to find the distance of 
// the node from the given source 
// vertex to the destination vertex 
vector<int> dijkstraDist( 
	vector<Node*> g, 
	int s, vector<int>& path) 
{ 
	// Stores distance of each 
	// vertex from source vertex 
	vector<int> dist(g.size()); 

	// Boolean array that shows 
	// whether the vertex 'i' 
	// is visited or not 
	bool visited[g.size()]; 
	for (int i = 0; i < g.size(); i++) { 
		visited[i] = false; 
		path[i] = -1; 
		dist[i] = infi; 
	} 
	dist[s] = 0; 
	path[s] = -1; 
	int current = s; 

	// Set of vertices that has 
	// a parent (one or more) 
	// marked as visited 
	unordered_set<int> sett; 
	while (true) { 

		// Mark current as visited 
		visited[current] = true; 
		for (int i = 0; 
			i < g[current]->children.size(); 
			i++) { 
			int v = g[current]->children[i].first; 
			if (visited[v]) 
				continue; 

			// Inserting into the 
			// visited vertex 
			sett.insert(v); 
			int alt 
				= dist[current] 
				+ g[current]->children[i].second; 

			// Condition to check the distance 
			// is correct and update it 
			// if it is minimum from the previous 
			// computed distance 
			if (alt < dist[v]) { 
				dist[v] = alt; 
				path[v] = current; 
			} 
		} 
		sett.erase(current); 
		if (sett.empty()) 
			break; 

		// The new current 
		int minDist = infi; 
		int index = 0; 

		// Loop to update the distance 
		// of the vertices of the graph 
		for (int a: sett) { 
			if (dist[a] < minDist) { 
				minDist = dist[a]; 
				index = a; 
			} 
		} 
		current = index; 
	} 
	return dist; 
} 

// Function to print the path 
// from the source vertex to 
// the destination vertex 
void printPath(vector<int> path, 
			int i, int s) 
{ 
	if (i != s) { 

		// Condition to check if 
		// there is no path between 
		// the vertices 
		if (path[i] == -1) { 
			cout << "Path not found!!"; 
			return; 
		} 
		printPath(path, path[i], s); 
		cout << path[i] << " "; 
	} 
} 

// Driver Code 
int main() 
{ 
	vector<Node*> v; 
	// int n = 4, s = 0, e = 5; 

	// Loop to create the nodes 
	
    cin >> N >> M;
    for (int i = 1; i <= N; i++) { 
		Node* a = new Node(i); 
		v.push_back(a); 
	} 
	// Creating directed 
	// weighted edges 
    
    for(int i = 1; i<= M; i++)
    {
        int u, d, w;
        cin >> u >> d >> w;
        v[u]->add_child(d, w);
    }
    int s, ds;
    // cin >> s >> ds;
    // cout << s << endl;
	// v[0]->add_child(1, 1); 
	// v[0]->add_child(2, 4); 
	// v[1]->add_child(2, 2); 
	// v[1]->add_child(3, 6); 
	// v[2]->add_child(3, 3); 
    

	// vector<int> path(v.size()); 
	// vector<int> dist 
	// 	= dijkstraDist(v, s, path); 

	// Loop to print the distance of 
	// every node from source vertex 
	// for (int i = 0; i < dist.size(); i++) { 
	// 	if (dist[i] == infi) { 
	// 		cout << i << " and " << s 
	// 			<< " are not connected"
	// 			<< endl; 
	// 		continue; 
	// 	} 
	// 	cout << "Distance of " << i 
	// 		<< "th vertex from source vertex "
	// 		<< s << " is: "
	// 		<< dist[i] << endl; 
	// } 
	return 0; 
} 
