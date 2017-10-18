/************************************************************************  
[�ļ���]  C51���ֳ���(���¹�)  
[����]    ͨ����Ƭ����������  
  
/**********************************************************************/   
#include <REG52.H>    
#include <INTRINS.H>    
//��������89C52, ����Ϊ12MHZ    
//������α������ִ���, ��ʵʮ�ּ�,��λ���Կ����´���.    
//Ƶ�ʳ��������������е�����,�����ĳ��������������еĶ�����;    
//�����ó�����, ��̽���!    

sbit Beep =  P1^5; 
   
unsigned char n=0;  //nΪ���ĳ�������    
unsigned char code music_tab[] ={   
0xF2,0xF3,0xF5,0xF5,0xF6,0xF7,0xF8, //���� 1��2��3��4��5��6��7

0xF9,0xF9,0xFA,0xFA,0xFB,0xFB,0xFC,0xFC, //���� 1��2��3��4��5��6��7��i

0xFC,0xFD,0xFD,0xFD,0xFD,0xFE,	//���� 2��3��4��5��6��7

0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFF,	//������1��2��3��4��5��6��7

};
   
 code unsigned char FREQL[]={

0x42,0xC1,0x17,0xB6,0xD0,0xD1,0xB6,

0x21,0xE1,0x8C,0xD8,0x68,0xE9,0x5B,0x8F, //1,2,3,4,5,6,7,8,i

0xEE,0x44, 0x6B,0xB4,0xF4,0x2D,

0x47,0x77,0xA2,0xB6,0xDA,0xFA,0x16,//�����������������ͳ��������ĸ��˶ȹ�28������

};
  
void int0()  interrupt 1   //�����ж�0 ���ƽ���    
{  TH0=0xd8;   
   TL0=0xef;   
   n--;   
}   
   
void delay (unsigned char m)   //����Ƶ����ʱ    
{   
 unsigned i=3*m;   
 while(--i);   
}   
   
void delayms(unsigned char a)  //������ʱ�ӳ���    
{   
  while(--a);                  //����while(--a) ��Ҫ����while(a--); ��λ�ɱ���һ�¿����������֪����!    
}   
   
void main()   
{ unsigned char p,m;   //mΪƵ�ʳ�������    
  unsigned char i=0;   
  TMOD&=0x0f;   
  TMOD|=0x01;   
  TH0=0xd8;TL0=0xef;   
  IE=0x82;   
play:   
   while(1)   
    {   
    a: p=music_tab[i];   
       if(p==0x00)       { i=0, delayms(1000); goto play;}     //�������������,��ʱ1��,�ص���ʼ����һ��    
       else if(p==0xff)  { i=i+1;delayms(100),TR0=0; goto a;}  //��������ֹ��,��ʱ100ms,����ȡ��һ����    
            else         {m=music_tab[i++], n=music_tab[i++];}  //ȡƵ�ʳ��� �� ���ĳ���    
             TR0=1;                                             //����ʱ��1    
           while(n!=0) Beep=~Beep,delay(m);                         //�ȴ��������, ͨ��P1�������Ƶ(�ɶ�����Ŷ!)    
       TR0=0;                                             //�ض�ʱ��1    
    }   
}  