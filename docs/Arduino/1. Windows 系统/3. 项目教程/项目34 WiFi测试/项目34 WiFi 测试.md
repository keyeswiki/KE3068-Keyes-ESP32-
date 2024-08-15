# 项目34 WiFi 测试

## 1.实验简介：
在本实验中，我们先使用ESP32的WiFi Station模式读取WiFi的IP地址，然后通过APP连接WiFi来读取APP上各功能按钮发送的字符。

## 2.实验元件
|![图片不存在](../../../media/afc52f6616725ba37e3b12a2e01685ad.png)|![图片不存在](../../../media/b4421594adeb4676d63581a1047c6935.png)|![图片不存在](../../../media/4d0be04892e2038c372f82caba521f64.png)|
| :--: | :--: | :--: |
| ESP32*1 | USB 线*1 |智能手机/平板电脑(<span style="color: rgb(255, 76, 65);">自备</span>)*1|

## 3.实验接线：
使用USB线将ESP32主板连接到电脑上的USB口。
![图片不存在](../../../media/46cf3a8a1c79e456ac0f02da5ef38aec.png)

## 4.安装APP:

(1) 安卓系统设备（手机/平板）APP：
我们提供了Android APP 的安装包：
![图片不存在](../../../media/bd1eb78d8b5a99c776cad52ecad76f42.png)

**安装步骤：**

A. 现将文件夹中的**keyes wifi.apk**文件转移到安卓系统手机或平板电脑上。

或者用安卓系统手机/平板电脑的浏览器中的扫码功能扫下面的二维码。
![图片不存在](../../../media/f59967cba580bc752cd628dbd274e886.png)

B. 点击keyes wifi.apk文件进入安装页面，点击“**允许**”按钮，然后点击“**安装**”按钮，过一会儿，安装完成后点击“**打开**”按钮就可以进入APP界面。
![图片不存在](../../../media/e15c916fc960d7abbba15a3c2a95b325.png)
![图片不存在](../../../media/c4df6d064c1819cf0ab703bd6917bc54.png)
![图片不存在](../../../media/d7034b3177f4ff96779641bf2a278248.png)
![图片不存在](../../../media/89d8312749d5fc0aa584f4542aeb132b.png)
![图片不存在](../../../media/2da4df243f0b9c2425681625d77f7f52.png)
![图片不存在](../../../media/7cddf433df535865414cddbb52c2d672.png)

(2) IOS系统设备（手机/iPad）APP

a. 打开App Store。
![图片不存在](../../../media/0d6b6944ea693ebe5d6b939a66104462.png)

b.在搜索框输入**keyes link**，点击搜索，出现下载界面，点击“![图片不存在](../../../media/a9c7179df093d9f6eb1d39906cc2b90d.png)”，就可以下载安装**keyes link**的APP。接下来的操作和安卓系统类似的，可以参考上面安卓系统的步骤进行操作。

## 3.项目代码：
你可以打开我们提供的代码：

本项目中使用的代码保存在在（即路径)：**..\Keyes ESP32 中级版学习套件\4. Arduino C 教程\1. Windows 系统\3. 项目教程\项目34 WiFi测试\Project_34_WiFi_Test** 。

```
//**********************************************************************************
/*
 * 文件名   : WIFI 测试
 * 描述 : Wifi模块测试Wifi ip
*/

#include <Arduino.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiClient.h>

String item = "0";
const char* ssid = "ChinaNet-2.4G-0DF0";
const char* password = "ChinaNet@233";
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  Serial.println("TCP server started");
  MDNS.addService("http", "tcp", 80);
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
      return;
  }
  while(client.connected() && !client.available()){
      delay(1);
  }
  String req = client.readStringUntil('\r');
  int addr_start = req.indexOf(' ');
  int addr_end = req.indexOf(' ', addr_start + 1);
  if (addr_start == -1 || addr_end == -1) {
      Serial.print("Invalid request: ");
      Serial.println(req);
      return;
  }
  req = req.substring(addr_start + 1, addr_end);
  item=req;
  Serial.println(item);
  String s;
  if (req == "/")
  {
      IPAddress ip = WiFi.localIP();
      String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
      s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>Hello from ESP32 at ";
      s += ipStr;
      s += "</html>\r\n\r\n";
      Serial.println("Sending 200");
      client.println(s);
  }
  //client.print(s);
  client.stop();
}
//**********************************************************************************

```
<span style="color: rgb(255, 76, 65);">特别注意：</span>需要先将实验代码![图片不存在](../../../media/e738c0e72f68d100db4f47b8772c9a4a.png)中的用户Wifi名称和用户Wifi密码改成你们自己的Wifi名称和Wifi密码。

## 5.实验现象
确认程序代码中的Wifi名称和Wifi密码修改正确后，编译并上传代码到ESP32主板上。
<span style="color: rgb(255, 76, 65);">注意：</span> 如果上传代码不成功，可以再次点击![图片不存在](../../../media/86b9e2ff982873d7304e9ba692e7f0da.png)后用手按住ESP32主板上的Boot键![图片不存在](../../../media/a3ce49fbd6f40f09869aa7e1d9f902f8.png)，出现上传进度百分比数后再松开Boot键，如下图所示：
![图片不存在](../../../media/0fdadbed575d5f54ae1ca9405c3647cb.png)

打开串口监视器，设置波特率为<span style="color: rgb(255, 76, 65);">115200</span>，这样，串口监视器打印检测到的WiFi IP地址，然后打开WiFi APP。 在WIFI按钮前面的文本框中输入检测到的WIFI IP地址（<span style="color: rgb(255, 76, 65);">例如，下上面串口监视器检测到的IP地址：192.168.1.136</span>），再点击WIFI按钮，“403 Forbidden”或“网页无法打开”就会变成“192.168.1.136”。这样，就说明APP已经连接上了WIFI。
![图片不存在](../../../media/b42be62a79b4b9639584699eb6bd1e06.png)

用手分别点击APP上的各个功能按钮，然后串口监视器会打印接收到的对应字符。
![图片不存在](../../../media/e2844e48850242aa0b5bcf191d5ef28a.png)

**注意：** 如果打开串口监视器且设置波特率为115200之后，串口监视器窗口没有显示如下信息，可以按下ESP32的复位键![图片不存在](../../../media/515a31c10d414cae43980905e7df1879.jpg)）

