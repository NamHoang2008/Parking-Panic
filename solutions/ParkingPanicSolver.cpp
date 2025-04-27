#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<stack>
using namespace std;

pair<int,int> group[6]; int group_id, car_direction;
void dfs(int i, int j, vector<vector<int>>& board){
    group[group_id++] = {i,j};
    if(board[i + 1][j] == board[i][j]){
        car_direction = 0;
        dfs(i + 1,j,board);
    }
    else if(board[i][j + 1] == board[i][j]){
        car_direction = 2;
        dfs(i,j + 1,board);
    }
}
pair<int,int> findExit(vector<vector<int>>& grid){
    for(int i = 1; i < 7; i++){
        if(grid[i][0] == 0) return {i,1};
        else if(grid[i][7] == 0) return {i,6};
    }
    for(int j = 1; j < 7; j++){
        if(grid[0][j] == 0) return {1,j};
        else if(grid[7][j] == 0) return {6,j};
    }
    return {};
}
vector<pair<int,pair<char,int>>> solve(vector<vector<int>>& grid){
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}}; vector<char> directions = {'D','U','R','L'};
    bool visited[6][6]; for(int i = 0; i < 6; i++) for(int j = 0; j < 6; j++) visited[i][j] = false;
    unordered_set<string> memo; int count[6][6]; string boardStr(36,'.');
    int cnt = 0; for(int i = 0; i < 6; i++) for(int j = 0; j < 6; j++) count[i][j] = cnt++;
    for(int i = 0; i < 6; i++) for(int j = 0; j < 6; j++) if(grid[i + 1][j + 1] != 0) boardStr[count[i][j]] = '#';
    memo.insert(boardStr);
    pair<int,int> exit = findExit(grid);

    queue<pair<vector<vector<int>>,stack<pair<int,pair<char,int>>>>> q; q.push({grid,{}}); queue<pair<int,int>> revert;
    while(!q.empty()){
        vector<vector<int>> board = q.front().first;
        stack<pair<int,pair<char,int>>> steps = q.front().second;
        q.pop();

        boardStr = string(36,'.'); for(int i = 0; i < 6; i++) for(int j = 0; j < 6; j++) if(board[i + 1][j + 1] != 0) boardStr[count[i][j]] = '#'; 

        for(int i = 0; i < 6; i++)
            for(int j = 0; j < 6; j++)
                if(board[i + 1][j + 1] > 0 && !visited[i][j]){
                    int num = board[i + 1][j + 1]; group_id = 0; car_direction = -1; dfs(i + 1,j + 1,board);

                    for(int k = 0; k < group_id; k++){
                        pair<int,int>& it = group[k];
                        board[it.first][it.second] = 0;
                        visited[it.first - 1][it.second - 1] = true; revert.push({it.first - 1,it.second - 1});
                        boardStr[count[it.first - 1][it.second - 1]] = '.';
                    }

                    pair<int,int>& minId = group[0], maxId = group[group_id - 1];
                    for(int dir = car_direction; dir < car_direction + 2; dir++){
                        if(dir - car_direction == 0){ if(board[maxId.first + dirs[dir].first][maxId.second + dirs[dir].second] != 0) continue; }
                        else if(dir - car_direction == 1){ if(board[minId.first + dirs[dir].first][minId.second + dirs[dir].second] != 0) continue; }

                        for(int k = 0; k < group_id; k++){
                            pair<int,int>& it = group[k];
                            board[it.first + dirs[dir].first][it.second + dirs[dir].second] = num;
                            boardStr[count[it.first + dirs[dir].first - 1][it.second + dirs[dir].second - 1]] = '#';
                        }

                        if(board[exit.first][exit.second] == 1){
                            bool f = steps.empty() || steps.top().first != num;
                            if(f) steps.push({num,{directions[dir],1}});
                            else steps.top().second.second += 1;

                            vector<pair<int,pair<char,int>>> res(steps.size()); int res_id = steps.size() - 1;
                            while(!steps.empty()){
                                res[res_id--] = steps.top();
                                steps.pop();
                            }
                            return res;
                        }

                        else if(memo.find(boardStr) == memo.end()){
                            memo.insert(boardStr);
                            bool f = steps.empty() || steps.top().first != num;
                            if(f) steps.push({num,{directions[dir],1}});
                            else steps.top().second.second += 1;
                            q.push({board,steps});
                            if(f) steps.pop();
                            else steps.top().second.second -= 1;
                        }

                        for(int k = 0; k < group_id; k++){
                            pair<int,int>& it = group[k];
                            board[it.first + dirs[dir].first][it.second + dirs[dir].second] = 0;
                            boardStr[count[it.first + dirs[dir].first - 1][it.second + dirs[dir].second - 1]] = '.';
                        }
                    }

                    for(int k = 0; k < group_id; k++){
                        pair<int,int>& it = group[k];
                        board[it.first][it.second] = num;
                        boardStr[count[it.first - 1][it.second - 1]] = '#';
                    }
                }

        while(!revert.empty()){
            visited[revert.front().first][revert.front().second] = false;
            revert.pop();
        }
    }

    return {};
}

int main(){
    vector<vector<int>> grid = {
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1, 0, 0, 0, 0, 0, 0,-1},
        {-1, 0, 0, 0, 0, 0, 0,-1},
        {-1, 0, 0, 0, 0, 0, 0,-1},
        {-1, 0, 0, 0, 0, 0, 0,-1},
        {-1, 0, 0, 0, 0, 0, 0,-1},
        {-1, 0, 0, 0, 0, 0, 0,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1}
    };
    vector<pair<int,pair<char,int>>> res = solve(grid);
}