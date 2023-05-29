#include <iostream>
using namespace std;

float dollar_conversion(float amount_dollar, float dollar_rate){
    float dollar_to_rupee=amount_dollar*dollar_rate;
    return dollar_to_rupee;

}
int main(){
    int a, b;
    cout<<"Enter the amount in dollars: ";
    cin>>a;
    cout<<"Enter the dollar-to-rupee conversion rate :";
    cin>>b;
    cout<<"The amount in rupees is: "<<dollar_conversion(a,b);
    return 0;
}