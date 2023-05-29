#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int i = 0;
    int index = 0;
    while(i < nums.size()){
        if(nums[i] != 0){
            swap(nums[i], nums[index++]);
        }
        ++i;
    }
}

int main(){
    
    return 0;
}