class Solution {
    int[] printKClosest(int[] arr, int n, int k, int x) {
        // code here
        int vec[] = new int[k];
        int low=0,high=n-1,mid=0,mn=Integer.MAX_VALUE,ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            int diff=Math.abs(arr[mid]-x);
            if(diff<=mn){
                if(ans==-1)ans=mid;
                else{
                    if(diff==mn && arr[ans]<arr[mid]){
                        ans=mid;
                    }
                    if(diff<mn)ans=mid;
                }
                mn=diff;
            }
            if(arr[mid]<x)low=mid+1;
            else high=mid-1;
        }
        int total=0,i=ans-1,j=ans+1;
        if(arr[ans]!=x){
            vec[total]=arr[ans];
            total++;
        }
        while(total<k){
            if(i>=0 && j<n){
                if(Math.abs(arr[i]-x)<Math.abs(arr[j]-x))vec[total]=arr[i--];
                else vec[total]=arr[j++];
            }
            else if(i>=0)vec[total]=arr[i--];
            else vec[total]=arr[j++];
            total++;
        }
        return vec;
    }
}