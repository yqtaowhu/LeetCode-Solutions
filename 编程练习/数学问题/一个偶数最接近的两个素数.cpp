/*****************************************************************
����һ��ż��������2����������2��������ɣ����ż����2�������кܶ��������
����ĿҪ��������ָ��ż��������������ֵ��С�������� 
*********************************************************************/

#include<iostream>
#include<vector>
using namespace std;
//����
bool help(int n){
    for(int i=2;i<=n/2;i++)
        if (n%i==0) return false;
    return true;
}
int main(){
    int n;
    while(cin>>n){
        int a=0,b=0;
		for (int i=2;i<=n/2;i++) {
            if (help(i)&&help(n-i)) {
                a=i;
                b=n-i;
            }
        }
        cout<<a<<endl;
        cout<<b<<endl;
    }
}