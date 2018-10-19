#include<iostream.h>
using namespace std;

//solving 1-0 knapsack problem using dynamic programming
int knapsack_dp(int n, int M, int w[], int p[])
{
    int i,j;                 //i is items available and j is capacity of knapsack
    int knapsack[n+1][M+1];
    
    for(j=0;j<=M;j++)
        knapsack[0][j]=0;

    for(i=0;i<=n;i++)
        knapsack[i][0]=0;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=M;j++)
        {
            //checking if the weight of current item i is less than or equal to the capacity of sack,
            //taking maximum of once including the current item and once not including
            if(w[i-1]<=j)
            {
                knapsack[i][j]=max(knapsack[i-1][j],p[i-1]+knapsack[i-1][j-w[i-1]]);              //including current item
            }
            else
            {
                knapsack[i][j]=knapsack[i-1][j];        //not including current item
            }
        }
    }
 
 
    return knapsack[n][M];
 
 
}
 
int main()
{
    int i,j;
    int n;  //number of items
    int M;  //capacity of knapsack
 
    cout<<"Enter the no. of items ";
    cin>>n;
 
    int w[n];  //weight of items
    int p[n];  //value of items
 
    cout<<"Enter the weight and price of all items"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>w[i]>>p[i];
    }
 
    cout<<"enter the capacity of knapsack  ";
    cin>>M;
 
 
    int result=knapsack_dp(n,M,w,p);
 
    //the maximum value will be given by knapsack[n][M], ie. using n items with capacity M
    cout<<"The maximum value of items that can be put into knapsack is "<<result;
 
    return 0;
 }
