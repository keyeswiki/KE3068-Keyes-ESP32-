# 项目02 点亮LED

## 1.项目介绍：
在这个项目中，我们将向你展示点亮LED。我们使用ESP32的数字引脚打开LED，使LED被点亮。

## 2.项目元件：
|![图片不存在](../../../media/afc52f6616725ba37e3b12a2e01685ad.png)|![图片不存在](../../../media/a2aa343488c11843f13ae0413547c673.png)|![图片不存在](../../../media/325f351a1cc5c9af86988ddafd03fa19.png)|
| :--: | :--: | :--: |
|ESP32*1|面包板*1|红色LED*1|
|![图片不存在](../../../media/a487df5effb3b0ae28e7601cad88c97b.png)| ![图片不存在](../../../media/8d920d12138bd3b4e62f02cecc2c63a3.png)|![图片不存在](../../../media/b4421594adeb4676d63581a1047c6935.png)|
|220Ω电阻*1|跳线*2|USB 线*1|

## 3.元件知识：
**（1）LED**
![图片不存在](../../../media/32369e035f09fa12898e90cd3f916cbe.png)
LED是一种被称为“发光二极管”的半导体，是一种由半导体材料(硅、硒、锗等)制成的电子器件。它有正极和负极。短腿为负极，接GND，长腿为正极，接3.3V或5V。
![图片不存在](../../../media/cbb16ef4d8cb62a4001d1a05ae3ac615.png)

**（2）五色环电阻**
电阻是电路中限制或调节电流流动的电子元件。左边是电阻器的外观，右边是电阻在电路中表示的符号。电阻(R)的单位为欧姆(Ω)，1 mΩ= 1000 kΩ，1kΩ= 1000Ω。
   
我们可以使用电阻来保护敏感组件，如LED。电阻的强度（以Ω为单位）用小色环标记在电阻器的主体上。每种颜色代表一个数字，你可以用电阻对照卡查找。
![图片不存在](../../../media/e60472f717ced1cc0bd94f4972ef0cd0.png)

在这个套件中，我们提供了3个具有不同电阻值的五色环电阻。这里以3个五色环电阻为例：
220Ω电阻×10
![图片不存在](../../../media/951ce7d7778b34bf8fbdb3de1b8c3116.png)
10KΩ电阻×10
![图片不存在](../../../media/2d3f0996515352c92c07d17e074e7308.png)
1KΩ电阻×10
![图片不存在](../../../media/931d1535563f6d817300f97c0946a01c.png)
在相同的电压下，会有更小的电流和更大的电阻。电流、电压、电阻之间的联系可以用公式表示：I=U/R。在下图中，目前通过R1的电流: I = U / R = 3 V / 10 KΩ= 0.0003A= 0.3mA。
![图片不存在](../../../media/997accddd11490d13b769b9f3477daa7.png)
不要把电阻值很低的电阻直接连接在电源两极，这样会使电流过高而损坏电子元件。电阻是没有正负极之分。

**（3）面包板**
面包板是实验室中用于搭接电路的重要工具。面包板上有许多孔，可以插入集成电路和电阻等电路元件。熟练掌握面包板的使用方法是提高实验效率，减少实验故障出现几率的重要基础之一。下面就面包板的结构和使用方法做简单介绍。一个典型的面包板如下所示：
![图片不存在](../../../media/d4cb46e6b01d820bb150f0e8a122417e.png)
 面包板的外观和内部结构如上图所示，常见的最小单元面包板分上、中、下三部分，上面和下面部分一般是由一行或两行的插孔构成的窄条，中间部分是由中间一条隔离凹槽和上下各5 行的插孔构成的条。
![图片不存在](../../../media/2e9ef45f88652609af40b031ed0f0084.png)
在面包板的两个窄条分别有两行插孔，两行之间是不连通的，一般是作为电源引入的通路。上方第一行标有“+”的一行有10组插孔（内部都是连通），均为正极；上方第二行标有“-”的一行有10组插孔，（内部都是连通），均为接地。面包板下方的第一行与第二行结构同上。如需用到整个面包板，通常将“+”与“+”用导线连接起来，“-”与“-”用导线连接起来。
中间部分宽条是由中间一条隔离凹槽和上下各5 行的插孔构成。在同一列中的5 个插孔是互相连通的，列和列之间以及凹槽上下部分则是不连通的。外观及结构如下图：
![图片不存在](../../../media/8690e125a8f918f5e2b7950526e98ebb.png)
中间部分宽条的连接孔分为上下两部分，是面包板的主工作区，用来插接原件和跳线。在同一列中的5个插孔（即a-b-c-d-e，f-g-h-i-j）是互相连通的；列和列之间以及凹槽上下部分是不连通的。在做实验的时候，通常是使用两窄一宽组成的小单元，在宽条部分搭接电路的主体部分，上面的窄条取一行做电源，下面的窄条取一行做接地。中间宽条用于连接电路，由于凹槽上下是不连通的，所以集成块一般跨插在凹槽上。

**(4)电源**
ESP32需要3.3V-5V电源，在本项目中，我们通过用USB线将ESP32和电脑连起来。
![图片不存在](../../../media/46cf3a8a1c79e456ac0f02da5ef38aec.png)

## 4.项目接线图：
首先，切断ESP32的所有电源。然后根据接线图搭建电路。电路搭建好并验证无误后，用USB线将ESP32连接到电脑上。
<span style="color: rgb(255, 76, 65);">注意：</span>避免任何可能的短路(特别是连接3.3V和GND)!
<span style="color: rgb(255, 76, 65);">警告：短路可能导致电路中产生大电流，造成元件过热，并对硬件造成永久性损坏。  
</span>
![图片不存在](../../../media/6d79aa47daab6bc5dc46b1e62215d9c8.png)

<span style="color: rgb(255, 76, 65);">注意: </span>

怎样连接LED 
![图片不存在](../../../media/cbb16ef4d8cb62a4001d1a05ae3ac615.png)
怎样识别五色环220Ω电阻
![图片不存在](../../../media/951ce7d7778b34bf8fbdb3de1b8c3116.png)

## 5.项目代码：
你可以打开我们提供的代码：

本项目中使用的代码保存在（即路径)：**..\Keyes ESP32 中级版学习套件\4. Arduino C 教程\1. Windows 系统\3. 项目教程\项目02 点亮LED\Project_02_Turn_On_LED** 。

```
//**********************************************************************
/*
 * 文件名 : 点亮LED
 * 描述 : 点亮一盏灯.
*/
#define LED_BUILTIN 15

// 复位或单板上电时，setup功能只运行一次
void setup() {
  // 初始化数字引脚LED_BUILTIN作为输出.
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // 打开LED (HIGH为高电平)
}
//*************************************************************************************

```
在上传项目代码到ESP32之前，点击“**工具**”→“**开发板**”，选择“**ESP32 Wrover Module**”。
![图片不存在](../../../media/9b0703c5d3b7f1bdcd8de3bfe70eff7c.png)

选择正确的端口（COM）。(<span style="color: rgb(255, 76, 65);">注意：</span>将ESP32主板通过USB线连接到计算机后才能看到对应的端口。)
![图片不存在](../../../media/28bd4716860a4962f12d7ffe42b989a8.png)

<span style="color: rgb(255, 76, 65);">注意：</span>对于macOS用户，如果上传失败，在单击之前，请设置波特率为**115200**。
![图片不存在](../../../media/b737d2c5724e49b69ab472e2b369e543.png)

单击![图片不存在](../../../media/86b9e2ff982873d7304e9ba692e7f0da.png)将项目代码上传到ESP32主板上。
![图片不存在](../../../media/e32cec541e8479b04aa7eddfa26045e2.png)

<span style="color: rgb(255, 76, 65);">注意：</span> 如果上传代码不成功，可以再次点击![图片不存在](../../../media/86b9e2ff982873d7304e9ba692e7f0da.png)后用手按住ESP32主板上的Boot键![图片不存在](../../../media/a3ce49fbd6f40f09869aa7e1d9f902f8.png)，出现上传进度百分比数后再松开Boot键，如下图所示：
![图片不存在](../../../media/0fdadbed575d5f54ae1ca9405c3647cb.png)

项目代码上传成功！
![图片不存在](../../../media/413f0f5221cedb45f82c108f6b5e1ab2.png)

## 6.项目现象：
项目代码上传成功后，利用USB线供电，LED被点亮。
![图片不存在](../../../media/96672306fbbac2d8b33a55315d0d8fc5.png)




