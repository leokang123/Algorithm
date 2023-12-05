// list iter 구조가 좀 이해하기 어려워서 정리 해보고자 한다
#include <bits/stdc++.h>
using namespace std; 
int main(void){
    list<int> li;
    list<int>::iterator iter = li.begin();
    li.push_back(3);
    li.push_back(5);
    li.push_front(9);
    li.insert(iter,6);
    if(iter == li.end()) cout << "end와 iter위치가 같다..\n";
    /* 보이는가! 리스트가 비어있을때 즉, li.begin() == li.end()일 때의 시작점을 iter가 참조하는 바람에 값들이 전부 insert를 하든 push_back을 하든 뒤에 삽입이 되게 되는 것이다 */

    cout << *iter<<'\n';
    /* 여기서 *iter 값이 4라는 것을 볼 수 있는데  
    이걸 어떻게 이해해야할까 고민을 했다 
    결론은 이렇다 처음에 빈 리스트를 iter로 참조하는 바람에 pushback을 하든 pushfront를 하든 insert를 하든 값이 iter 왼쪽에 추가 되는 것이다 따라서 여기서 4는 아마 인덱스 4에 iter가 위치한다는 뜻이다 
    같은 논리로 그렇다면 iter-- 를 하게 되면 인덱스 3을 참조하게 되어 3번째로 추가한 6을 출력할 것이다 
    */
    iter--;
    li.sort(); // 3 5 6 9
    cout << *iter<<'\n'; // 6 
    iter++; // 9 를 참조중 
    cout << *iter<<'\n'; // 6 을 참조하던게 sort를 한후 참조해줄값을 1더해주니 9가 되었다 
    /* 그리고 list 를 정렬한다 한들 iter이 참조하는 노드자체는 변하지 않으므로 값이 6 에서 변하지 않는다 */
    iter = li.erase(iter);// 9를 지우고 9오른쪽인 li.end()참조중 
    // li.erase(iter); iter--; 
    //이렇게 하면 segment fault 가 난다  그이유론 반복자 무효화라고 erase를 수행하고 반환값을 받지 않으면 반복자 선언이 무효화된다 
    // list 같은 경우 vector와 다르게 반복자를 반환하면 소멸하지 않고 보존할 수 있다 
    //insert,push_back의 경우 iter가 참조하는 값 왼쪽에 추가된다 
    //erase 의 경우 iter가 참조하는 값이 삭제된다 이때 삭제된 요소의 오른쪽 노드를 반환하는데 이때 반환값을 받아줘야 반복자가 무효화 안된다 => 꼭 반환값을 받자 
    // 현재 iter  li.end() 참조중 
    iter--; // 9 참조 
    cout << *iter<<'\n';


    // vector의 경우 더 복잡하다 참조하거나 입력,삭제하는 방식은 list와 같지만 vector의 경우는 원소를 추가할떄 자료구조가 재할당되면서 참조하는 객체가 변할수 있기 때문에
    // erase 는 리스트와 마찬가지로 반복자가 무효화 되고(재설정해야하고), 추가로 원소 추가시에도 반복자가 무효화 된다 
    // std::vector<int> vec;

    // auto v_it4 = vec.begin();	

    // v_it4 = vec.insert(vec.begin(), 0);	// v_it4 반복자는 무효화된다
    // // for(int i = 5 ; i < 2000;i++){
    // //     vec.insert(vec.begin(),i);
    // // }
    // // 이 밑부턴 의미없는 발버둥질 => 괜히 의미부여하지말자 걍 무효화 된거임 
    // v_it4 = vec.end();
    // auto v_it2 = v_it4;
    // vec.insert(v_it2,100);
    // // cout << *v_it2<<'\n';
    // v_it2 = vec.end();
    // vec.insert(v_it2,200);
    // // cout << *v_it2<<'\n';

    // v_it2--;
    // vec.erase(v_it2); // 100
    // // v_it4 = vec.erase(v_it4); 
    // // for(int i : vec) cout << i<<' ';
    // if(v_it4 == vec.end()) cout << "yes\n";
    // // cout << *v_it4 ;
    // // cout << *v_it4;
    }
