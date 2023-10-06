// 처음에 쓴 문자열을 재배열 했을 때 나올수 있는 경우면 possible 아니면 impossible 
#include <iostream>
#include <algorithm>
using namespace std;
int arr[27];
int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str1,str2;
  int num;cin >> num;
  while(num--)
  {
    cin>>str1>>str2;
    int check = 1;
    fill(arr,arr+27,0);
    if(str1.length() == str2.length()){ //길이가 같아야 함 
      for(char e : str1)
      {
        arr[e - 'a']++;
      }
      for(char e : str2)
      {
        if(arr[e - 'a'] == 0){
          cout << "Impossible"<<'\n';
          check = 0;
          break;
        }
        arr[e-'a']--; //한번씩만 사용해야 해서 쓰고 삭제해야함 
      }
      if(check) cout <<"Possible"<<'\n';
    }else{
      cout <<"Impossible"<<'\n';
    }
  }
}