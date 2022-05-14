#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int maxknapsackvalue(int n, int k, int wt[], int val[])
{
    int maxValue[k+1][n+1];
    for (int i = 0; i < k + 1; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            if (i == 0 || j == 0) {
                maxValue[i][j] = 0;
            } else if (wt[i - 1] <= j) {
                int profit1 = val[i - 1] + maxValue[i - 1][j - wt[i - 1]];

                int profit2 = maxValue[i - 1][j];

                maxValue[i][j] = std::max(profit1, profit2);
            } else {
                
                maxValue[i][j] = maxValue[i - 1][j];
            }
        }
    }

    return maxValue[k][n];
}

int main()
{
    int t,n,k;
    cin>>k;
    cin>>n>>k;
    int wt[k],val[k];
    for(int i=0;i<k;i++)
    {
        cin>>wt[i];
        cin>>val[i];
    }
    cout<<maxknapsackvalue(n,k,wt,val);
    
    return 0;
}
