//�����һ�����ʵĳ���
//�Ӻ���ǰ��һ�ַǳ��򵥵�˼·
#include<iostream>
#include<string>
using namespace std;
int lengthOfLastWord(string s) {
       int i=s.size()-1,len=0;
       while (s[i]==' '&&i>=0) i--;    //ȥ������0
       while (s[i]!=' '&&i>=0) {
           i--;len++;
       }
       return len;
    }
int main(){
    string str;
    while(getline(cin,str)){
       cout<<lengthOfLastWord(str)<<endl;  
    }
}