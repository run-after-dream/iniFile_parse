/********************************************************
FileName: 	iniFile_parse.cpp
Author: 	czl
Email: 		137493336@qq.com
Created: 	2018/10/17
Description:�����ļ�����С�������
********************************************************/

#include "config.h"

using namespace iniFile_parse;

/************************************
@ Brief:		������
@ Author:		czl
@ Created: 		2018/11/20
@ Param:		argc:�����в���������argv:�����в���
@ Return:		����״̬
************************************/
int main(int argc, char *argv[])
{
	//�����в�������
	if (argc != 2)
	{
		printf("param error!\nexample: parse xxx.ini.\n");
		return EC_ERROR;
	}

	//������
	int ret = 0;
	Config config;
	ret = parse_ini_file(argv[1], &config);
	if (ret != EC_NONE)
	{
		printf("ERROR | parse the ini file failed.\n");
		return EC_ERROR;
	}

	//��ӡ�����е�������
	printf("print all config items.\n");
	printf("Day=%s.\n", config["Day"].get_value());
	printf("Time=%s.\n", config["Time"].get_value());
	printf("Num=%d.\n", config["Num"].as_int());
	printf("F_Num=%.12g.\n", config["F_Num"].as_double());//��0���Ᵽ��12λ��Чλ
	
	return EC_NONE;
}

