#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> adj; // adjacency matrix of graph
const int INF = 10000000; // weight INF means there is no edge

struct Edge {
    int w = INF, to = -1;
};


vector<int> convertVecStrToVecInt(vector<string> vecStrings)
{
    vector<int> vecInt;
    for (auto str : vecStrings)
    {
        int aux = atoi(str.c_str());
        vecInt.push_back(aux);
    }
    return vecInt;
}
int calcTSP(vector<int> route, vector<vector<int>> distances)
{
    int total_distance = 0;
    for (int i = 0; i < route.size() - 1; i++)
    {
        total_distance += distances[route[i]][route[i + 1]];
    }
    total_distance += distances[route[route.size() - 1]][route[0]];
    return total_distance;
}
vector<string> getTokens(string line)
{
    int pos = 0;
    string token;
    vector<string> vecStrings;
    for (pos = 0; pos < line.size(); ++pos)
    {
        if (line[pos] != ' ')
        {
            token.insert(token.end(), line[pos]);
        }
        else
        {
            if (!token.empty())
            {
                vecStrings.push_back(token);
                token = "";
            }
        }
    }
    vecStrings.push_back(token);
    return vecStrings;
}
vector<vector<int>> final_vec;
void prim() {
    int total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    
    min_e[0].w = 0;

    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }

        if (min_e[v].w == INF) {
            cout << "No MST!" << endl;
            exit(0);
        }

        selected[v] = true;
        total_weight += min_e[v].w;
        if (min_e[v].to != -1){
            cout << v << " " << min_e[v].to << endl;
            vector<int> auxil;
            auxil.push_back(min_e[v].to);
            auxil.push_back(v);
            final_vec.push_back(auxil);
            }
        for (int to = 0; to < n; ++to) {
            if (adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }

    cout << total_weight << endl;
}

int main(){
    string filename = "tsp5_27603.txt"; 

    ifstream fileInput(filename);
    string line;
    vector<vector<int>> distances;
    if (!fileInput)
    {
        cout << "Falha!" << endl;
    }               
    while (getline(fileInput, line))
    {
        vector<string> auxString = getTokens(line);
        vector<int> auxInt = convertVecStrToVecInt(auxString);
        adj.push_back(auxInt);
    }
    n = adj.size() - 1;
    prim();
    vector<int> order;
    for(auto p:final_vec){
        if(std::find(order.begin(), order.end(), p.at(0)) != order.end()) {
    
} else {
    order.push_back(p.at(0));
}
if(std::find(order.begin(), order.end(), p.at(1)) != order.end()) {
    
} else {
    order.push_back(p.at(1));
}
    }
    int calc_aprox = 0;
    for(auto inn:order){
        cout << inn << ' ';
    }
    for(auto ll:order){
        if(ll == 0){

        }else{
            calc_aprox += adj[ll-1][ll];
        }
            
    }
    cout << "\n aprox:" << calc_aprox; 
}