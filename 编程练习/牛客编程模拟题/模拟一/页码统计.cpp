#include <iostream>
#include <vector>
using namespace std;
long long counteach(long long n, int i)  //ͳ������i���ָ���
{
	long long iCount = 0;
	long long iFactor = 1;
	long long iLowerNum = 0;
	long long iCurrNum = 0;
	long long iHigherNum = 0;

	while (n / iFactor != 0)
	{
		iLowerNum = n - (n / iFactor)*iFactor;
		iCurrNum = (n / iFactor) % 10;
		iHigherNum = n / (iFactor * 10);

		if (iCurrNum<i)
			iCount += iHigherNum*iFactor;
		else if (i == iCurrNum)
			iCount += iHigherNum*iFactor + iLowerNum + 1;
		else if (iCurrNum>i)
			iCount += (iHigherNum + 1)*iFactor;
		//����0�ĸ���
		//��nΪ1λ�������籾����1 2 3 4 5 6 ��֮ǰ����� 0 1 2 3 4 5 6,�����1��0
		//��nΪ2λ�������籾����1 2 3 4 5 6 7 8 9 10 11 12��֮ǰ����� 00 01 02 ...09 10 11 12,�����1+10��0
		//��nΪ3λ�������籾����1 2 3 4 ... 115��֮ǰ�����000 001 002 ...009 010 011...099 100...115�������1+10+100��0
		//�����Ҫ��ÿ��ѭ���м�ȥ������0�ĸ���
		if (0 == i)
			iCount -= iFactor;

		iFactor *= 10;
	}
	return iCount;
}
vector<long long> count(long long n)    //����ͳ��0~9
{
	vector<long long>res(10, 0);
	for (int i = 0; i<10; i++){
		res[i] += counteach(n, i);
	}
	return res;
}
int main()
{
	long long n;
	cin >> n;
	vector<long long>res = count(n);
	for (int i = 0; i < res.size(); i++){
		i == 0 ? cout << res[i] : cout << " " << res[i];
	}
	return 0;
}