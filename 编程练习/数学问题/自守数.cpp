/*****************************************************************
��������ָһ������ƽ����β�����ڸ����������Ȼ����
���磺25^2 = 625��76^2 = 5776��9376^2 = 87909376�������n���ڵ��������ĸ���

*********************************************************************/
//ת���ַ�����Ȼ����в��Ҳ���
#include<iostream>
#include<string>
using namespace std;
int help(int n){
    int ret=0;
    for (int i=0;i<n;i++){
        long long int m=i*i;
    	string s1=to_string(i);
   		string s2=to_string(m);
    	int pos = s2.size()-s1.size();
        if (s2.find(s1,pos)!=string::npos)
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