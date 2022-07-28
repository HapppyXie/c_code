#include"数据结构08_二叉树.cpp"
typedef struct BiThrNode {
	TElemType data;
	struct BiThrNode* lchild, * rchild;
	int LTag, RTag;	//为0指向孩子，为1,指向前驱，指向后驱
}BiThrNode,*BiThrTree;





