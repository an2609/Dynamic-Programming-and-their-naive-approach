#include<bits/stdc++.h>
using namespace std;
int ma(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    char a[1000];
    char b[1000];
    cout<<"Enter the first string\n";
    cin.getline(a,1000);
    cout<<"Enter the second string\n";
    cin.getline(b,1000);
    int n=strlen(a);
    int m=strlen(b);
    int ar[n+1][m+1];
    memset(ar,0,sizeof(ar));
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<m+1; j++)
        {
            if(i==0||j==0)
                ar[i][j]=0;
            else if(a[i-1]==b[j-1])
                ar[i][j]=1+ar[i-1][j-1];
            else
            {
                ar[i][j]=ma(ar[i-1][j],ar[i][j-1]);
            }
        }
    }
    printf("Length of longest common subsequence is %d\n",ar[n][m]);
    /*for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<m+1; j++)
        {
            cout.width(4);
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }*/
}
