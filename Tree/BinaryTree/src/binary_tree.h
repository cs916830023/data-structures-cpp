/*!
 * @file binary_tree.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ������ģ����
 * @version 0.2.1
 * @date 2020-11-01
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#ifndef CYBER_DASH_BINARY_TREE_H
#define CYBER_DASH_BINARY_TREE_H


#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
#include "binary_tree.h"


using namespace std;


/*!
 * @brief ���������ģ��ṹ��
 * @tparam T ����ģ�����
 */
template <class T>
struct BinTreeNode {
  /*! @brief ���캯��(�޲���) */
  BinTreeNode(): left_child(NULL), right_child(NULL) {}
  /*! @brief ���캯��(����������Һ���) */
  BinTreeNode(T data, BinTreeNode<T>* left_child = NULL, BinTreeNode<T>* right_child = NULL):
    data(data), left_child(left_child), right_child(right_child) {}

  T data; //!< ���������������
  BinTreeNode<T>* left_child; //!< ���ӽ��ָ��
  BinTreeNode<T>* right_child; //!< �Һ��ӽ��ָ��
};


/*!
 * @brief �������ջ���ģ����
 * @tparam T ����ģ�����
 */
template <class T>
struct PostOrderStackNode {
  /*! @brief ���캯�� */
  explicit PostOrderStackNode(BinTreeNode<T>* node = NULL) {
    this->node = node;
    tag = LEFT;
  }

  BinTreeNode<T>* node; //!< ���������ָ��
  enum { LEFT, RIGHT } tag; //!< ��ǩ
};


/*!
 * @brief ������ģ����
 * @tparam T ����ģ�����
 */
template <class T>
class BinaryTree {
public:
  /*! @brief ���캯��(�޲���) */
  BinaryTree(): root_(NULL) {}
  /*! @brief ���캯��(���ڵ�������) */
  BinaryTree(T data) { this->SubTreeInsert_(this->root_, data); }
  /*! @brief ���ƹ��캯�� */
  BinaryTree(const BinaryTree<T>& bin_tree) { this->root_ = this->Copy_(bin_tree.Root()); }
  /*! @brief �������� */
  ~BinaryTree() { this->SubTreeDestroy_(root_); }

  /* �������� */
  /*!
   * @brief ��ȡ���ڵ�
   * @return �����ָ��
   * */
  BinTreeNode<T>* Root() const { return this->root_; }

  /*!
   * @brief �Ƿ�Ϊ����
   * @return �Ƿ�Ϊ��
   */
  bool IsEmpty() { return this->root_ == NULL; }

  /*!
   * @brief ��ȡ���ڵ�
   * @return �����ָ��
   */
  BinTreeNode<T>* GetRoot() const { return this->root_; }

  /*!
   * @brief��ȡ���ڵ�
   * @return ���ڵ�ָ��
   */
  BinTreeNode<T>* Parent(BinTreeNode<T>* node) {
    return (this->root_ == NULL || this->root_ == node) ? NULL : this->Parent_(this->root_, node);
  }

  /*!
   * @brief ����
   * @return ����ָ��
   */
  BinTreeNode<T>* LeftChild(BinTreeNode<T>* node) { return (node != NULL) ? node->left_child : NULL; }

  /*!
   * @brief ����
   * @return ����ָ��
   */
  BinTreeNode<T>* RightChild(BinTreeNode<T>* node) { return (node != NULL) ? node->right_child : NULL; }

  /*!
   * @brief ��ȡ���ĸ߶�
   * @return �߶�
   */
  int Height() { return this->SubTreeHeight_(this->root_); }

  /*!
   * @brief ��ȡ���Ľ����
   * @return �����
   */
  int Size() { return this->SubTreeSize_(this->root_); }

  /*!
   * @brief ������
   * @param data ������
   * @return �Ƿ�ɹ�
   */
  bool Insert(T data) { return this->SubTreeInsert_(this->root_, data); }

  /*!
   * @brief ��ѯ������
   * @param data ����
   * @return �Ƿ�������
   */
  bool Find(T data) { return this->SubTreeFind_(this->root_, data); }

  /* ����ϵ�� */
  /*!
   * @brief ǰ�����(ʹ�õݹ�)
   * @param visit ����������
   */
  void PreOrder(void (*visit)(BinTreeNode<T>* node)) { this->SubTreePreOrder_(this->root_, visit); }

  /*!
   * @brief ǰ�����(ʹ�÷ǵݹ�)
   * @param visit ����������
   */
  void PreOrderNonRecursive(void (*visit)(BinTreeNode<T>* node)) {
    this->SubTreePreOrderNonRecursive_(this->root_, visit);
  }

  /*!
   * @brief �������(ʹ�õݹ�)
   * @param visit ����������
   */
  void InOrder(void (*visit)(BinTreeNode<T>* node)) { this->SubTreeInOrder_(this->root_, visit); }

  /*!
   * @brief �������(ʹ�÷ǵݹ�)
   * @param visit ����������
   */
  void InOrderNonRecursive(void (*visit)(BinTreeNode<T>* node)) {
    this->SubTreeInOrderNonRecursive_(this->root_, visit);
  }

  /*!
   * @brief �������(ʹ�õݹ�)
   * @param visit ����������
   */
  void PostOrder(void (*visit)(BinTreeNode<T>* node)) { this->SubTreePostOrder_(this->root_, visit); }

  /*!
   * @brief �������(ʹ�÷ǵݹ�)
   * @param visit ����������
   */
  void PostOrderNonRecursive(void (*visit)(BinTreeNode<T>* node)) {
    this->SubTreePostOrderNonRecursive_(this->root_, visit);
  }

  /*!
   * @brief �������
   * @param visit ����������
   */
  void LevelOrder(void (*visit)(BinTreeNode<T>* node)) { this->SubTreeLevelOrder_(this->root_, visit); }

  /*!
   * @brief ʹ��ǰ�����������������, ����������
   * @param pre_order_str ǰ������ַ���
   * @param in_order_str ��������ַ���
   * @param str_length �ַ�������
   */
  void CreateBinTreeByPreAndInOrderString(T* pre_order_str, T* in_order_str, int str_length) {
    this->CreateSubBinTreeByPreAndInOrderString_(pre_order_str, in_order_str, str_length, this->root_);
  }

  /* ��ӡ���ϵ�� */
  /*!
   * @brief ��ӡ������(ʹ��'(', ',',')')
   */
  void Print() { this->SubTreePrint_(this->root_); };

  /*!
   * @brief ʹ������������������
   * @param in ������
   */
  void CreateBinTree(istream &in) { this->CreateBinTree_(in, this->root_); }

  //
  // void Traverse(BinTreeNode<T>* sub_tree_root, ostream& out);

  /*! ������CyberDash:-) */
  void CyberDashShow();

  // �ж����Ŷ������Ƿ���ͬ(�ݹ�)
  static bool Equal(BinTreeNode<T>* root_ptr_a, BinTreeNode<T>* root_ptr_b);

protected:
  BinTreeNode<T>* root_; //!< �����

  // void CreateBinTree_(istream& in, BinTreeNode<T>*& subTree);

  // ������������
  bool SubTreeInsert_(BinTreeNode<T>*& sub_tree_root, T data);
  // ɾ������
  void SubTreeDestroy_(BinTreeNode<T>*& sub_tree_root);
  // ���������Ƿ���(��)����(�ݹ�)
  bool SubTreeFind_(BinTreeNode<T>* sub_tree_root, T value) const;
  // ���ƶ�����
  BinTreeNode<T>* Copy_(BinTreeNode<T>* src_sub_tree_root);
  // �������ĸ߶�(�ݹ�)
  int SubTreeHeight_(BinTreeNode<T>* sub_tree_root) const;
  // ��������Size(�ݹ�)
  int SubTreeSize_(BinTreeNode<T>* sub_tree_root) const;
  // ������ȡ�ڵ�ĸ��ڵ�
  BinTreeNode<T>* Parent_(BinTreeNode<T>* sub_tree_root, BinTreeNode<T>* node);

  // ����ǰ�����(�ݹ�)
  void SubTreePreOrder_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node));
  // ����ǰ�����(�ǵݹ�)
  void SubTreePreOrderNonRecursive_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node));
  // �����������(�ݹ�)
  void SubTreeInOrder_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node));
  // �����������(�ǵݹ�)
  void SubTreeInOrderNonRecursive_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T> *node));
  // �����������(�ݹ�)
  void SubTreePostOrder_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node));
  // �����������(�ǵݹ�)
  void SubTreePostOrderNonRecursive_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node));
  // �����������
  void SubTreeLevelOrder_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node));
  // ������ӡ
  void SubTreePrint_(BinTreeNode<T>* sub_tree_root);

  // ʹ��ǰ�����������������, ������������(�ݹ�)
  void CreateSubBinTreeByPreAndInOrderString_(T* pre_order_str, T* in_order_str,
                                              int str_length, BinTreeNode<T>*& sub_tree_root);

  // �ж���������ͬ
  template<class U>
  friend bool operator == (const BinaryTree<T>& bin_tree_1, const BinaryTree<T>& bin_tree_2);
  // ���������
  template<class U>
  friend istream& operator >> (istream& in, BinaryTree<T>& bin_tree);
  // ���������
  template<class U>
  friend ostream& operator << (ostream& out, BinaryTree<T>& bin_tree);
};


/*!
 * @brief ������������
 * @tparam T ����ģ�����
 * @param sub_tree_root ���������
 * @param data ���������
 * @return �Ƿ����ɹ�
 */
template<class T>
bool BinaryTree<T>::SubTreeInsert_(BinTreeNode<T>*& sub_tree_root, T data) {

  if (sub_tree_root == NULL) {
    sub_tree_root = new BinTreeNode<T>(data);
    if (sub_tree_root == NULL) {
      cerr << "�洢�������!" << endl;
      return false;
    }

    return true;
  }

  bool insert_done = false;

  int left_sub_tree_height = SubTreeHeight_(sub_tree_root->left_child);
  int right_sub_tree_height = SubTreeHeight_(sub_tree_root->right_child);

  if (left_sub_tree_height > right_sub_tree_height) {
    insert_done = SubTreeInsert_(sub_tree_root->right_child, data);
  } else {
    insert_done = SubTreeInsert_(sub_tree_root->left_child, data);
  }

  return insert_done;
}


/*!
 * @brief ɾ������
 * @param sub_tree_root �������ڵ�
 */
template <class T>
void BinaryTree<T>::SubTreeDestroy_(BinTreeNode<T>*& sub_tree_root) {
  if (sub_tree_root == NULL) {
    return;
  }

  this->SubTreeDestroy_(sub_tree_root->left_child);
  this->SubTreeDestroy_(sub_tree_root->right_child);

  delete sub_tree_root;
  sub_tree_root = NULL;
}


/**
 * @brief ���������Ƿ���(��)����(�ݹ�)
 * @tparam T �������ģ������
 * @param sub_tree_root �������ڵ�ָ��
 * @param value ����������
 * @return �Ƿ����
 */
template<class T>
bool BinaryTree<T>::SubTreeFind_(BinTreeNode<T>* sub_tree_root, T value) const {

  if (sub_tree_root == NULL) {
    return false;
  }

  if (sub_tree_root->data == value) {
    return true;
  }

  if (SubTreeFind_(sub_tree_root->left_child, value)) {
    return true;
  }

  return SubTreeFind_(sub_tree_root->right_child, value);
}


/*!
 * @brief ���ƶ�����(�ݹ�)
 * @tparam T ����ģ�����
 * @param src_sub_tree_root Դ�����ڵ�
 * @return �������ڵ�
 */
template<class T>
BinTreeNode<T>* BinaryTree<T>::Copy_(BinTreeNode<T>* src_sub_tree_root) {
  if (src_sub_tree_root == NULL) {
    return NULL;
  }

  BinTreeNode<T>* new_sub_tree_root = new BinTreeNode<T>();
  /* Null handler */

  new_sub_tree_root->data = src_sub_tree_root->data;
  new_sub_tree_root->left_child = this->Copy_(src_sub_tree_root->left_child);
  new_sub_tree_root->right_child = this->Copy_(src_sub_tree_root->right_child);

  return new_sub_tree_root;
}


/*!
 * @brief �������ĸ߶�(�ݹ�)
 * @tparam T �ڵ�����ģ������
 * @param sub_tree_root �������ڵ�ָ��
 * @return �����߶�
 */
template<class T>
int BinaryTree<T>::SubTreeHeight_(BinTreeNode<T>* sub_tree_root) const {
  // ����������ڵ�Ϊ��, �򷵻�0
  if (sub_tree_root == NULL) {
    return 0;
  }

  int left_sub_tree_height = SubTreeHeight_(sub_tree_root->left_child); // �ݹ����������߶�
  int right_sub_tree_height = SubTreeHeight_(sub_tree_root->right_child); // �ݹ����������߶�

  // ���߶� = ��ߵ����������߶� + 1
  if (left_sub_tree_height < right_sub_tree_height) {
    return right_sub_tree_height + 1;
  } else {
    return left_sub_tree_height + 1;
  }
}


/*!
 * @brief ��������size(�ݹ�)
 * @tparam T �ڵ�����ģ������
 * @param sub_tree_root �������ڵ�ָ��
 * @return ����size
 */
template<class T>
int BinaryTree<T>::SubTreeSize_(BinTreeNode<T>* sub_tree_root) const {
  if (sub_tree_root == NULL) {
    return 0;
  }

  int left_sub_tree_size = SubTreeSize_(sub_tree_root->left_child); // �ݹ���������size
  int right_sub_tree_size = SubTreeSize_(sub_tree_root->right_child); // �ݹ���������size

  int sub_tree_size = 1 + left_sub_tree_size + right_sub_tree_size;

  return sub_tree_size;
}


/*!
 * @brief ������ȡ�ڵ�ĸ��ڵ�
 * @tparam T �ڵ�����ģ������
 * @param sub_tree_root �������ڵ�ָ��
 * @param node �ڵ�ָ��
 * @return �ڵ��(λ�������ڵ�)���ڵ�ָ��
 */
template<class T>
BinTreeNode<T>* BinaryTree<T>::Parent_(BinTreeNode<T>* sub_tree_root, BinTreeNode<T>* node) {

  // ���������ΪNULL, �򷵻�NULL
  if (sub_tree_root == NULL) {
    return NULL;
  }

  // ���������������or�Һ���, ����node_ptr�ĸ��ڵ�, �򷵻����������
  if (sub_tree_root->left_child == node || sub_tree_root->right_child == node) {
    return sub_tree_root;
  }

  BinTreeNode<T>* parent = this->Parent_(sub_tree_root->left_child, node);

  if (parent == NULL) {
    parent = Parent_(sub_tree_root->right_child, node);
  }

  return parent;
}


/*
template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T> *sub_tree_root, ostream& out) {
  if (sub_tree_root != NULL) {
    out << sub_tree_root->data << ' ';
    Traverse(sub_tree_root->left_child, out);
    Traverse(sub_tree_root->right_child, out);
  }
}
 */


/*!
 * @brief ����ǰ�����(�ݹ�)
 * @tparam T �ڵ�����ģ������
 * @param sub_tree_root �������ڵ�ָ��
 * @param visit ���ʺ���
 */
template<class T>
void BinaryTree<T>::SubTreePreOrder_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node)) {
  if (sub_tree_root == NULL) {
    return;
  }

  visit(sub_tree_root);

  SubTreePreOrder_(sub_tree_root->left_child, visit);
  SubTreePreOrder_(sub_tree_root->right_child, visit);
}


/**
 * @brief ����ǰ�����(�ǵݹ�)
 * @tparam T �ڵ�����ģ������
 * @param sub_tree_root �������ڵ�ָ��
 * @param visit ���ʺ���
 */
template<class T>
void BinaryTree<T>::SubTreePreOrderNonRecursive_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>*)) {

  // (ջ��ʼ��)����ǰ�����ջ, �������ڵ�ָ����ջ
  stack<BinTreeNode<T>*> pre_traverse_stack;
  pre_traverse_stack.push(sub_tree_root);

  while (!pre_traverse_stack.empty()) {

    // ��ջ
    BinTreeNode<T>* cur_node_ptr = pre_traverse_stack.top();
    pre_traverse_stack.pop();

    // ����
    visit(cur_node_ptr);

    // ���ӽڵ���ջ
    if (cur_node_ptr->right_child != NULL) {
      pre_traverse_stack.push(cur_node_ptr->right_child);
    }

    if (cur_node_ptr->left_child != NULL) {
      pre_traverse_stack.push(cur_node_ptr->left_child);
    }
  }
}


/*!
 * @brief �����������(�ݹ�)
 * @tparam T �ڵ�����ģ������
 * @param sub_tree_root �������ڵ�ָ��
 * @param visit ���ʺ���
 */
template<class T>
void BinaryTree<T>::SubTreeInOrder_(BinTreeNode<T>* sub_tree_root,
                                    void (*visit)(BinTreeNode<T>*))
{
  if (sub_tree_root == NULL) {
    return;
  }

  SubTreeInOrder_(sub_tree_root->left_child, visit);

  visit(sub_tree_root);

  SubTreeInOrder_(sub_tree_root->right_child, visit);
}


/**
 * @brief �����������(�ǵݹ�)
 * @tparam T �ڵ�����ģ������
 * @param sub_tree_root �������ڵ�ָ��
 * @param visit ���ʺ���
 */
template<class T>
void BinaryTree<T>::SubTreeInOrderNonRecursive_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node)) {

  stack<BinTreeNode<T>*> in_traverse_stack;
  BinTreeNode<T>* cur_node = sub_tree_root;

  while (cur_node != NULL || !in_traverse_stack.empty()) {

    while (cur_node != NULL) {
      in_traverse_stack.push(cur_node);
      cur_node = cur_node->left_child;
    }

    if (!in_traverse_stack.empty()) {

      cur_node = in_traverse_stack.top();
      in_traverse_stack.pop();

      visit(cur_node);

      cur_node = cur_node->right_child;
    }
  }
}


/*!
 * @brief �����������(�ݹ�)
 * @tparam T �ڵ�����ģ������
 * @param sub_tree_root �������ڵ�ָ��
 * @param visit ���ʺ���
 */
template<class T>
void BinaryTree<T>::SubTreePostOrder_(BinTreeNode<T>* sub_tree_root,
                                      void (*visit)(BinTreeNode<T>*))
{
  if (sub_tree_root == NULL) {
    return;
  }

  SubTreePostOrder_(sub_tree_root->left_child, visit);
  SubTreePostOrder_(sub_tree_root->right_child, visit);

  visit(sub_tree_root);
}


/**
 * @brief �����������(�ǵݹ�)
 * @tparam T �ڵ�����ģ������
 * @param sub_tree_root �������ڵ�ָ��
 * @param visit ���ʺ���
 */
template <class T>
void BinaryTree<T>::SubTreePostOrderNonRecursive_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>*)) {

  stack<PostOrderStackNode<T> > post_traverse_stack;

  BinTreeNode<T>* cur_node = sub_tree_root;

  do {
    while (cur_node != NULL) {
      PostOrderStackNode<T> traverse_node(cur_node);
      post_traverse_stack.push(traverse_node);
      cur_node = cur_node->left_child;
    }

    bool left_unfinished = true;
    while (left_unfinished && !post_traverse_stack.empty()) {

      PostOrderStackNode<T> cur_traverse_node = post_traverse_stack.top();
      post_traverse_stack.pop();

      cur_node = cur_traverse_node.node;

      switch (cur_traverse_node.tag) {
        case PostOrderStackNode<T>::LEFT:
          cur_traverse_node.tag = PostOrderStackNode<T>::RIGHT;
          post_traverse_stack.push(cur_traverse_node);
          cur_node = cur_node->right_child;

          left_unfinished = false;

          break;
        case PostOrderStackNode<T>::RIGHT:
          visit(cur_node);

          break;
      }
    }
  } while (!post_traverse_stack.empty());
}


/**
 * @brief �����������
 * @tparam T �ڵ�����ģ������
 * @param sub_tree_root �������ڵ�ָ��
 * @param visit ���ʺ���
 */
template<class T>
void BinaryTree<T>::SubTreeLevelOrder_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node_ptr)) {

  queue<BinTreeNode<T>*> level_traverse_queue;

  BinTreeNode<T>* cur_node = sub_tree_root;
  level_traverse_queue.push(cur_node);

  while (!level_traverse_queue.empty()) {
    cur_node = level_traverse_queue.front();
    level_traverse_queue.pop();

    visit(cur_node);

    if (cur_node->left_child != NULL) {
      level_traverse_queue.push(cur_node->left_child);
    }

    if (cur_node->right_child != NULL) {
      level_traverse_queue.push(cur_node->right_child);
    }
  }
}


/*!
 * @brief ������ӡ
 * @tparam T �������ģ������
 * @param sub_tree_root �������ڵ�
 */
template<class T>
void BinaryTree<T>::SubTreePrint_(BinTreeNode<T>* sub_tree_root) {

  if (sub_tree_root == NULL) {
    return;
  }

  cout << sub_tree_root->data;

  if (sub_tree_root->left_child != NULL || sub_tree_root->right_child != NULL) {

    cout << '(';

    this->SubTreePrint_(sub_tree_root->left_child);

    cout << ',';

    if (sub_tree_root->right_child != NULL) {
      this->SubTreePrint_(sub_tree_root->right_child);
    }

    cout << ')';
  }
}


/*!
 * @brief ʹ��ǰ�����������������, ������������(�ݹ�)
 * @param pre_order_str ǰ������ַ���
 * @param in_order_str ��������ַ���
 * @param str_length �ַ�������
 * @param sub_tree_root ���������
 */
template<class T>
void BinaryTree<T>::CreateSubBinTreeByPreAndInOrderString_(T* pre_order_str, T* in_order_str,
                                                           int str_length, BinTreeNode<T>*& sub_tree_root)
{
  if (str_length == 0) {
    return;
  }

  int pivot = 0;
  T cur_root_value = pre_order_str[0];

  while (cur_root_value != in_order_str[pivot]) {
    pivot++;
  }

  sub_tree_root = new BinTreeNode<T>(cur_root_value);
  if (sub_tree_root == NULL) {
    cerr << "�洢�������!" << endl;
    exit(1);
  }

  CreateSubBinTreeByPreAndInOrderString_(pre_order_str + 1,
                                         in_order_str,
                                         pivot,
                                         sub_tree_root->left_child);

  CreateSubBinTreeByPreAndInOrderString_(pre_order_str + pivot + 1,
                                         in_order_str + pivot + 1,
                                         str_length - pivot - 1,
                                         sub_tree_root->right_child);
}


/*!
 * @brief �ж����Ŷ������Ƿ���ͬ(�ݹ�)
 * @tparam T �������ģ������
 * @param root_ptr_a ���ڵ�a
 * @param root_ptr_b ���ڵ�2
 * @return �Ƿ���ͬ
 */
template<class T>
bool BinaryTree<T>::Equal(BinTreeNode<T>* root_ptr_a, BinTreeNode<T>* root_ptr_b) {
  if (root_ptr_a == NULL && root_ptr_b == NULL) {
    return true;
  }

  if (root_ptr_a != NULL && root_ptr_b != NULL && root_ptr_a->data == root_ptr_b->data
      && BinaryTree<T>::Equal(root_ptr_a->left_child, root_ptr_b->left_child)
      && BinaryTree<T>::Equal(root_ptr_a->right_child, root_ptr_b->right_child))
  {
    return true;
  } else {
    return false;
  }
}


/*
template<class T>
void BinaryTree<T>::CreateBinTree_(istream& in, BinTreeNode<T>*& subTree) {
  T item;

  if (!in.eof()) {
    in >> item;
    if (item != value_) {
      subTree = new BinTreeNode<T>(item);
      if(subTree == NULL) {
        cerr << "�洢�������!" << endl;
        exit(1);
      }
      CreateBinTree_(in, subTree->left_child);
      CreateBinTree_(in, subTree->right_child);
    } else {
      subTree = NULL;
    }
  }
}
 */


/*!
 * @brief ����==
 * @tparam T ����ģ�����
 * @param bin_tree_1 ������1
 * @param bin_tree_2 ������2
 * @return
 */
template<class T>
bool operator == (const BinaryTree<T>& bin_tree_1, const BinaryTree<T>& bin_tree_2) {
  return (BinaryTree<T>::Equal(bin_tree_1.GetRoot(), bin_tree_2.GetRoot()));
}


template<class T>
istream& operator >> (istream& in, BinaryTree<T>& Tree) {
  Tree.CreateBinTree(in);
  return in;
}


template<class T>
ostream& operator << (ostream& out, BinaryTree<T>& Tree) {
  out << "��������ǰ�����\n";
  Tree.Traverse(Tree.GetRoot(), out);
  out << endl;
  return out;
}


/**
 * ������CyberDash :-)
 */
template<class T>
void BinaryTree<T>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"������\"CyberDash���������\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash��Ա:"<<endl
      <<"Ԫ��(cyberdash@163.com), "<<"�����ʵ��ѧ(ͨ�Ź��̱���)/�����ʵ��ѧ(��Ϣ��ͨ��ϵͳ�о���)"<<endl
      <<"�ڸ�(alei_go@163.com), "<<"ɽ������ѧ(��ѧ����)/�����ʵ��ѧ(������о���)"<<endl<<endl
      <<"L_Dash(yuleen_@outlook.com), "<<"�����ʵ��ѧ(������о����ڶ�)"<<endl<<endl
      <<"���ݽṹ��Դ����(C++�廪��ѧ������)ħ�������汾: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}


#endif //CYBER_DASH_BINARY_TREE_H
