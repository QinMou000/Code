class Solution {
  public:
    vector<vector<int> > flipChess(vector<vector<int> >& A,
                                   vector<vector<int> >& f) {
        int m = A.size();
        int n = A[0].size();

        for (auto V : f) {
            // 映射坐标
            int x = V[0] - 1;
            int y = V[1] - 1;
            // 翻转操作
            if (x + 1 < m )
                A[x + 1][y] ^= 1;
            if (y + 1 < n)
                A[x][y + 1] ^= 1;
            if (x - 1 >= 0)
                A[x - 1][y] ^= 1;
            if ( y - 1 >= 0)
                A[x][y - 1] ^= 1;
        }

        return A;
    }
};