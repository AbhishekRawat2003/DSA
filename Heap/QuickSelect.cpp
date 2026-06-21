// Quickselect is a selection algorithm used to find the k-th smallest element in an unordered list.  It is closely related to Quicksort but only recurses into the partition containing the target element, yielding an average time complexity of O(n) and a worst-case of O(n²). 

// Lomuto partition scheme

#include<iostream>
#include<vector>
using namespace std;

int quickSelect(vector<int> &nums,int left, int right,int k){   
    

}


int main(){
    vector<int> nums={7,4,6,3,9,1};
    int k=2;
     int result = quickSelect(nums, 0, nums.size() - 1, k);
    cout << "The " << k + 1 << "-th smallest element is: " << result << endl;
    
    return 0;
}