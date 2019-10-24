TTGO_T_Watch_Web_Mic <br/>
本项目原型参考 https://github.com/paranerd/simplecam 技术点是树莓派生成网页,并可以通过网页访问麦克风的声音.
仅仅把声音功能移植到了TTGO_T_Watch, 非常黑科技。

功能：<br/>
利用本程序，esp32充当HTML远程麦克风

示意图:<br/>

硬件:<br/>
  TTGO T-Watch + 语音扩展板(用到板上的INMP441 I2S麦克风模块)<br/>
  其它普通的esp32也可以,需要连接一个INMP441 I2S麦克风模块 <br/>

使用场景：<br/>
没想好,娱乐,先做出来再说.<br/>
做对讲机应该可以.<br/>

代码编译:<br/>
1.调整代码中的路由器参数,固定ip参数.<br/>
2.需要安装arduino for esp32开发包<br/>
3.代码库,下载zip,用arduino 导入库, 添加zip<br/>
 https://github.com/Links2004/arduinoWebSockets  <br/>
 https://github.com/me-no-dev/ESPAsyncWebServer<br/>
 https://github.com/me-no-dev/AsyncTCP<br/>
4.板选择: ESP32 Dev Module <br/>
5.选好端口,编译并烧写到TTGO T-Watch<br/>

使用方法: <br/>
1.在电脑或手机上打开浏览器.电脑上建议用chrome浏览器.输入 http://192.168.1.100<br/>
2.点击界面上的切换按钮,点一次是播放声音,再点一次是关闭播放声音.<br/>

高级用法: <br/>
外网穿透<br/>
1.将192.168.1.100的端口80, 1331用 frp软件进行内网穿透
2.访问内网穿透后的地址.
