# Snake-Game

2020년 1학기 C++프로그래밍 프로젝트로 진행된 ncurses를 이용한 SnakeGame Project입니다.

[결과보고서](https://github.com/minjj0905/kmucs-cpp-snakegame/blob/master/SnakeGame-%ED%8F%B0%EC%BD%94%EB%94%A9-%EA%B2%B0%EA%B3%BC%EB%B3%B4%EA%B3%A0%EC%84%9C.pdf)


## 팀 소개

**폰코딩**
| 이름          | 학번     |
| ------------- | -------- |
| 김민정 (팀장) | 20191556 |
| 김은수        | 20191568 |



## 컴파일

- Version : C++ 14

- Compile `make`



## 실행

`./Snake`



## **::** **주의사항 ::**

터미널 창이 작다면 게임이 정상적으로 실행되지 않습니다.

충분히 창 사이즈를 키우고 실행해 주세요.

 

ncurses 라이브러리를 설치한 후 진행해주세요.

```bash	
sudo apt-get update
sudo apt-get install libncurses5-dev libncursesw5-dev
```



 

## **::** **게임 설명 ::**

게임은 총 4 스테이지로 구성되어 있습니다.

스테이지의 미션을 모두 클리어하시면 다음 스테이지로 넘어갑니다.

마지막 4스테이지를 완료하시면 게임이 종료됩니다.



방향키 : ↑↓←→

■ : 벽

● : Snake 머리

○ : Snake 몸통

♣ : Grow 아이템 ( 획득시 길이+1 )

❌ : Poison 아이템 ( 획득시 길이-1 )

🄶 : Gate ( 진입시 반대 Gate로 진출 )

 

## **::Game over::**

■ 에 충돌시

반대 방향 방향키 입력시

○(몸통)에 ●(머리) 충돌시

Snake의 길이가 3이하로 줄어들 시



## 게임 플레이 화면
![play_ex](https://github.com/minjj0905/kmucs-cpp-snakegame/blob/master/img/play_ex.png)
