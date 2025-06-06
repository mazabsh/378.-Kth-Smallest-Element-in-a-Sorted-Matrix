#include<iostream> 
#include<algorithm> 
#include<vector>

using namespace std; 

class Solution{
public: 
     int kthSmallest(vector<vector<int>>& matrix, int k){
       int n = matrix.size(); 
       int low = matrix[0][0]; 
       int high = matrix[n-1][n-1];
       int ans = high; 
       while(low<=high){
         int mid = low +(high-low)/2; 
         int count = 0; 
         for(int i=0; i<n;++i){
           count +=upper_bound(matrix[i].begin(), matrix[i].end(), mid) -matrix[i].begin(); 
         }
           if(count<k){
             low = mid+1; 
           }else {
             ans= mid; 
             high = mid-1; 
           }
        
      }
      return ans ;
     }
};
int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}}; 
    int k=8; 
    Solution sol; 
    cout << sol.kthSmallest(matrix, k) << endl; 
    return 0; 
}
