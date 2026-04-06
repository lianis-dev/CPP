#include <iostream>
#include <vector>
#include <map> 
#include <queue>
#include <climits> 
using namespace std;
int main(){
    int n, e; //n is nodes, e is edges 
    cin >> n >> e;

    int INF= INT_MAX;
    map<int, vector<int>> graph; //the graph structure is made by a node and a vector of it's connected nodes
    //alternative: vector<vector<int>>
    vector<int> distances(n, INF); //create a vector to store how much is the distance from the starting point to every node
    //the vector has size n and all values are set to INF, this way we'll know if that node has been visited or not
    queue<int> q; //create a queue of which nodes we still have to 'explore'
    int start = 0; //let's say the starting point is node #0
    //NOTE: if the starting point is 1, the vector of distances should have size n+1 as we will
    // ignore #0 and the vector will have values until n+1

    for(int i=0; i<e; i++){ //input of all connections 
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y); //insert y as connection of x 
        graph[y].push_back(x); //if the graph has two-way connections (x is connected to y and y is connected to x)
    }

    q.push(start); //insert starting node in the queue 
    distances[start] = 0; //set the distance of the starting point to 0 as we are already there and it takes nothing to reach it

    while(!q.empty()){ //while the queue isn't empty
        int first = q.front(); //get the first element in the queue
        q.pop(); //remove it from the queue 

        for(int s: graph[first]){ //for every connection of first 
            if(distances[s] == INF){ //if the distance is still INF, meaning it hasn't been visited yet
                q.push(s); //insert it in the queue to explore it next
                distances[s] = distances[first]+1; //set it distance from the start as the previous node +1
            }
        }
    } //this way we will explore the whole graph and fill the vector of distances 
    //now we can do operations with the vector of distances 

    return 0;
}