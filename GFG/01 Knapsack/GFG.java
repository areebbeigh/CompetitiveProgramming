// { Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class gfg {

  public static void main(String args[]) throws IOException {
    //reading input using BufferedReader class
    BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

    //reading total testcases
    int t = Integer.parseInt(read.readLine());

    while (t-- > 0) {
      //reading number of elements and weight
      int n = Integer.parseInt(read.readLine());
      int w = Integer.parseInt(read.readLine());

      int val[] = new int[n];
      int wt[] = new int[n];

      String st[] = read.readLine().trim().split("\\s+");

      //inserting the values
      for (int i = 0; i < n; i++) val[i] = Integer.parseInt(st[i]);

      String s[] = read.readLine().trim().split("\\s+");

      //inserting the weigths
      for (int i = 0; i < n; i++) wt[i] = Integer.parseInt(s[i]);

      //calling method knapSack() of class Knapsack
      System.out.println(new Solution().knapSack(w, wt, val, n));
    }
  }
}

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
class Solution {

  //Function to return max value that can be put in knapsack of capacity W.
  static int knapSack(int capacity, int wt[], int val[], int itemCount) {
    int dp[][] = new int[capacity + 1][itemCount + 1];

    for (int i = 0; i < itemCount + 1; i++) dp[0][i] = 0;
    for (int c = 0; c < capacity + 1; c++) dp[c][0] = 0;

    for (int c = 1; c < capacity + 1; c++) {
      for (int i = 1; i < itemCount + 1; i++) {
        if (wt[i - 1] <= c) {
          dp[c][i] =
            Math.max(val[i - 1] + dp[c - wt[i - 1]][i - 1], dp[c][i - 1]);
        } else {
          dp[c][i] = dp[c][i - 1];
        }
      }
    }

    return dp[capacity][itemCount];
  }
}
