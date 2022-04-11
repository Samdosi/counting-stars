/*

09/17/2021
counting stars
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
const int DX[] = {-1,0,0,1};
const int DY[] = {0,-1,1,0};
// function prototype
void floodfill(int m, int n, int r, int c, char grid[][max+1], char newchar, char oldchar);
int countstar(char str[][max+1], int m, int n);

int main(void) {
    // m is the number of lines and n is the number of pixles in each line
    int m, n, i, result;
    // declaring the temp variable to store the strings
    char str [max][max+1];
    //getting the number of lines a number of pixles
    int testcase= 1;
    while(scanf("%d %d", &m, &n) != EOF)
    {
        
        for(i=0; i<m; i++)
        {
        
            scanf("%s", str[i]);
        }

    
        // function will count the stars and return a int
        result = countstar(str, m, n);
        
        printf("Case %d: %d\n",testcase, result);
        testcase++;
    }
    return 0;
}
void floodfill(int m, int n, int r, int c, char grid[][max+1], char newchar, char oldchar)
{
    int i;
        // out of range
        if(r<0 || c<0 || r>=m || c>=n)
            return ;
        // return if is a #
        if(grid[r][c]!= oldchar)
            return;
    
        grid[r][c]= newchar;
    
    for (i=0; i<4; i++){
        floodfill(m,n, r + DX[i], c + DY[i], grid,'#', '-');
    }

    

                
}

int countstar(char str[][max+1], int m, int n)
{
    int i=0, j=0, res=0;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(str[i][j]=='-'){
                res++;
                floodfill(m, n,i,j,str, '#', '-');
            }
        }
    }
    
    return res;
}
       
