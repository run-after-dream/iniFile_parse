һ�����߽��ܣ�
�����߹���Ϊ��ȡini�����ļ��е�������������������򣬱���ű��������Ա�����֤�����ڰ�װ��G++4.4.7���ϰ汾��linux������ֱ������makefile(����make),�������ɿ�ִ���ļ�parse
������������˵�����Ĳ��֡�
���轫������Ƕ��������Ŀ��ֱ��ʹ�ã�ֻ�轫config.cpp��config.h�ļ�����������Ŀ��Դ����Ŀ¼�£�Ȼ�������Ĵ����м���"config.h"ͷ�ļ����ο�����iniFile_parse.cpp�е�д����
���ã�int parse_ini_file(const char *fileName, Config *pconfig);�ӿڽ��������ļ���Config������У��ٴ�Config������ж�ȡ����Ӧ�����ü��ɣ�����Config�����Ҫ���ܣ����Բο���˵�������������ݡ�

�������ļ���飺
config.cpp��������ʵ��
config.h�������ඨ��
iniFile_parse.cpp�����������ڲ��Թ��ߵĻ������ܣ��������ļ��еĸ������ö�ȡ����ӡ����
makefile������ű�
my.ini�����������ļ�
readme.txt������˵���ĵ�

����Config�����Ҫ���ܣ�
operator[](string key)���������±����ʽ����ȡ���������ã�ʹ��������iniFile_parse.cpp��41-44�У�
set_item(string key, const char *value)�����ò�������ñ��е�Ԫ�أ�key:��ֵ��value���������ֵ

�ġ������������£�
$ parse my.ini
print all config items.
Day=20190101.
Time=09:00:00.
Num=99.
F_Num=99.88.
