#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of rows:";
    cin>>n;
    int i=1;
    // while(i<=n){
    //     int j=1;
    //     while(j<=i){
    //         char ch='A'+n-i+j-1;
    //         cout<<ch;
    //         j++;           /*C'
    //                          B C
    //                          A B C
    //                        */
    //     }
    //     cout<<endl;
    //     i++;
    // }

    // while(i<=n){
    //     int space=n-i;
    //     while(space>0){
    //         cout<<" ";
    //         space--;
    //     }                    /*|   *
    //                            |  **
    //     int j=1;               | ***
    //     while(j<=i){           |****
    //                          */
    //         cout<<"*";
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }

    // while(i<=n){
    //     int j=n-i+1;
    //     while(j){
    //         cout<<"*";      /*|****
    //         j--;              |***
    //                           |**
    //     }                     |*
    //     cout<<endl;         */
    //     i++;
    // }

    // while(i<=n){
    //     int space=1;
    //     while(space<=i-1){
    //         cout<<" ";
    //         space++;
    //     }
    //     int j=1;
    //     while(j<=n-i+1){
    //         cout<<"*";/*|****
    //                     | ***
    //                     |  **
    //                     |   *
    //                   *///<----replace "*" with i for number pattern.
    //         j++;
    //     }
    //     i++;
    //     cout<<endl;
    // }
    
    // while(i<=n){
    //     int space=1;
    //     while(space<=i-1){
    //         cout<<" ";
    //         space++;
    //     }
    //     int j=1;
    //     while(j<=n-i+1){
    //         cout<<j;  /*|1234
    //                     | 123
    //                     |  12
    //                     |   1
    //                   */
    //         j++;
    //     }
    //     i++;
    //     cout<<endl;
    // }
    
    
    // while(i<=n){
    //     int space=1;
    //     while(space<=i-1){
    //         cout<<" ";
    //         space++;
    //     }
    //     int j=i;
    //     while(j<=n){
            
    //         cout<<j;  /*|1234
    //                     | 234
    //                     |  34
    //                     |   4
    //                   */
    //         j++;
    //     }
    //     i++;
    //     cout<<endl;
    // }

    while(i<=n){
        int space=n-i;
        while(space){
            cout<<" ";
            space--;
        }
        int j=1;
        while(j<=i){
            cout<<j;
            j++;
        }
        int k=i-1;
        while(k>=1){
            cout<<k;
            k--;
        }
        cout<<endl;
        i++;
    }


    
    return 0;
}