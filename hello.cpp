#include<bits/stdc++.h>
using namespace std;

// void printSubsequence(int n, string s, string ans) {
// 	if (n >= s.size()) {
// 		cout << ans << endl;
// 		return;
// 	}
// 	printSubsequence(n + 1, s, ans + s[n]);

// 	printSubsequence(n + 1, s, ans);

// 	return;
// }

void combinationSum1(int idx, vector<int> &arr, int t, vector<vector<int>> &res, vector<int> &curr) {
	if (idx == arr.size()) {
		if (t == 0) {
			res.push_back(curr);
			return;
		}
	}
	if (arr[idx] <= t) {
		curr.push_back(arr[idx]);
		combinationSum1(idx, arr, t - arr[idx], res, curr);
		curr.pop_back();
	}
	combinationSum1(idx + 1, arr, t, res, curr);
	return;
}
void combinationSum2(int idx, vector<int> &arr, int t, vector<vector<int>> &res, vector<int> &curr) {
	//for this problem sort the input array first in the main function
	if (t == 0) {
		res.push_back(curr);
		return;
	}
	for (int i = idx; i < arr.size(); i++) {
		if (i > idx && arr[i] == arr[i - 1]) { //we don't want the starting element to be repeated and hence if we to use this condition
			continue;
		}
		if (arr[idx] > t) break;
		curr.push_back(arr[idx]);
		combinationSum2(idx + 1, arr, t - arr[idx], res, curr);
		curr.pop_back();
	}
	return;
}

void subsetSum(int idx, int sum, vector<int> arr, vector<int> &sumSubset) {
	if (idx == arr.size()) {
		sumSubset.push_back(sum);
		return;
	}
	//include this element in the subset
	subsetSum(idx + 1, sum + arr[idx], arr, sumSubset);
	//don't include
	subsetSum(idx + 1, sum, arr, sumSubset);

}
void subset2(int idx, vector<int> nums, vector<int> &curr, vector<vector<int>> &res) {
	//sort the input array in the main function
	res.push_back(curr);
	for (int i = idx; i < nums.size(); i++) {
		if (i != idx && nums[i] == nums[i - 1])continue;
		curr.push_back(nums[i]);
		subset2(idx + 1, nums, curr, res);
		curr.pop_back();
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> arr(3);
	for (int i = 0; i < 3; ++i)
	{
		arr[i] = i + 1;
		cout << arr[i] << " ";
	}
	cout << endl;
	vector<vector<int>> res;
	//printSubsequence(0, s, "");
	vector<int> curr;
	//combinationSum1(0, arr, 10, res, curr);
	subset2(0, arr, curr, res);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;

}

