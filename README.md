# AVR_WashingMashine

## 목차
   
01. 개요
02. 팀 구성 및 역할
03. 프로젝트 수행 계획
04. 프로젝트 과정
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
  
  ![image](https://github.com/subin111/AVR_WashingMashine/assets/143717650/45bfce79-039c-4151-9fff-d62b2994d9d4)


  ![image](https://github.com/subin111/AVR_WashingMashine/assets/143717650/f457467f-6167-4546-a495-c93cb839f5eb)

   
* 개발 환경 및 장비
   
  Board : ATmega128a   
  Use to : 초음파 센서, 부저, lcd, dc모터    
  Language : C    
  Program : CodeVisionAVR     

     
## 2. 팀 구성 및 역할
   
* 이재경(팀장) - ▶ H/W  프로토타입 제작, 회로 구성도 및 코드 개발
* 장민영(팀원) - ▶ H/W  프로토타입 제작, 파트 별 코드 개발
* 최원빈(팀원) - ▶ H/W  프로토타입 제작, 전반적인 코드 구성 및  개발
* 이유진(팀원) - ▶ H/W  프로토타입 제작, 파트 별 코드 개발
* 이수빈(팀원) - ▶ 파트 별 코드 개발, 프로토타입 구성도 및 ppt 제작

   
## 3. 프로젝트 수행 계획

1. 사전 기획 - ▶ 조원 별 파트 분배 및 기획서 작성 - ▶ 01/16
2. 기초 셋팅 및 테스트 - ▶ ATmega128a 및 각종 부품 회로 결선 - ▶ 01/16
3. 핵심 기능 구현 - ▶ S/W 코드 파트 별 개발 - ▶ 01/16 ~ 01/17   
                     * 스위치 모드 설정 및 dc모터 회전
                     * 타이머 코드를 통한 일시정지 기능
                     * 초음파 센서, 부저를 연결하여 기타 기능
4. 중간 시스템 통합 - ▶ 각 부품 별 코드 통합 및 디버깅 - ▶ 01/17 ~ 01/18
5. 시스템 통합 및 완성 - ▶ 최종 프로토타입 제작, 최적화 및 완성 - ▶ 01/19
   
## 4. 프로젝트 과정
## 5. 프로젝트 결과
## 6. 프로젝트 결론

   



