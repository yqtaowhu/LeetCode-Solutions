
/**********************************************************************
���ӣ�https://www.nowcoder.com/questionTerminal/138f0ae35154438caf3d0072bd6ffef5
��Դ��ţ����

���������ַ���A��B��C�����ǳ�C��A��B������ɵ��ҽ���C�����ҽ�����A��B�������ַ���
�Ҷ�Ӧ��˳�򲻸ı䡣���дһ����Ч�㷨���ж�C���Ƿ���A��B������ɡ�
	���������ַ���A,B��C�������ǵĳ��ȡ��뷵��һ��boolֵ������C�Ƿ���A��B������ɡ���֤�������ĳ��Ⱦ�С�ڵ���100��
	����������
	"ABC",3,"12C",3,"A12BCC",6
	���أ�true
************************************************************************************/
//�ݹ�
class Mixture {
public:
    bool chkMixture(string A, int n, string B, int m, string C, int v) {
        if(n+m!=v) return false;
        if ((n==0&&B==C)||(m==0&&A==C)) return true;
        if ((n==0&&B!=C)||(m==0&&A!=C)) return false;
        if (A[0]!=C[0]&&B[0]==C[0])
            return chkMixture(A,n,B.substr(1),m-1,C.substr(1),v-1);
        else if (A[0]==C[0]&&B[0]!=C[0])
            return chkMixture(A.substr(1),n-1,B,m,C.substr(1),v-1);
        else if (A[0]==C[0]&&B[0]==C[0])
            return chkMixture(A.substr(1),n-1,B,m,C.substr(1),v-1)||
            	   chkMixture(A,n,B.substr(1),m-1,C.substr(1),v-1);
        else return false;
    }
};

//dp
class Mixture {
public:
    bool chkMixture(string A, int n, string B, int m, string C, int v) {
        // write code here
        if(n+m!=v)return false;
    
        vector<vector<bool>> dp (n+1,vector<bool>(m+1,false));
          
        int a=0;
        int b=0;
        dp[0][0] = true;
        for(int i=0;i<v;i++){
            if(A[a] == C[i] && dp[a][b] == true){
                a++;
                dp[a][b] = true;
            }
              
            if(B[b] == C[i] && dp[a][b] == true){
                b++;
                dp[a][b] = true;
            }
        }
        return dp[n][m];
          
    }
};