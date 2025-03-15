//duplicate
//https://leetcode.com/problems/contains-duplicate/description/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (int num : nums) {
            if (seen[num] >= 1)
                return true;
            seen[num]++;
        }
        return false;
    }
};
//missingclass Solution {
//https://leetcode.com/problems/missing-number/solutions/6535224/100-acceptance-0ms-very-easy-to-understand-python3-c/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n+1);
        sort(nums.begin(),nums.end());
        for(int i=0;i<=n;i++)v[i]=i;
        for(int i=0;i<n;i++)if(v[i]!=nums[i])return v[i];
        return v[n];
    }
};
//missing number
//find all missing numbers https://leetcode.com/problems/missing-number/description/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        set<int> s(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (s.find(i) == s.end()) { 
                ans.push_back(i);
            }
        }
        return ans;
    }
}; 
//two sum
//https://leetcode.com/problems/two-sum/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size(); 
        for (int i = 0; i < n; i++) {
            numMap[nums[i]] = i;
        } 
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i) {
                return {i, numMap[complement]};
            }
        }

        return {}; 
    }
};
//how many numbers are smaller than current number
//https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>ans;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            int element = nums[i];
            for(int j=0;j<nums.size();j++){
                if(i!=j && nums[j]<element){
                    count++;
                }
            }
            ans.push_back(count);
            count = 0;
        }
        return ans;
    }
};
//minimum time visiting all points
https://leetcode.com/problems/minimum-time-visiting-all-points/description/

class Solution {
public:
    int toTime(std::vector<int>& from, std::vector<int>& to) {
        int xDiff = std::abs(from[0] - to[0]);
        int yDiff = std::abs(from[1] - to[1]);
        
        return std::max(xDiff, yDiff);
    }

    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
        int time = 0;

        for (int i = 1; i < points.size(); i++) {
            time += toTime(points[i - 1], points[i]);
        }

        return time;
    }
};
//Spiral matrix
//https://leetcode.com/problems/spiral-matrix/description/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix[0].size() - 1;
        int m = matrix.size() - 1;
        int top = 0;
        int right = n;
        int left = 0;
        int bottom = m;

        vector<int> res;

        while(top <= bottom && left <= right){ 
            for(int i = left; i <= right; i++){
                res.push_back(matrix[top][i]);
            }
            top++; 
            for(int i = top; i <= bottom; i++){
                res.push_back(matrix[i][right]);
            }
            right--;

            if(top <= bottom){ 
                for(int i = right; i >= left; i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left <= right){ 
                for(int i = bottom; i >= top; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};
//number of islands
//https://leetcode.com/problems/number-of-islands/ 
class Solution {
    public:
        int numIslands(vector<vector<char>>& grid) {
            if (grid.empty() || grid[0].empty()) {
                return 0;
            }
            
            int numIslands = 0;
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (grid[i][j] == '1') {
                        numIslands++;
                        dfs(grid, i, j);
                    }
                }
            }
            
            return numIslands;
        }
        
    private:
        void dfs(vector<vector<char>>& grid, int i, int j) {
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
                return;
            }
            
            grid[i][j] = '0';  
            dfs(grid, i + 1, j);  
            dfs(grid, i - 1, j);  
            dfs(grid, i, j + 1);  
            dfs(grid, i, j - 1); 
        }
    };
//Best time to buy and sell stocks
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
class Solution {
    public:
        int maxProfit(std::vector<int>& prices) {
            int buy = prices[0];
            int profit = 0;
            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] < buy) {
                    buy = prices[i];
                } else if (prices[i] - buy > profit) {
                    profit = prices[i] - buy;
                }
            }
            return profit;
        }
    };
//squares of a sorted array
//https://leetcode.com/problems/squares-of-a-sorted-array/
class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            vector<int> res(nums.size(), 0);
            int left = 0;
            int right = nums.size() - 1;
    
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (abs(nums[left]) > abs(nums[right])) {
                    res[i] = nums[left] * nums[left];
                    left++;
                } else {
                    res[i] = nums[right] * nums[right];
                    right--;
                }
            }
            return res;        
        }
    };
//3sum

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int target = 0;
            sort(nums.begin(), nums.end());
            set<vector<int>> s;
            vector<vector<int>> output;
            for (int i = 0; i < nums.size(); i++){
                int j = i + 1;
                int k = nums.size() - 1;
                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == target) {
                        s.insert({nums[i], nums[j], nums[k]});
                        j++;
                        k--;
                    } else if (sum < target) {
                        j++;
                    } else {
                        k--;
                    }
                }
            }
            for(auto triplets : s)
                output.push_back(triplets);
            return output;
        }
    };

//longest mountain in array
class Solution {
    public:
        int longestMountain(vector<int>& arr) {
            int longest = 0 ;
            int increase = 0 , decrease = 0 ;
            for (int i = 1 ; i < arr.size() ; i++) {
                if ((decrease && arr[i-1] < arr[i]) || arr[i-1] == arr[i])
                    increase = decrease = 0 ;
    
                increase += (arr[i-1] < arr[i]);
                decrease += (arr[i-1] > arr[i]);
    
                if (increase != 0 && decrease != 0)
                    longest = max(longest , increase + decrease + 1 );
            }
            return longest ; 
        }
    };
    





 