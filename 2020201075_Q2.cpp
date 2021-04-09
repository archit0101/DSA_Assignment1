#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
#define max 10000
typedef long long unsigned llu;
using namespace std;
class BigInteger{
 public:
        string add(string num1, string num2);
        string factorial(long num);
        string multiply(string num1, string num2);
        string exponentiation(string a, long b);
        string gcd(string a, string b);
};
string BigInteger :: add(string num1, string num2){
    string result="";
    
    if(num1.length()> num2.length()){
        llu a;
        a= num1.length()-num2.length();
        string temp="";
        for(int i=0;i<a;i++){
            temp.push_back('0');
        }
        temp.append(num2);
        llu b= num1.length()-1;
        int carry =0;
        for(int i=b;i>=0;i--){
                int x=(num1[i]-'0')+(temp[i]-'0')+carry;
                char c=(x%10)+'0';
                result.push_back(c);
                carry=x/10;
            }
        

            if(carry!=0){
                while(carry!=0){
                    char q=(carry%10)+'0';
                    result.push_back(q);
                    carry/=10;
                    cout<<carry;
                }
                
            }
            reverse(result.begin(),result.end());
        }
        else if(num2.length()>num1.length()){
           llu a;
        a= num2.length()-num1.length();
        string temp="";
        for(int i=0;i<a;i++){
            temp.push_back('0');
        }
        temp.append(num1);
        llu b= num2.length()-1;
        int carry =0;
        for(int i=b;i>=0;i--){
                int x=(num2[i]-'0')+(temp[i]-'0')+carry;
                char c=(x%10)+'0';
                result.push_back(c);
                carry=x/10;
            }
            if(carry!=0){
                
                while(carry!=0){
                    char q=(carry%10)+'0';
                    result.push_back(q);
                    carry/=10;
                }
                
            } 
            reverse(result.begin(),result.end());
        }
        else{
            llu b= num2.length()-1;
            int carry =0;
            for(int i=b;i>=0;i--){
                   int x=(num2[i]-'0')+(num1[i]-'0')+carry;
                   char c=(x%10)+'0';
                   result.push_back(c);
                   carry=x/10;
                }
            if(carry!=0){
                  while(carry!=0){
                      char q=(carry%10)+'0';
                      result.push_back(q);
                      carry/=10;
                    }
                  
                } 
                reverse(result.begin(),result.end());
        }
        return result;
    }

string BigInteger :: multiply(string num1, string num2){
    string result="";
    int a= num1.length()-1;
    int b= num2.length()-1;
    for(int i=b; i>=0; i--){
        int carry=0,temp;
        string x;
        for(int j=0;j<(b-i);j++){
            x.push_back('0');
        }
        for(int j=a;j>=0;j--){
            temp=(num1[j]-'0')*(num2[i]-'0')+carry;
            char g=temp%10+'0';
            x.push_back(g);
            carry=temp/10;
        }
        while(carry!=0){
            char a=(carry%10)+'0';
            x.push_back(a);
            carry/=10;
        }
        reverse(x.begin(),x.end());
        result=add(result,x);
    }
    return result;
}
string BigInteger :: factorial(long num){
    string ans = to_string(num);
    for(int i=num-1; i>1; i--){
            ans = multiply(ans, to_string(i));
        }

        return ans;

}
string BigInteger :: exponentiation(string a, long b){
    char c;
    if(a[0]=='-'){
        if(b%2!=0){
            c='-';
        }
        a=a.substr(1,a.length()-1);
    }
	string ans;
    ans.push_back('1');
	while(b>0)
	{
	  if(b&1){
	     ans = multiply(ans,a);
	  }
	   
	  a=multiply(a,a); 
	  b = b>>1;
	}
	if(c=='-'){
        reverse(ans.begin(),ans.end());
        ans.push_back(c);
        reverse(ans.begin(),ans.end());
    }
	return ans;
}

string longDivision(string dividend, string divisor){
    long long int div = stoll(divisor);
    int len = dividend.length();
    string res = "";
    long long int rem;
    int i=0;
    long long int val = dividend[i]-'0';
    i++;
    while(val<div){
        val = val*10 + dividend[i++]-'0';
    }

    while(i<=len){
        int tempRes = val/div;
        rem = val%div;
        val = rem*10 + dividend[i++]-'0';
        res.push_back(tempRes + '0');
    }

    return to_string(rem);
}

bool isSmaller(string str1, string str2){ 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
    return true; 
    if (n2 < n1) 
    return false; 
  
    for (int i=0; i<n1; i++) 
    if (str1[i] < str2[i]) 
        return true; 
    else if (str1[i] > str2[i]) 
        return false; 
  
    return false; 
} 

bool great(string str1, string str2){
    return isSmaller(str2,str1);
}

string subtract(string n1, string n2){
    string res="";
    long long int l1=n1.length();
    long long int l2=n2.length(); 
    reverse(n1.begin(),n1.end()); 
    reverse(n2.begin(),n2.end()); 
    int carry = 0,diff;
    long long int i=0;
    for (i=0;i<l2;i++){ 
        diff=(n1[i]-'0')-(n2[i]-'0')-carry; 
        if(diff<0){ 
            diff=diff+10;
            carry=1; 
        } 
        else{
            carry = 0;
        }
        res.push_back(diff+'0'); 
    } 
  
    while(i<l1){ 
        diff=((n1[i]-'0')-carry); 
        if(diff<0){ 
         diff=diff+10; 
         carry=1; 
         } 
        else{
          carry=0; 
        }
        res.push_back(diff+'0'); 
        i++;
        } 
    reverse(res.begin(), res.end()); 
    res.erase(0, min(res.find_first_not_of('0'), res.size()-1));
    return res;
}

string subtractCount(string n1,string n2){
    string rem=n1;
    while(great(rem,n2)){
        rem=subtract(rem,n2);
    }
    return rem;
}

string divide(string n1, string n2){
    long long int l1=n1.length();
    long long int l2=n2.length();
    if(n2=="0"){
        return "0";
    }   
    if(l2>18){
        return subtractCount(n1,n2);
    }
    else{
        return longDivision(n1,n2);
    }
                    
}

string BigInteger :: gcd(string a, string b){
    if(b.length()>a.length()){
        swap(a,b);
    }
    if(b.length() == a.length()){
        if(great(b,a)){
                swap(a,b);
        }
    }
    if(b=="0") return a;
    else{
        string rem  = divide(a,b);
        return gcd(b,rem);
    }
}

int main(){
    BigInteger b;
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int num;
        cin>>num;
        if(num==1){
            string a;
            long long int x;
            cin>>a>>x;
            string res= b.exponentiation(a,x);
            cout<<res<<endl;
        }
        else if(num==2){
            string a,x;
            cin>>a>>x;
            string res= b.gcd(a,x);
            cout<<res<<endl;
        }
        else if(num==3){
            int a;
            cin>>a;
            string res = b.factorial(a);
            cout<<res<<endl;
        }
    }
    return 0;
}
