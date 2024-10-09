#include<bits/stdc++.h>
using namespace std;

class SegTree{
    
    public:
    
    vector<int>seg;
    SegTree(int n){
        seg.resize(4*n);
    }
    
    void build(vector<int>&arr, int low, int high, int index){
        if(low>=high){
            seg[index] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(arr,low,mid,2*index+1);
        build(arr,mid+1,high,2*index+2);
        seg[index] = min(seg[2*index+1],seg[2*index+2]);
    }
    
    int query(vector<int>&arr, int l, int r, int low, int high, int index){
        if(low>r || high<l){
            return 1e9;
        }
        else if(low>=l && r>=high){
            return seg[index];
        }
        int mid = (low+high)/2;
        return min(query(arr,l,r,low,mid,2*index+1),query(arr,l,r,mid+1,high,2*index+2));
    }
    
    void update(vector<int>&arr, int i, int val, int low, int high, int index){
        if(low>=high){
            seg[index] = val;
            return;
        }
        int mid = (low+high)/2;
        if(i<=mid){
            update(arr,i,val,low,mid,2*index+1);
        }
        else{
            update(arr,i,val,mid+1,high,2*index+2);
        }
        seg[index] = min(seg[2*index+1],seg[2*index+2]);
    }
    
};
