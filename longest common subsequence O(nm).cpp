#include<bits/stdc++.h>
using namespace std;
int ma(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

char temp[10000];
int top=0;
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
    char br[n+1][m+1];
    memset(ar,0,sizeof(ar));
    memset(br,0,sizeof(br));
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<m+1; j++)
        {
            if(i==0||j==0)
                ar[i][j]=0;
            else if(a[i-1]==b[j-1])
            {
                ar[i][j]=1+ar[i-1][j-1];
                br[i][j]='D';
            }

            else
            {
                int k=ar[i-1][j];
                int f=ar[i][j-1];
                if(k>f)
                {
                    ar[i][j]=k;
                    br[i][j]='L';
                }
                else
                {
                    ar[i][j]=f;
                    br[i][j]='U';
                }
            }
        }
    }
    printf("Length of longest common subsequence is %d\n",ar[n][m]);
    int i=n;
    int j=m;
    while(i>0&&j>0)
    {
        if(a[i-1]==b[j-1])
        {
            temp[top++]=a[i-1];
        }
        if(br[i][j]=='D')
        {
            i--;
            j--;
        }
        else if(br[i][j]=='U')
        {
            j--;
        }
        else if(br[i][j]=='L')
        {
            i--;
        }
    }
    cout<<"One of the longest common subsequence is ";
    for(int i=top-1;i>=0;i--)
    {
        printf("%c",temp[i]);
    }
    cout<<endl;
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
