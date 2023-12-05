/*
삼각형이 v1, v2, v3 세점으로 이루어져 있을때
d1 = v2 - v1
d2 = v3 - v1

테스트 하고자 하는 점을 k 라고 할때
p = k - v1

그려면 2차원 상의 한 점 p는 d1과 d2의 선형 합으로 나타낼 수 있습니다.
t1 * d1 + t2 * d2 = p
위의 식을 연립 방정식으로 풀면 t1과 t2를 얻을 수 있습니다.

점 k가 삼각형 내에 있으려면

0 <= t1 <= 1
0 <= t2 <= 1
t1 + t2 <= 1

이 세가지 조건을 만족하면 됩니다.
3차원에서도 성립합니다.
제 생각으로는 이게 가장 간단한 방법일듯 합니다. 2변수 1차연립방정식만 풀고 분기판단만 거치면 되니까요.
단, 2변수 연립방정식이므로 x, y, z 좌표중 2개에 대해서만 식을 선택해야 하는데, 좌표평면( xy, yz, zx평면)과 평행한 삼각형일 때, 해당 평면과 수직인 좌표축을 제외하고 선택하는것만 신경쓰면 될 것 같습니다.
헉. .글이 지워졌네요.
원글도 못 찾겠고..

t1*d1+t2*d2=p
에서
양변에 d1,d2를 각각 내적해서 구하세요.*/

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    std::cout << a.getX() << std::endl;
    std::cout << a.getY() << std::endl;
    std::cout << b.getX() << std::endl;
    std::cout << b.getY() << std::endl;
    std::cout << c.getX() << std::endl;
    std::cout << c.getY() << std::endl;
    std::cout << point.getX() << std::endl;
    std::cout << point.getY() << std::endl;
    return 1;
}