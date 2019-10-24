TTGO_T_Watch_Web_Mic <br/><br/>
本项目原型参考 https://github.com/paranerd/simplecam <br/> 
原始项目有个技能, 树莓派带mic,通过网页把声音传给访问端<br/>
看到后感觉比较有意思,就移植到了esp32上, 正好手上有个TTGO_T_Watch 把代码烧录上测试了效果,很满意,<br/>
非常黑科技。 <br/>

功能：<br/>
利用本程序，esp32充当HTML远程麦克风

示意图:<br/>
<img src= 'https://raw.githubusercontent.com/lixy123/TTGO_T_Watch_Web_Mic/master/jiagou.jpg' /> <br/>

硬件:<br/>
  TTGO T-Watch + 语音扩展板(用到板上的INMP441 I2S麦克风模块)<br/>
  其它普通的esp32也可以,需要连接一个INMP441 I2S麦克风模块 <br/>

代码编译:<br/>
1.调整代码中的路由器参数,固定ip参数.<br/>
2.需要安装arduino for esp32开发包<br/>
3.代码库,下载zip,用arduino 导入库, 添加zip<br/>
 https://github.com/Links2004/arduinoWebSockets  <br/>
 https://github.com/me-no-dev/ESPAsyncWebServer<br/>
 https://github.com/me-no-dev/AsyncTCP<br/>
4.板选择: ESP32 Dev Module <br/>
5.选好端口,编译并烧写到TTGO T-Watch<br/>

使用场景：<br/>
没想好,娱乐,先做出来再说.<br/>
做对讲机应该可以.<br/>

使用方法: <br/>
1.在电脑或手机上打开浏览器.电脑上建议用chrome浏览器.输入 http://192.168.1.100<br/>
2.点击界面上的切换按钮,点一次是播放声音,再点一次是关闭播放声音.<br/>
<img src= 'https://raw.githubusercontent.com/lixy123/TTGO_T_Watch_Web_Mic/master/remote_mic_web.jpg' />

高级用法: <br/>
外网穿透<br/>
1.将192.168.1.100的端口80, 1331用 frp软件进行内网穿透<br/>
2.访问内网穿透后的地址.<br/>

效果: <br/>
声音效果尚可,在家里本地监听没发现什么噪音,但如果在公司远程听家里的MIC,感觉噪音比之前大. 第一种可能是周围有电流干扰.第二种可能是用的耳机不一样.先前我用的耳机是高阻抗的,可能自带高降噪能力. <br/>
如果要做得好,对声音要进行降噪处理,要对网络中断自动重连等,提升稳定性. <br/>
个人做着玩就不需要这么多讲究了. <br/>



