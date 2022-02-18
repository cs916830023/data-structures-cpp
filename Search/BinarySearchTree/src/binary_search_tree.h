#ifndef CYBER_DASH_BINARY_SEARCH_TREE_H
#define CYBER_DASH_BINARY_SEARCH_TREE_H


#include <iostream>
#include <cstdlib>


using namespace std;


template <class Elem, class Key>
class BSTNode {
public:
  BSTNode(): left_child_ptr_(NULL), right_child_ptr_(NULL) {}
  BSTNode(Elem elem, Key key): elem_(elem), key_(key), left_child_ptr_(NULL), right_child_ptr_(NULL) {}
  BSTNode(Elem elem, Key key, BSTNode<Elem, Key>* left_child_ptr, BSTNode<Elem, Key>* right_child_ptr):
      elem_(elem), key_(key), left_child_ptr_(left_child_ptr), right_child_ptr_(right_child_ptr) {}

  BSTNode<Elem, Key>*& LeftChildPtr() { return this->left_child_ptr_; };
  BSTNode<Elem, Key>*& RightChildPtr() { return this->right_child_ptr_; };

  void SetLeftChildPtr(BSTNode<Elem, Key>* node_ptr) { this->left_child_ptr_ = node_ptr; }
  void SetRightChildPtr(BSTNode<Elem, Key>* node_ptr) { this->right_child_ptr_ = node_ptr; }

  virtual void SetKey(const Key& key) { this->key_ = key; }
  virtual Key GetKey() { return this->key_; }

  virtual void SetData(const Elem& elem) { this->elem_ = elem;}
  virtual Elem GetData() {
    return this->elem_;
  }

protected:
  BSTNode<Elem, Key>* left_child_ptr_;
  BSTNode<Elem, Key>* right_child_ptr_;

  Key key_;
  Elem elem_;
};


template <class Elem, class Key>
class BST {
public:
  BST(): root_node_ptr_(NULL) {}
  BST(Key key, Elem elem);

  virtual ~BST() { delete this->root_node_ptr_; };

  virtual bool Insert(Elem elem, Key key);
  virtual bool Remove(const Key& key) { return RemoveInSubTree_(key, root_node_ptr_); }
  BSTNode<Elem, Key>* Search (Key key) { return SearchInSubTree_(key, this->root_node_ptr_); }
  virtual int Height() { return this->SubTreeHeight_(this->root_node_ptr_); }

  virtual Elem Min();
  virtual Elem Max();

  virtual void MakeEmpty() { MakeEmptySubTree_(root_node_ptr_); root_node_ptr_ = NULL; }
  void PrintTree(void (*visit)(BSTNode<Elem, Key>*)) { this->PrintSubTree_(this->root_node_ptr_, visit); }

  BST<Elem, Key>& operator=(const BST<Elem, Key>& origin_BST);

protected:
  BSTNode<Elem, Key>* root_node_ptr_; // ���ڵ�

  // �����в���ڵ�(�ݹ�)
  bool InsertInSubTree_(Elem elem, Key key, BSTNode<Elem, Key>*& sub_tree_root_ptr);

  // ������ɾ���ڵ�(�ݹ�)
  bool RemoveInSubTree_(Key key, BSTNode<Elem, Key>*& sub_tree_root_ptr);

  // ��������, ʹ�ùؼ����������
  BSTNode<Elem, Key>* SearchInSubTree_(Key key, BSTNode<Elem, Key>* sub_tree_root_ptr);

  int SubTreeHeight_(BSTNode<Elem, Key>* sub_tree_root_ptr);

  // �������(�ݹ�)
  void MakeEmptySubTree_(BSTNode<Elem, Key>*& sub_tree_root_ptr);

  // ��ӡ����(�ݹ�/����)
  void PrintSubTree_(BSTNode<Elem, Key>* sub_tree_root_ptr, void (*visit)(BSTNode<Elem, Key>* p)) const;

  // ����һ����
  BSTNode<Elem, Key>* Copy_(const BSTNode<Elem, Key>* origin_tree_root_ptr);

  // �����йؼ�����С��
  BSTNode<Elem, Key>* MinInSubTree_(BSTNode<Elem, Key>* sub_tree_root_ptr) const;

  // �����йؼ��������
  BSTNode<Elem, Key>* MaxInSubTree_(BSTNode<Elem, Key>* sub_tree_root_ptr) const;
};


/**
 * @brief ��������, ʹ�ùؼ����������
 * @tparam Elem ������ģ������
 * @tparam Key �ؼ���ģ������
 * @param key �ؼ���
 * @param sub_tree_root_ptr �������ڵ�
 * @return �������
 * @note
 * 1. ����������ڵ�ΪNULL, ����NULL
 * 2. ʹ�õ�ǰ�����ڵ��key, �����key���Ƚ�, �ֱ���еݹ�ͷ����������(��ֹ�ݹ�)
 */
template <class Elem, class Key>
BSTNode<Elem, Key>* BST<Elem, Key>::SearchInSubTree_(Key key, BSTNode<Elem, Key>* sub_tree_root_ptr) {
  if (sub_tree_root_ptr == NULL) {
    return NULL;
  }

  Key cur_key = sub_tree_root_ptr->GetKey();

  if (key < cur_key) {
    return SearchInSubTree_(key, sub_tree_root_ptr->LeftChildPtr());
  } else if (key > cur_key) {
    return SearchInSubTree_(key, sub_tree_root_ptr->RightChildPtr());
  } else {
    return sub_tree_root_ptr;
  }
}


template<class Elem, class Key>
bool BST<Elem, Key>::Insert(Elem elem, Key key) {
  if (this->Search(key) != NULL) {
    return true;
  }

  return this->InsertInSubTree_(elem, key, this->root_node_ptr_);
}


template<class Elem, class Key>
Elem BST<Elem, Key>::Min() {
  return MinInSubTree_(root_node_ptr_)->GetData();
}


/**
 * @brief �����в���ڵ�(�ݹ�)
 * @tparam Elem ������ģ������
 * @tparam Key �ؼ���ģ������
 * @param elem ������
 * @param key �ؼ���
 * @param sub_tree_root_ptr �������ڵ�ָ��
 * @return �Ƿ����ɹ�
 * @note
 * ������ڵ�ָ��ΪNULL, �򴴽��ڵ�
 * �жϲ���ؼ������������ڵ�ؼ���Ĵ�С��ϵ, ��������or���������������(�ݹ�)
 * ����ؼ�����ͬ, �򷵻�false
 */
template <class Elem, class Key>
bool BST<Elem, Key>::InsertInSubTree_(Elem elem, Key key, BSTNode<Elem, Key>*& sub_tree_root_ptr) {
  if (sub_tree_root_ptr == NULL) {
    sub_tree_root_ptr = new BSTNode<Elem, Key>(elem, key);
    /* error handler */

    return true;
  }

  if (key < sub_tree_root_ptr->GetKey()) {
    return InsertInSubTree_(elem, key, sub_tree_root_ptr->LeftChildPtr());
  } else if (key > sub_tree_root_ptr->GetKey()) {
    return InsertInSubTree_(elem, key, sub_tree_root_ptr->RightChildPtr());
  } else {
    return false;
  }
}


template <class Elem, class Key>
BST<Elem, Key>::BST(Key key, Elem elem) {
  this->Insert(elem, key);
}


/**
 * @brief ������ɾ���ڵ�(�ݹ�)
 * @tparam Elem ������ģ������
 * @tparam Key �ؼ���ģ������
 * @param key ��ɾ���ڵ��������
 * @param sub_tree_root_ptr �������ڵ�
 * @return �Ƿ�ɾ���ɹ�
 * @note
 * 1. ����������ڵ�ָ��ΪNULL, �򷵻�false
 * 2. �ݹ����, �ҵ�ɾ���ڵ��λ��
 * 3. ������������ӽڵ�, ʹ������ǰ��or���, �滻����ɾ���ڵ�
 * 4. ���ֻ��һ�����ӽڵ�, �򽫸ú�����������ɾ���ڵ�
 */
template <class Elem, class Key>
bool BST<Elem, Key>::RemoveInSubTree_(Key key, BSTNode<Elem, Key>*& sub_tree_root_ptr) {

  if (sub_tree_root_ptr == NULL) {
    return false;
  }

  if (key < sub_tree_root_ptr->GetKey()) {
    return RemoveInSubTree_(key, sub_tree_root_ptr->LeftChildPtr());
  } else if (key > sub_tree_root_ptr->GetKey()) {
    return RemoveInSubTree_(key, sub_tree_root_ptr->RightChildPtr());
  }

  // ɾ��sub_tree_root_ptr, ʹ������ǰ��or����滻���ýڵ�, �˴�ʹ�ú��
  if (sub_tree_root_ptr->LeftChildPtr() != NULL && sub_tree_root_ptr->RightChildPtr() != NULL) { // �������Һ���

    BSTNode<Elem, Key>* cur_node_ptr = sub_tree_root_ptr->RightChildPtr();
    while (cur_node_ptr->LeftChildPtr()!= NULL) {
      cur_node_ptr = cur_node_ptr->LeftChildPtr();
    }

    // �õ���̽ڵ������, ��Ϊ�滻����
    Elem replace_data = cur_node_ptr->GetData();
    Key replace_key = cur_node_ptr->GetKey();

    sub_tree_root_ptr->SetData(replace_data);
    sub_tree_root_ptr->SetKey(replace_key);

    // ɾ���滻����ԭ�����ڵĽڵ�
    return RemoveInSubTree_(replace_key, sub_tree_root_ptr->RightChildPtr());
  } else {
    BSTNode<Elem, Key>* delete_node_ptr = sub_tree_root_ptr;

    if (sub_tree_root_ptr->LeftChildPtr() == NULL) {
      sub_tree_root_ptr = sub_tree_root_ptr->RightChildPtr();
    } else {
      sub_tree_root_ptr = sub_tree_root_ptr->LeftChildPtr();
    }

    delete delete_node_ptr;
    delete_node_ptr = NULL;

    return true;
  }
}


/**
 * @brief �������(�ݹ�)
 * @tparam Elem ����������ģ��
 * @tparam Key �ؼ�������ģ��
 * @param sub_tree_root_ptr �������ڵ�ָ��
 * @note
 * ���sub_tree_root_ptrΪNULL, ��ݹ����
 * ����������, �ݹ�ִ�к���
 * �������ڵ�ִ��delete����NULL����
 */
template <class Elem, class Key>
void BST<Elem, Key>::MakeEmptySubTree_(BSTNode<Elem, Key>*& sub_tree_root_ptr) {

  if (sub_tree_root_ptr == NULL) {
    return;
  }

  MakeEmptySubTree_(sub_tree_root_ptr->LeftChildPtr());
  MakeEmptySubTree_(sub_tree_root_ptr->RightChildPtr());

  delete sub_tree_root_ptr;
  sub_tree_root_ptr = NULL;
}


/**
 * @brief ��ӡ����(�ݹ�/����)
 * @tparam Elem ����������ģ��
 * @tparam Key �ؼ�������ģ��
 * @param sub_tree_root_ptr �������ڵ�ָ��
 * @param visit ���ʺ���
 * @note
 * ��ӡ��ʽ: "[�������ڵ�]([�������ڵ�������], [�������ڵ�������])"
 *
 * 1. ����/��ӡ�������ڵ�
 * 2. ��ӡ��(��
 * 3. ����/��ӡ�������ڵ��������
 * 4. ��ӡ��,��
 * 5. ����/��ӡ�������ڵ��������
 * 6. ��ӡ��)��
 */
template <class Elem, class Key>
void BST<Elem, Key>::PrintSubTree_(BSTNode<Elem, Key>* sub_tree_root_ptr, void (*visit)(BSTNode<Elem, Key>*)) const {

  if (sub_tree_root_ptr == NULL) {
    return;
  }

  visit(sub_tree_root_ptr);

  cout << "(";

  PrintSubTree_(sub_tree_root_ptr->LeftChildPtr(), visit);

  cout << ",";

  PrintSubTree_(sub_tree_root_ptr->RightChildPtr(), visit);

  cout << ")";
}


/**
 * @brief ����һ����
 * @tparam Elem ������ģ������
 * @tparam Key �ؼ���ģ������
 * @param origin_tree_root_ptr Դ����
 * @return �����ĸ��ڵ�
 */
template <class Elem, class Key>
BSTNode<Elem, Key>* BST<Elem, Key>::Copy_(const BSTNode<Elem, Key>* origin_tree_root_ptr) {

  if (origin_tree_root_ptr == NULL) {
    return NULL;
  }

  BSTNode<Elem, Key>* new_tree_root_ptr = new BSTNode<Elem, Key>(
      origin_tree_root_ptr->GetData(),
      origin_tree_root_ptr->GetKey());
  /* error handler */

  new_tree_root_ptr->SetLeftChildPtr(Copy_(origin_tree_root_ptr->left_child_ptr_));
  new_tree_root_ptr->SetRightChildPtr(Copy_(origin_tree_root_ptr->right_child_ptr_));

  return new_tree_root_ptr;
}


/**
 * @brief �����йؼ�����С��
 * @tparam Elem ������ģ������
 * @tparam Key �ؼ���ģ������
 * @param sub_tree_root_ptr �������ڵ�
 * @return �ؼ�����С��
 * @note
 * ���ӽڵ����
 */
template <class Elem, class Key>
BSTNode<Elem, Key>* BST<Elem, Key>::MinInSubTree_(BSTNode<Elem, Key>* sub_tree_root_ptr) const {

  if (sub_tree_root_ptr == NULL) {
    return NULL;
  }

  BSTNode<Elem, Key>* cur_node_ptr = sub_tree_root_ptr;

  while (cur_node_ptr->LeftChildPtr() != NULL) {
    cur_node_ptr = cur_node_ptr->LeftChildPtr();
  }

  return cur_node_ptr;
}


/**
 * @brief �����йؼ��������
 * @tparam Elem ������ģ������
 * @tparam Key �ؼ���ģ������
 * @param sub_tree_root_ptr �������ڵ�
 * @return �ؼ��������
 * @note
 * �Һ��ӽڵ����
 */
template <class Elem, class Key>
BSTNode<Elem, Key>* BST<Elem, Key>::MaxInSubTree_(BSTNode<Elem, Key>* sub_tree_root_ptr) const {

  if (sub_tree_root_ptr == NULL) {
    return NULL;
  }

  BSTNode<Elem, Key>* cur_node_ptr = sub_tree_root_ptr;
  while (cur_node_ptr->RightChildPtr() != NULL) {
    cur_node_ptr = cur_node_ptr->RightChildPtr();
  }

  return cur_node_ptr;
}


template<class Elem, class Key>
BST<Elem, Key>& BST<Elem, Key>::operator=(const BST<Elem, Key>& origin_BST) {

  this->root_node_ptr_ = this->Copy_(origin_BST.root_node_ptr_);

  return *this;
}


template<class Elem, class Key>
Elem BST<Elem, Key>::Max() {
  BSTNode<Elem, Key>* root_node_ptr = this->root_node_ptr_;
  BSTNode<Elem, Key>* max_node = this->BST::MaxInSubTree_(root_node_ptr);
  return max_node->GetData();
}


template<class Elem, class Key>
int BST<Elem, Key>::SubTreeHeight_(BSTNode<Elem, Key>* sub_tree_root_ptr) {
  if (sub_tree_root_ptr == NULL) {
    return 0;
  }

  int left_sub_tree_height = SubTreeHeight_(sub_tree_root_ptr->LeftChildPtr());
  int right_sub_tree_height = SubTreeHeight_(sub_tree_root_ptr->RightChildPtr());

  if (left_sub_tree_height < right_sub_tree_height) {
    return right_sub_tree_height + 1;
  } else {
    return left_sub_tree_height + 1;
  }
}


#endif // CYBER_DASH_BINARY_SEARCH_TREE_H
