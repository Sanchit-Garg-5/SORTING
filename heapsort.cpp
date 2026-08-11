#include <bits/stdc++.h>
using namespace std;
// --- Companion macros required for this debugger ---
typedef long long ll;
#define f first
#define s second
// --- Master Debugger Block ---
// Debug Overloads
#ifdef SanG_05
#define debug(x) _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class... Args> void _print(unordered_set <Args...> v);
template <class... Args> void _print(unordered_multiset <Args...> v);
template <class... Args> void _print(unordered_map <Args...> v);
template <class... Args> void _print(unordered_multimap <Args...> v);
template <class... Args> void _print(list <Args...> v);
template <class... Args> void _print(forward_list <Args...> v);
template <class... Args> void _print(stack <Args...> v);
template <class... Args> void _print(queue <Args...> v);
template <class... Args> void _print(priority_queue <Args...> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(unordered_set <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(unordered_multiset <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(unordered_map <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(unordered_multimap <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(list <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(forward_list <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(stack <Args...> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "]";}
template <class... Args> void _print(queue <Args...> v) {cerr << "[ "; while (!v.empty()) {_print(v.front()); cerr << " "; v.pop();} cerr << "]";}
template <class... Args> void _print(priority_queue <Args...> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "]";}

class maxheap{
    public:
    vector<ll>heap; 
    maxheap(vector<ll>&arr){ // constructor
        heap=arr;
    }
    void heapifydown(int idx,int boundary){ // tc is logn
        int n=heap.size();
        ll left,right;
        if(idx>=boundary){return;}
        if(2*idx+1<boundary){left=heap[2*idx+1];}
        if(2*idx+2<boundary){right=heap[2*idx+2];}
        ll mvalue=heap[idx], lidx=idx;
        if(2*idx+1<boundary && left>mvalue){mvalue=left; lidx=2*idx+1;}
        if(2*idx+2<boundary && right>mvalue){mvalue=right; lidx=2*idx+2;}
        if(lidx==idx){return;}
        else{
            swap(heap[idx],heap[lidx]); heapifydown(lidx, boundary);
        }
    }
    void swapfunc(int i,int j){
        swap(heap[0],heap[j]);
    }
    void heapifyup(int idx){ // tc is logn
        int n=heap.size();
        int pidx=(idx-1)/2;
        if(pidx<0 || idx==0){return;}
        ll parent=heap[(idx-1)/2];
        if(parent>=heap[idx]){return;}
        else{swap(heap[idx],heap[pidx]); heapifyup(pidx);}
    }
  

    void build_hd(){ // tc is o(n) only
        int n=heap.size(); 
        for(int i=(n/2)-1;i>-1;i--){
            heapifydown(i,n);
        }
    }
    void build_hu(){  // tc is o(n*logn) only
        int n=heap.size();
        for(int i=1;i<n;i++){
            heapifyup(i);
        }
    }
    int getmax(){ // tc is o(logn) 
        if(heap.size()){ return heap[0];}
        return -1;
       
    }
    void insertele(ll val){ //tc is o(logn)
        heap.push_back(val);
        heapifyup(heap.size()-1);
    }
    void deletemax(){ // tc is o(logn)
        int n=heap.size();
        swap(heap[0],heap[heap.size()-1]);
        heap.pop_back();
        if(heap.size()==0){return;}
        heapifydown(0,n);
    }
    void display(){
        for(auto it:heap){
            cout<<it<<" ";
        }
    }

};

int main(){
    cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);
    int n; cin>>n; vector<ll>arr(n,0); for(int i=0;i<n;i++){cin>>arr[i];}
    maxheap obj(arr);
    obj.build_hd();
    int k=0;
    for(int i=0;i<n;i++){cin>>arr[i];} 
    while(n-1-k>0){
        obj.swapfunc(0,n-1-k);
        obj.heapifydown(0,n-1-k);
        k++;
    }
    obj.display();
}