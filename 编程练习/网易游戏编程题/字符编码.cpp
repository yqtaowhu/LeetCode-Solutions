/*******************************************************************************
����һ���ַ��������㽫�ַ������±��룬���������ַ��滻�ɡ��������ֵĸ���+�ַ�����
�����ַ���AAAABCCDAA�ᱻ�����4A1B2C1D2A��
*********************************************************************************/
#include<iostream>
#include<string>
using namespace std;
string help(string s){
    if(s.size()==0) return "";
    int count=1;char first=s[0];
    string res="";
    for (int i=1;i<s.size();i++) {
        if (s[i]==first) count++;
        else {
            res+=to_string(count)+first;
            count=1;
            first=s[i];
        }
    }
    res+=to_string(count)+first;
    return res;
}
int main(){
    string s;
    while(cin>>s){
        cout<<help(s)<<endl;
    }
    return 0;
}