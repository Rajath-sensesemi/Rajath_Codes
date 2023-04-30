//By Rajath B T
/*You are given a string s and two integers x and y. You can perform two
types of operations any number
of times:
• Remove the substring "ab" and gain x points.
• Remove the substring "ba" and gain y points.
• Remove the substring "aba" or "bab" and gain x + y points.
• Remove the substring "aaa" or "bbb" and gain x * y points.
Return the maximum points you can gain after applying the above
operations on s.*/
#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int solve(char* s, int x, int y) {
    int n = strlen(s);
    int dp[n+1][4];

    // dp[i][j] stores the maximum score that can be obtained
    // by processing the first i characters of s and ending with state j
    // 0: no 'a' or 'b' processed yet
    // 1: last processed character is 'a'
    // 2: last processed character is 'b'
    // 3: last processed substring is 'ab' or 'ba'
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        char c = s[i-1];

        // Case 1: Remove "ab" and gain x points
        if (c == 'a' && i >= 2 && s[i-2] == 'b') {
            dp[i][1] = max(dp[i][1], dp[i-2][0] + x);
            dp[i][3] = max(dp[i][3], dp[i-2][2] + x);
        } else if (c == 'b' && i >= 2 && s[i-2] == 'a') {
            dp[i][2] = max(dp[i][2], dp[i-2][0] + y);
            dp[i][3] = max(dp[i][3], dp[i-2][1] + y);
        }

        // Case 2: Remove "aba" or "bab" and gain x + y points
        if (c == 'a' && i >= 3 && s[i-2] == 'b' && s[i-3] == 'a') {
            dp[i][3] = max(dp[i][3], dp[i-3][0] + x + y);
        } else if (c == 'b' && i >= 3 && s[i-2] == 'a' && s[i-3] == 'b') {
            dp[i][3] = max(dp[i][3], dp[i-3][0] + x + y);
        }

        // Case 3: Remove "aaa" or "bbb" and gain x * y points
        if (c == 'a' && i >= 3 && s[i-2] == 'a' && s[i-3] == 'a') {
            dp[i][0] = max(dp[i][0], dp[i-3][0] + x*y);
        } else if (c == 'b' && i >= 3 && s[i-2] == 'b' && s[i-3] == 'b') {
            dp[i][0] = max(dp[i][0], dp[i-3][0] + x*y);
        }

        // Case 4: Don't remove anything
        dp[i][0] = max(dp[i][0], dp[i-1][0]);
        dp[i][1] = max(dp[i][1], dp[i-1][1]);
        dp[i][2] = max(dp[i][2], dp[i-1][2]);
        dp[i][3] = max(dp[i][3], dp[i-1][3]);
    }

    return max(max(dp[n][0], dp[n][1]), max(dp[n][2], dp[n][3]));
}

int main() {
    char s[100];
    int x, y;
    printf("Enter the string s: ");
    scanf("%s", s);
    printf("Enter x and y: ");
    scanf("%d %d", &x, &y);

    int ans = solve(s, x, y);
    printf("The maximum points that can be gained is: %d\n", ans);

    return 0;
}