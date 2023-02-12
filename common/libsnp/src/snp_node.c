#include "snp_node.h"

#include "queue.h"


/**
 * @brief @brief 系统节点连接描述结构
 */
struct SNP_LINK {
	struct SNP_NODE *src_node;      /**< 一个连接的源节点 */
	struct SNP_NODE *dst_node;      /**< 一个连接的目标节点 */

	void *link_handle;
	SNP_NODE_READ link_read;      /**< 节点数据读取接口 */
	SNP_NODE_WRITE link_write;      /**< 节点数据写入接口 */

	LIST_ENTRY(SNP_LINK) LINK;
};

LIST_HEAD(SNP_LINK_LIST, SNP_LINK);


/**
 * @brief 系统节点描述结构
 */
struct SNP_NODE
{
	struct SNP_LINK_LIST links;      /**< 节点支持的外部连接 */

	TAILQ_ENTRY(SNP_NODE) NODE;
};


TAILQ_HEAD(SNP_NODE_LIST, SNP_NODE);


/**
 * @brief 创建节点连接构造接口
 * @param src 连接的源节点
 * @param dst 连接的目标节点
 * @return struct SNP_LINK* 
 */
struct SNP_LINK *snp_link_create(struct SNP_NODE *src, struct SNP_NODE *dst)
{
	struct SNP_LINK *_new_link = NULL;

	if (NULL == src || NULL == dst)
	{
		return _new_link;
	}

	_new_link = (struct SNP_LINK *)malloc(sizeof(struct SNP_LINK));
	if (NULL != _new_link)
	{
		memset(_new_link, 0, sizeof(struct SNP_LINK));
		_new_link->src_node = src;
		_new_link->dst_node = dst;
		
		LIST_INSERT_HEAD(&src->links, _new_link, LINK);
	}

	return _new_link;
}


/**
 * @brief 创建新的连接节点
 * @param node_list 新节点挂载到的节点管理列表
 * @return struct SNP_NODE* 
 */
struct SNP_NODE *snp_node_create(struct SNP_NODE_LIST *node_list)
{
	struct SNP_NODE *_snp_node = (struct SNP_NODE *)malloc(sizeof(struct SNP_NODE));

	if (NULL != _snp_node)
	{
		memset(_snp_node, 0, sizeof(struct SNP_NODE));
		LIST_INIT(&_snp_node->links);
		TAILQ_INSERT_TAIL(node_list, _snp_node, NODE);
	}

	return _snp_node;
}


/**
 * @brief 创建节点列表对象
 * @return struct SNP_NODE_LIST* 
 */
struct SNP_NODE_LIST *snp_node_list_create()
{
	struct SNP_NODE_LIST *_snp_node_list = (struct SNP_NODE_LIST *)malloc(sizeof(struct SNP_NODE_LIST));

	if (NULL != _snp_node_list)
	{
		memset(_snp_node_list, 0, sizeof(struct SNP_NODE_LIST));
		TAILQ_INIT(_snp_node_list);
	}

	return _snp_node_list;
}


/**
 * @brief 打印所有节点的构造信息，包括节点信息，连接信息等
 * @param node_list 
 */
void snp_nodes_print_all(struct SNP_NODE_LIST *node_list)
{
	if (NULL == node_list)
	{
		return;
	}
	struct SNP_NODE *_var_node = NULL;

	TAILQ_FOREACH(_var_node, node_list, NODE)
	{
		SNP_DEBUG("node ptr: 0x%p\r\n", _var_node);
		struct SNP_LINK *_var_link = NULL;
		LIST_FOREACH(_var_link, &_var_node->links, LINK)
		{
			SNP_DEBUG("    [node 0x%p] -----> [node 0x%p]\r\n", _var_link->src_node, _var_link->dst_node);
		}
	}
}
