# 소프트웨어 구조설계서

- Constant.h

  상수 정의

- Gate

  attributes

  method

  | 이름   | 반환 | 설명   |
  | ------ | ---- | ------ |
  | Gate() |      | 생성자 |
  |        |      |        |
  |        |      |        |

- Map

  attributes

  | 타입   | 이름      | 설명            |
  | ------ | --------- | --------------- |
  | int    | mapHeight | map의 y축 길이  |
  | int    | mapWidth  | map의 x축 길이  |
  | int ** | map       | map             |
  | string | mapPath   | map file의 경로 |

  method

  | 리턴타입      | 이름                                 | 설명                 |
  | ------------- | ------------------------------------ | -------------------- |
  |               | Map(int stage)                       | 생성자               |
  | void          | loadMap()                            | 맵 불러오기          |
  | int           | getMapValue(int y, int x)            | 좌표로 값 불러오기   |
  | void          | setMapValue(int y, int x, int value) | 좌표로 값 설정하기   |
  | vector\<int\> | getMapPos(int value)                 | 값으로 좌표 불러오기 |
  | void | setSnakeZero() | 갖고온 스네이크 좌표를 0으로 바꿈 |



- Level

  attributes

  | 타입  | 이름         | 설명             |
  | ----- | ------------ | ---------------- |
  | int   | currentLevel | 현재 맵의 인덱스 |
  | Map   | maps         | Map 객체 array   |
  |       |              |                  |
  |       |              |                  |

  method

  | 리턴타입 | 이름              | 설명                                |
  | -------- | ----------------- | ----------------------------------- |
  |          | Level()           | 생성자, currentLevel을 0으로 초기화 |
  | int     | getCurrentLevel() |  현재 레벨을 가져온다  |
  | void     | upCurrentLevel()  | 레벨을 1 올린다.     |
  | Map      | getCurrentMap()   |   레벨에 따른 현재 맵을 가져온다.     |
  | void     | createMap()              | Map객체 array에 맵을 넣는다.                                    |

- Snake
  
  struct
  | 타입                    | 이름        | 설명                      |
  | ----------------------- | ----------- | ------------------------- |
  | struct | POSITION | 좌표 저장 방식 |
  | int | x | column |
  | int | y | row |
  || POSITION(int row, int col)| 구조체의 생성자 / x 에 col 을 담고 y 에 row 를 담는다.|
  || POSITION() | 기본생성자 / x, y는 0으로 초기화 |


  attribute

  | 타입                    | 이름        | 설명                      |
  | ----------------------- | ----------- | ------------------------- |
  | vector\<POSITION\>   |  snakePos   | 스네이크 좌표                 |                    
  | char                    | direction   | 방향                      |
  | int                     | growCount   | grow Item 먹은 횟수       |
  | int                     | poisonCount | poison Item 먹은 횟수     |
  | bool                    | fail        | snake의 생사여부 |

  method

  | 리턴타입 | 이름             | 설명        |
  | -------- | ---------------- | ----------- |
  | void | initSnake(Level& lv)| 처음 시작할때 스네이크의 좌표를 맵에서 받아냄 |
  | bool     | isFailed()       | snake의 생사 여부 반환 |
  | int      | getGrowCount()   | grow Item 을 먹은 횟수 반환            |
  | int      | getPoisonCount() | poison Item 먹은 횟수 반환            |
  | int         | getLength()      | snake의 길이 반환            |
  |  void     | setFailed()      | snake가 죽음            |
  | void | setDirection() | 키를 받고 snake 방향전환함  |



- Item

  attributes

  | 타입 | 이름 | 설명                |
  | ---- | ---- | ------------------- |
  | int  | type | grow인지 poison인지 |
  |      | pos  |                     |
  |      |      |                     |
  |      |      |                     |



- View

  하는 사람이 알아서 잘 짜고 써놓기,,,

