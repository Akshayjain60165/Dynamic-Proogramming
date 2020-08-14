#include<iostream>
using namespace std;

void par(int** s,int i,int j)
{
    if(i==j)
    {
        cout<<"A"<<i;
    }
    else
    {    int k=s[i][j];
           cout<<"(";
        par(s,i,k);

        par(s,k+1,j);
   cout<<")";
    }
}

void fun(int n,int* p)
{
    int i,m[n][n];
    int** s;
    s=new int*[n];
    for(i=1;i<n;i++)
    {
        m[i][i]=0;
    }
    for(i = 0; i <n; i++)
    {
      s[i] = new int[n];
    }

    for (int L = 2; L < n; L++)
	{
		for (i = 1; i < n - L + 1; i++)
		{
			int j = i + L - 1;
			m[i][j] = 0;
			for (int k = i; k <= j - 1; k++)
			{

				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

				if (q < m[i][j]||m[i][j]==0)
                {
                    m[i][j] = q;
                     s[i][j]=k;
                }

			}
		}
	}

     cout<<"Optimal parenthesis cost is: "<<m[1][n-1]<<"\n";
    cout<<" Optimal parentesis sequence is: ";
    par(s,1,n-1);

}


int main()
{
    int n;
    cout<<"Enter number of matrices to be multiplied";
    cin>>n;
    cout<<"\n Enter the dimensions of the matrices i.e. array p: ";
    int i;
    int arr[n+1];

    for(i=0;i<n+1;i++)
    {
        cin>>arr[i];
    }

   fun(n+1,arr);
}
