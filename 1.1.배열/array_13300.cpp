//남자끼리 여자끼리 같은 학년 끼리  K명이서 한방 쓸수 있게 방배정
#include <iostream>
using namespace std;

int memo[7][2];

int main(void)
{
  int N,K;
  int count = 0;
  cin >>N>>K;
  while(N--)
  {
    int i,j;cin >>i>>j;
    memo[j][i]++;
  }
  for(int i = 1;i<7;i++) // 근데 이렇게 배열 전부 다 도는게 맞는 건지 모르겠네 
  {
    for(int j = 0;j<2;j++)
    {
      while(memo[i][j] >= K){ //수용인원 초과시 방 늘리고 인원 나누기 
        memo[i][j] -= K;
        count++; 
      }
      if(memo[i][j] > 0) count++;
    }
  }
  cout <<count <<'\n';
}