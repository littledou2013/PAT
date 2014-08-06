#include <cstdio>

struct Node
{
  int val;
  Node *left;
  Node *right;
  int height;
  Node(): val(0), left(NULL), right(NULL),height(1){}

};
Node tree[20];
int height(Node *node)
{
  if (node == NULL)
    return 0;
  else
    return node->height;
}
int max(int a, int b)
{
  if (a < b)
    return b;
  else
    return a;
}
//左左
Node *singleRotateWithLeft(Node *k2)
{
  Node *k1;
  k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->right ), height(k2->right)) + 1;
  k1->height = max(height(k1->left), k2->height) + 1;
    return k1;  /* New root */
}
Node *singleRotateWithRight(Node *k2)
{
  Node *k1;
  k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->right ), height(k2->right) ) + 1;
  k1->height = max(k2->height, height(k2->right)) + 1;
    return k1;  /* New root */
}
Node *doubleRotateWithLeft(Node *k3)
{
  k3->left = singleRotateWithRight(k3->left);
  return singleRotateWithLeft(k3);
}
Node *doubleRotateWithRight(Node *k3)
{
  k3->right = singleRotateWithLeft(k3->right);
  return singleRotateWithRight(k3);
}
Node *insert(Node *node, Node * head)
{
  if (head == NULL)
    head = node;
  else
  {
    //插入左子树
    if (node->val < head->val)
    {
      head->left = insert(node, head->left);
      if (height(head->left) - height(head->right) == 2)
        if (node->val < head->left->val)
          head = singleRotateWithLeft(head);
        else
          head = doubleRotateWithLeft(head);

    }
    //插入右子树
    else
    {
      head->right = insert(node, head->right);
      if(height(head->right) - height(head->left) == 2)
        if (node->val > head->right->val)
          head = singleRotateWithRight(head);
        else
          head = doubleRotateWithRight(head);
    }
  }
  head->height = max(height(head->left), height(head->right)) + 1;
  return head;
}
int main(void)
{
  int N;
  scanf("%d", &N);
  int val;
  for (int i = 0; i < N; ++i)
  {
    scanf("%d", &tree[i].val);
  }
  Node * head = NULL;
  for (int i = 0; i < N; ++i)
  {
    head = insert(&tree[i], head);
  }
  printf("%d\n", head->val);
  return 0;
}
/*方法二：
#include <cstdio>
#include <iostream>

struct Node
{
	int val;
	Node *left;
	Node *right;
	int height;
	Node(int _val): val(_val), left(NULL), right(NULL),height(1){}

};
int height(Node *node)
{
	if (node == NULL)
		return 0;
	else
		return node->height;
}
int max(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}
//左左
Node *singleRotateWithLeft(Node *k2)
{
	Node *k1;
	k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->right ), height(k2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;
    return k1;  
}
Node *singleRotateWithRight(Node *k2)
{
	Node *k1;
	k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->right ), height(k2->right) ) + 1;
	k1->height = max(k2->height, height(k2->right)) + 1;
    return k1; 
}
Node *doubleRotateWithLeft(Node *k3)
{
	k3->left = singleRotateWithRight(k3->left);
	return singleRotateWithLeft(k3);
}
Node *doubleRotateWithRight(Node *k3)
{
	k3->right = singleRotateWithLeft(k3->right);
	return singleRotateWithRight(k3);
}
Node *insert(int val, Node * head)
{
	if (head == NULL)
	{
		head = new Node(val);
	}
	else
	{
		//插入左子树
		if (val < head->val)
		{
			head->left = insert(val, head->left);
			if (height(head->left) - height(head->right) == 2)
				if (val < head->left->val)
					head = singleRotateWithLeft(head);
				else
					head = doubleRotateWithLeft(head);

		}
		//插入右子树
		else
		{
			head->right = insert(val, head->right);
			if(height(head->right) - height(head->left) == 2)
				if (val > head->right->val)
					head = singleRotateWithRight(head);
				else
					head = doubleRotateWithRight(head);
		}
	}
	head->height = max(height(head->left), height(head->right)) + 1;
	return head;
}
int main(void)
{
	int N;
	scanf("%d", &N);
	int val;
	Node *head = NULL;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &val);
		head = insert(val, head);
	}
	printf("%d\n", head->val);
	system("pause");
	return 0;
}*/
