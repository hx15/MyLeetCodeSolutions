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
