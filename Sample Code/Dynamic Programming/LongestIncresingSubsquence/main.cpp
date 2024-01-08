#include <bits/stdc++.h>
using namespace std;

//Phuong phap tro thanh O(n^2)
// L[i] : do dai cua day con tang dai nhat ket thuc o chi so i
// L[i] = max ( L[i], (L[j] + 1) ) va a[i] > a[j]
int lengthOfLIS1(vector<int>& a){
    int n = a.size();
    vector<int> L(n,1);

    for(int i = 0; i < n; i++){
        // cap nhat L[i] bang L[j] da biet truoc
        // duyet qua tung phan tu dung truoc chi so i
        for (int j = 0 ; j < i; j++){
            if ( a[i] > a[j] ){
                L[i] = max (L[i], (L[j] + 1) );
            }
        }
    }
    return *max_element(L.begin(),L.end());
}
// Phuong phap su dung binary search de giam do phuc tap xuong O(nlogn)
int lengthOfLIS2(vector<int>& nums){

    int n = nums.size();
    vector<int> ans;
    ans.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back()) {
            ans.push_back(nums[i]);
        }
        else {
            int low = lower_bound(ans.begin(), ans.end(), nums[i] )- ans.begin();
            ans[low] = nums[i];
        }
    }
    return ans.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i <= n - 1; i++){
        cin >>a[i];
    }
    // Function call

    cout <<"Length of LIS is: " << lengthOfLIS1(a)<<endl;
    cout <<"Length of LIS is: " << lengthOfLIS2(a)<<endl;
    return 0;

}