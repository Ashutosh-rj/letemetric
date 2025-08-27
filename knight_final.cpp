#include <iostream>
#include <cmath>
using namespace std;

int findMoves(int knightrow, int knightcol, int queenrow, int queencol, int chesssize) {
    int knightMoves[8][2] = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
        {1, -2}, {1, 2}, {2, -1}, {2, 1}
    };
    
    int validMoves = 0;
    
    for (int i = 0; i < 8; i++) {
        int newRow = knightrow + knightMoves[i][0];
        int newCol = knightcol + knightMoves[i][1];
        
        if (newRow >= 1 && newRow <= chesssize && newCol >= 1 && newCol <= chesssize) {
            bool attacked = false;
            
            if (newRow == queenrow || newCol == queencol) {
                attacked = true;
            }
            
            if (abs(newRow - queenrow) == abs(newCol - queencol)) {
                attacked = true;
            }
            
            if (!attacked) {
                validMoves++;
            }
        }
    }
    
    return validMoves;
}

int main() {
    int knightrow, knightcol, queenrow, queencol, chesssize;
    cin >> knightrow >> knightcol >> queenrow >> queencol >> chesssize;
    
    cout << findMoves(knightrow, knightcol, queenrow, queencol, chesssize) << endl;
    
    return 0;
}