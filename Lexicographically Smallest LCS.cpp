#include<bits/stdc++.h>
using namespace std;

// function to find the lexicographically smallest longest common subsequence of two strings
string lcs(string N, string M);

// function to compare two strings and return the longer or lexicographically smaller one
string compare(string s1,string s2);

int main()
{
    string N,M;
    cin>>N>>M;
    string res=lcs(N,M); // calling the lcs function and storing the result
    cout<<res.length()<<endl; // output the length of the lexicographically smallest LCS
    cout<<res; // output the lexicographically smallest LCS itself

    return 0;
}

string lcs(string N, string M)
{
    // create and initialize an array to store the LCS
    string dp[M.length()+1];
    for(int i=0;i<=M.length();i++)
        dp[i]="";

    // iterate over the characters of the two input strings
    for(int i=1;i<=N.length();i++)
    {
        string upperCell="", diagonalCell="";
        for(int j=1;j<=M.length();j++)
        {
            //to track value of upper cell and left cell
            // move the current value of dp[j] to upperCell
            // and the value of dp[j-1] to leftCell
            diagonalCell=move(upperCell);
            upperCell=move(dp[j]);

            // if the current characters match, append it to the LCS found so far
            //here diagonalCell contain dp[i-1][j-1] cell after one iteration
            if(N[i-1]==M[j-1])
                dp[j]=move(diagonalCell+N[i-1]);
            // if the characters don't match, take the string which length is longer of the two adjacent cells
            // or if find equal take the lexicographically smallest one
            else{
                dp[j]=move(compare(dp[j-1],upperCell));
            }
        }
    }
    // return the last cell of the dp array, which contains the lexicographically smallest LCS of the two input strings
    return dp[M.length()];
}

// function to compare two strings and return the longer or lexicographically smaller one
string compare(string s1,string s2)
{
    if(s1.length()>s2.length())
        return s1;
    else if(s1.length()<s2.length())
        return s2;
    else
    {
        // compare character by character until the first difference is found
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]<s2[i])
                return s1;
            else if(s1[i]>s2[i])
                return s2;
        }
        // if both strings are identical, return either one
        return s1;
    }
}

