/********************************************************
FileName: 	config.h
Author: 	czl
Email: 		137493336@qq.com
Created: 	2019/01/09
Description:�����ļ��ඨ��
********************************************************/

using namespace std;

#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "map"

#ifndef config_define
#define config_define

#define NULL 0	//�������Ͷ���

//Error Code ����
#define EC_NONE				0		//û�д���
#define EC_WOULDBLOCK		-1		//������
#define EC_ERROR			-2		//��������
#define EC_ACCESS			-3		//�ɴ����
#define EC_OUT_OF_BOUNDS	-4		//���޴���
#define EC_OPERATION		-5		//�������
#define EC_INSUF_BUFFER		-6		//���治��
#define EC_READ				-7		//������
#define EC_WRITE			-8		//д����
#define	EC_FORMAT			-9		//��ʽ����
#define EC_TIMEOUT			-10		//��ʱ����
#define EC_DISCARD			-11		//��������
#define EC_EXIST			-12		//�Ѿ�����
#define EC_PARAM			-13		//��������
#define EC_MISMATCH			-14		//��ƥ�����
#define EC_NOENT			-15		//û�����
#define EC_INVAL			-16		//��Ч

#define MAX_CONFIG_LINE_LENGTH 128	//����������󳤶�

namespace iniFile_parse
{

	/************************************
	@ ClassName		ConfigItem
	@ Brief:		�Զ������ͣ����ڱ�ʾ�����ļ��е�������
	@ Author:		czl
	@ Created: 		2019/01/09
	************************************/
	class ConfigItem
	{
	public:
		ConfigItem();
		ConfigItem(const char *key, const char *value);
		ConfigItem(const ConfigItem &tmp);
		~ConfigItem();

	public:
		void clear();//�ͷſռ�
		ConfigItem& operator = (const ConfigItem& tmp);//��ֵ���������
		void set_key(const char *tmp);//����key
		char *get_key() const;//��ȡkey
		void set_value(const char *tmp);//����value
		char *get_value() const;//��ȡvalue
		int as_int() const;//��value��ֵ��int���ͷ���
		double as_double() const;//��value��ֵ��double���ͷ���
		string as_string() const;//��value��ֵ��string���ͷ��أ�ֱ����char *��ֵstring���ͱ������ɣ�

	private:
		char *m_key;
		char *m_value;

		friend class Config;
	};


	/************************************
	@ ClassName		Config
	@ Brief:		�����ļ��࣬���ڶ�ȡ�����ļ�����ȡ������Ϣ��
	@ Author:		czl
	@ Created: 		2019/01/09
	************************************/
	class Config
	{
	public:
		Config();
		Config(const Config &tmp);
		~Config();

	public:
		Config& operator = (const Config& tmp);
		void clear();//������ñ�
		int size() const;//��ȡ���ñ�Ĵ�С
		int get_item(string key, ConfigItem *ptr);//��ȡĳһ�����ñ��е�Ԫ��
		void set_item(string key, const char *value);//���ò�������ñ��е�Ԫ��
		ConfigItem &operator[](string key);//�������±����ʽ����ȡ����������

	private:
		map<string, ConfigItem> m_item_map;//����map
		ConfigItem *p_item;//������
	};

	int parse_ini_file(const char *fileName, Config *pconfig);//���������ļ�
}

#endif // !iniFile_parse
