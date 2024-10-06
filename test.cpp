#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
//返回最长无重复子数组的长度
    int maxLength(vector<int>& arr) {
        // write code here
        int n = arr.size();
        if(n == 0) return 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        int max_len = 1;
        for(int i = 1; i < n; i++)
        {
            int j = i - 1;
            while(j >= i - dp[i - 1] && arr[j] != arr[i])
            {
                j--;
            }
            dp[i] = i - j;
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }

int main()
{
    vector<int> arr = {2,3,4,5};
    cout << maxLength(arr) << endl;
    return 0;
}