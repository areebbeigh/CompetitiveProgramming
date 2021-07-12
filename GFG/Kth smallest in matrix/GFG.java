// { Driver Code Starts
//Initial Template for Java

import java.util.*;
class KthSmallestElement{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int t=Integer.parseInt(sc.next());
		while(t>0)
		{
			int n=Integer.parseInt(sc.next());
			int[][] a=new int[n][n];
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
    				a[i][j]=Integer.parseInt(sc.next());
    		
			int k=Integer.parseInt(sc.next());
		    Solution ob = new Solution();
		    System.out.println(ob.kthSmallest(a,n,k));
		    
		    t--;
		}
	}
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1
class Solution
{
	public static int kthSmallest(int[][]mat,int n,int k)
	{
        int min = mat[0][0], max = mat[mat.length-1][mat[0].length-1];
        
        int lo = min, hi = max;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            int lesserCount = 0;
            
            // Count the elements less than mid in the matrix
            for (int rowIdx = 0; rowIdx < mat.length; rowIdx++) {
                if (lesserCount >= k) break;
                
                int row[] = mat[rowIdx];
                int searchIdx = Arrays.binarySearch(row, mid);
                
                if (searchIdx >= 0) {
                    lesserCount += searchIdx;
                } else {
                    searchIdx = -(searchIdx + 1);
                    lesserCount += searchIdx;
                }
            }
            
            if (lesserCount > k-1) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo-1;
    }
}