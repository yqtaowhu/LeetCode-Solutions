
��һЩ��Ǯ�����ٶ��ټ���������һ������
1,2,5=��11  5  5 1=��3

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
	int Max = amount + 1;
	vector<int>dp(amount + 1, Max);
	dp[0] = 0;
	//iΪҪ��ɵ���
	for (int i = 1; i <= amount; i++) {
		for (int j = 0; j<coins.size(); j++) {
			//Ӳ��С��i�Ž�����һ��
			if (coins[j] <= i) {
				//i-coins[j]��ʣ���Ǯ�������ŵ���ɸ���,�ټ�1
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				cout << dp[i] << endl;
			}
		}
	}
	return dp[amount] == Max ? -1 : dp[amount];
}
int main(){
	vector<int> v = { 1,2,5 };
	cout << coinChange(v, 11) << endl;
	return 0;
}