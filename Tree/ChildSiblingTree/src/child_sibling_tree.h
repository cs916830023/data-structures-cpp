/*!
 * @file ChildSiblingTree.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 子女兄弟树模板类
 * @version 0.2.1
 * @date 2020-11-01
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_CHILD_SIBLING_TREE_H
#define CYBER_DASH_CHILD_SIBLING_TREE_H


#include <cstdlib>
#include <iostream>
#include <queue>


using namespace std;


/*!
 * @brief 子女兄弟树结点模板结构体
 * @tparam T 类型模板参数
 */
template <class T>
struct ChildSiblingNode {
  /*!
   * @brief 结构体构造函数
   * @param data 数据项
   * @param first_child 长子结点指针
   * @param next_sibling 下一兄弟结点指针
   */
  explicit ChildSiblingNode(T data, ChildSiblingNode<T>* first_child = NULL, ChildSiblingNode<T>* next_sibling = NULL):
    data(data), first_child(first_child), next_sibling(next_sibling) {}

  T data; //!< 数据项
  ChildSiblingNode<T>* first_child; //!< 长子结点指针
  ChildSiblingNode<T>* next_sibling; //!< 兄弟结点指针
};


/*!
 * @brief 子女兄弟树模板类
 * @tparam T 类型模板参数
 */
template <class T>
class ChildSiblingTree {
public:
  /*! @brief 构造函数 */
  ChildSiblingTree(): root_(NULL), current_(NULL) {}
  bool SetRootToCurrent();
  bool IsEmpty() { return this->root_ == NULL; }
  bool FirstChild(); // todo: 书上设计有缺陷, 应返回指针类型
  bool NextSibling(); // todo: 书上设计有缺陷, 同上
  bool FindParentAndSetCurrent(); // todo: 书上设计有缺陷, 同上
  bool FindAndSetCurrent(T data); // todo: 书上设计有缺陷, 同上
  void Insert(T& item) { return this->InsertInSubTree_(this->root_, item);} // todo: 有问题
  ChildSiblingNode<T>* AddSibling(ChildSiblingNode<T>* node, T data);
  ChildSiblingNode<T>* Root() { return this->root_; }
  void PreOrder(ostream& out) { PreOrderByOstream(out, this->root_); }
  void PostOrder(ostream& out) { PostOrderByOstream(out, this->root_); }
  void PreOrder(void (*visit)(ChildSiblingNode<T>*)) { PreOrderInSubTreeRecursive_(root_, visit); }
  void PostOrder(void (*visit)(ChildSiblingNode<T>*)) { PostOrderInSubTreeRecursive_(root_, visit); }
  void LevelOrder(ostream& out) { LevelOrderInSubTree_(out, root_); }
  int NodeCount() { return this->SubTreeNodeCountRecursive_(this->root_); }
  int Depth() { return this->SubTreeDepthRecursive_(this->root_); }
  void CreateTreeByStr(char*& str) { this->CreateTreeByStrRecursive_(this->root_, str); }
  void ShowTree() { this->ShowSubTreeRecursive_(this->root_); }
  void CyberDashShow();
private:
  ChildSiblingNode<T>* root_; //!< 根结点
  ChildSiblingNode<T>* current_; //!< 当前指针, 为了方便链表操作

  // 在子树中使用数据项查找, 并将节点赋给current_
  bool FindAndSetCurrentInSubTree_(ChildSiblingNode<T>* sub_tree_root, T data);
  // 删除子树
  void RemoveSubTree_(ChildSiblingNode<T>* sub_tree_root);
  // 在子树中寻找父结点, 并设置当前结点current_
  bool FindParentAndSetCurrentInSubTree_(ChildSiblingNode<T>* sub_tree_root, ChildSiblingNode<T>* node);

  void InsertInSubTree_(ChildSiblingNode<T>*& sub_tree_root, T& data);
  void PreOrderByOstream(ostream& out, ChildSiblingNode<T> *p);
  void PostOrderByOstream(ostream& out, ChildSiblingNode<T> *p);
  // 在子树中进行先根遍历(递归)
  void PreOrderInSubTreeRecursive_(ChildSiblingNode<T>* sub_tree_root, void (*visit)(ChildSiblingNode<T>*));
  // 在子树中进行后根遍历(递归)
  void PostOrderInSubTreeRecursive_(ChildSiblingNode<T>* sub_tree_root, void (*visit)(ChildSiblingNode<T>*));
  // 在子树中层序遍历
  void LevelOrderInSubTree_(ostream& out, ChildSiblingNode<T> *sub_tree_root);
  // 使用字符串创建子女兄弟树
  void CreateTreeByStrRecursive_(ChildSiblingNode<T>*& , char*& str);
  // 子树节点数量(递归)
  int SubTreeNodeCountRecursive_(ChildSiblingNode<T> *sub_tree_root);
  // 子树深度(递归)
  int SubTreeDepthRecursive_(ChildSiblingNode<T> *sub_tree_root);
  // 打印子树(递归)
  void ShowSubTreeRecursive_(ChildSiblingNode<T> *sub_tree_root);
};


/*!
 * @brief 让树的根结点成为树的当前结点
 * @tparam T 类型模板参数
 * @return 是否设置成功
 */
template <class T>
bool ChildSiblingTree<T>::SetRootToCurrent() {
  if (this->root_ == NULL) {
    this->current_ = NULL;
    return false;
  }

  this->current_ = this->root_;

  return true;
}


/*!
 * @brief 删除子树
 * @tparam T 类型模板参数
 * @param sub_tree_root 子树根结点
 */
template<class T>
void ChildSiblingTree<T>::RemoveSubTree_(ChildSiblingNode<T>* sub_tree_root){
  if (sub_tree_root != NULL) {
    this->RemoveSubTree_(sub_tree_root->first_child);
    this->RemoveSubTree_(sub_tree_root->next_sibling);
    delete sub_tree_root;
  }
}


/*!
 * @brief 寻找父结点, 并设置当前结点current_
 * @tparam T 类型模板参数
 * @return 是否成功
 */
template <class T>
bool ChildSiblingTree<T>::FindParentAndSetCurrent() {
  ChildSiblingNode<T>* node = this->current_;

  if (this->current_ == NULL || this->current_ == this->root_) {
    this->current_ = NULL;
    return false;
  }

  return FindParentAndSetCurrentInSubTree_(this->root_, node);
}


/*!
 * @brief 在子树中寻找父结点, 并设置当前结点current_
 * @tparam T 类型模板参数
 * @param sub_tree_root 子树根结点
 * @param node 待寻找父结点的结点
 * @return 是否成功
 */
template <class T>
bool ChildSiblingTree<T>::FindParentAndSetCurrentInSubTree_(ChildSiblingNode<T>* sub_tree_root, ChildSiblingNode<T>* node) {

  /*
  ChildSiblingNode<T>* cur = sub_tree_root->first_child;
  bool succ;

  while (cur != NULL && cur != node) {
    if ((succ = FindParentInSubTree_(cur, node)) == true) {
      return succ;
    }
    cur = cur->next_sibling;
  }

  if (cur != NULL && cur == node) {
    current_ = sub_tree_root;
    return true;
  } else {
    current_ = NULL;
    return false;
  }
   */

  ChildSiblingNode<T>* cur = sub_tree_root->first_child;

  while (cur != NULL && cur != node) {
    bool isFound = FindParentAndSetCurrentInSubTree_(cur, node);
    if (isFound == true) {
      return true;
    }
    cur = cur->next_sibling;
  }

  // node是根节点的孩子
  if (cur != NULL && cur == node) {
    this->current_ = sub_tree_root;
    return true;
  }

  this->current_ = NULL;
  return false;
}


template <class T>
bool ChildSiblingTree<T>::FirstChild() {
  if (this->current_ != NULL && this->current_->first_child != NULL) {
    current_ = current_->first_child;
    return true;
  }

  current_ = NULL;

  return false;
}


template <class T>
bool ChildSiblingTree<T>::NextSibling() {
  if (current_ != NULL && current_->next_sibling != NULL) {
    current_ = current_->next_sibling;
    return true;
  }

  current_ = NULL;

  return false;
}


template <class T>
bool ChildSiblingTree<T>::FindAndSetCurrent(T data) {
  if (this->IsEmpty()) {
    return false;
  }

  return FindAndSetCurrentInSubTree_(this->root_, data);
}


template <class T>
ChildSiblingNode<T>* AddSibling(ChildSiblingNode<T>* node, T data) {
    if (node == NULL) {
        return NULL;
    }

    while (node->next_sibling != NULL) {

    }
}

/*!
 * @brief 在子树中使用数据项查找, 并将节点赋给current_
 * @tparam T 类型模板参数
 * @param sub_tree_root 子树根结点
 * @param data 数据项
 * @return 是否成功
 */
template <class T>
bool ChildSiblingTree<T>::FindAndSetCurrentInSubTree_(ChildSiblingNode<T>* sub_tree_root, T data) {
  bool isFound = false;

  if (sub_tree_root->data == data) {
    isFound = true;
    this->current_ = sub_tree_root;
  } else {
    ChildSiblingNode<T>* cur = sub_tree_root->first_child;
    /*
    while (cur != NULL && !(isFound = FindAndSetCurrentInSubTree_(cur, data))) {
      cur = cur->next_sibling;
    }
     */
    while (cur != NULL) {
      isFound = FindAndSetCurrentInSubTree_(cur, data);
      if (isFound) {
        break;
      }

      cur = cur->next_sibling;
    }
  }

  return isFound;
}


template <class T>
void ChildSiblingTree<T>::InsertInSubTree_(ChildSiblingNode<T>*& sub_tree_root, T& data) {

  if (sub_tree_root == NULL) {
    sub_tree_root = new ChildSiblingNode<T>(data);
    // error handling
  } else {
    InsertInSubTree_(sub_tree_root->first_child, data);
    if (sub_tree_root == Root()) {
      return;
    }
    InsertInSubTree_(sub_tree_root->next_sibling, data);
  }
}


template <class T>
void ChildSiblingTree<T>::PreOrderByOstream(ostream& out, ChildSiblingNode<T>* p) {
  if (p != NULL) {
    out << p->data;

    for (p = p->first_child; p != NULL; p = p->next_sibling) {
        PreOrderByOstream(out, p);
    }
  }
}

template <class T>
void ChildSiblingTree<T>::PostOrderByOstream(ostream& out, ChildSiblingNode<T> *p) {
  if (p != NULL) {
    ChildSiblingNode<T> *q;

    for (q = p->first_child; q != NULL; q = q->next_sibling) {
        PostOrderByOstream(out, q);
    }
    out << p->data;
  }
}


/*!
 * @brief 在子树中先根遍历
 * @tparam T 类型模板参数
 * @param sub_tree_root 子树根结点
 * @param visit 遍历函数
 */
template <class T>
void ChildSiblingTree<T>::PreOrderInSubTreeRecursive_(ChildSiblingNode<T>* sub_tree_root,
                                                      void (*visit)(ChildSiblingNode<T>*))
{
  if (sub_tree_root == NULL) {
    return;
  }

  visit(sub_tree_root);

  PreOrderInSubTreeRecursive_(sub_tree_root->first_child, visit); // 对长子结点进行递归
  PreOrderInSubTreeRecursive_(sub_tree_root->next_sibling, visit); // 对兄弟结点进行递归
}


/*!
 * @brief 在子树中后根遍历
 * @tparam T 类型模板参数
 * @param sub_tree_root 子树根结点
 * @param visit 遍历函数
 */
template <class T>
void ChildSiblingTree<T>::PostOrderInSubTreeRecursive_(ChildSiblingNode<T>* sub_tree_root,
                                                       void (*visit)(ChildSiblingNode<T>*))
{
  if (sub_tree_root == NULL) {
    return;
  }

  PostOrderInSubTreeRecursive_(sub_tree_root->first_child, visit);
  visit(sub_tree_root);
  PostOrderInSubTreeRecursive_(sub_tree_root->next_sibling, visit);
}


/*!
 * @brief 在子树中层序遍历
 * @tparam T 类型模板参数
 * @param out 输出流
 * @param sub_tree_root 子树根节点
 */
template <class T>
void ChildSiblingTree<T>::LevelOrderInSubTree_(ostream& out, ChildSiblingNode<T>* sub_tree_root)
{
  queue<ChildSiblingNode<T>*> node_queue;

  if (sub_tree_root == NULL) {
    return;
  }

  // 初始化队列node_queue
  node_queue.push(sub_tree_root);

  while (!node_queue.empty()) {
    // 取队头
    ChildSiblingNode<T>* front_node = node_queue.front();
    node_queue.pop();

    // 输出流输出
    out << front_node->data;

    // 队头节点的所有孩子节点入队
    for (ChildSiblingNode<T>* cur = front_node->first_child; cur != NULL; cur = cur->next_sibling) {
      node_queue.push(cur);
    }
  }
}


/*!
 * @brief 子树节点数量(递归)
 * @tparam T 类型模板参数
 * @param sub_tree_root
 * @return 节点数量
 */
template <class T>
int ChildSiblingTree<T>::SubTreeNodeCountRecursive_(ChildSiblingNode<T>* sub_tree_root) {
  if (sub_tree_root == NULL) {
    return 0;
  }

  int count = 1;

  count += SubTreeNodeCountRecursive_(sub_tree_root->first_child);
  count += SubTreeNodeCountRecursive_(sub_tree_root->next_sibling);

  return count;
}


/*!
 * @brief 子树深度(递归)
 * @tparam T 类型模板参数
 * @param sub_tree_root 子树根结点
 * @return 深度
 */
template <class T>
int ChildSiblingTree<T>::SubTreeDepthRecursive_(ChildSiblingNode<T>* sub_tree_root) {
  if (sub_tree_root == NULL) {
    return 0;
  }

  // 长子结点对应的深度
  int first_child_depth = SubTreeDepthRecursive_(sub_tree_root->first_child) + 1;
  // 下一兄弟结点对应的深度
  int next_sibling_depth = SubTreeDepthRecursive_(sub_tree_root->next_sibling);

  return (first_child_depth > next_sibling_depth) ? first_child_depth : next_sibling_depth;
}


/*!
 * @brief 使用字符串创建子女兄弟树
 * @tparam T 类型模板参数
 * @param sub_tree_root 子树根节点
 * @param str 字符串
 */
template <class T>
void ChildSiblingTree<T>::CreateTreeByStrRecursive_(ChildSiblingNode<T>*& sub_tree_root, char*& str) {
  if (*str == '\0') {
    return;
  }

  if (*str == ')') {
    str++; // 下一个兄弟节点
    return;
  }

  while (*str == '(') {
    str++;
  }

  sub_tree_root = new ChildSiblingNode<T>(*(str++) - '0');
  /* error handler */

  CreateTreeByStrRecursive_(sub_tree_root->first_child, str);
  CreateTreeByStrRecursive_(sub_tree_root->next_sibling, str);
}


/*!
 * @brief 打印子树(递归)
 * @tparam T 类型模板参数
 * @param sub_tree_root 子树根结点
 */
template <class T>
void ChildSiblingTree<T>::ShowSubTreeRecursive_(ChildSiblingNode<T>* sub_tree_root) {
  if (sub_tree_root == NULL) {
    return;
  }

  cout << '(';
  cout << sub_tree_root->data;

  for (ChildSiblingNode<T>* cur = sub_tree_root->first_child; cur != NULL; cur = cur->next_sibling) {
      ShowSubTreeRecursive_(cur);
  }

  cout << ')';
}


template<class T>
void ChildSiblingTree<T>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"L_Dash(lyu2586@163.com), "<<"北京邮电大学(计算机在读研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}

#endif // CYBER_DASH_CHILD_SIBLING_TREE_H
