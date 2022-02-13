#include <string>
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> v[8];
unordered_map<string, int> um;
unordered_map<string, int> dup;
int n, answer;

void dfs(int idx, int num, vector<string> comb)
{
    if(num == n) {
        sort(comb.begin(), comb.end());
        string s = "";
        
        for(auto id : comb)
            s += id;
        
        if(!dup[s]){
            ++answer;
            dup[s] = 1;
        }
        return;
    }
    
    for(int i=idx; i<v[num].size(); i++){
        if(!um[v[num][i]]){
            um[v[num][i]] = 1;
            comb.push_back(v[num][i]);
            dfs(0, num+1, comb);
            um[v[num][i]] = 0;
            comb.pop_back();
        }
    }
}

bool check(string id, string ban){
    if(id.length() != ban.length())
        return false;
    else{
        int len = id.length();
        for(int i=0; i<len; i++){
            if(ban[i] == '*')
                continue;
            if(ban[i] != id[i])
                return false;
        }
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {

    n = banned_id.size();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<user_id.size(); j++){
            if(check(user_id[j], banned_id[i])){
                v[i].push_back(user_id[j]);
            }
        }
    }
    dfs(0,0,{});
    return answer;
}