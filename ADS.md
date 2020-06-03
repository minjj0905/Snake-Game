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



- Level

  attributes

  | 타입  | 이름         | 설명             |
  | ----- | ------------ | ---------------- |
  | int   | currentLevel | 현재 맵의 인덱스 |
  | Map * | maps         | Map 객체 array   |
  |       |              |                  |
  |       |              |                  |

  method

  | 리턴타입 | 이름              | 설명                                |
  | -------- | ----------------- | ----------------------------------- |
  |          | Level()           | 생성자, currentLevel을 0으로 초기화 |
  | void     | getCurrentLevel() |                                     |
  | void     | upCurrentLevel()  |                                     |
  | Map      | getCurrentMap()   |                                     |
  |          |                   |                                     |

- Snake

  attribute

  | 타입                    | 이름        | 설명                      |
  | ----------------------- | ----------- | ------------------------- |
  | int                     | length      | 길이                      |
  | vector\<int\>           | headPos     | 머리 좌표                 |
  | vector\<vector\<int\>\> | bodyPos     | 몸통 좌표                 |
  | char                    | direction   | 방향                      |
  | int                     | growCount   | grow Item 먹은 횟수       |
  | int                     | poisonCount | poison Item 먹은 횟수     |
  | bool                    | fail        | snake가 뒤졋는지 살았느지 |

  method

  | 리턴타입 | 이름             | 설명        |
  | -------- | ---------------- | ----------- |
  | bool     | isFailed()       | fail return |
  | void     |                  |             |
  |          | getGrowCount()   |             |
  |          | getPoisonCount() |             |
  |          | getLength()      |             |
  |          |                  |             |
  |          |                  |             |



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

