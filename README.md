# Gal-Saving
一个C++写的简易的类galgame/养成类游戏存读档。欢迎完善。  
介绍了简要的文件输入输出流。


## 食用方法
当调用showtext("filename")时，会读取根目录下名为"filename.txt"的文本文档。文档必须以ANSI格式存储。(除非哪位能帮我写个utf8版本)  
调用showtext("filename",int)时，会额外指定每一次显示的文档行数。注意，文本的空行会被自动略过，可以用全角空格解决这个问题。  
直接调用wfshow()可以调用默认的存读档功能。数据结构有待优化。
