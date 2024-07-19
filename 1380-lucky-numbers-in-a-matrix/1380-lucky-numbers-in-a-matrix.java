import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        
        for (int i = 0; i < matrix.length; i++) {
            int minRow = Integer.MAX_VALUE;
            int colIndex = -1;
            
            // Find the minimum element in the current row
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] < minRow) {
                    minRow = matrix[i][j];
                    colIndex = j;
                }
            }
            
            boolean isLucky = true;
            
            // Check if the minimum element is also the maximum in its column
            for (int k = 0; k < matrix.length; k++) {
                if (matrix[k][colIndex] > minRow) {
                    isLucky = false;
                    break;
                }
            }
            
            if (isLucky) {
                result.add(minRow);
            }
        }
        
        return result;
    }
}
