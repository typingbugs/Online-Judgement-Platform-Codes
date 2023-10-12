#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
	string ans;
	int i = 0;
	while (strs[0][i] != 0)
	{
		char c = strs[0][i];
		bool flag = 1;
		for (int j = 0; j < strs.size(); j++)
		{
			if (strs[j][i] != c)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			ans.append(1, c);
		else
			break;
		i++;
	}
	return ans;
}

////更好的解答：
//class Solution {
//public:
//	string longestCommonPrefix(vector<string>& strs) {
//		sort(strs.begin(), strs.end());
//
//		string& s1 = strs.front();
//		string& s2 = strs.back();
//		int i = 0;
//		while (i < s1.size() && i < s2.size() && s1[i] == s2[i])
//			i++;
//		return string(s1.begin(), s1.begin() + i);
//	}
//};