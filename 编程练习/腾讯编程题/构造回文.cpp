/**************************************************************************************************
���ӣ�https://www.nowcoder.com/questionTerminal/28c1dc06bc9b4afd957b01acdf046e69
��Դ��ţ����
����һ���ַ���s������Դ���ɾ��һЩ�ַ���ʹ��ʣ�µĴ���һ�����Ĵ������ɾ������ʹ�û��Ĵ���أ�
 �����Ҫɾ�����ַ�������
��������:
���������ж��飬ÿ�����һ���ַ���s���ұ�֤:1<=s.length<=1000.
 
�������:

����ÿ�����ݣ����һ������������������Ҫɾ�����ַ�������

��������:
abcda
google


�������:
2
2
*************************************************************************************************/
//���ӣ�https://www.nowcoder.com/questionTerminal/28c1dc06bc9b4afd957b01acdf046e69
��Դ��ţ����
/*
�ᵽ���Ĵ�����ȻҪ���û��Ĵ����ص㣬�뵽��Դ�ַ�����ת�󣬡����Ĵ�������һ��������
�൱��˳��û�� ��ԭ�ַ������䷴������󹫹������У������Ӵ�����Ϊ���Բ��������ĳ��ȣ�ʹ�ö�̬�滮��������ã���
Ȼ����ԭ�ַ����ĳ��ȼ�ȥ�����󹫹������еĳ��Ⱦ͵õ�����С�༭����
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int help(string p, string s) {
	int len = p.size();
	vector<vector<int>>dp(len + 1, vector<int>(len + 1, 0));
	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= len; j++) {
			if (p[i-1] == s[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[len][len];
}
int main() {
	string s;
	while (cin >> s) {
		string p = s;
		reverse(p.begin(), p.end());
		int size=help(p,s);  //�������������
		cout << p.size() - size << endl;
	}
}