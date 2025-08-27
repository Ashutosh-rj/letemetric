#include <iostream>
#include <vector>
using namespace std;

bool isValidPosition(int row, int col, int chessSize) {
    return row >= 0 && row < chessSize && col >= 0 && col < chessSize;
}

bool isUnderQueenAttack(int row, int col, int queenRow, int queenCol) {
    return row == queenRow || col == queenCol || 
           abs(row - queenRow) == abs(col - queenCol);
}

int findMoves(int knightRow, int knightCol, int queenRow, int queenCol, int chessSize) {
    int validMoves = 0;
    
    int knightMoves[8][2] = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
        {1, -2}, {1, 2}, {2, -1}, {2, 1}
    };
    
    for (int i = 0; i < 8; i++) {
        int newRow = knightRow + knightMoves[i][0];
        int newCol = knightCol + knightMoves[i][1];
        
        if (isValidPosition(newRow, newCol, chessSize) && 
            !isUnderQueenAttack(newRow, newCol, queenRow, queenCol)) {
            validMoves++;
        }
    }
    
    return validMoves;
}

int main() {
    int knightRow, knightCol, queenRow, queenCol, chessSize;
    
    cin >> knightRow >> knightCol >> queenRow >> queenCol >> chessSize;
    
    int result = findMoves(knightRow, knightCol, queenRow, queenCol, chessSize);
    cout << result << endl;
    
    return 0;
}