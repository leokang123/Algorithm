// 9개 숫자들이 들어있는게 한세트 숫자를사용해 번호를 만든다 할때 필요한 세트수(6,9는 돌려가며 사용가능 
#include <iostream>
#include <vector>
using namespace std;
int memo[10];

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> v;
  int num; cin >> num;
  int max = 0; // 6,9 뺀 최대갯수
  int max2 = 0; // 6,9 더한 최대갯수 
  while(num>0)
  {
    int a = num % 10;
    memo[a]++;
    num = num/10;
    if(a != 6 && a != 9){
      if(memo[a]> max) max = memo[a];
    }
  }
  max2 = (memo[6] + memo[9] + 1) / 2; // upper 
  max = (max > max2)? max : max2;
  cout << max<<'\n';
  return 0;
}