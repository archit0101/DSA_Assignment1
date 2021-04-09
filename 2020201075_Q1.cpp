#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<math.h>
#include<string>
typedef long long ll;
long long Size= 10;
using namespace std;
template<class T>
class stack{
 T*a;
 int top;
 int capacity;
 public:
    stack(long long size=Size);
    void push(T);
    T pop();
    long long size();
    bool isEmpty();
    bool isFull();
    T Top();
};

template<class T>
stack<T>::stack(long long size){
    a= new T[size];
    capacity= size;
    top= -1;
}
template<class T>
T stack<T>::Top(){
    return a[top];
}
template<class T>
T stack<T>::pop(){
    return a[top--];

}

template<class T>
void stack<T>::push(T t){
    top++;
    a[top]=t;
}

template<class T>
bool stack<T>::isEmpty(){
    if(top==-1){
        return true;
    }
    return false;
}
template<class T>
long long stack<T>::size(){
    return top+1;
}
template<class T>
bool stack<T>::isFull(){
    if(top==capacity-1){
        return true;
    }
    return false;
}
int preced(char o){
    if(o == '+' || o == '-')
    return 1;
    if(o == '*' || o =='/'|| o =='%')
    return 2;
    return 0;
}
double operation(double a, double b, char op ){
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '%': return ((int)a)%((int)b);
        case '/': return a/b;

    }
    return 0;
}
double calculator(string exp){
    stack<double> operands(exp.length());
    stack<char> operators(exp.length());
    for(int i=0;i<exp.length();i++){
        if(exp[i]=='('){
            operators.push(exp[i]);
        }
        if(isdigit(exp[i])||exp[i]=='.'){
            double val=0;
            while(i<exp.length()&&(isdigit(exp[i])||exp[i]=='.')){
                if(exp[i]=='.'){
                    i++;
                    int j=1;
                    while(j<exp.length()&&isdigit(exp[i])){
                        val+=(exp[i]-'0')*pow(10,-j);
                        j++;
                        i++;
                    }
                    break;
                }
                val=(val*10)+(exp[i]-'0');
                i++;
            }
            operands.push(val);
        }
        if(exp[i] == ')'){
            while(!operators.isEmpty() && operators.Top()!='('){
                double num2=operands.pop();
                double num1=operands.pop();
                char op=operators.pop();
                operands.push(operation(num1,num2,op));
            }
            if(!operators.isEmpty())
               operators.pop();
        }
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='%'||exp[i]=='*'||exp[i]=='/'){
            while(!operators.isEmpty() && preced(operators.Top()) >= preced(exp[i])){
                double num2=operands.pop();
                double num1=operands.pop();
                char op=operators.pop();
                operands.push(operation(num1,num2,op));
            }
            operators.push(exp[i]);
        }
    }
    while(!operators.isEmpty()){
        double num2= operands.pop();
        double num1= operands.pop();
        char op= operators.pop();
        operands.push(operation(num1,num2,op));
    }
    return operands.Top();
}
int main(){
    string s;
    double r;
    cout<<"enter the expression:";
    cin>>s;
    r=calculator(s);
    if(r==(int)r){
        cout<<r<<endl;
    }
    else{
        cout<<fixed<<setprecision(5)<<r<<endl;
    }
    return 0;
}

