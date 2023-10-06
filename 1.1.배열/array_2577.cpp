// 세수 곱한거 숫자 나온 횟수 출력 
#include <iostream>
using namespace std;
int num[10];

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a,b,c;
  int i = 0;
  cin>>a>>b>>c;
  int ref = a* b* c;
  while(ref>0)
  {
    num[ref%10]++;
    ref = ref / 10;
  }
  for(int i : num)
  {
    cout << i<<'\n';
  }
}
