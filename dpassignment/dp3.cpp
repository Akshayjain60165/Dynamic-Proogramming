#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void fun(string a,string b,int n,int t)
{
    int arr[n+1][t+1];

    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=t;j++)
        {
            if(i==0||j==0)
            {
                arr[i][j]=0;
            }
            else
            {
                if(a[i-1]==b[j-1])
                {
                    arr[i][j]=arr[i-1][j-1]+1;
                }
                else
                {
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }
    }
    int in[n][t];
    char f[arr[n][t]+1];
    f[arr[n][t]]='\0';
    int g=arr[n][t]-1;
    int x,y;
    x=n;
    y=t;
    while(x>0&&y>0)
    {
        if(a[x-1]==b[y-1])
        {
             f[g]=a[x-1];
             x--;
             y--;
             g--;
        }
        else
        {
            if(arr[x-1][y]>arr[x][j-1])
            {
                x--;
            }
            else
            {
                y--;
            }
        }


    }
    for(int h=0;h<arr[n][t];h++)
    {
        cout<<f[h];
    }
}
int main()
{
    string a,b;
    cout<<" Enter the first string: ";
    cin>>a;
   cout<<" Enter the second string: ";
    cin>>b;
    cout<<"The longest subsequence is: ";
    fun(a,b,a.size(),b.size());

}
