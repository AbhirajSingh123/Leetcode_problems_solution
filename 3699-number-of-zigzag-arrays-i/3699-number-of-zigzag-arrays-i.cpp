class Solution {
public:
    int zigZagArrays(int n,int l,int r){
        long long mod=1000000007LL;
        int m=r-l+1;
        vector<vector<long long>>dp(m,vector<long long>(2,0)),ndp(m,vector<long long>(2,0));
        for(int num=0;num<m;num++){
            dp[num][0]=1;
            dp[num][1]=1;
        }
        for(int len=2;len<=n;len++){
            vector<long long> pref(m,0),suff(m,0);
            long long s=0;
            for(int i=0;i<m;i++){
                s=(s+dp[i][0])% mod;
                pref[i]=s;
            }
            s=0;
            for(int i=m-1;i>=0;i--){
                s=(s+dp[i][1])% mod;
                suff[i]=s;
            }
            for(int num=0;num<m;num++){
                long long up=(num>0? pref[num-1]:0),down=(num+1<m?suff[num+1]:0);
                ndp[num][1]=up;
                ndp[num][0]=down;
            }
            swap(dp,ndp);
        }
        long long ans=0;
        for(int num=0;num<m;num++) ans=(ans+dp[num][0]+dp[num][1])%mod;
        return(int)ans;
    }
};
