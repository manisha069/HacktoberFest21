
/*
 * @lc app=leetcode id=600 lang=cpp
 *
 * [600] Non-negative Integers without Consecutive Ones
 */

// @lc code=start
class Solution {
public:
    int fibonacci(int n){
        
        int a=1,b=2;
        while(n--){
            int tmp = a;
            a = b;
            b = tmp + b;
        }
        return a;
    }
    int log2(int n){
        int res = 0;
        while(n){
            n >>= 1;
            res++;
        }
        return res;
    }

    int pow2(int n){
        if(n == 0) return 1;
        return 2*(pow2(n-1));
    }
    int findIntegers(int n) {
        n++;
        int i=log2(n);
        int ans=0;
        bool flag = false;
        while (i+1){
            if (n & pow2(i)){
                ans+=fibonacci(i);
                if(flag) break;
                flag=true;
            }else{
                flag=false;
            }
            i--;
        }
        return ans;
    }
};
// @lc code=end

