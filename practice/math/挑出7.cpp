���7�й����ֵĸ���������7�ı��������а���7�����֣���17��27��37...70��71��72��73...���ĸ���

��������:
һ��������N��(N������30000)


#include<iostream>
#include<string>
using namespace std;

int help(int n){
    int ret=0;
	for (int i=1;i<=n;i++) {
        string s = to_string(i);
        if (s.find('7')!=string::npos||i%7==0)
            ret++;
    }
    return ret;
}
int main(){
    int n;
    while(cin>>n){
		cout<<help(n)<<endl;
    }
    return 0;
}