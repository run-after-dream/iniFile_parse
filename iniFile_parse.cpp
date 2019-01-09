/********************************************************
FileName: 	iniFile_parse.cpp
Author: 	czl
Email: 		137493336@qq.com
Created: 	2018/10/17
Description:配置文件解析小工具入口
********************************************************/

#include "config.h"

using namespace iniFile_parse;

/************************************
@ Brief:		主函数
@ Author:		czl
@ Created: 		2018/11/20
@ Param:		argc:命令行参数个数，argv:命令行参数
@ Return:		运行状态
************************************/
int main(int argc, char *argv[])
{
	//命令行参数处理
	if (argc != 2)
	{
		printf("param error!\nexample: parse xxx.ini.\n");
		return EC_ERROR;
	}

	//主函数
	int ret = 0;
	Config config;
	ret = parse_ini_file(argv[1], &config);
	if (ret != EC_NONE)
	{
		printf("ERROR | parse the ini file failed.\n");
		return EC_ERROR;
	}

	//打印出所有的配置项
	printf("print all config items.\n");
	printf("Day=%s.\n", config["Day"].get_value());
	printf("Time=%s.\n", config["Time"].get_value());
	printf("Num=%d.\n", config["Num"].as_int());
	printf("F_Num=%.12g.\n", config["F_Num"].as_double());//除0以外保留12位有效位
	
	return EC_NONE;
}

