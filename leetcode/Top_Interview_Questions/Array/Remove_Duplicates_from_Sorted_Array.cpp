#include <iostream>
using namespace std;

/* solution #1
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur=0, next=0, idx=0;
        
        while(cur < nums.size()){
            while(next < nums.size() && nums[cur] == nums[next])
                next ++;
            
            nums[idx++] = nums[cur];
            cur = next;
            next ++;
        }
        return idx;
    }
};*/


/* solution #2 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=1;
        
        if(!nums.size()) return 0;
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[i-1]){
                nums[j++] = nums[i];
            }
        }
        
        return j;
    }
};
