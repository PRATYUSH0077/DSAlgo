class Solution {
public:
    void bfs(queue<pair<int,int>>&  q,vector<vector<char>>& board ,vector<vector<char>>& visited){
        int m=board.size();
        int n= board[0].size();
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            visited[row][col]='O';
            for(int i=0; i<4 ;i ++){
                int nrow= row+delrow[i];
                int ncol= col+delcol[i];
                if(nrow<m && nrow>-1 && ncol<n && ncol>-1 && board[nrow][ncol]=='O' && visited[nrow][ncol]=='X')
                {
                    visited[nrow][ncol]='O';
                    q.push({nrow,ncol});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n= board[0].size();
        vector<vector<char>> visited(m,vector<char>(n,'X'));
        queue<pair<int,int>>  q;

        // PUSHING ALL BOUNDARY ZEROS INTO QUEUE
        for(int i=0 ; i<m ; i++){
            if(board[i][0]=='O') q.push({i,0});
            if(board[i][n-1]=='O') q.push({i,n-1});
            
        }
        for(int j=0 ; j<n ; j++){
            if(board[0][j]=='O') q.push({0,j});
            if(board[m-1][j]=='O') q.push({m-1,j});
            
        }


        bfs(q,board,visited);
        board=visited;

    }
};