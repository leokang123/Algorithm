
#include <iostream>
#include <list>
using namespace std;

// int main(void){
//     int num;cin >> num;
//     while(num--){
//         list<char> li;
//         list<char>::iterator iter =  li.begin(); // []빙공간 가르킴 
//         string str; cin >> str;
//         for(char c : str){
//             if(c == '<'){
//                 if(iter == li.begin()) continue;
//                 iter--;
//                 continue;
//             }else if(c == '>'){
//                 if(iter == li.end()) continue;
//                 iter++;
//                 continue;
//             }else if(c == '-'){
//                 if(iter == li.begin()) continue;
//                 iter--;
//                 iter = li.erase(iter); // 삭제한 요소의 앞에 칸을 가르킴 =>insert에 문제가 생기지 않음 
//                 continue;
//             }
//             li.insert(iter,c); // [A][] 맨마지막을 iter가 가르키고 있음 그래서 insert 하면 그 앞에 추가 되어 ABC라 입력해도 [A][B][C][]가 입력된다 insert 의 반환값은 입력한 값의 iter가 반환되는데 따로 변수로 받지 않으면 소멸됌 
//         }
//         for(char c : li){
//             cout << c;
//         }
//         // cout <<'\n';
//         // iter--;
//         // cout << *iter;
//         // cout << *li.begin();
//     }

// }

int main(void){
    int num;cin >>num;
    while(num--){
        string str;cin>>str;
        list<char> li;
        list<char>::iterator iter = li.begin();// == li.end() 사실 끝을 참조하는거임 
        for(char c: str){
            if(c == '<'){
                if(iter == li.begin()) continue; 
                // 비어있다는 의미임 원소 한개 이상 있을떈 iter == li.end()임 
                iter--;
                continue;
            }
            else if(c == '>'){
                if(iter == li.end()) continue;
                iter++;
                continue;
            }else if(c == '-'){
                if(iter == li.begin()) continue;
                iter--; // iter이 참조하는 end의 하나 뒤에꺼 삭제해야하니까 하나 빼주고 erase 
                iter = li.erase(iter); // 결국은 erase요소의 앞요소=> end를 다시 가르킴 
                continue;
            }
            li.insert(iter,c);
        }
        for(char c : li) cout << c;
        cout <<'\n';
    }
}