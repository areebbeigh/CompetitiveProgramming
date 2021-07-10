// { Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;


class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String S[] = read.readLine().split(" ");
            int R = Integer.parseInt(S[0]);
            int C = Integer.parseInt(S[1]);
            String line[] = read.readLine().trim().split("\\s+");
            int matrix[][] = new int[R][C];
            int c = 0;
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    matrix[i][j] = Integer.parseInt(line[c++]);
                }
            }
            Solution ob = new Solution();
            int ans = ob.median(matrix, R, C);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#
class Solution {
    int findMedian(int matrix[][], int size, int lo, int hi) {
        
        while (lo <= hi) {
            int m = lo + (hi - lo)/2;

            // Does this number split the matrix into two halves?
            int lesserCount = 0;
            boolean isInArray = false;
            for (int ir = 0; ir < matrix.length; ir++) {
                int row[] = matrix[ir];
                int searchIdx = Arrays.binarySearch(row, m);
                
                if (searchIdx >= 0) {
                    isInArray = true;
                    while(searchIdx < row.length-1 && row[searchIdx+1] == m) {
                        searchIdx++;
                    }
                    lesserCount += searchIdx + 1;
                } else {
                    searchIdx = -(searchIdx + 1);
                    lesserCount += searchIdx;
                }
                
                // System.out.println(m + " " + Arrays.toString(row) + " sIdx: " + searchIdx);
            }
            
            // System.out.println(m + " " + lesserCount + " " + lo + " " + hi);
            
            if (lesserCount-1 == size/2 && isInArray) return m;
            
            if (lesserCount-1 < size/2) {
                lo = m + 1;
            } else {
                hi = m - 1;
            }
        }
        
        return lo;
    }
    
    int median(int matrix[][], int r, int c) {
        int noOfElements = r * c;
        
        // Find min and max
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        
        for (int ir = 0; ir < r; ir++) {
            min = Math.min(matrix[ir][0], min);
            max = Math.max(matrix[ir][c - 1], max);
        }
        
        // System.out.println(min + " " + max);
        
        return findMedian(matrix, noOfElements, min, max);
    }
}