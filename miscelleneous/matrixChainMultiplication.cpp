#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void printOptimalParens(vector<vector<int>>&s, int i, int j){
    if(i==j){
        cout<<"A"<<i<<" ";
        return;
    }
    cout<<"(";
    printOptimalParens(s, i, s[i][j]);
    printOptimalParens(s, s[i][j]+1, j);
    cout<<")";
}

int main(){
    int n=5;
    vector<vector<int>>m(n, vector<int>(n));
    vector<vector<int>>s(n, vector<int>(n));
    vector<int> p = {5,4,6,2,7};

    //traverse the upper triangle of the matrices m and s.
    cout<<"**** Calculating matrix M and S ****\n"<<endl;
    for(int col=2; col<n; col++){
        int i=1, j=col;
        cout<<"diagonal no --> "<<col<<endl;
        while(j<n){
            int cost =10e7, k=i;

            //find the minimum value of cost and k.
            while(k<j){
                int tempCost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                cout<<"i="<<i<<", "<<"j="<<j<<", "<<"k="<<k<<", "<<"cost="<< tempCost<<endl;

                //update the values of cost and k
                if(tempCost < cost){
                    cost = tempCost;
                    m[i][j] = tempCost;
                    s[i][j] = k;
                }
                k++;
            }
            printf("hence, M[%d][%d] = %d, S[%d][%d] = %d\n\n",i,j,m[i][j],i,j,s[i][j]);
            // cout<<"Optimal cost for i="<<i<<", j="<<j<<" is "<<m[i][j]<<" and corresponding value of k is "<<s[i][j]<<endl<<endl;
            i++, j++;
        }
    }


    cout<<"\nMatrix M"<<endl;
    for (int row = 1; row < n; row++){
        for (int col = 1; col < n; col++){
            cout<<setw(5)<<m[row][col]<<", ";
        }cout<<endl;        
    }
    cout<<"\nMatrix S"<<endl;
    for (int row = 1; row < n; row++){
        for (int col = 1; col < n; col++){
            cout<<setw(5)<<s[row][col]<<", ";
        }cout<<endl;        
    }
    cout<<"\nThe minimum cost of multiplication of given matrices is: "<<m[1][4];
    cout<<"\nThe optimal parenthesization can be given as:";
    printOptimalParens(s, 1, 4);

    return 0;
}