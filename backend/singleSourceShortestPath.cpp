#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include<climits>
using namespace std;

//BSF Memoization
typedef tuple<int, int, int> tupl;

//Function to implement BFS
int findCheapestPrice(int cities,
                    vector<vector<int>>&flights, int src, int dst, int stops)
    {
        unordered_map<int, vector<pair<int, int>>> adjList;
        
        //Traverse Flight [][]
        for (auto flight :flights){
            //Create Adjacency Matrix
            adjList[flight[0]].push_back(
                {flight[1], flight[2]});
            
        }
        //<city, distancefromsource> pair
        queue<pair<int,int>> q;
        q.push({src, 0});
        //store the result
        int srcDist = INT_MAX;

        //traverse the matrix
        while(!q.empty()&& stops-- >= 0){
            int qSize = q.size();
            for(int i=0; i<qSize; i++){
                pair<int, int> curr = q.front();
                q.pop();

                for (auto next: adjList[curr.first]){
                    /*if source distance is already
                    least then skip this iteration */
                    if(srcDist < curr.second + next.second)
                        continue;
                    q.push({next.first,curr.second + next.second});
                    if(dst==next.first){
                        srcDist = min(srcDist, curr.second + next.second);

                    }
                }
            }
        }
        //Returning the answer
        return srcDist == INT_MAX?-1:srcDist;
    }

    int main(){
        int cities, flightCount;
        cin >> cities >> flightCount;
    
        vector<vector<int>> flights;
        for(int i = 0; i < flightCount; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            flights.push_back({u, v, w});
        }
    
        int src, dst, stops;
        cin >> src >> dst >> stops;
    
        cout << findCheapestPrice(cities, flights, src, dst, stops) << endl;
        return 0;
    }
    