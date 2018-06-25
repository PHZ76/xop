# C++11实现的轻量级网络框架

项目介绍
-
* 在工作中需要实现一个跨平台的流媒体转发服务，在参考了开源项目muduo和live555的设计后，重新封装了一个简单的网络框架。感谢muduo, 感谢live555。

项目案例
- [RtspServer](https://github.com/PHZ76/RtspServer)

目前情况
-
* 支持Windows和Linux平台, 在Windows下使用select, Linux下使用 epoll。
* 实现了定时器，触发事件，日志，环形缓冲区, 内存池等模块。

编译环境
-
* Linux: ubuntu16.04 -- gcc4.7
* Windows: win10 -- vs2015

整体框架
- 
![image](https://github.com/PHZ76/xop/blob/master/pic/1.pic.jpg) 

后续计划
-
* 增加多线程支持。
* 增加对象池。
* 其他优化。

其他
-
