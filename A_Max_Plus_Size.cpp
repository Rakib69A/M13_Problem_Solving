#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int odd = INT_MIN, even = INT_MIN;
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(even < arr[i]){
                    even = arr[i];
                }
                cnt1++;
            }
            else{
                if(odd < arr[i]){
                    odd = arr[i];
                }
                cnt2++;
            }
        }
        int mx = max(even+cnt1,odd+cnt2);
        cout<<mx<<endl;
    }

    return 0;
}