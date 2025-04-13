class Solution {
public:
    int fn(int mul, long long y,int mod){
        int temp = 1;
        while (y > 0) {
            if (y % 2 == 1) {
                temp = (long long)temp * mul % mod;
            }
            mul = (long long)mul * mul % mod;
            y /= 2;
        }
        return temp;
    };
    int countGoodNumbers(long long n) {
        int mod=1e9+7;
        return (long long)fn(5, (n + 1) / 2,mod) * fn(4, n / 2,mod) % mod;
    }
};