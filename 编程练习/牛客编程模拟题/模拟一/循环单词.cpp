/*****************************************************************************************
���һ������ͨ��ѭ�����ƻ�õĵ��ʣ����ǳ���Щ���ʶ�Ϊһ��ѭ�����ʡ� ���磺picture �� turepic ��������ͬһ��ѭ�����ʡ� ���ڸ���n�����ʣ���Ҫͳ�����n���������ж�����ѭ�����ʡ� 
��������:
�������n+1�У�

��һ��Ϊ���ʸ���n(1 �� n �� 50)

��������n�У�ÿ��һ������word[i]������length(1 �� length �� 50)����Сд��ĸ����


�������:
���ѭ�����ʵ�����

��������:
5
picture
turepic
icturep
word
ordw

�������:
2
*****************************************************************************************/
//�����ķ���
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
	int n;
    while(cin>>n) {
		string s;
        int count=0;
        map<string,int>m;
        while(n--){
			cin>>s;
            if (m.find(s)==m.end()) {
                count++;
                m[s]=1;
				//ö�����еĿ��ܣ�����map��
				for (int i=1;i<s.size();i++) {
					string tmp = s.substr(i)+s.substr(0,i);
                    m[tmp]=1;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
//set�ķ�����������С�����
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
//calc��Ŀ���Ǽ�������ַ�������С���������
string calc(string x) {
    vector<string> v;
    int n=x.size();
	//����n����ϣ���Ϊ��n������
    for (int i=0;i<n;i++) {
        string temp=x;
        for (int j=0;j<n;j++) {
            temp[j]=x[(i+j)%n];
        }
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
	//��С�����
    return v[0];
}
int main() {
    int n;cin>>n;
    string x;	
    set<string> s;
    for (int i=0;i<n;i++) {
    	cin>>x;
    	string y=calc(x);
    	s.insert(y); //������С�ģ�ÿһ����ת����С�ģ���Ϊsetû���ظ���
    }
    cout<<s.size();
}