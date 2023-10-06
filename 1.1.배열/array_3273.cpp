// 입력에 맞는 합을 표현할수 있는 배열 쌍 갯수 세기 -> 시간복잡도 고려 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int num;cin>>num; // 반복횟수 
  int sum = 0;
  int count = 0;
  vector<int> v1(num);
  for(int i = 0 ;i<num;i++) cin >> v1[i];
  cin >>sum;
  vector<int> v2(sum+1);
  for(int i =0;i<num;i++)
  {
    if(sum-v1[i] >= 0)
    {
      if(v2[v1[i]] != 0)count++;
      v2[sum-v1[i]]++;
    }
  }
  cout <<count <<'\n';
}
/*
  for(int i =0;i<num;i++)
  {
    if(sum-v1[i] >= 0)
    {
      v2[sum-v1[i]]++;
      if(v2[v1[i]] != 0)count++;    *****
    }
  }
**** 여기를 이렇게 바꾸고 해서  계속 오류가 났어 
전 연습문제에서는 이런 구조였던거 같은데 거기서 생각없이 짜다보니까 계속 똑같은 실수를 한거같아
1. 전에 조건에 맞는 수가 있는지 확인하고 -> 2. 지금 해당하는 수의 배열값 올리기 -> 반복 
*/