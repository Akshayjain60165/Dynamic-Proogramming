#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int ans=100000000;

void fun(int n,int* noa,int* eof,int* as1,int* as2,int* as2p,int* as1p,queue<int> &q1,queue<int> &q2)
{
    int arr1[n];
    int arr2[n];
    arr1[0]=noa[0]+as1[0];
    q1.push(1);
    q2.push(2);
    arr2[0]=noa[1]+as2[0];
     for(int i=1;i<n;i++)
     {
         arr1[i]=min(arr1[i-1]+as1[i],arr2[i-1]+as1p[i-1]+as1[i]);
         if(arr1[i-1]+as1[i]>arr2[i-1]+as1p[i-1]+as1[i])
         {
             q1.push(1);
         }
         else{
            q1.push(2);
         }
         arr2[i]=min(arr2[i-1]+as2[i],arr1[i-1]+as2p[i-1]+as2[i]);
         if(arr2[i-1]+as2[i]>arr1[i-1]+as2p[i-1]+as2[i])
         {
             q2.push(2);
         }
         else
         {
             q2.push(1);
         }
     }
     int d=min(arr1[n-1]+eof[0],arr2[n-1]+eof[1]);
     cout<<"Optimal path value from DP ";
     cout<<d<<"\n";
     cout<<"Optimal Path ";
     if(arr1[n-1]+eof[0]<arr2[n-1]+eof[1])
     {
        while(!q1.empty())
        {
            cout<<q1.front()<<",";
            q1.pop();
        }

    }
    else
    {
         while(!q2.empty())
        {
            cout<<q2.front()<<",";
            q2.pop();
        }
     }



}
void  solve(int index,int row,int time_taken,int n,int**a,int**b,int eof[]){
    if(index == n-1){
        time_taken=time_taken+eof[row];
     ans = min(ans,time_taken);


    }
    else{
      solve(index+1,row,time_taken+a[row][index+1], n,a,b,eof);//we don't shift row
     solve(index+1,1-row,time_taken + b[row][index] + a[1-row][index+1],n,a,b,eof);//we shift rows
    }
}



int main()
{
    time_t start, end;


       start = clock();
    cout<<"Enter number of stations";
    int n;
    cin>>n;
     int** a;
    int** b;

    a=new int*[2];
    b=new int*[2];

    for(int i = 0; i <2; i++)
    {
      a[i] = new int[n];
      b[i] = new int[n-1];
    }
    cout<<"\nEnter entry time for assembly line 1 and assembly line 2 respectively";
    int noa[2];
    int i;
    for(i=0;i<2;i++)
    {
        cin>>noa[i];
    }
    cout<<"\nEnter exit time for assembly line 1 and assembly line 2 respectively: ";
    int eof[2];
    for(i=0;i<2;i++)
    {
        cin>>eof[i];
    }
    cout<<"Enter the processing time at stations for assembly line 1: ";
    int as1[n];
    for(i=0;i<n;i++)
    {
        cin>>as1[i];
        a[0][i]=as1[i];
    }
    cout<<"Enter the processing time at stations for assembly line 2: ";
    int as2[n];
    for(i=0;i<n;i++)
    {
        cin>>as2[i];
        a[1][i]=as2[i];
    }
    cout<<"Enter Transfer times from assembly 1 to assembly 2: ";
    int as2p[n-1];
     for(i=0;i<n-1;i++)
    {
        cin>>as2p[i];
        b[0][i]=as2p[i];
    }
    cout<<"Enter Transfer times from assembly 2 to assembly 1: ";
    int as1p[n-1];
     for(i=0;i<n-1;i++)
    {
        cin>>as1p[i];
        b[1][i]=as1p[i];
    }

    queue<int> q1;
    queue<int> q2;

     fun( n, noa, eof, as1, as2, as2p, as1p,q1,q2);

    end = clock();

    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;

     time_t star,en;
      start = clock();
    cout<<"\nOptimal path value from brute force  ";
    solve(0,0,noa[0]+as1[0], n,a,b, eof);
    solve(0,1,noa[1]+as2[0],n,a,b,eof);
    cout<<ans<<"\n";

        time_taken = double(en - star) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         <<- time_taken << setprecision(5);
    cout << " min " << endl;

}
