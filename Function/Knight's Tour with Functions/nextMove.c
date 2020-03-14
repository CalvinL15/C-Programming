int nextMove(int r, int c, int n, int visited[100][100]){
    int x = validMoveNum(r, c, n, visited);
    if(x == -1)
        return -1;
    else{
        if(visited[r-2][c+1] == 0 && r-2 >= 0 && c+1 <= n-1)
            return 0;
        if(visited[r-1][c+2] == 0 && r-1 >= 0 && c+2 <= n-1)
            return 1;
        if(visited[r+1][c+2] == 0 && r+1 <= n-1 && c+2 <= n-1)
            return 2;
        if(visited[r+2][c+1] == 0 && r+2 <= n-1 && c+1 <= n-1)
            return 3;
        if(visited[r+2][c-1] == 0 && r+2 <= n-1 && c-1 >= 0)
            return 4;
        if(visited[r+1][c-2] == 0 && r+1 <= n-1 && c-2 >= 0)
            return 5;                        
        if(visited[r-1][c-2] == 0 && r-1 >= 0 && c-2 >= 0)
            return 6;
        if(visited[r-2][c-1] == 0 && r-2 >= 0 && c-1 >= 0)
            return 7;
    }
    return -1;    
}
