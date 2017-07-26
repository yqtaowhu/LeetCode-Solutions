//��Ŀ���ӣ�https://www.nowcoder.com/question/next?pid=4236887&qid=78086&tid=6964684
/******************************************************************************************************************
���һ�������ܱ�ʾΪp^q(^��ʾ������)��pΪһ������,qΪ����1���������ͳ�������������������ݡ����ڸ���һ��������n,
���n��һ��������������Ҫ�ҳ���Ӧ��p,q�� 
��������:
����һ��������n(2 �� n �� 10^18)
�������:
���n��һ�����������������p,q,�Կո�ָ�,��ĩ�޿ո�
���n���ǳ��������ݣ������No

��������:
27

�������:
3 3
*******************************************************************************************************************/
#include <iostream>
#include <math.h>
using namespace std;
long long n;
//������
long long calc(long long base, int exp) {
	long long ret = 1;
	while (exp) {
		if (exp & 1)
			ret *= base;
		exp = exp >> 1;
		base *= base;
	}
	return ret;
}
//�ж�����
bool check(long long n) {
	long long temp = sqrt(n);
	for (long long i = 2; i <= temp; i++) {
		if (n%i == 0) return false;
	}
	return true;
}
int main() {
	cin >> n;
	int flag = 1;
	//����ö��q��ֵ
	for (int i = 2; ; i++) {
		double temp = pow(n, 1.0 / i);
		if (temp < 2.0) break;
		if (calc((long long)temp, i) == n&&check((long long)temp)) {
			flag = 0;
			cout << (long long)temp << " " << i << endl;
		}
	}
	if (flag)
		cout << "No" << endl;
}