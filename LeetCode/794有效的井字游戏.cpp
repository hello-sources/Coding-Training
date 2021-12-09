bool win(char **board, char ch) {
    if (board[0][0] == ch && board[0][1] == ch && board[0][2] == ch) return 1;
    if (board[1][0] == ch && board[1][1] == ch && board[1][2] == ch) return 1;
    if (board[2][0] == ch && board[2][1] == ch && board[2][2] == ch) return 1;
    if (board[0][0] == ch && board[1][0] == ch && board[2][0] == ch) return 1;
    if (board[0][1] == ch && board[1][1] == ch && board[2][1] == ch) return 1;
    if (board[0][2] == ch && board[1][2] == ch && board[2][2] == ch) return 1;
    if (board[0][0] == ch && board[1][1] == ch && board[2][2] == ch) return 1;
    if (board[0][2] == ch && board[1][1] == ch && board[2][0] == ch) return 1;
    return 0;
}

bool validTicTacToe(char ** board, int boardSize){
    int xcnt = 0, ocnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') xcnt++;
            else if (board[i][j] == 'O') ocnt++;
        }
    } 
    if (ocnt == xcnt && win(board, 'X') == 0) return 1;
    else if (xcnt == ocnt + 1 && win(board, 'O') == 0) return 1;
    return 0;
}