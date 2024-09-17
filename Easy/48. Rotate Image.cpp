class Solution {
public:
    // We use two functions: one to transpose the matrix and then to swap the elements inward.
    
    void transpose_matrix(vector<vector<int>>& matrix)
    {
        // Iterate over the matrix
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                // If j (we can define j as the column index of the element to access)
                // is greater than i (we can refer to i as the row index),
                // this will avoid swapping diagonal elements, as they don't change position
                // during transposition.
                if (j > i)
                {
                    // Swap the corresponding element positions
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        // Transpose the matrix first, since rotation is like a mirror of the transposition.
        // So we need to transpose the matrix first and then mirror it.
        transpose_matrix(matrix);
        
        // Define i as the first position from left to right
        int i = 0;
        
        // Define j as the last position from right to left, so then
        // we increment i by 1 and decrement j by 1, emulating that
        // we are moving towards the center of the matrix, row by row, swapping
        // the elements.
        int j = matrix.size() - 1;
        
        // Condition j > i to ensure we don't over-swap
        while (j > i)
        {
            for (int k = 0; k < matrix.size(); k++)
            {
                swap(matrix[k][i], matrix[k][j]);
            }
            i++;
            j--;
        }
    }
};
