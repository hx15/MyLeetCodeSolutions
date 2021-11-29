class Solution {
public:
    struct outSum{
        char a;
        char c;
        outSum(char a0, char c0){
            a = a0;
            c = c0;
        }
        outSum(int a0, int c0){
            a = a0 + '0';
            c = c0 + '0';
        }
    };
    struct inSum{
        char a;
        char b;
        char c;
        inSum(char a0, char b0, char c0){
            a = a0;
            b = b0;
            c = c0;
        }
    };
    
    outSum charBinarySummer(inSum in){
        int sum;
        int carry;
        int a = in.a - '0';
        int b = in.b - '0';
        int c = in.c - '0';
        sum = a ^ b;
        carry = a & b | sum & c;
        sum ^= c;
        return outSum(sum,carry);
    }
    
    string addBinary(string a, string b) {
        int ap = a.size()-1;
        int bp = b.size()-1;
        char c = '0';
        string res = "";
        while(ap >= 0 && bp >= 0){
            outSum out = charBinarySummer(inSum(a[ap], b[bp], c));
            res += out.a;
            c = out.c;
            ap--;
            bp--;
        }
        
        while(bp >= 0){
            outSum out = charBinarySummer(inSum('0', b[bp], c));
            res += out.a;
            c = out.c;
            bp--;
        }
        
      while(ap >= 0){
            outSum out = charBinarySummer(inSum('0', a[ap], c));
            res += out.a;
            c = out.c;
          ap--;
        }
        
        if(c == '1')
            res += '1';
​
        reverse(res.begin(), res.end());
        
        return res;
    }
};
