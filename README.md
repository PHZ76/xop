C++11实现的轻量级网络框架<br>
-

项目初衷<br>
-
* 在工作中需要实现一个跨平台的流媒体转发服务，发现没有什么合适的网络库可以直接使用。在参考了开源项目muduo和live555的设计后，重新封装了一个简单的网络框架。<br>
    <br>
* 感谢muduo，感谢live555。<br>


目前情况<br>
-
* 支持Windows和Linux, 在Windows下使用select, Linux下使用epoll。<br>
* 实现了定时器，日志，环形缓冲区等模块。<br>

编译环境<br>
-
* Linux: ubuntu16.04 - gcc4.7<br>
* Windows: win10 - vs2015<br>
