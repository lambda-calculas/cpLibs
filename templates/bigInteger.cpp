#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll ;
typedef long long ll ;

#define vi vector<int> 
const int base=1e9;
typedef vi BigInt;

void Set(BigInt &a){
  while(a.size() > 1 && a.back()==0){
    a.pop_back();
  }
}

void Print(BigInt a){
  Set(a);
  printf("%d",(a.size()==0) ?0:a.back());
  for(int i=a.size();i>=0;i--){
    printf("%09d",a[i]);
    printf("\n");
  }
}

BigInt Integer(string s){
  BigInt ans ;
  if(s[0]=='-'){
    return ans;
  }
  if(s.size()==0){
    ans.pb(0);
    return ans;
  }
  while(s.size()%9!=0){
    s='0'+s;
  }
  for(int i=0;i<s.size();i+=9){
    int v=0;
    for(int j=i;j<i+9;j++){
      v=v*10+(s[j]-'0');
    }
    ans.insert(ans.begin(),v);
  }
  Set(ans);
  return ans;
}


