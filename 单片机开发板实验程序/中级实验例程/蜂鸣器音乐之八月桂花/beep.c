/************************************************************************  
[文件名]  C51音乐程序(八月桂花)  
[功能]    通过单片机演奏音乐  
  
/**********************************************************************/   
#include <REG52.H>    
#include <INTRINS.H>    
//本例采用89C52, 晶振为12MHZ    
//关于如何编制音乐代码, 其实十分简单,各位可以看以下代码.    
//频率常数即音乐术语中的音调,而节拍常数即音乐术语中的多少拍;    
//所以拿出谱子, 试探编吧!    

sbit Beep =  P1^5; 
   
unsigned char n=0;  //n为节拍常数变量    
unsigned char code music_tab[] ={   
0xF2,0xF3,0xF5,0xF5,0xF6,0xF7,0xF8, //低音 1，2，3，4，5，6，7

0xF9,0xF9,0xFA,0xFA,0xFB,0xFB,0xFC,0xFC, //中音 1，2，3，4，5，6，7，i

0xFC,0xFD,0xFD,0xFD,0xFD,0xFE,	//高音 2，3，4，5，6，7

0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFF,	//超高音1，2，3，4，5，6，7

};
   
 code unsigned char FREQL[]={

0x42,0xC1,0x17,0xB6,0xD0,0xD1,0xB6,

0x21,0xE1,0x8C,0xD8,0x68,0xE9,0x5B,0x8F, //1,2,3,4,5,6,7,8,i

0xEE,0x44, 0x6B,0xB4,0xF4,0x2D,

0x47,0x77,0xA2,0xB6,0xDA,0xFA,0x16,//低音、中音、高音和超高音，四个八度共28个音符

};
  
void int0()  interrupt 1   //采用中断0 控制节拍    
{  TH0=0xd8;   
   TL0=0xef;   
   n--;   
}   
   
void delay (unsigned char m)   //控制频率延时    
{   
 unsigned i=3*m;   
 while(--i);   
}   
   
void delayms(unsigned char a)  //毫秒延时子程序    
{   
  while(--a);                  //采用while(--a) 不要采用while(a--); 各位可编译一下看看汇编结果就知道了!    
}   
   
void main()   
{ unsigned char p,m;   //m为频率常数变量    
  unsigned char i=0;   
  TMOD&=0x0f;   
  TMOD|=0x01;   
  TH0=0xd8;TL0=0xef;   
  IE=0x82;   
play:   
   while(1)   
    {   
    a: p=music_tab[i];   
       if(p==0x00)       { i=0, delayms(1000); goto play;}     //如果碰到结束符,延时1秒,回到开始再来一遍    
       else if(p==0xff)  { i=i+1;delayms(100),TR0=0; goto a;}  //若碰到休止符,延时100ms,继续取下一音符    
            else         {m=music_tab[i++], n=music_tab[i++];}  //取频率常数 和 节拍常数    
             TR0=1;                                             //开定时器1    
           while(n!=0) Beep=~Beep,delay(m);                         //等待节拍完成, 通过P1口输出音频(可多声道哦!)    
       TR0=0;                                             //关定时器1    
    }   
}  