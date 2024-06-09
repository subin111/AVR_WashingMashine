# AVR_WashingMashine
  ATmega128a 보드를 활용한 AVR 미니 세탁기
  
## 목차
   
01. 개요
02. 팀 구성 및 역할
03. 프로젝트 수행 계획
04. 주요 특징 및 핵심 기술
05. 프로젝트 결과
06. 프로젝트 결론

   
## 1. 개요
   
* 추진 배경 및 기대효과
  
  -ATmega128A 보드로 세탁기 구현
  -AVR 보드인 ATmega128a의 학습과정을 총정리 하는 팀프로젝트
  -프로토타입 제작을 통해 전자제품 구성에 대한 이해도를 높임
   

* 구현 목표 및 내용
  
  -여닫이 문 닫혔을 시에만 모드 시작
  -전원 버튼 구현
  -세탁기 기능 구현 [세탁, 헹굼, 탈수]
  -일시정지/ 시작 버튼 구현
  -모드 종료 시 종료 음 구현

  
* 개발 구성도
  
   <img src = "https://github.com/subin111/AVR_WashingMashine/assets/143717650/45bfce79-039c-4151-9fff-d62b2994d9d4" width="450" height="350"/>


  <img src ="https://github.com/subin111/AVR_WashingMashine/assets/143717650/f457467f-6167-4546-a495-c93cb839f5eb" width="250" height="350"/>

   
* 개발 환경 및 장비
   
  Board : ATmega128a   
  Use to : 초음파 센서, 부저, lcd, dc모터    
  Language : C    
  Program : CodeVisionAVR     

     
## 2. 팀 구성 및 역할
   
* 이재경(팀장) ▶ H/W  프로토타입 제작, 회로 구성도 및 코드 개발
* 장민영(팀원) ▶ H/W  프로토타입 제작, 파트 별 코드 개발
* 최원빈(팀원) ▶ H/W  프로토타입 제작, 전반적인 코드 구성 및  개발
* 이유진(팀원) ▶ H/W  프로토타입 제작, 파트 별 코드 개발
* 이수빈(팀원) ▶ 파트 별 코드 개발, 프로토타입 구성도 및 ppt 제작

   
## 3. 프로젝트 수행 계획
   
|계획|활동|기간|
|------|---|---|
|사전 기획|조원 별 파트 분배 및 기획서 작성|01/16|
|기초 셋팅 및 테스트|Tmega128a 및 각종 부품 회로 결선|01/16|
|핵심 기능 구현|S/W 코드 파트 별 개발|1/16 ~ 01/17|
|중간 시스템 통합|각 부품 별 코드 통합 및 디버깅|1/17 ~ 01/18|
|시스템 통합 및 완성|최종 프로토타입 제작, 최적화 및 완성|1/19|
   
## 4. 주요 특징 및 핵심 기술
    
### 1. 여닫이 문 거리 인식
   
* 초음파 센서
* 타이머/카운터 1

     - 초음파 센서의 값을 통해 여닫이 문이 닫혀있어야 전원 스위치를 눌렀을 때 전원이 켜지도록 함

### 2. 스위치로 모드 설정 및 실행
   
   * Dc모터 PWM 제어
   * 고속 PWM 모드
   * 타이머/카운터 0
        
<p align="center"><img src ="https://github.com/subin111/AVR_WashingMashine/assets/143717650/f183d7d0-4a3a-4bcb-8db5-2a2c44d2c38d" width="200" height="300"/></p>

     -  모드 1: 세탁(세탁+헹굼+탈수)
     -  모드 2: 헹굼(헹굼+탈수)
     -  모드 3: 탈수(탈수)
          
### 3. 일시 정지 및 재시작
   
   * 타이머/카운터 3
     
     - 스위치 4를 한 번 누르면 일시정지
     - 스위치 4를 한 번 더 누르면 모드 시작 및 재시작


<p align="center"><img src ="https://github.com/subin111/AVR_WashingMashine/assets/143717650/5bf8f938-e1f8-4a78-afe6-92224817af69" width="350" height="600"/></p>

   
### 4. Buzzer로 종료음 구현 (부가 기능)

   * 타이머/카운터 1
   * sound(): OCR1A 레지스터에 옥타브(행)에 따른 음의 높낮이 값(열)을 저장
   * bgm(): sound(몇 옥타브, 몇 번째 음), delay_ms()를 통해 종료음 재생
    

## 5. 프로젝트 결과

   * 프로토타입 윗면 외부, 구동 내부
  
<img src="https://github.com/subin111/AVR_WashingMashine/assets/143717650/36be231b-9710-4923-95be-84169145746b" width="500" height="400"/><img src="https://github.com/subin111/AVR_WashingMashine/assets/143717650/ec63aa73-9e5f-4f45-bbb8-bb9432db244f" width="500" height="400"/></p>

   * 세탁기 구현 결과 영상

   <p align="center"><img src="https://github.com/subin111/AVR_WashingMashine/assets/143717650/77f51dbf-a19e-42fd-8059-4a2762a9864d" width="200" height="200"/></p>



    
## 6. 프로젝트 결론

   * 결론
     
     - 핵심 기능인 초음파 센싱, 1스위치로 3모드 구현 및 dc 모터의 작동, 일시 정지 기능 모두 알맞게 구현됨
     - 세부 기능인 부저 종료음 구현이 완벽하게 구현되지 않은 한계점
     - 세탁기를 이루는 각 모듈과 회로, 코드에 대한 이해도를 높일 수 있었으며 또한 타이머/카운터의 활용 방식에 대해 배울 수 있었음.


  * 추가 계획

    - 부저 종료음이 특정음에서 멈추는 문제를 해결
    - 세탁, 헹굼, 탈수 모드의 강약 조절 버튼 추가
    - 탈수 시간을 설정한 후 타이머처럼 시간이 주는 display 구현




   



