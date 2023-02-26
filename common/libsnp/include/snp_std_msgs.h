#ifndef __LIBSNP_INCLUDE_SNP_STD_MSGS_H__
#define __LIBSNP_INCLUDE_SNP_STD_MSGS_H__


#include "snp_defs.h"


/**
 * @brief 所有的结构体默认单字节对齐，默认小端模式 特定平台有差异的话，目前需要自行处理
 */


#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief 协议栈标准消息枚举
 */
enum SNP_STD_MSGS_TYPE {
	SSM_UNKNOWN_MSG,      /**< 未知消息类型 */
	SSM_DISCOVERY_REQ,      /**< 设备发现请求 */
	SSM_DISCOVERY_RES,      /**< 设备发现请求响应 */
	SSM_DEV_NETWORK_BROADCAST,      /**< 节点连接信息广播 */

	SSM_LOG_MSG,      /**< 标准日志消息 */

	SSM_APP_MSG_FIELD_BEGIN = 1024,      /**< 应用层消息域起始枚举 应用层协议号从此开始 */
};


/**
 * @brief 设备发现请求结构
 */
struct SSM_DISCOVERY_REQ_MSG {
	char name[SNP_NODE_NAME_SIZE];      /**< 发起请求的节点名 */
	int32_t type;      /**< 发起请求的节点类型 */
	int32_t id;      /**< 发起请求的节点标识符 */
};


/**
 * @brief 设备发现请求响应结构
 */
struct SSM_DISCOVERY_RES_MSG {
	char name[SNP_NODE_NAME_SIZE];      /**< 发起请求的节点名 */
	int32_t type;      /**< 发起请求的节点类型 */
	int32_t id;      /**< 发起请求的节点标识符 */
};


/**
 * @brief 设备连接信息描述结构
 */
struct SSM_DEV_LINK_MSG {
	char node_name[SNP_NODE_NAME_SIZE];      /**< 连接的节点名 */
	int32_t node_type;      /**< 连接的节点类型 */
	int32_t node_id;      /**< 连接的节点标识符 */
	int32_t link_type;      /**< 连接类型 enum SNP_LINK_TYPE */
};


/**
 * @brief 广播本节点的连接信息 定时以及本节点连接出现变化时更新
 */
struct SSM_DEV_NETWORK_BROADCAST_MSG {
	char name[SNP_NODE_NAME_SIZE];      /**< 本节点名 */
	int32_t type;      /**< 本节点类型 */
	int32_t id;      /**< 本节点的标识符 */
	int32_t link_num;      /**< 本节点的直接连接个数 */
	struct SSM_DEV_LINK_MSG links[];      /**< 连接描述数组，个数和 link_num 一致 */
};


#ifdef __cplusplus
}
#endif



#endif // __LIBSNP_INCLUDE_SNP_STD_MSGS_H__
