# Microcontrollers-C
C framework for different microcontrollers用C语言写的单片机程序

51单片机开发板视频

# 流水灯
## sbit 变量名=地址值；  在给某个引脚取名的时候经常会用到。

## typedef使用
`typedef unsigned char u8;`
`typedef unsigned int u16;（后面要加分号）`

## define使用
`define A P0(注意后面不用加分号)`

# 蜂鸣器

* I/O端口默认都是高电平

## 数码管(静态，动态)

* 位选，3-8译码器
```
sbit LSA=P2^2;			 //三八译码器
sbit LSB=P2^3;
sbit LSC=P2^4;
```
![image.png](http://upload-images.jianshu.io/upload_images/4340772-24f9fab2cb8ee7dc.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

## 独立按键

* P3^1，P是大写
* 消除抖动 一般大约10ms


### 相关图片
![端口](http://upload-images.jianshu.io/upload_images/4340772-0a1fbf7f6d0c4741.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![image.png](http://upload-images.jianshu.io/upload_images/4340772-9d468957c85d74d3.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![image.png](http://upload-images.jianshu.io/upload_images/4340772-ca19c6d8bfbbd442.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![是否使用上拉电阻](http://upload-images.jianshu.io/upload_images/4340772-c41c185e5280073d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![image.png](http://upload-images.jianshu.io/upload_images/4340772-c6726738b0838219.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

选取上拉电阻4.7K-10K 
![](http://upload-images.jianshu.io/upload_images/4340772-9bd298501c93df17.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
