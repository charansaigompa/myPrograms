#include<iostream> 
#include<vector> 
using namespace std; 
void merge(vector<int> &a,int s,int mid,int e){ 
 vector<int>temp; 
 int i=s,j=mid+1; 
 while(i<=mid&&j<=e){ 
    if(a[i]<a[j]){ 
        temp.emplace_back(a[i]); 
        i++; 
    } 
    else{ 
        temp.emplace_back(a[j]); 
        j++; 
    } 
     
  
 } 
 while(i<=mid){ 
     temp.emplace_back(a[i]); 
        i++; 
 } 
 while(j<=e){ 
     temp.emplace_back(a[j]); 
        j++; 
 } 
 for(int idx=s,x=0;idx<=e;idx++){ 
        a[idx]=temp[x++]; 
    } 
 
} 
 
void mergSort(vector<int>&arr,int s,int e){ 
    if(s>=e){ 
        return; 
    } 
    int mid=s+(e-s)/2; 
    mergSort(arr,s,mid);//left array 
    mergSort(arr,mid+1,e); 
    merge(arr,s,mid,e); 
 
} 
 
int main(){ 
    vector<int>arr={6,4,2,3,7,8}; 
    mergSort(arr,0,arr.size()-1); 
    for(int x:arr){ 
        cout<<x<<" "; 
    } 
    return 0; 
} 
//QUICK SORT 
#include<iostream> 
#include<vector> 
using namespace std; 
int part(vector<int>&v,int s,int e){ 
    int i=s-1,piv=v[e]; 
    for(int j=s;j<e;j++){ 
        if(v[j]<=piv){ 
            i++; 
            swap(v[i],v[j]); 
        } 
        
    } 
     i++; 
        swap(v[i],v[e]); 
        return i; 
 
} 
 
void quickSort(vector<int>&v,int s, int e){ 
 
    if(s>=e) return; 
       int pvtIdx=part(v,s,e); 
       quickSort(v,s,pvtIdx-1); 
       quickSort(v,pvtIdx+1,e); 
} 
 
int main(){ 
    vector<int> v={4,5,3,5,7,3,6}; 
    quickSort(v,0,v.size()-1); 
    for(int x:v){ 
        cout<<x<<" "; 
    } 
} 
 
