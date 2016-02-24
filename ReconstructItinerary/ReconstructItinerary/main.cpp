//
//  main.cpp
//  ReconstructItinerary
//
//  Created by 仓颉 on 16/2/16.
//  Copyright © 2016年 Aiyi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <stack>

using namespace::std;

class Solution {
public:
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> itinerarys;
        
        unordered_map<string, multiset<string>> graph;
        
        if (tickets.size() == 0) {
            return itinerarys;
        }
        
        for (int i = 0; i < tickets.size(); i++) {
            graph[tickets.at(i).first].insert(tickets.at(i).second);
        }
        
        stack<string> dfs;
        
        dfs.push("JFK");
        
        while (!dfs.empty()) {
            string topAir = dfs.top();
            
            if (graph[topAir].empty()) {
                itinerarys.push_back(topAir);
                dfs.pop();
            } else {
                dfs.push(*graph[topAir].begin());
                graph[topAir].erase(graph[topAir].begin());
            }
        }
        
        reverse(itinerarys.begin(), itinerarys.end());
        
        return itinerarys;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<pair<string, string>> tickets;
    
//    ["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]
//    tickets.push_back(make_pair("MUC", "LHR"));
//    tickets.push_back(make_pair("JFK", "MUC"));
//    tickets.push_back(make_pair("SFO", "SJC"));
//    tickets.push_back(make_pair("LHR", "SFO"));
    
//    ["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]
    
//    tickets.push_back(make_pair("JFK", "SFO"));
//    tickets.push_back(make_pair("JFK", "ATL"));
//    tickets.push_back(make_pair("SFO", "ATL"));
//    tickets.push_back(make_pair("ATL", "JFK"));
//    tickets.push_back(make_pair("ATL", "SFO"));
    
//    [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
    
//    tickets.push_back(make_pair("JFK", "KUL"));
//    tickets.push_back(make_pair("JFK", "NRT"));
//    tickets.push_back(make_pair("NRT", "JFK"));
//    
//    [["EZE","AXA"],["TIA","ANU"],["ANU","JFK"],["JFK","ANU"],["ANU","EZE"],["TIA","ANU"],["AXA","TIA"],["TIA","JFK"],["ANU","TIA"],["JFK","TIA"]]
    
//    tickets.push_back(make_pair("EZE", "AXA"));
//    tickets.push_back(make_pair("TIA", "ANU"));
//    tickets.push_back(make_pair("ANU", "JFK"));
//    tickets.push_back(make_pair("JFK", "ANU"));
//    tickets.push_back(make_pair("ANU", "EZE"));
//    tickets.push_back(make_pair("TIA", "ANU"));
//    
//    tickets.push_back(make_pair("AXA", "TIA"));
//    tickets.push_back(make_pair("TIA", "JFK"));
//    tickets.push_back(make_pair("ANU", "TIA"));
//    tickets.push_back(make_pair("JFK", "TIA"));
    
//    [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
//    tickets.push_back(make_pair("JFK", "KUL"));
//    tickets.push_back(make_pair("JFK", "NRT"));
//    tickets.push_back(make_pair("NRT", "JFK"));
    
//[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    tickets.push_back(make_pair("JFK", "SFO"));
    tickets.push_back(make_pair("JFK", "ATL"));
    tickets.push_back(make_pair("SFO", "ATL"));
    tickets.push_back(make_pair("ATL", "JFK"));
    tickets.push_back(make_pair("ATL", "SFO"));
    
    Solution solution;
    
//    solution.larger("NRT", "KUL");
    
//    vector<string> itinerarys = solution.findItinerary(tickets);

    
    std::cout << solution.comp("ADL", "AUA") << "\n";
        std::cout << solution.comp("ORD", "ATL") << "\n";
    
    return 0;
}
