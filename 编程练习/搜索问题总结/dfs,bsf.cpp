/************************************************************************************
������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���
ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ��
���ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
 ���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18��
 ���ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
 ****************************************************************************************/
 //bfs����·�����У�vis����
class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
		if (threshold<0) return 0;
        if (threshold==0) return 1;
        vector<vector<int>> vis(rows,vector<int>(cols,0));
       	int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>>que;
        que.push({0,0});
        int sum = 1;
        vis[0][0]=1;
        while(!que.empty()) {
            for (int k=0;k<4;k++) {
                int tx = que.front().first + dir[k][0];
                int ty = que.front().second + dir[k][1];
                if (tx<0||tx>=rows||ty<0||ty>=cols||vis[tx][ty]==1)
            		continue;
                if (getsum(tx)+getsum(ty)<=threshold) {
                    sum++;
                    que.push({tx,ty});
                    vis[tx][ty]=1;
                }
            }
            que.pop();
        }
        return sum;
    }
    int getsum(int x) {
        int ret = 0;
        while(x) {
			ret += x%10;
            x/=10;
        }
        return ret;
    }   
};


/*****************************************************************
�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
���һ��·�������˾����е�ĳһ�����ӣ����·�������ٽ���ø��ӡ� ����[a b c e s f c s a d e e]��3*4����
��������ַ���"bcced"��·�������Ǿ����в�������abcb��·����
��Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�
*******************************************************************/
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str) {
        vector<bool>visit(strlen(matrix),false);
    	for (int i=0;i<rows;i++) {
            for (int j=0;j<cols;j++) {
				int len=strlen(str);
                if (check(matrix,i,rows,j,cols,0,visit,str)) 
                    return true;
            }
        }
        return false;
    }
    bool check(char* matrix,int i,int rows,int j,int cols,int k,vector<bool>& visit,char* str) {
        int index=i*cols+j;
        if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || visit[index] ==true)
            return false;
        if (k==strlen(str)-1) return true;
        visit[index]=true;
        if (check(matrix, i-1,rows,j,cols, k + 1, visit,str)
                || check(matrix, i,rows,j-1,cols, k + 1, visit,str)
                || check(matrix, i,rows,j+1,cols, k + 1, visit,str)
                || check(matrix, i+1,rows,j,cols, k + 1, visit,str)) 
            return true;
        visit[index] = 0;  //����
        return false;
    }
};