#include<bits/stdc++.h>
using namespace std;
int main() {
	int nums[] = {1,2,-2147483648};
	int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for(int i = 0; i < 3; i++) {
            if(nums[i] > max1) {
                max1 = nums[i];
            }
        }
        cout<<max1<<"\n";
         for(int i = 0; i < 3; i++) {   
            if((nums[i] > max2) && (nums[i] < max1)) {
                max2 = nums [i];
            }
         }
         cout<<max2<<"\n";
        for(int i = 0; i < 3; i++) {
            if((nums[i] < max1) && (nums[i] < max2) && (max3 < nums[i])) {
                max3 = nums[i];
            }
        }
        cout<<max3;
}
