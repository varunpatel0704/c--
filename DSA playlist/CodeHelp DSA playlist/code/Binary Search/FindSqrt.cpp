#include <iostream>
using namespace std;

int binarySqrt(long long int N){

    long long int start=0, end=N, mid=start+(end-start)/2, ans;

    while (start<=end)
    {
        if (mid*mid==N)
        {
            return mid;
        }

        else if(mid*mid<N){

            ans=mid;
            start=mid+1;
        }

        else{

            end=mid-1;
        }

        mid=start+(end-start)/2;
    }
    
    return ans;
}

double preciseRoot(long long int n, int precison){

    double ans=binarySqrt(n);
    double factor=1;
    
    for(int i=0; i<precison;i++){
        
        factor=factor*0.1;
        
        int j = ans;
        for (double j = ans; j*j<n; j+=factor)
        {
            ans=j;
        }
        
    }

    return ans;
}

int main(){
    int num;
    cout<<"Enter num to find square root ";
    cin>>num;
    cout<<"Square root is "<<binarySqrt(num)<<endl;

    cout<<"\nprecise ans is "<<preciseRoot(num,3);
    return 0;
}