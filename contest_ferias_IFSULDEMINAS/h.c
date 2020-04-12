// Problema padrão: longest palindromic subsequence
// Código do LPS: https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

// A Dynamic Programming based C++ program for LPS problem 
// Returns the length of the longest palindromic subsequence in seq 
#include<stdio.h> 
#include<string.h> 
  
// A utility function to get max of two integers 
int max (int x, int y) { return (x > y)? x : y; } 
  
// Returns the length of the longest palindromic subsequence in seq 
int lps(char *str) 
{ 
   int n = strlen(str); 
   int i, j, cl; 
   int L[n][n];  // Create a table to store results of subproblems 
  
  
   // Strings of length 1 are palindrome of lentgh 1 
   for (i = 0; i < n; i++) 
      L[i][i] = 1; 
  
    // Build the table. Note that the lower diagonal values of table are 
    // useless and not filled in the process. The values are filled in a 
    // manner similar to Matrix Chain Multiplication DP solution (See 
    // https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/). cl is length of 
    // substring 
    for (cl=2; cl<=n; cl++) 
    { 
        for (i=0; i<n-cl+1; i++) 
        { 
            j = i+cl-1; 
            if (str[i] == str[j] && cl == 2) 
               L[i][j] = 2; 
            else if (str[i] == str[j]) 
               L[i][j] = L[i+1][j-1] + 2; 
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]); 
        } 
    } 
  
    return L[0][n-1]; 
} 
  
char * retira_a(char * x, int n, char * resp) {
	int cont = 0;
	
	for(int i = 0; i < n; i++) {
		if(x[i] != 'a') {
			resp[cont] = x[i];
			cont++;
		}
	}
	resp[cont] = '\0';
	return resp;

}

/* Driver program to test above functions */
int main() 
{ 
	char resp[10000];
    char seq[10000];
    scanf("%s", seq);
    int n = strlen(seq); 
    char * x = retira_a(seq, n, resp);
    printf ("%d\n", lps(x)); 
    return 0; 
} 
