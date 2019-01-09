一、工具介绍：
本工具功能为读取ini配置文件中的配置项，包含有样例程序，编译脚本，如需自编译验证，可在安装有G++4.4.7以上版本的linux环境下直接运行makefile(命令make),即可生成可执行文件parse
运行样例见本说明第四部分。
如需将本工具嵌入您的项目中直接使用，只需将config.cpp与config.h文件拷贝到您项目的源程序目录下，然后在您的代码中加入"config.h"头文件，参考样例iniFile_parse.cpp中的写法，
采用：int parse_ini_file(const char *fileName, Config *pconfig);接口解析配置文件到Config类对象中，再从Config类对象中读取出相应的配置即可，关于Config类的主要功能，可以参考本说明第三部分内容。

二、各文件简介：
config.cpp：配置类实现
config.h：配置类定义
iniFile_parse.cpp：主程序，用于测试工具的基本功能，将配置文件中的各项配置读取并打印出来
makefile：编译脚本
my.ini：样例配置文件
readme.txt：工具说明文档

三、Config类的主要功能：
operator[](string key)：以数组下标的形式来获取配置项引用，使用样例见iniFile_parse.cpp（41-44行）
set_item(string key, const char *value)：设置并添加配置表中的元素，key:键值，value：配置项的值

四、运行样例如下：
$ parse my.ini
print all config items.
Day=20190101.
Time=09:00:00.
Num=99.
F_Num=99.88.
