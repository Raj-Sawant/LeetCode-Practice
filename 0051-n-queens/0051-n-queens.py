class Solution:
    def solveNQueens(self, n):
        def create_board(queens):
            board = []
            for i in range(n):
                row = ['.'] * n
                row[queens[i]] = 'Q'
                board.append(''.join(row))
            return board
        
        def is_safe(row, col, queens):
            for prev_row in range(row):
                prev_col = queens[prev_row]
                if prev_col == col:
                    return False
                if abs(prev_row - row) == abs(prev_col - col):
                    return False
            return True
        
        def backtrack(row, queens):
            if row == n:
                result.append(create_board(queens))
                return
            
            for col in range(n):
                if is_safe(row, col, queens):
                    queens[row] = col 
                    backtrack(row + 1, queens)
            
        result = []
        queens = [-1] * n  
        backtrack(0, queens)
        return result  