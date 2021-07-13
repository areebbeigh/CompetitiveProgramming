// { Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    int m = sc.nextInt();
                    int Arr[] = new int[m];
                    for(int i = 0;i<m;i++)
                        Arr[i] = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.count(Arr,m,n));
                }
        }
}    // } Driver Code Ends


//User function Template for Java
// https://practice.geeksforgeeks.org/problems/coin-change2448/1
class Solution
{
    public long count(int coins[], int length, int target) 
    { 
        long dp[][] = new long[target+1][coins.length+1];
        
        // Initialization / base cases
        for (int j = 0; j < coins.length+1; j++) dp[0][j] = 1;
        for (int i = 1; i < target+1; i++) dp[i][0] = 0;

        // Bottom up
        for (int t = 1; t < target+1; t++) {
            for (int l = 1; l < coins.length+1; l++) {
                long res = 0;
                if (coins[l-1] <= t) {
                    res += dp[t-coins[l-1]][l];
                }
                res += dp[t][l-1];
                dp[t][l] = res;
                // System.out.println(t + " " + l + " " + res);
            }
        }
        
        return dp[target][coins.length];
    } 
}