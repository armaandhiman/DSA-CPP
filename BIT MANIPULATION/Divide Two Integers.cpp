class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == divisor)
        return 1;

        bool sign = true;
        
        if(dividend == 0)
        return 0;
        if((dividend > 0 && divisor < 0)||(dividend < 0 && divisor > 0))
        sign = false;

        long long ans = 0;
        long long n = (long long)abs((long long)dividend);
        long long d = (long long)abs((long long)divisor);

        divisor = (long long)abs((long long)divisor);

        while(n >= d)
        {
            int cnt = 0;
            while(n >= (d << (cnt+1)))
            cnt++;
            ans += (1 << cnt);
            n -= (d<<cnt);
        }
        if(ans == (1<<31) && sign == true)
        return INT_MAX;
        if(ans  == (1<<31) && sign == false)
        return INT_MIN;

        return sign?ans:-ans;

    }
};
