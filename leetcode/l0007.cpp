//that's ugly.
//using some ugly edge configures

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        bool retp = x>=0;
        if(x == -2147483648)return 0;
        if(!retp)x=-x;
        while(x!=0){
            if(ret>214748364)return 0;bian
            ret *= 10;
            if(ret==214748364&&x%10>7)return 0;
            ret += x%10;
            x /= 10;
        }
        return retp?ret:-ret;
    }
};
