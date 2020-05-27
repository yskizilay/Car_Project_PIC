#include <16F887.H>
#include <stdio.h>
#fuses HS,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD
#use delay(clock=20000000)

#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
#use fast_io(e)
char acik=0;
char kapali=17;

int a;
byte b;
int x;
int leda1=0;
int leda2=0;
int ledb1=0;
int ledb2=0;
int enA=0;
int enB=0;
int input1=0;
int input2=0;
int input3=0;
int input4=0;

int enxA=0;
int enxB=0;
int inputx1=0;
int inputx2=0;
int inputx3=0;
int inputx4=0;



#use rs232 (baud=9600,xmit=pin_C6, rcv=pin_C7, stop=1, parity=N)

#int_rda
void serihaberlesme_kesmesi(){
disable_interrupts(int_rda);
a= getc();


}

void main(){

setup_adc_ports(NO_ANALOGS);
setup_adc(ADC_OFF);
setup_spi(FALSE);
setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
setup_timer_1(T1_DISABLED);
setup_timer_2(T2_DISABLED,0,1);



    set_tris_a(0b00000000);
    set_tris_b(0b00000000);
    set_tris_c(0b01000000);
    set_tris_d(0b00000000);
    set_tris_e(0b00000000);
    
    
    
    output_low(pin_b1); //enxA
    output_low(pin_b2); //enxB
    
    output_low(pin_b3); //leda1
    output_low(pin_b4); //leda2
    output_low(pin_c0); //ledb1
    output_low(pin_b0); //ledb2
    
    output_low(pin_d0); //input1
    output_low(pin_d1); //input2
    output_low(pin_d2); //input3
    output_low(pin_d3); //input4
    
    output_low(pin_d4); //inputx1
    output_low(pin_d5); //inputx2
    output_low(pin_d6); //inputx3
    output_low(pin_d7); //inputx4
    
    output_low(pin_e0); //enA
    output_low(pin_e1); //led2
    output_low(pin_e2); //enB
    
   
    
    
   enable_interrupts(GLOBAL);
   
  while(1){
  
   // uzun ledler
    output_bit(pin_b3, leda1);
    output_bit(pin_b4, leda2);
   //kýsa ledler 
    output_bit(pin_c0, ledb1);
    output_bit(pin_b0, ledb2);
    
    //ön tekerlekler
    output_bit(pin_e0, enA);
    output_bit(pin_e2, enB);
    output_bit(pin_d0, input1);
    output_bit(pin_d1, input2);
    output_bit(pin_d2, input3);
    output_bit(pin_d3, input4);
    
    //arka tekerlekler
     output_bit(pin_b1, enxA);
    output_bit(pin_b2, enxB);
    output_bit(pin_d4, inputx1);
    output_bit(pin_d5, inputx2);
    output_bit(pin_d6, inputx3);
    output_bit(pin_d7, inputx4);
    
  a=getchar();
  
 enable_interrupts(int_rda);
   
 if( a == 0b1100111 ){ //1. led
 disable_interrupts(int_rda);


if(ledb1==0) { ledb1=1;}
  else if(ledb1==1) { ledb1=0;}
if(ledb2==0) { ledb2=1;}
   else if(ledb2==1) { ledb2=0;}

 
 }
 
if( a == 0b110011 ){ //2. led
 disable_interrupts(int_rda);
if(leda1==0) { leda1=1;}
    else if(leda1==1) { leda1=0;}
if(leda2==0) { leda2=1;}
   else if(leda2==1) { leda2=0;}
   
 if(ledb1==0) { ledb1=1;}
  else if(ledb1==1) { ledb1=0;}
if(ledb2==0) { ledb2=1;}
   else if(ledb2==1) { ledb2=0;}



 }
 
if( a == 0b1100110 ){ //3. led
 disable_interrupts(int_rda);



 }
 
 if( a == 0b11001 ){ //4. led
 disable_interrupts(int_rda);

 
 }
 
 if( a == 0b1000100 ){ //w

 disable_interrupts(int_rda);
 delay_ms(5);
 //Ön tekerlekler
 output_high(pin_e0); //enA
 output_high(pin_e2);//enB
 output_high(pin_d0); //input1
 output_low(pin_d1); //input2
 output_high(pin_d2); //input3
 output_low(pin_d3); //input4 
 //arka tekerlekler
  output_high(pin_b1); //enxA
  output_high(pin_b2); //enxB
  output_high(pin_d4); //inputx1
  output_low(pin_d5); //inputx2
  output_high(pin_d6); //inputx3
  output_low(pin_d7); //inputx4

delay_ms(15);
 
     
 }
   
 
 
 

 if( a == 0b1001111 ){ //a
 disable_interrupts(int_rda);
 delay_ms(3);
 
 //arka tekerlekler
  output_high(pin_b1); //enxA
  output_high(pin_b2); //enxB
  output_high(pin_d4); //inputx1
  output_low(pin_d5); //inputx2
  output_high(pin_d6); //inputx3
  output_low(pin_d7); //inputx4
  
   //Ön tekerlekler
    //sag tekerlek
 output_high(pin_e2);//enB
 output_high(pin_d2); //input3
 output_low(pin_d3); //input4 
   //sol tekerlek
 output_high(pin_e0); //enA
 output_low(pin_d0); //input1
 output_low(pin_d1); //input2
   delay_ms(acik);
  //arka tekerlekler
  output_high(pin_b1); //enxA
  output_high(pin_b2); //enxB
  output_high(pin_d4); //inputx1
  output_low(pin_d5); //inputx2
  output_high(pin_d6); //inputx3
  output_low(pin_d7); //inputx4
  
   //Ön tekerlekler
    //sag tekerlek
 output_high(pin_e2);//enB
 output_high(pin_d2); //input3
 output_low(pin_d3); //input4 
   //sol tekerlek
 output_high(pin_e0); //enA
 output_low(pin_d0); //input1
 output_low(pin_d1); //input2
   delay_ms(kapali);
    }
 
 if( a == 0b1000110 ){ //s
 disable_interrupts(int_rda); 
  delay_ms(5);
 //Ön tekerlekler
  output_low(pin_e0); //enA
 output_low(pin_d0); //input1
 output_high(pin_d1); //input2
 
  output_low(pin_e2);//enB
 output_low(pin_d2); //input3
 output_high(pin_d3); //input4 

 //arka tekerlekler
  output_high(pin_b1); //enxA
  output_high(pin_b2); //enxB
  output_low(pin_d4); //inputx1
  output_high(pin_d5); //inputx2
  output_low(pin_d6); //inputx3
  output_high(pin_d7); //inputx4

delay_ms(15);

 
 }
 
 if( a == 0b10011 ){ //d
 disable_interrupts(int_rda);
  delay_ms(3);

//arka tekerlekler
  output_high(pin_b1); //enxA
  output_high(pin_b2); //enxB
  output_high(pin_d4); //inputx1
  output_low(pin_d5); //inputx2
  output_high(pin_d6); //inputx3
  output_low(pin_d7); //inputx4
  
   //Ön tekerlekler
    //sag tekerlek
 output_high(pin_e2);//enB
 output_low(pin_d2); //input3
 output_low(pin_d3); //input4 
   //sol tekerlek
 output_high(pin_e0); //enA
 output_high(pin_d0); //input1
 output_low(pin_d1); //input2
 delay_ms(acik);
  //arka tekerlekler
  output_high(pin_b1); //enxA
  output_high(pin_b2); //enxB
  output_high(pin_d4); //inputx1
  output_low(pin_d5); //inputx2
  output_high(pin_d6); //inputx3
  output_low(pin_d7); //inputx4
  
   //Ön tekerlekler
    //sag tekerlek
 output_high(pin_e2);//enB
 output_low(pin_d2); //input3
 output_low(pin_d3); //input4 
   //sol tekerlek
 output_high(pin_e0); //enA
 output_high(pin_d0); //input1
 output_low(pin_d1); //input2
 delay_ms(kapali);
  
 
 }
 
 if( a == 0b110010 ){ //space(6)
 disable_interrupts(int_rda);
  delay_ms(5);
 //Ön tekerlekler
 output_high(pin_e0); //enA
 output_high(pin_e2);//enB
 output_low(pin_d0); //input1
 output_low(pin_d1); //input2
 output_low(pin_d2); //input3
 output_low(pin_d3); //input4 
 //arka tekerlekler
  output_high(pin_b1); //enxA
  output_high(pin_b2); //enxB
  output_low(pin_d4); //inputx1
  output_low(pin_d5); //inputx2
  output_low(pin_d6); //inputx3
  output_low(pin_d7); //inputx4

delay_ms(15);
 

 

 
 }
  }
}
 
  
  
