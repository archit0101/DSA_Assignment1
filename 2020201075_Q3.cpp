#include<iostream>
#define SIZE 10
using namespace std;
typedef long long ll;
template<class T>
class Deque{
public:
    T*a;
    ll capacity;
    ll count;
    ll fro,rear;
public:
    Deque(){
        a=new T[SIZE];
        fro=-1;
        rear=-1;
        capacity=SIZE;
        count=0;
    }
    Deque(ll n, T x){
        a= new T[n];
        for(ll i=0;i<n;i++){
            a[i]=x;
        }
        fro=0;
        rear=n-1;
        capacity=n;
        count=n;
    }
    bool empty(){
        if(fro==-1 && rear==-1){
            return true;
        }
        return false;
    }
    bool isfull(){
        if((rear+1)%capacity==fro){
            return true;
        }
        return false;
    }
    void push_back(T x){
        if(empty()){
        fro=0;
        rear=0;
        a[rear]=x;
        count=1;
        }
        else if(isfull()){
            T* temp = new T[2*capacity];
            ll k=0;
            for(ll i=fro;(i!=rear);i=(i+1)%capacity){
                    temp[k]=a[i];
                    k++;
                }
            temp[k]=a[rear];
            fro=0;
            rear=k;
            delete[] a;
            capacity=capacity*2;
            a=temp;
            rear++;
            a[rear]=x;
            count++;
        }
        else{
            
            rear=(rear+1)%capacity;
            a[rear]=x;
            count++;
        }

    }
    void push_front(T x){
        if(empty()){
            fro=0;
            rear=0;
            a[fro]=x;
            count=1;
        }
        else if(isfull()){
            T* temp= new T[2*capacity];
            ll k=0;
            for(ll i=fro;i!=rear;i=(i+1)%capacity){
                temp[k]=a[i];
                k++;
            }
            temp[k]=a[rear];
            fro=0;
            rear=k;
            delete[] a;
            capacity=2*capacity;
            a=temp;
            fro=capacity-1;
            a[fro]=x;
            count++;
        }
        else{
            if(fro == 0)
              fro=capacity-1;
            else
            {
             fro--;
            }
            
            a[fro]=x;
            count++;
        }
    }
    void pop_back(){
        if(empty()){
            cout<<"Deque is empty"<<endl;
        }
        else{
            if(rear==fro){
                rear=-1;
                fro=-1;
                count--;
            }
            else if(rear==0){
                rear=capacity-1;
                count--;
            }
            else{
                rear--;
                count--;
            }
        }
    }
    void pop_front(){
        if(empty()){
            cout<<"Deque is Empty"<<endl;
        }
        else{
            if(fro==rear){
                rear=-1;
                fro=-1;
                count--;
            }
            else{
            fro=(fro+1)%capacity;
            count--;
            }
        }
    }
    T front(){
        return a[fro];
    }
    T back(){
        return a[rear];
    }
    ll size(){
        return count;
    }

    void resize(int n, T x){

        T* temp=new T[n]; 

        if(empty()){
            for(int i=0; i<n; i++){
                temp[i] = x;
            }
        }
        else{

            int j=0;
            for (int i = fro; i!=rear && j<n; i=(i+1)%capacity) { 
                temp[j] = a[i]; 
                j++;
            } 
            if(count<=n) temp[j++] = a[rear];

            while(j<n){
                temp[j++] = x;
            }
        }

        rear = n-1; 
        fro = 0; 
        delete[] a; 
        capacity = n; 
        a = temp;
        count = n;
    }
    void clear(){
        T*temp= new T[SIZE];
        delete[] a;
        capacity=SIZE;
        a=temp;
        fro=-1;
        rear=-1;
        count=0;
    }
    T &operator[](ll n){
        ll x=(fro + n)%capacity;
        return a[x];
    }
    void display(){
        for(int i=fro;i!=rear;i=(i+1)%capacity){
            cout<<a[i]<<" ";
        }
        cout<<a[rear]<<endl;
    }
    
};

int main()
{ 
Deque<string> *arr =NULL;
    int Q,c,n;
    string x;
    cin>>Q;
    while (Q--){      
 
 cin>>c;

 switch (c)
 {

 case 1: cin>>x;
         arr->push_front(x);  
         arr->display();

         break;
 case 2: arr->pop_front();
         arr->display();
         break;
 
 case 3: cin>>x;
         arr->push_back(x);
         arr->display();
         break;
 
 case 4: arr->pop_back();
         arr->display();
         break;
 
 case 5: if(arr !=NULL)
         delete arr;
         arr = new Deque<string>();
         break;

 case 6: cin>>n>>x;
         if(arr !=NULL)
         delete arr;
         arr = new Deque<string>(n,x);
         arr->display();
         break;

 case 7: cout<<arr->front()<<endl;
         break;

 case 8: cout<<arr->back()<<endl;
         break;
 
 case 9: if(arr->empty())
          cout<<"true\n";
         else
          cout<<"false\n";
         break;

 case 10: cout<<arr->size()<<endl;
          break;

 case 11: cin>>n>>x;
          arr->resize(n,x);
          arr->display();
          break;

 case 12: arr->clear();
          break;
 
 case 13: cin>>n;
          cout<<(*arr)[n]<<endl;
          break;

 case 14: arr->display();
         break;

 default:
     break;
 }
    }


delete arr;
return 0;
}