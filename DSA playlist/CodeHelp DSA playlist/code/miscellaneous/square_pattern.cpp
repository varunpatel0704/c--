#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    int row=1;
    
    
    // while(row<=n){
    //     int col=1;
    //     while(col<=n){
    //         char ch='A'+row+col-2;/*A B C
    //                                 B C D
    //                                 C D E
    //                                 */
    //         cout<<ch;
    //         col++;
    //     }
    //     cout<<endl;
    //     row++;
    // }
    
    
    // while(row<=n){
    //     int col=1;
    //     while(col<=n){
    //         char ch='A'+col-1; /*A B C
    //                              A B C
    //                              A B C
    //                          */
    //         cout<<ch;
    //         col++;
    //     }
    //     cout<<endl;
    //     row++;
    // }
    
    
    while(row<=n){
        int col=1;
        while(col<=n){
            char ch='A'+row-1; /*A A A
                                 B B B 
                                 C C C
                             */
            cout<<ch;
            col++;
        }
        cout<<endl;
        row++;
    }   /*in short if the row is changing then we use row or i for building the relation 
          to print the element and use coloumn or j if the coloumn is changing.
          If both are changing then we use both in the relation.*/
    return 0;
}