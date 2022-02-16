/*!
 * @file ChildSiblingTree.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ��Ů�ֵ���ģ����
 * @version 0.2.1
 * @date 2020-11-01
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#ifndef CYBER_DASH_CHILD_SIBLING_TREE_H
#define CYBER_DASH_CHILD_SIBLING_TREE_H


#include <cstdlib>
#include <iostream>
#include <queue>


using namespace std;


/*!
 * @brief ��Ů�ֵ������ģ��ṹ��
 * @tparam T ����ģ�����
 */
template <class T>
struct ChildSiblingNode {
  /*!
   * @brief �ṹ�幹�캯��
   * @param data ������
   * @param first_child ���ӽ��ָ��
   * @param next_sibling ��һ�ֵܽ��ָ��
   */
  ChildSiblingNode(T data, ChildSiblingNode<T>* first_child = NULL, ChildSiblingNode<T>* next_sibling = NULL):
    data(data), first_child(first_child), next_sibling(next_sibling) {}

  T data; //!< ������
  ChildSiblingNode<T>* first_child; //!< ���ӽ��ָ��
  ChildSiblingNode<T>* next_sibling; //!< �ֵܽ��ָ��
};


/*!
 * @brief ��Ů�ֵ���ģ����
 * @tparam T ����ģ�����
 */
template <class T>
class ChildSiblingTree {
public:
  /*! @brief ���캯�� */
  ChildSiblingTree(): root_(NULL), current_(NULL) {}
  bool SetRootToCurrent();
  bool IsEmpty() { return this->root_ == NULL; }
  bool FirstChild();
  bool NextSibling();
  bool FindParentAndSetCurrent();
  bool FindAndSetCurrent(T data);
  void Insert(T& item) { return this->InsertInSubTree_(this->root_, item);}
  ChildSiblingNode<T>* Root() { return this->root_; }
  void PreOrder(ostream& out) { PreOrder(out, this->root_); }
  void PostOrder(ostream& out) { PostOrder(out, this->root_); }
  void PreOrder(void (*visit)(ChildSiblingNode<T>*)) { PreOrderInSubTreeRecursive_(root_, visit); }
  void PostOrder(void (*visit)(ChildSiblingNode<T>*)) { PostOrderInSubTreeRecursive_(root_, visit); }
  void LevelOrder(ostream& out) { LevelOrderInSubTree_(out, root_); }
  int NodeCount() { return this->SubTreeNodeCountRecursive_(this->root_); }
  int Depth() { return this->SubTreeDepthRecursive_(this->root_); }
  void CreateTreeByStr(char*& str) { this->CreateTreeByStrRecursive_(this->root_, str); }
  void ShowTree() { this->ShowSubTreeRecursive_(this->root_); }
  void CyberDashShow();
private:
  ChildSiblingNode<T>* root_; //!< �����
  ChildSiblingNode<T>* current_; //!< ��ǰָ��, Ϊ�˷����������

  // ��������ʹ�����������, �����ڵ㸳��current_
  bool FindAndSetCurrentInSubTree_(ChildSiblingNode<T>* sub_tree_root, T data);
  // ɾ������
  void RemoveSubTree_(ChildSiblingNode<T>* sub_tree_root);
  // ��������Ѱ�Ҹ����, �����õ�ǰ���current_
  bool FindParentAndSetCurrentInSubTree_(ChildSiblingNode<T>* sub_tree_root, ChildSiblingNode<T>* node);

  void InsertInSubTree_(ChildSiblingNode<T>*& sub_tree_root, T& data);
  void PreOrder(ostream& out, ChildSiblingNode<T> *p);
  void PostOrder(ostream& out, ChildSiblingNode<T> *p);
  // �������н����ȸ�����(�ݹ�)
  void PreOrderInSubTreeRecursive_(ChildSiblingNode<T>* sub_tree_root, void (*visit)(ChildSiblingNode<T>*));
  // �������н��к������(�ݹ�)
  void PostOrderInSubTreeRecursive_(ChildSiblingNode<T>* sub_tree_root, void (*visit)(ChildSiblingNode<T>*));
  // �������в������
  void LevelOrderInSubTree_(ostream& out, ChildSiblingNode<T> *sub_tree_root);
  // ʹ���ַ���������Ů�ֵ���
  void CreateTreeByStrRecursive_(ChildSiblingNode<T>*& , char*& str);
  // �����ڵ�����(�ݹ�)
  int SubTreeNodeCountRecursive_(ChildSiblingNode<T> *sub_tree_root);
  // �������(�ݹ�)
  int SubTreeDepthRecursive_(ChildSiblingNode<T> *sub_tree_root);
  // ��ӡ����(�ݹ�)
  void ShowSubTreeRecursive_(ChildSiblingNode<T> *sub_tree_root);
};


/*!
 * @brief �����ĸ�����Ϊ���ĵ�ǰ���
 * @tparam T ����ģ�����
 * @return �Ƿ����óɹ�
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
 * @brief ɾ������
 * @tparam T ����ģ�����
 * @param sub_tree_root ���������
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
 * @brief Ѱ�Ҹ����, �����õ�ǰ���current_
 * @tparam T ����ģ�����
 * @return �Ƿ�ɹ�
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
 * @brief ��������Ѱ�Ҹ����, �����õ�ǰ���current_
 * @tparam T ����ģ�����
 * @param sub_tree_root ���������
 * @param node ��Ѱ�Ҹ����Ľ��
 * @return �Ƿ�ɹ�
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

  // node�Ǹ��ڵ�ĺ���
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


/*!
 * @brief ��������ʹ�����������, �����ڵ㸳��current_
 * @tparam T ����ģ�����
 * @param sub_tree_root ���������
 * @param data ������
 * @return �Ƿ�ɹ�
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
void ChildSiblingTree<T>::PreOrder(ostream& out, ChildSiblingNode<T>* p) {
  if (p != NULL) {
    out << p->data;

    for (p = p->first_child; p != NULL; p = p->next_sibling) {
      PreOrder(out, p);
    }
  }
}

template <class T>
void ChildSiblingTree<T>::PostOrder(ostream& out, ChildSiblingNode<T> *p) {
  if (p != NULL) {
    ChildSiblingNode<T> *q;

    for (q = p->first_child; q != NULL; q = q->next_sibling) {
      PostOrder(out, q);
    }
    out << p->data;
  }
}


/*!
 * @brief ���������ȸ�����
 * @tparam T ����ģ�����
 * @param sub_tree_root ���������
 * @param visit ��������
 */
template <class T>
void ChildSiblingTree<T>::PreOrderInSubTreeRecursive_(ChildSiblingNode<T>* sub_tree_root,
                                                      void (*visit)(ChildSiblingNode<T>*))
{
  if (sub_tree_root == NULL) {
    return;
  }

  visit(sub_tree_root);

  PreOrderInSubTreeRecursive_(sub_tree_root->first_child, visit); // �Գ��ӽ����еݹ�
  PreOrderInSubTreeRecursive_(sub_tree_root->next_sibling, visit); // ���ֵܽ����еݹ�
}


/*!
 * @brief �������к������
 * @tparam T ����ģ�����
 * @param sub_tree_root ���������
 * @param visit ��������
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
 * @brief �������в������
 * @tparam T ����ģ�����
 * @param out �����
 * @param sub_tree_root �������ڵ�
 */
template <class T>
void ChildSiblingTree<T>::LevelOrderInSubTree_(ostream& out, ChildSiblingNode<T>* sub_tree_root)
{
  queue<ChildSiblingNode<T>*> node_queue;

  if (sub_tree_root == NULL) {
    return;
  }

  // ��ʼ������node_queue
  node_queue.push(sub_tree_root);

  while (!node_queue.empty()) {
    // ȡ��ͷ
    ChildSiblingNode<T>* front_node = node_queue.front();
    node_queue.pop();

    // ��������
    out << front_node->data;

    // ��ͷ�ڵ�����к��ӽڵ����
    for (ChildSiblingNode<T>* cur = front_node->first_child; cur != NULL; cur = cur->next_sibling) {
      node_queue.push(cur);
    }
  }
}


/*!
 * @brief �����ڵ�����(�ݹ�)
 * @tparam T ����ģ�����
 * @param sub_tree_root
 * @return �ڵ�����
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
 * @brief �������(�ݹ�)
 * @tparam T ����ģ�����
 * @param sub_tree_root ���������
 * @return ���
 */
template <class T>
int ChildSiblingTree<T>::SubTreeDepthRecursive_(ChildSiblingNode<T>* sub_tree_root) {
  if (sub_tree_root == NULL) {
    return 0;
  }

  // ���ӽ���Ӧ�����
  int first_child_depth = SubTreeDepthRecursive_(sub_tree_root->first_child) + 1;
  // ��һ�ֵܽ���Ӧ�����
  int next_sibling_depth = SubTreeDepthRecursive_(sub_tree_root->next_sibling);

  return (first_child_depth > next_sibling_depth) ? first_child_depth : next_sibling_depth;
}


/*!
 * @brief ʹ���ַ���������Ů�ֵ���
 * @tparam T ����ģ�����
 * @param sub_tree_root �������ڵ�
 * @param str �ַ���
 */
template <class T>
void ChildSiblingTree<T>::CreateTreeByStrRecursive_(ChildSiblingNode<T>*& sub_tree_root, char*& str) {
  if (*str == '\0') {
    return;
  }

  if (*str == ')') {
    str++; // ��һ���ֵܽڵ�
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
 * @brief ��ӡ����(�ݹ�)
 * @tparam T ����ģ�����
 * @param sub_tree_root ���������
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
      <<"������\"CyberDash���������\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash��Ա:"<<endl
      <<"Ԫ��(cyberdash@163.com), "<<"�����ʵ��ѧ(ͨ�Ź��̱���)/�����ʵ��ѧ(��Ϣ��ͨ��ϵͳ�о���)"<<endl
      <<"�ڸ�(alei_go@163.com), "<<"ɽ������ѧ(��ѧ����)/�����ʵ��ѧ(������о���)"<<endl<<endl
      <<"L_Dash(lyu2586@163.com), "<<"�����ʵ��ѧ(������ڶ��о���)"<<endl<<endl
      <<"���ݽṹ��Դ����(C++�廪��ѧ������)ħ�������汾: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}

#endif // CYBER_DASH_CHILD_SIBLING_TREE_H
