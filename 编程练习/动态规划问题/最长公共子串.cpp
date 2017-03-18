

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int lcs(string a,string b){
    int m=a.size(),n=b.size(),ret=0;
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++){
            if (a[i-1]==b[j-1]) {                      //��a[i],b[j]��β����Ӵ�
                dp[i][j]=dp[i-1][j-1]+1;               //���䲻���Ǻ����ԣ�Ϊ0
				ret = max(ret,dp[i][j]);
            }
            else dp[i][j]=0;
    	}
	}
    return ret;
}
int main(){
	string m,n;
    while(cin>>m>>n){
        cout<<lcs(m,n)<<endl;
    }
}