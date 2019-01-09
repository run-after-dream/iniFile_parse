/********************************************************
FileName: 	config.cpp
Author: 	czl
Email: 		137493336@qq.com
Created: 	2019/01/09
Description:�����ļ���ʵ��
********************************************************/

#include "config.h"

namespace iniFile_parse
{
	/************************************
	@ Brief:		ConfigItem���캯��
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		NA
	************************************/
	ConfigItem::ConfigItem()
	{
		m_key = new char[MAX_CONFIG_LINE_LENGTH];
		m_value = new char[MAX_CONFIG_LINE_LENGTH];
	}

	/************************************
	@ Brief:		ConfigItem���ι��캯��
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		key:��ֵ��value:ֵ
	************************************/
	ConfigItem::ConfigItem(const char *key, const char *value)
	{
		m_key = new char[MAX_CONFIG_LINE_LENGTH];
		m_value = new char[MAX_CONFIG_LINE_LENGTH];
		strcpy(m_key, key);
		strcpy(m_value, value);
	}

	/************************************
	@ Brief:		ConfigItem�������캯��
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		tmp:��������������
	************************************/
	ConfigItem::ConfigItem(const ConfigItem &tmp)
	{
		m_key = new char[MAX_CONFIG_LINE_LENGTH];
		m_value = new char[MAX_CONFIG_LINE_LENGTH];
		strcpy(m_key, tmp.m_key);
		strcpy(m_value, tmp.m_value);
	}

	/************************************
	@ Brief:		ConfigItem��������
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		NA
	************************************/
	ConfigItem::~ConfigItem()
	{
		delete[] m_key;
		delete[] m_value;
		m_key = NULL;
		m_value = NULL;
	}

	/************************************
	@ Brief:		���������
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		NA
	@ Return:		NA
	************************************/
	void ConfigItem::clear()
	{
		delete[] m_key;
		delete[] m_value;
		m_key = NULL;
		m_value = NULL;
	}

	/************************************
	@ Brief:		��ֵ���������
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		ConfigItem��������
	@ Return:		ConfigItem��������
	************************************/
	ConfigItem& ConfigItem::operator = (const ConfigItem& tmp)
	{
		strcpy(this->m_key, tmp.m_key);
		strcpy(this->m_value, tmp.m_value);
		return *this;
	}

	/************************************
	@ Brief:		����key
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		�������ַ���
	@ Return:		NA
	************************************/
	void ConfigItem::set_key(const char *tmp)
	{
		strcpy(m_key, tmp);
	}

	/************************************
	@ Brief:		��ȡkey
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		NA
	@ Return:		���ؼ�ֵ
	************************************/
	char *ConfigItem::get_key() const
	{
		return m_key;
	}

	/************************************
	@ Brief:		����value
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		�������ַ���
	@ Return:		NA
	************************************/
	void ConfigItem::set_value(const char *tmp)
	{
		strcpy(m_value, tmp);
	}

	/************************************
	@ Brief:		��ȡvalue
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		NA
	@ Return:		����valueֵ
	************************************/
	char *ConfigItem::get_value() const
	{
		return m_value;
	}

	/************************************
	@ Brief:		��value��ֵ��int���ͷ���
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		NA
	@ Return:		��int���ͷ���valueֵ
	************************************/
	int ConfigItem::as_int() const
	{
		int value = atoi(m_value);
		if (value == 0)
		{
			printf("Warning | ConfigItem::as_int() is 0, may be failed.\n");
		}
		return value;
	}

	/************************************
	@ Brief:		��value��ֵ��double���ͷ���
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		NA
	@ Return:		��double���ͷ���valueֵ
	************************************/
	double ConfigItem::as_double() const
	{
		char **end_ptr = NULL;
		double value = strtod(m_value, end_ptr);
		if (value == 0)
		{
			printf("Warning |  ConfigItem::as_double() is 0, may be failed.\n");
		}
		return value;
	}

	/************************************
	@ Brief:		��value��ֵ��string���ͷ��أ�ֱ����char *��ֵstring���ͱ������ɣ�
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		NA
	@ Return:		��string���ͷ���valueֵ
	************************************/
	string ConfigItem::as_string() const
	{
		string value = m_value;
		return value;
	}

	/************************************
	@ Brief:		Config���캯��
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		NA
	************************************/
	Config::Config()
	{
		m_item_map.clear();
		p_item = new ConfigItem();
	}

	/************************************
	@ Brief:		�������캯��
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		NA
	************************************/
	Config::Config(const Config &tmp)
	{
		m_item_map.clear();
		*p_item = *tmp.p_item;
		m_item_map = tmp.m_item_map;
	}

	/************************************
	@ Brief:		Config��������
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		NA
	************************************/
	Config::~Config()
	{
		m_item_map.clear();
		delete p_item;
	}

	/************************************
	@ Brief:		�����ļ��࣬��ֵ���������
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		��̬�����ļ�������
	@ Return:		�����ļ�������
	************************************/
	Config& Config::operator = (const Config& tmp)
	{
		this->m_item_map.clear();
		*(this->p_item) = *tmp.p_item;
		this->m_item_map = tmp.m_item_map;
		return *this;
	}

	/************************************
	@ Brief:		������ñ�
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		NA
	@ Return:		NA
	************************************/
	void Config::clear()
	{
		m_item_map.clear();
	}

	/************************************
	@ Brief:		��ȡ���ñ�Ĵ�С
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		NA
	@ Return:		���ñ�Ĵ�С
	************************************/
	int Config::size()const
	{
		int size = m_item_map.size();
		return size;
	}

	/************************************
	@ Brief:		��ȡĳһ�����ñ��е�Ԫ��
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		key:��ֵ,ptr:ָ���������ָ��
	@ Return:		���ñ�Ĵ�С
	************************************/
	int Config::get_item(string key, ConfigItem *ptr)
	{
		map<string, ConfigItem>::iterator iter;
		iter = m_item_map.find(key);
		if (iter == m_item_map.end())
		{
			printf("ERROR | Config::get_item can't find the item with the key = %s.\n", key.c_str());
			return EC_MISMATCH;
		}
		else
		{
			*ptr = iter->second;
			return EC_NONE;
		}
	}

	/************************************
	@ Brief:		���ò�������ñ��е�Ԫ��
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		key:��ֵ,value:ָ��������m_valueֵ��ָ��
	@ Return:		NA
	************************************/
	void Config::set_item(string key, const char *value)
	{
		map<string, ConfigItem>::iterator iter;
		p_item->set_key(key.c_str());
		p_item->set_value(value);
		iter = m_item_map.find(key);
		//�ѵ���ֵ��ֱ���޸�
		if (iter != m_item_map.end())
		{
			m_item_map[key] = *p_item;
		}
		else//�Ѳ�����ֵ�������
		{
			m_item_map.insert(make_pair(key, *p_item));
		}
	}

	/************************************
	@ Brief:		�������±����ʽ����ȡ����������
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		key:��ֵ
	@ Return:		����������
	************************************/
	ConfigItem &Config::operator[](string key)
	{
		map<string, ConfigItem>::iterator iter;
		iter = m_item_map.find(key);
		if (iter == m_item_map.end())
		{
			printf("ERROR | const ConfigItem & Config::operator[] can't find the item with the key = %s.\n", key.c_str());
			p_item->m_key = NULL;
			p_item->m_value = NULL;
			return *p_item;
		}
		else
		{
			*p_item = iter->second;
			char *value = p_item->get_value();
			return *p_item;
		}
	}

	/************************************
	@ Brief:		���������ļ�
	@ Author:		czl
	@ Created: 		2019/01/09
	@ Param:		fileName:�����ļ�·��������,pconfig:����ָ��
	@ Return:		����״̬
	************************************/
	int parse_ini_file(const char *fileName, Config *pconfig)
	{
		char buffer[MAX_CONFIG_LINE_LENGTH];
		pconfig->clear();

		FILE *fp = fopen(fileName, "rt");

		if (fp == NULL)
		{
			printf("ERROR | parse_ini_file open the file failed.\n");
			return EC_FORMAT;
		}
		while (fgets(buffer, MAX_CONFIG_LINE_LENGTH, fp) != NULL)
		{
			if (buffer[0] == '#')
				continue;
			char *key = strtok(buffer, "\n\r=");
			if (key == NULL)
			{
				continue;
			}
			const char *value = strtok(NULL, "\n\r");
			if (value == NULL)
			{
				value = "";
			}
			pconfig->set_item(key, value);
		}
		fclose(fp);

		return EC_NONE;
	}
}