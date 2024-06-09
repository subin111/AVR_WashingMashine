#include <mega128a.h>
#include <stdio.h>
#include <alcd.h>
#include <delay.h>
#define Trigger_ON      PORTF|=0x01 
#define Trigger_OFF     PORTF&=~0x01
#define Echo           (PINF&0x04)

#define Do   0      #define DoS  1
#define Re   2      #define ReS  3
#define Mi   4      #define Fa   5
#define FaS  6      #define Sol  7
#define SolS 8      #define La   9
#define LaS  10     #define Ti   11

int cnt=0, mode=0;
int msec=0, sec=0;
int res_cnt=1;
int i=0;

int pause=0;
unsigned int range=0;
char data[80];
char data2[80];

flash unsigned int ocr1a[7][12]={
    30577,28860,27240,25711,24268,22906,21620,20407,19261,18180,17160,16197,
    15288,14429,13619,12855,12133,11452,10809,10203, 9630, 9089, 8579,64791,
    61155,57722,54482,51424,48538,45814,43242,40815,38524,36362,34321,32395,
    30577,28860,27240,25711,24268,22906,21620,20407,19261,18180,17160,16197,
    15288,14429,13619,12855,12133,11452,10809,10203, 9630, 9089, 8579, 8098,
     7643, 7214, 6809, 6427, 6066, 5725, 5404, 5101, 4814, 4544, 4289, 4048,
     3821, 3606, 3404, 3213, 3032, 2862, 2701, 2550, 2406, 2271, 2144, 2023,
};

unsigned int getEcho(void)
{
    Trigger_ON; delay_us(10); Trigger_OFF;
    while(!Echo);              // Wait for echo pin to go high
    TCNT1=0x00; TCCR1B=0x02;         // 1: 8 prescaler=0.5us
    while(Echo);               // Wait for echo pin to go low
    TCCR1B=0x08;
    return(TCNT1/116); // the range in CM
}

void sound(char octave, char pitch){
    if(octave>6)
    {
        octave=6;
    }
    if(pitch>11)pitch=11;
    {
        TCCR1B&=~7;
    } 
    if((octave*12+pitch)<23)
    {
        TCCR1B|=2;
    } 
    else
    {
        TCCR1B|=1;
    }
    OCR1A=ocr1a[octave][pitch];
}

void bgm(){
    TCCR1A=0x40; TCCR1B=9; TCCR1C=0x80; OCR1A=0;
   
        sound(4,0);
        delay_ms(500);
        
        sound(4,5);
        delay_ms(166);
        sound(4,4);
        delay_ms(166);
        sound(4,2);
        delay_ms(166);
        sound(4,0);
        delay_ms(500);
        
        sound(3,9);
        delay_ms(500);
        
        sound(3,11);
        delay_ms(166);
        sound(4,0);
        delay_ms(166);
        sound(4,2);
        delay_ms(166);
        
        sound(3,7);
        delay_ms(166);
        sound(3,9);
        delay_ms(166);
        sound(3,11);
        delay_ms(166); 
        sound(3,9);
        delay_ms(500);    
        
        sound(4,0);
        delay_ms(500);

        sound(4,0);
        delay_ms(500);        
        
        sound(4,5);
        delay_ms(166);
        sound(4,4);
        delay_ms(166);
        sound(4,2);
        delay_ms(166);
        sound(4,0);
        delay_ms(500);
        
        sound(4,5);
        delay_ms(500);
        
        sound(4,5);
        delay_ms(166);
        sound(4,7);
        delay_ms(166);
        sound(4,5);
        delay_ms(166);
        sound(4,4);
        delay_ms(166);
        sound(4,2);
        delay_ms(166);
        sound(4,4);
        delay_ms(166);

        sound(4,5);
        delay_ms(1000);
        // PORTB=0xff;
        TCCR1A=0x00; TCCR1B=0; TCCR1C=0x00; OCR1A=0;
}

void setak(void){
    lcd_clear();
    lcd_gotoxy(0,0);
    lcd_puts("setak!!");
    sec=0;
    while(sec<=1){OCR0=0; }
    while(sec<=3){while(pause!=1){OCR0=0;} PORTB=0x90; OCR0=150;}
    while(sec<=4){OCR0=0;}
    while(sec<=6){while(pause!=1){OCR0=0;} PORTB=0x50; OCR0=150;}
}

void wash(void){
    lcd_clear();
    lcd_gotoxy(0,0);
    lcd_puts("wash!!");
    sec=0;
    while(sec<=1){OCR0=0; }
    while(sec<=4){while(pause!=1){OCR0=0;} PORTB=0x90; OCR0=200;}
    while(sec<=5){OCR0=0;}
    while(sec<=8){while(pause!=1){OCR0=0;} PORTB=0x50; OCR0=200;}
}

void dewater(void){
    lcd_clear();
    lcd_gotoxy(0,0);
    lcd_puts("dewater!!");
    for(i=0;i<res_cnt;i++){
        sec=0;
        while(sec<=2){while(pause!=1){OCR0=0;} PORTB=0x90; OCR0=250;}
        while(sec<=7){while(pause!=1){OCR0=0;} PORTB=0x50; OCR0=250;}   
    }
    OCR0=0;  
    lcd_clear();
    lcd_gotoxy(0,0);
    lcd_puts("FINISHED!!");
    delay_ms(1000);
    bgm();
    cnt++;
}

interrupt [EXT_INT0] void ext_int0_isr(void)
{
range=getEcho();
if(range<20) {cnt++;}
if(cnt>=2) {cnt=0;}
delay_ms(55);
}

interrupt [EXT_INT1] void ext_int1_isr(void)
{
if(cnt==0){OCR0=0;}
if(cnt==1){ 
    mode++;
    if(mode>3) mode=0;    
}
delay_ms(55);
}

interrupt [EXT_INT2] void ext_int2_isr(void) // drytimer
{
if(cnt==1){res_cnt++;}
delay_ms(50);
}

interrupt [EXT_INT4] void ext_int4_isr(void) // pause/restart
{
    pause++;
    if(pause==1) {lcd_gotoxy(0,1); lcd_puts("start");}
    if(pause>=2) {lcd_gotoxy(0,1); lcd_puts("pause"); pause=0;}
    delay_ms(55);
}

interrupt [TIM3_OVF] void timer3_ovf_isr(void)  
{
TCNT3H=0xb1;
TCNT3L=0xe0;
if(cnt==1 && pause==1){msec++; if(msec==100){sec++; msec=0;}}
}

void main(void)
{
DDRA=0xff; // LED
PORTA=0xff;
DDRB=0xff; // motor   11010000   pb4 = ENA(OC0) ,  pb6 = IN1  , pb7 = IN2 
PORTB=0x00; 
DDRC=0xff; // LCD
PORTC=0xff;
DDRD=0xf0;
PORTD=0xff;
DDRE=0xef;
PORTE=0x00;
DDRF=3; // PORTF.0 Trigger  PORTF.2 Echo

ASSR=0<<AS0;

TCCR0=(1<<WGM00) | (1<<COM01) | (0<<COM00) | (1<<WGM01) | (1<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x00; 

TCCR3B=0x02;
TCNT3H=0xb1;
TCNT3L=0xe0;

TIMSK=0x04;
ETIMSK=(0<<TICIE3) | (0<<OCIE3A) | (0<<OCIE3B) | (1<<TOIE3) | (0<<OCIE3C) | (0<<OCIE1C);

EICRA=(0<<ISC31) | (0<<ISC30) | (1<<ISC21) | (0<<ISC20) | (1<<ISC11) | (0<<ISC10) | (1<<ISC01) | (0<<ISC00);
EICRB=(0<<ISC71) | (0<<ISC70) | (0<<ISC61) | (0<<ISC60) | (0<<ISC51) | (0<<ISC50) | (1<<ISC41) | (0<<ISC40);
EIMSK=(0<<INT7) | (0<<INT6) | (0<<INT5) | (1<<INT4) | (0<<INT3) | (1<<INT2) | (1<<INT1) | (1<<INT0);
EIFR=(0<<INTF7) | (0<<INTF6) | (0<<INTF5) | (1<<INTF4) | (0<<INTF3) | (1<<INTF2) | (1<<INTF1) | (1<<INTF0);


SFIOR=(0<<ACME);
lcd_init(16);
#asm("sei")
while (1)
    {
    
    if(cnt==0)
    {   
        cnt=mode=msec=0;
        OCR0=0;
        res_cnt=1;
        lcd_clear();
        lcd_gotoxy(0,0);
        lcd_puts("power off..");
        delay_ms(500);
        lcd_clear();
    }
    if(cnt==1){
       lcd_clear();
       sprintf(data,"MODE : %d",mode);
       lcd_gotoxy(0,0);
       lcd_puts(data);
       sprintf(data2,"DEWATER COUNT:%d",res_cnt);
       lcd_gotoxy(0,1);
       lcd_puts(data2);
       if(pause==1)
          {
          if(mode==0){PORTB=0x00; OCR0=0;}
          if(mode==1){setak(); wash(); dewater(); }
          if(mode==2){wash();dewater();}
          if(mode==3){dewater();}
          }
       }
    }
}
