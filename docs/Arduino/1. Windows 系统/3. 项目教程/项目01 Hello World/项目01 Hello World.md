# 项目01 Hello World

## 1.项目介绍：
对于ESP32的初学者，我们将从一些简单的东西开始。在这个项目中，你只需要一个ESP32主板，USB线和电脑就可以完成“Hello World!”项目。它不仅是ESP32主板和电脑的通信测试，也是ESP32的初级项目。

## 2.项目元件：
|![图片不存在](../../../media/afc52f6616725ba37e3b12a2e01685ad.png)|![图片不存在](../../../media/b4421594adeb4676d63581a1047c6935.png)|
| :--: | :--: |
| ESP32*1 | USB 线*1 |

## 3.项目接线：
在本项目中，我们通过USB线将ESP32和电脑连接起来。
![图片不存在](../../../media/46cf3a8a1c79e456ac0f02da5ef38aec.png)

## 4.项目代码：
你可以打开我们提供的代码：

本项目中使用的代码保存在（即路径)：**..\Keyes ESP32 中级版学习套件\4. Arduino C 教程\1. Windows 系统\3. 项目教程\项目01 Hello World\Project_01_Hello_World** 。

```
//*************************************************************************************
/*
 * 文件名 : Hello World
 * 描述 : 输入字母R，串口显示“Hello World”.
*/
char val;// 定义变量val
void setup()
{
Serial.begin(115200);// 设置波特率为115200
}
void loop()
{
  if (Serial.available() > 0) {
    val=Serial.read();// 读取并赋值给val
    if(val=='R')// 检查输入的字母“R”
    {  // 如果是这样的话,    
     Serial.println("Hello World!");// 显示“Hello World !”.
    }
  }
}
//*************************************************************************************

```
在上传项目代码到ESP32之前，点击“**工具**”→“**开发板**”，选择“**ESP32 Wrover Module**”。
![图片不存在](../../../media/e4e1d7c497e408cf00cebfa63b6ef7eb.png)

选择正确的端口（COM）。(<span style="color: rgb(255, 76, 65);">注意：</span>将ESP32主板通过USB线连接到计算机后才能看到对应的端口。)
![图片不存在](../../../media/f4a42b32cce8472c2033bab12ad2c82a.png)

<span style="color: rgb(255, 76, 65);">注意：</span>对于macOS用户，如果上传失败，在单击之前，请设置波特率为**115200**。
![图片不存在](../../../media/8c7346fc57c7d09ec75b5fb60d83ef67.png)

单击![图片不存在](../../../media/86b9e2ff982873d7304e9ba692e7f0da.png)将项目代码上传到ESP32主板上。
![图片不存在](../../../media/ce1eafb4ca085a0e732750e1dfec0fd9.png)

<span style="color: rgb(255, 76, 65);">注意：</span> 如果上传代码不成功，可以再次点击![图片不存在](../../../media/86b9e2ff982873d7304e9ba692e7f0da.png)后用手按住ESP32主板上的Boot键![图片不存在](../../../media/a3ce49fbd6f40f09869aa7e1d9f902f8.png)，出现上传进度百分比数后再松开Boot键，如下图所示：
![图片不存在](../../../media/0fdadbed575d5f54ae1ca9405c3647cb.png)

项目代码上传成功！
![图片不存在](../../../media/429b498bda8415f70866f28e6b9569ed.png)

## 5.项目结果： 
项目代码上传成功后，单击图标![图片不存在](../../../media/c15895718b4de5012fcb63ad6a767d00.png)进入串行监视器，设置波特率为115200，在文本框输入字母“R”，按下回车键(Enter 键)，这样串口监视器打印“Hello World!”。
![图片不存在](../../../media/131f86617fbf04fbccc219bdd8a83111.png)
















































