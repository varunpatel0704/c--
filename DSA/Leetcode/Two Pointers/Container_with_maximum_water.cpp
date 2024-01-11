#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    // trying to optimize using two pointers --> O(N) .
    // our objective is to find the rectangle with maximum area.
    // hence we should try to maximize the length and breadth of the reactangle at each step.
    
    // initialize two pointers - first at the beginning of array and second at the ending of the array.

    int i = 0, j = height.size() - 1;
    int maxArea = 0;
    while(i < j){
        // calculate the area of current rectangle.
        int h = min(height[i], height[j]), l = j-i;
        int area = l*h;
        maxArea = max(maxArea, area);

        if(height[i] < height[j]){
            int temp = height[i];
            while(height[i] <= temp and i < j){
                // try to find height[i] such that it is just greater than current height[i] (temp)
                i++;
            }
        }

        else if(height[j] <= height[i]){
            int temp = height[j];
            while(height[j] <= temp and i < j){
                j--;
            }

        }            
    }
    return maxArea;

    // brute force. Try out all the containers and return the one with maximum area. O(N^2) --> TLE.
    // int maxWater = 0;
    // for(int i=0; i<height.size()-1; i++){
    //     for(int j=i+1; j<height.size(); j++){
    //         int length = j - i;
    //         int breadth = min(height[i], height[j]);
    //         int area = length * breadth;
    //         maxWater = max(maxWater, area);
    //     }
    // }
    // return maxWater;
}

int main(){
    
    return 0;
}