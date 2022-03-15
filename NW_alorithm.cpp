#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <iostream>
#include <fstream>

#define MAX_N 120000
#define RAS 120000

#define DPRINTC(C) printf(#C " = %c\n", (C))
#define DPRINTS(S) printf(#S " = %s\n", (S))
#define DPRINTD(D) printf(#D " = %d\n", (D))
#define DPRINTLLD(LLD) printf(#LLD " = %lld\n", (LLD))
#define DPRINTLF(LF) printf(#LF " = %.5lf\n", (LF))

using namespace std;
typedef long long lld;
typedef unsigned long long llu;
using std::ifstream;

int n, m;
int match_score, mismatch_score, gap_score;
string A, B;
int dp[RAS][MAX_N];

/*
 Needleman-Wunsch algorithm for determining the optimal alignment between two strings
 assuming a given score for hits, gaps and mismatches.
 Complexity: O(n * m) time, O(n * m) memory
*/

inline int needleman_wunsch()
{
    for (int i=0;i<=n;i++) dp[i][0] = dp[0][i] = -i * gap_score;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            int S = (A[i-1] == B[j-1]) ? match_score : -mismatch_score;
            dp[i][j] = max(dp[i-1][j-1] + S, max(dp[i-1][j] - gap_score, dp[i][j-1] - gap_score));
        }
    }
    return dp[n][m];
}

inline pair<string, string> get_optimal_alignment()
{
    string retA, retB;
    stack<char> SA, SB;
    int i = n, j = m;
    while (i != 0 || j != 0)
    {
        if (i == 0)
        {
            SA.push('-');
            SB.push(B[j-1]);
            j--;
        }
        else if (j == 0)
        {
            SA.push(A[i-1]);
            SB.push('-');
            i--;
        }
        else
        {
            int S = (A[i-1] == B[j-1]) ? match_score : -mismatch_score;
            if (dp[i][j] == dp[i-1][j-1] + S)
            {
                SA.push(A[i-1]);
                SB.push(B[j-1]);
                i--; j--;
            }
            else if (dp[i-1][j] > dp[i][j-1])
            {
                SA.push(A[i-1]);
                SB.push('-');
                i--;
            }
            else
            {
                SA.push('-');
                SB.push(B[j-1]);
                j--;
            }
        }
    }
    while (!SA.empty())
    {
        retA += SA.top();
        retB += SB.top();
        SA.pop();
        SB.pop();
    }
    return make_pair(retA, retB);
}

int main()
{
    ifstream out("/Users/starkzihanqu/desktop/output.txt");
    ofstream align("/Users/starkzihanqu/desktop/alignment.txt");
    
    string curr;
    
    match_score = 2, mismatch_score = 1, gap_score = 1;
    while (getline(out, curr)) {
        cout << curr << endl;
        getline(out, curr);
        A = curr;
        getline(out, curr);
        getline(out, curr);
        B = curr;
        
        n = A.length(), m = B.length();
        if (abs((int)m - (int)n) < 5000 && m >= n) {
            unsigned int scoreResult = needleman_wunsch();
            if (scoreResult > 100) {
                align << ">" + B.substr(0,3) + A.substr(0, 3) + "pair sequence " << endl;
                align << scoreResult << endl;
                pair<string, string> alignment = get_optimal_alignment();
                align << alignment.first.c_str() << endl;
                align << alignment.second.c_str() << endl;
                align << endl;
            }
        }

//        printf("%d\n",needleman_wunsch());
        
        
//        printf("%s\n%s\n", alignment.first.c_str(), alignment.second.c_str());
    }

    
    return 0;
}

