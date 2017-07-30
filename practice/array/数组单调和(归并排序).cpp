
/***************************************************************
�ֶ������鵥����Ϊ����Ԫ��i��f(i)ֵ֮�͡�
�����f(i)��������ΪԪ��i���(������������)С�ڵ�����������֮�͡������һ����Ч�㷨����������ĵ����͡�
����һ������Aͬʱ��������Ĵ�Сn���뷵������ĵ����͡�
��֤�����СС�ڵ���500��ͬʱ��֤�����Ͳ��ᳬ��int��Χ��
����������
[1,3,5,2,4,6],6
���أ�27
******************************************************************/
class MonoSum {
public:
    int ret = 0;
    void merge_sort(vector<int>&arr,int low,int high) {
        if (low<high) {
        	int mid = (low+high)/2;
       	 	merge_sort(arr,low,mid);
        	merge_sort(arr,mid+1,high);
        	merge(arr,low,mid,high);
    	}
    }
    void merge(vector<int>&arr,int low,int mid,int high) {
        int i=low,j=mid+1,k=0;
        vector<int> tmp(high-low+1);
        while(i<=mid&&j<=high) {
            if (arr[i]>arr[j]) tmp[k++]=arr[j++];
            else {
                ret+=arr[i]*(high-j+1);
                tmp[k++]=arr[i++];
            }
		}
        while(i<=mid) tmp[k++]=arr[i++];
        while(j<=high) tmp[k++]=arr[j++];
        for (int i=0;i<k;i++) arr[low+i]=tmp[i];
    }
    int calcMonoSum(vector<int> A, int n) {
       if (n<=1) return 0;
       merge_sort(A,0,n-1);
       return ret;
    }
};