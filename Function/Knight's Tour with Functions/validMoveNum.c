int validMoveNum(int r, int c, int n, int visited[100][100]){
    int res = 0;
    if(r < 0 || c < 0 || r > n-1 || c > n-1 || visited[r][c] != 0)
        return -1;
    if(visited[r-2][c+1] == 0 && r-2 >= 0 && c+1 <= n-1)
        res++;
    if(visited[r-1][c+2] == 0 && r-1 >= 0 && c+2 <= n-1)
        res++;
    if(visited[r+1][c+2] == 0 && r+1 <= n-1 && c+2 <= n-1)
        res++;
    if(visited[r+2][c+1] == 0 && r+2 <= n-1 && c+1 <= n-1)
        res++;
    if(visited[r+2][c-1] == 0 && r+2 <= n-1 && c-1 >= 0)
        res++;
    if(visited[r+1][c-2] == 0 && r+1 <= n-1 && c-2 >= 0)
        res++;                        
    if(visited[r-1][c-2] == 0 && r-1 >= 0 && c-2 >= 0)
        res++;
    if(visited[r-2][c-1] == 0 && r-2 >= 0 && c-1 >= 0)
        res++;
    return res;            
}
