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
            String S = read.readLine();
            
            Solution ob = new Solution();
            System.out.println(ob.longestPalin(S));
        }
    }
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
class Solution{
    static int[] getPalindromeRange(
        String s, int leftIdx, int rightIdx, int currLength) {
        while(
            leftIdx >= 0 
            && rightIdx <= s.length()-1 
            && s.charAt(leftIdx) == s.charAt(rightIdx)) 
        {
            leftIdx--;
            rightIdx++;
            currLength += 2;
        }
        
        int res[] = {leftIdx+1, rightIdx-1, currLength};
        return res;
    }
    
    static String longestPalin(String s) {
        if (s.length() <= 1) return s;
        
        int maxLength = 0;
        int startIdx = -1;
        int endIdx = -1;
        
        for (int i = 0; i < s.length(); i++) {
            // Odd length palindromes
            int resOdd[] = getPalindromeRange(s, i-1, i+1, 1);
            // Even length palindromes
            int resEven[] = getPalindromeRange(s, i, i+1, 0);
            
            if (resOdd[2] > maxLength) {
                maxLength = resOdd[2];
                startIdx = resOdd[0];
                endIdx = resOdd[1];
            }
            
            if (resEven[2] > maxLength) {
                maxLength = resEven[2];
                startIdx = resEven[0];
                endIdx = resEven[1];
            }
        }
        
        return s.substring(startIdx, endIdx+1);
    }
}