class Solution {
public:
    
    bool isValid(vector<vector<char>>& board, int row, int col, char element)
    {
        // Check if the element is valid in it's row
        for (int row_c = 0; row_c < board.size(); row_c++)
        {
            // row_c != row cause not compare with itself
            if (row_c != col && board[row][row_c] == element) return false;
        }
        
        // Check if the element is valid in it's column
        for (int col_r = 0; col_r < board.size(); col_r++)
        {
            if (col_r != row && board[col_r][col] == element) return false;
        }
        
        // Check if the element is valid in it's 3x3 sub-matrix
        // Get the initial position [row][col] of 3x3 matrix where element is located
        int initial_row = row - (row % 3);
        int initial_col = col - (col % 3);
        
        // Only iterate over 3x3 matrix
        for (int row_t = 0; row_t < 3; row_t++)
        {
            for (int col_t = 0; col_t < 3; col_t++)
            {
                // Ensure that don't compare actual element with itself
                if ((initial_row + row_t) != row && (initial_col + col_t) != col && board[initial_row + row_t][initial_col + col_t] == element) return false;
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        // Iterate over board vector by row and then column (element)
       for (int row = 0; row < board.size(); row++)
       {
           for (int col = 0; col < board.size(); col++)
           {
               // If the actual element isn't "." check if it's valid
               if (board[row][col] != '.')
               {
                   char e = board[row][col];
                   if (!isValid(board, row, col, e)) return false;
               }
           }
       }
    return true;
    }
};
