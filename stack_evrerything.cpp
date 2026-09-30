//code for stack using arrays
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define max_len 1000
class stack1{
    public:
    ll arr[max_len]; int i=0;
    bool full1(){
        if(i>=max_len){return true;}
        return false;
    }
    bool empty1(){
        if(i==0){return true;}
        return false;
    }
    void push1(ll data){
        if(full1()){cout<<"sorry its full\n"; return;}
        arr[i++]=data;
    }
    void pop1(){
        if(empty1()){cout<<"sorry its empty\n"; return;}
        i--;
    }
    ll top1(){
        if(empty1()){cout<<"sorry its empty\n"; return -1;}
        return arr[i-1];
    }
    ll size1(){
        return i; // returns 0 if empty
    }
};
//code for nsl values
int main(){
     
    stack<ll>me;
    vector<ll>given={};
    ll n=given.size();  vector<ll>output(n);
    for(int i=0;i<n;i++){
        while(!me.empty() && me.top()>=given[i]){
            if(me.top()>=given[i]){
                me.pop();
            }
        }
        if(me.empty()){output[i]=-1;}
        else{output[i]=me.top();}
        me.push(given[i]);
    }
}
//code for ngr indexes
int main(){
    stack<pair<ll,ll>>me;
    vector<ll>given={};
    ll n=given.size();  vector<ll>output(n);
    for(int i=n-1;i>-1;i--){
        while(!me.empty() && me.top().first<=given[i]){
            if(me.top().first<=given[i]){
                me.pop();
            }
        }
        if(me.empty()){output[i]=-1;}
        else{output[i]=me.top().second;}
        me.push({given[i],i});
    }
}
// min stack
int main(){ 
    stack<ll>one;
    stack<ll>two;
    //push
    if(two.empty() || num<=two.top()){two.push(num);}
    one.push(num);
    //view minimum element
    if(!two.empty()){cout<<two.top();}
    //popping element
    if(one.top()==two.top()){two.pop();}
    one.pop();
}
// recursive sorting of stack
void placer(ll temp,stack<ll>&me){
    stack<ll>hehe;
    while(!me.empty() && me.top()<temp){
        hehe.push(me.top()); me.pop();
    }
    me.push(temp);
    while(!hehe.empty()){
        me.push(hehe.top()); hehe.pop();
    }
}
void insertionsort(stack<ll>&me){
    if(me.size()<=1){return;}
    ll temp=me.top(); me.pop();
    insertionsort(me);
    placer(temp,me);
    return;
}
int main(){
    stack<ll>me; vector<ll>given={};
    for(int i=0;i<n;i++){
        me.push(given[i]);
    }
    insertionsort(me);
    debug(me);
}
//below is stack using linked lists
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class node{ public:
    ll data=0; node* next=nullptr;
    node(): data(0), next(nullptr){}
    node(ll data1):data(data1), next(nullptr){}
    node(ll data1,node* next1):data(data1), next(next1){}
};
class stack1{ public:
    node* curr=nullptr;
    bool empty1(){
        if(curr==nullptr){return true;} return false;
    }
    void push1(ll data1){
        node* temp=new node(data1);
        temp->next=curr;
        curr=temp;
    }
    void pop1(){
        if(empty1()){cout<<"underflow\n"; return;}
        node* temp=curr->next;
        delete curr; curr=temp;
    }
    ll top1(){
        if(empty1()){cout<<"underflow\n"; return -1;}
        return curr->data;
    }
    ~stack1(){
        while(curr){
            node* temp=curr->next;
            delete curr; curr=temp;
        }
    }
};
int main(){
    stack1 astack;
}

