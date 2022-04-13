
#include<bits/stdc++.h>
#define ll long long int
#define prime 11
using namespace std;
 ll createHashValue(string str,int n) 
 {
    ll result=0;
    for(int i=0;i<n;i++){
        result +=(ll)(str[i]*(ll)pow(prime,i)); 
    }
    return result;
 }
 ll recalculateHash(string str,int oldIndex, int newIndex,ll oldHash,int patLength){
    ll newHash = oldHash - str[oldIndex];
    newHash/=prime;
    newHash+=(ll)(str[newIndex]*(ll)(pow(prime,patLength-1)));
    return newHash;
 }
 bool checkEqual(string str1,string str2,int start1,int start2,int end1,int end2){
     if(end1-start1 != end2-start2){
         return false;
     }
     while(start1<=end1 and start2<=end2){
         if(str1[start1]!=str2[start2]){
             return false;
         }
         start1++; 
         start2++;
     }
     return true;
 }
 int main()
 {
    string str="ACGTTCCACGTTCA";
    string pat="GTTCA";
    ll patHash=createHashValue(pat,pat.length());
    ll strHash=createHashValue(str,pat.length());
    cout<<"Pattern hash: "<<patHash<<"\n\n\n";
    for(int i=0;i<=str.length()-pat.length();i++){
    	cout<< "String hash: "<<strHash<<"\n";
        if(patHash == strHash && checkEqual(str,pat,i,0,i+pat.length()-1,pat.length()-1)){
            cout<<"\nPattern found at index: "<<i<<"\n";
        }
        if(i<str.length()-pat.length()){
            strHash = recalculateHash(str,i,i+pat.length(),strHash,pat.length());
        }
    }
 } 
