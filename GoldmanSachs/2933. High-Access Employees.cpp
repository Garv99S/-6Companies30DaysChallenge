// https://leetcode.com/problems/high-access-employees/description/

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string,vector<int>> m;
        for(int i=0;i<access_times.size();i++){
            string x = access_times[i][1];
            int minutes = stoi(x.substr(0,2))*60 + stoi(x.substr(2));
            m[access_times[i][0]].push_back(minutes);
        }
        vector<string> ans;
        for(auto x : m){
            string s = x.first;
            vector<int> times = x.second;

            vector<int> sweep(1441,0);
            for(auto l : times){
                sweep[l]++;
                if(l+60 < 1441)sweep[l+60]--;
            }

            int c = 0;
            for(int i=0;i<1441;i++){
                c += sweep[i];
                if(c >= 3){
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};