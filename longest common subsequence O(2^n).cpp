#include<bits/stdc++.h>
using namespace std;
int longest(char ar[],char br[],int n,int m)
{
    if(n==-1||m==-1)
        return 0;
    else if(ar[n]==br[m])
    {
        return 1+longest(ar,br,n-1,m-1);
    }
    else
        return max(longest(ar,br,n-1,m),longest(ar,br,n,m-1));
}
int main()
{
    char ar[10000];
    char br[10000];
    cout<<"Enter the first string\n";
    cin>>ar;
    cout<<"Enter the second string\n";
    cin>>br;
    cout<<"The length of longest common subsequence is ";
    cout<<longest(ar,br,strlen(ar)-1,strlen(br)-1)<<endl;
}
