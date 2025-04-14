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
    int cities = 4;
vector<vector<int>> flights = {
    {0, 1, 100},
    {1, 2, 100},
    {0, 2, 500},
    {2, 3, 100},
    {1, 3, 600}
    };
    int src = 0;
    int dst = 3;
    int stops = 2;
    cout << findCheapestPrice(cities, flights, src, dst, stops) << endl; // Output: 300
    return 0;
}