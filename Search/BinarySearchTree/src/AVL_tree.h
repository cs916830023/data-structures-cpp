//
// Created by cyberdash@163.com on 2021/7/5.
//

#ifndef CYBER_DASH_AVL_TREE_H
#define CYBER_DASH_AVL_TREE_H


#include "binary_search_tree.h"
#include "stack"


template<class Elem, class Key>
class AVLNode: public BSTNode<Elem, Key> {
public:
  AVLNode():
    left_child_ptr_(NULL), right_child_ptr_(NULL), balance_factor(0) {}
  AVLNode(const Elem& elem, const Key& key):
    elem_(elem), key_(key), left_child_ptr_(NULL), right_child_ptr_(NULL), balance_factor(0) {}
  AVLNode(Elem elem, Key key, AVLNode<Elem, Key>* left_child_ptr, AVLNode<Elem, Key>* right_child_ptr):
    elem_(elem), key_(key), left_child_ptr_(left_child_ptr), right_child_ptr_(right_child_ptr), balance_factor(0) {}

  void SetLeftChildPtr(AVLNode<Elem, Key>* node_ptr) { this->left_child_ptr_ = node_ptr; }
  void SetRightChildPtr(AVLNode<Elem, Key>* node_ptr) { this->right_child_ptr_ = node_ptr; }

  void SetData(const Elem& elem) { this->elem_ = elem;}
  Elem GetData() { return this->elem_; }

  void SetKey(const Key& key) { this->key_ = key; }
  Key GetKey() { return this->key_; }

  AVLNode<Elem, Key>*& LeftChildPtr() { return this->left_child_ptr_; };
  AVLNode<Elem, Key>*& RightChildPtr() { return this->right_child_ptr_; };

  int balance_factor;

protected:

  AVLNode<Elem, Key>* left_child_ptr_;
  AVLNode<Elem, Key>* right_child_ptr_;

  Elem elem_;
  Key key_;
};


template<class Elem, class Key>
class AVLTree: public BST<Elem, Key> {
public:
  AVLTree(): root_node_ptr_(NULL) {}
  AVLNode<Elem, Key>*& RootRef() { return (AVLNode<Elem, Key>*&)this->root_node_ptr_; }
  AVLNode<Elem, Key>* Root() { return (AVLNode<Elem, Key>*)this->root_node_ptr_; }

  bool Insert(Elem data, Key key);
  bool InsertByCyberDash(Elem data, Key key);
  // bool Remove(Key key, Elem& data) { return this->RemoveInSubTreeByCyberDash_(RootRef(), key); }
  bool RemoveByCyberDash(Key key);
  AVLNode<Elem, Key>* Search (Key key) { return this->SearchInSubTree_(key, this->root_node_ptr_); }
  int Height() { return this->SubTreeHeight_(this->root_node_ptr_); }


  Elem Max();
  Elem Min();
  void PrintTree(void (*visit)(AVLNode<Elem, Key>*));

  static AVLNode<Elem, Key>* GetInsertNodePtrAndInitStack(Key key,
                                                   AVLNode<Elem, Key>* node_ptr,
                                                   stack<AVLNode<Elem, Key>*>& AVL_node_stack);

  static AVLNode<Elem, Key>* GetDeleteNodePtrAndInitStack(Key key,
                                                          AVLNode<Elem, Key>* node_ptr,
                                                          stack<AVLNode<Elem, Key>*>& AVL_node_stack);

protected:
  // AVLNode<Elem, Key>* SearchInSubTree_(Key key, const AVLNode<Elem, Key>*& sub_tree_root_ptr);
  AVLNode<Elem, Key>* SearchInSubTree_(Key key, AVLNode<Elem, Key>* sub_tree_root_ptr);
  bool InsertInSubTree_(Elem elem, Key key, AVLNode<Elem, Key>*& sub_tree_root_ptr);
  // ƽ������������(CyberDashʵ�ְ汾)
  bool InsertInSubTreeByCyberDash_(Elem elem, Key key, AVLNode<Elem, Key>*& sub_tree_root_ptr);
  bool RemoveInSubTreeByCyberDash_(AVLNode<Elem, Key>*& sub_tree_root_ptr, Key key);

  // ����ת(Rotation Left), ͼ7.15(a)������
  void RotateLeft_(AVLNode<Elem, Key>*& node_ptr);
  // �ҵ���ת(Rotation Right), ͼ7.16(a)������
  void RotateRight_(AVLNode<Elem, Key>*& node_ptr);
  // �������˫��ת(Rotation Left Right), ͼ7.17(a)������
  void RotateLeftRight_(AVLNode<Elem, Key>*& node_ptr);
  // ���Һ���˫��ת(Rotation Right Left), ͼ7.18(a)������
  void RotateRightLeft_(AVLNode<Elem, Key>*& node_ptr);


  // �����йؼ�����С��
  AVLNode<Elem, Key>* MinInSubTree_(AVLNode<Elem, Key>* sub_tree_root_ptr) const;

  // �����йؼ��������
  AVLNode<Elem, Key>* MaxInSubTree_(AVLNode<Elem, Key>* sub_tree_root_ptr) const;
  // AVL�����ĸ߶�
  int SubTreeHeight_(AVLNode<Elem, Key>* sub_tree_root_ptr);

  void PrintSubTree_(AVLNode<Elem, Key>* sub_tree_root_ptr, void (*visit)(AVLNode<Elem, Key>*));

  AVLNode<Elem, Key>* root_node_ptr_; // ���ڵ�
};


/**
 * ����ת(Rotation Left), ͼ7.15(a)������
 * @tparam Elem �������(����)ģ������
 * @tparam Key �ؼ���ģ������
 * @param node_ptr AVL���ڵ�ָ�������
 */
template<class Elem, class Key>
void AVLTree<Elem, Key>::RotateLeft_(AVLNode<Elem, Key>*& node_ptr) {

  // ͼ7.15(b)
  AVLNode<Elem, Key>* sub_left_node_ptr = node_ptr;
  node_ptr = sub_left_node_ptr->RightChildPtr();

  // ͼ7.15(c)
  sub_left_node_ptr->SetRightChildPtr(node_ptr->LeftChildPtr());
  node_ptr->SetLeftChildPtr(sub_left_node_ptr);

  // ����ƽ������
  node_ptr->balance_factor = 0;
  sub_left_node_ptr->balance_factor = 0;
}


/**
 * �ҵ���ת(Rotation Right), ͼ7.16(a)������
 * @tparam Elem �������(����)ģ������
 * @tparam Key �ؼ���ģ������
 * @param node_ptr AVL���ڵ�ָ�������
 */
template<class Elem, class Key>
void AVLTree<Elem, Key>::RotateRight_(AVLNode<Elem, Key>*& node_ptr) {

  // ͼ7.16(b)
  AVLNode<Elem, Key>* sub_right_node_ptr = node_ptr;
  node_ptr = sub_right_node_ptr->LeftChildPtr();

  // ͼ7.16(c)
  sub_right_node_ptr->SetLeftChildPtr(node_ptr->RightChildPtr());
  node_ptr->SetRightChildPtr(sub_right_node_ptr);

  // ����ƽ������
  node_ptr->balance_factor = 0;
  sub_right_node_ptr->balance_factor = 0;
}


template<class Elem, class Key>
void AVLTree<Elem, Key>::RotateLeftRight_(AVLNode<Elem, Key>*& node_ptr) {

  // ͼ7.17(b)
  AVLNode<Elem, Key>* sub_right_node_ptr = node_ptr;
  AVLNode<Elem, Key>* sub_left_node_ptr = sub_right_node_ptr->LeftChildPtr();
  node_ptr = sub_left_node_ptr->RightChildPtr();

  // ͼ7.17(c)
  sub_left_node_ptr->SetRightChildPtr(node_ptr->LeftChildPtr()); // node_ptr��Ϊ�¸�ǰ, ˦������������
  node_ptr->SetLeftChildPtr(sub_left_node_ptr); // ����ת, node_ptr��Ϊ�¸�

  if (node_ptr->balance_factor <= 0) {
    sub_left_node_ptr->balance_factor = 0;
  } else {
    sub_left_node_ptr->balance_factor = -1;
  }

  sub_right_node_ptr->SetLeftChildPtr(node_ptr->RightChildPtr()); // node_ptr��Ϊ�¸�֮ǰ, ˦������������
  node_ptr->SetRightChildPtr(sub_right_node_ptr); // �ҵ���ת, node_ptr��Ϊ�¸�

  if (node_ptr->balance_factor == -1) {
    sub_right_node_ptr->balance_factor = 1;
  } else {
    sub_right_node_ptr->balance_factor = 0;
  }

  node_ptr->balance_factor = 0;
}


template<class Elem, class Key>
void AVLTree<Elem, Key>::RotateRightLeft_(AVLNode<Elem, Key>*& node_ptr) {

  // ͼ7.18(b)
  AVLNode<Elem, Key>* sub_left_node_ptr = node_ptr;
  AVLNode<Elem, Key>* sub_right_node_ptr= sub_left_node_ptr->RightChildPtr();
  node_ptr = sub_right_node_ptr->LeftChildPtr();

  // ͼ7.18(c)
  sub_right_node_ptr->SetLeftChildPtr(node_ptr->RightChildPtr()); // node_ptr��Ϊ�¸�֮ǰ, ˦������������
  node_ptr->SetRightChildPtr(sub_right_node_ptr); // �ҵ���ת, node_ptr��Ϊ�¸�

  if (node_ptr->balance_factor >= 0) {
    sub_right_node_ptr->balance_factor = 0;
  } else {
    sub_right_node_ptr->balance_factor = 1;
  }

  sub_left_node_ptr->SetRightChildPtr(node_ptr->LeftChildPtr()); // node_ptr��Ϊ�¸�ǰ, ˦������������
  node_ptr->SetLeftChildPtr(sub_left_node_ptr); // ����ת, node_ptr��Ϊ�¸�

  if (node_ptr->balance_factor == 1) {
    sub_left_node_ptr->balance_factor = -1;
  } else {
    sub_left_node_ptr->balance_factor = 0;
  }

  node_ptr->balance_factor = 0;
}


template<class Elem, class Key>
bool AVLTree<Elem, Key>::Insert(Elem data, Key key) {
  return this->InsertInSubTree_(data, key, (AVLNode<Elem, Key>*&)this->root_node_ptr_);
}


template<class Elem, class Key>
bool AVLTree<Elem, Key>::InsertByCyberDash(Elem data, Key key) {
  return this->InsertInSubTreeByCyberDash_(data, key, (AVLNode<Elem, Key>*&)this->root_node_ptr_);
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
template<class Elem, class Key>
bool AVLTree<Elem, Key>::InsertInSubTree_(Elem elem, Key key, AVLNode<Elem, Key>*& sub_tree_root_ptr) {

  AVLNode<Elem, Key>* cur_stack_node_ptr = NULL;
  AVLNode<Elem, Key>* cur_node_ptr = sub_tree_root_ptr;

  stack<AVLNode<Elem, Key>*> AVL_node_stack;

  // Ѱ�Ҳ���λ��
  while (cur_node_ptr != NULL) {
    // �ҵ�����key�Ľ��, �޷�����, (ԭ��ʹ��elem)
    if (key == cur_node_ptr->GetKey()) {
      return false;
    }

    cur_stack_node_ptr = cur_node_ptr;
    AVL_node_stack.push(cur_stack_node_ptr);

    if (key < cur_node_ptr->GetKey()) {
      cur_node_ptr = cur_node_ptr->LeftChildPtr();
    } else {
      cur_node_ptr = cur_node_ptr->RightChildPtr();
    }
  }

  cur_node_ptr = new AVLNode<Elem, Key>(elem, key);
  /* error handler */

  // ����, �½���Ϊ���ڵ�
  if (cur_stack_node_ptr == NULL) {
    sub_tree_root_ptr = cur_node_ptr;
    return true;
  }

  if (key < cur_stack_node_ptr->GetKey()) {
    cur_stack_node_ptr->SetLeftChildPtr(cur_node_ptr);
  } else {
    cur_stack_node_ptr->SetRightChildPtr(cur_node_ptr);
  }

  // ����ƽ�⻯
  while (AVL_node_stack.empty() == false) {
    cur_stack_node_ptr = AVL_node_stack.top();
    AVL_node_stack.pop();

    if (cur_node_ptr == cur_stack_node_ptr->LeftChildPtr()) {
      cur_stack_node_ptr->balance_factor--;
    } else {
      cur_stack_node_ptr->balance_factor++;
    }

    // ��1�����, ƽ���˳�
    if (cur_stack_node_ptr->balance_factor == 0) {
      break;
    }

    // ��2�����, |ƽ������| = 1
    if (cur_stack_node_ptr->balance_factor == 1 || cur_stack_node_ptr->balance_factor == -1) {
      cur_node_ptr = cur_stack_node_ptr;
    } else { // ��3�����, |bf| = 2
      int stack_node_rotate_flag = (cur_stack_node_ptr->balance_factor < 0) ? -1 : 1;
      if (cur_node_ptr->balance_factor == stack_node_rotate_flag) { // ��������ƽ������ͬ��, ����ת
        if (stack_node_rotate_flag == -1) {
          this->RotateRight_(cur_stack_node_ptr); // �ҵ���ת
        } else {
          this->RotateLeft_(cur_stack_node_ptr); // ����ת
        }
      } else { // ��������ƽ�����ӷ���, ˫��ת
        if (stack_node_rotate_flag == -1) {
          this->RotateLeftRight_(cur_stack_node_ptr);
        } else {
          this->RotateRightLeft_(cur_stack_node_ptr);
        }
      }

      break; // �������ϵ���
    }
  }

  if (AVL_node_stack.empty() == true) {
    sub_tree_root_ptr = cur_stack_node_ptr;
  } else {
    AVLNode<Elem, Key>* stack_top_node_ptr = AVL_node_stack.top();
    if (stack_top_node_ptr->GetKey() > cur_stack_node_ptr->GetKey()) {
      stack_top_node_ptr->SetLeftChildPtr(cur_stack_node_ptr);
    } else {
      stack_top_node_ptr->SetRightChildPtr(cur_stack_node_ptr);
    }
  }

  return true;
}


template<class Elem, class Key>
AVLNode<Elem, Key>* AVLTree<Elem, Key>::GetInsertNodePtrAndInitStack(Key key,
                                                 AVLNode<Elem, Key>* node_ptr,
                                                 stack<AVLNode<Elem, Key>*>& AVL_node_stack) {

  AVLNode<Elem, Key>* cur_node_ptr = node_ptr;

  // Ѱ�Ҳ���λ��
  while (cur_node_ptr != NULL) {
    // �ҵ�����key�Ľ��, �޷�����, todo: ԭ��ʹ��elem
    if (key == cur_node_ptr->GetKey()) {
      return NULL;
    }

    AVL_node_stack.push(cur_node_ptr);

    // ԭ��ʹ��elem, �˴�ʹ�ùؼ���
    if (key < cur_node_ptr->GetKey()) {
      cur_node_ptr = cur_node_ptr->LeftChildPtr();
    } else {
      cur_node_ptr = cur_node_ptr->RightChildPtr();
    }
  }

  return cur_node_ptr;
}


template<class Elem, class Key>
AVLNode<Elem, Key>* AVLTree<Elem, Key>::GetDeleteNodePtrAndInitStack(Key key,
                                                                     AVLNode<Elem, Key>* node_ptr,
                                                                     stack<AVLNode<Elem, Key>*>& AVL_node_stack) {

  AVLNode<Elem, Key>* cur_node_ptr = node_ptr;

  // Ѱ��ɾ��λ��
  while (cur_node_ptr != NULL) {
    // �ҵ�����key�Ľ��, �޷�����
    if (key == cur_node_ptr->GetKey()) {
      break;
    }

    AVL_node_stack.push(cur_node_ptr);

    if (key < cur_node_ptr->GetKey()) {
      cur_node_ptr = cur_node_ptr->LeftChildPtr();
    } else {
      cur_node_ptr = cur_node_ptr->RightChildPtr();
    }
  }

  return cur_node_ptr;
}


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
AVLNode<Elem, Key>* AVLTree<Elem, Key>::SearchInSubTree_(Key key, AVLNode<Elem, Key>* sub_tree_root_ptr) {
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


/**
 * @brief ƽ������������(CyberDashʵ�ְ汾)
 * @tparam Elem ������ģ������
 * @tparam Key �ؼ���ģ������
 * @param elem ������
 * @param key �ؼ���
 * @param sub_tree_root_ptr �������ڵ�
 * @return �Ƿ����ɹ�
 * @note
 * 1. �����ҵ�����λ��, ����ʹ��ջ����
 * 2. ��3�����, ����ƽ�⻯
 * 3. ƽ�⻯���������β����
 */
template<class Elem, class Key>
bool AVLTree<Elem, Key>::InsertInSubTreeByCyberDash_(Elem elem, Key key, AVLNode<Elem, Key>*& sub_tree_root_ptr) {

  stack<AVLNode<Elem, Key>* > AVL_node_stack;

  // ��ȡ����λ��, ��ʼ��ջ
  AVLNode<Elem, Key>* insert_node_ptr = GetInsertNodePtrAndInitStack(key, sub_tree_root_ptr, AVL_node_stack);

  insert_node_ptr = new AVLNode<Elem, Key>(elem, key);
  /* error handler */

  // ����, �½���Ϊ���ڵ�, ������
  if (AVL_node_stack.empty()) {
    sub_tree_root_ptr = insert_node_ptr;
    return true;
  }

  AVLNode<Elem, Key>* stack_node_ptr = AVL_node_stack.top();

  // ԭ��ʹ��elem���Ƚ�, Ӧ���Ǵ���
  if (key < stack_node_ptr->GetKey()) {
    stack_node_ptr->SetLeftChildPtr(insert_node_ptr);
  } else {
    stack_node_ptr->SetRightChildPtr(insert_node_ptr);
  }

  AVLNode<Elem, Key>* stack_node_child_ptr = insert_node_ptr;

  // ����ƽ�⻯
  while (AVL_node_stack.empty() == false) {

    // ջ����ջ
    stack_node_ptr = AVL_node_stack.top();
    AVL_node_stack.pop();

    // ����ƽ������
    if (stack_node_child_ptr == stack_node_ptr->LeftChildPtr()) {
      stack_node_ptr->balance_factor--;
    } else {
      stack_node_ptr->balance_factor++;
    }

    // ��1�����, ƽ���˳�
    if (stack_node_ptr->balance_factor == 0) {
      break;
    }

    // ��2�����, |ƽ������| = 1
    if (stack_node_ptr->balance_factor == 1 || stack_node_ptr->balance_factor == -1) {
      stack_node_child_ptr = stack_node_ptr;
    } else { // ��3�����, |bf| = 2
      int stack_node_rotate_flag = (stack_node_ptr->balance_factor < 0) ? -1 : 1;
      if (stack_node_child_ptr->balance_factor == stack_node_rotate_flag) { // ��������ƽ������ͬ��, ����ת
        if (stack_node_rotate_flag == -1) {
          this->RotateRight_(stack_node_ptr); // �ҵ���ת
        } else {
          this->RotateLeft_(stack_node_ptr); // ����ת
        }
      } else { // ��������ƽ�����ӷ���, ˫��ת
        if (stack_node_rotate_flag == -1) {
          this->RotateLeftRight_(stack_node_ptr);
        } else {
          this->RotateRightLeft_(stack_node_ptr);
        }
      }

      break; // �������ϵ���
    }
  }

  // �Ѿ����ƽ�⻯����, ��������
  if (AVL_node_stack.empty() == true) {
    sub_tree_root_ptr = stack_node_ptr;
  } else {
    AVLNode<Elem, Key>* stack_top_node_ptr = AVL_node_stack.top();
    if (stack_top_node_ptr->GetKey() > stack_node_ptr->GetKey()) {
      stack_top_node_ptr->SetLeftChildPtr(stack_node_ptr);
    } else {
      stack_top_node_ptr->SetRightChildPtr(stack_node_ptr);
    }
  }

  return true;
}


/**
 * @brief ƽ��������ɾ���ڵ�(CyberDashʵ�ְ汾)
 * @tparam Elem ������ģ������
 * @tparam Key �ؼ���ģ������
 * @param sub_tree_root_ptr �������ڵ�
 * @param key ��ɾ���ؼ���
 * @return
 */
template<class Elem, class Key>
bool AVLTree<Elem, Key>::RemoveInSubTreeByCyberDash_(AVLNode<Elem, Key> *&sub_tree_root_ptr, Key key) {
  AVLNode<Elem, Key>* cur_node_pre_ptr = NULL;

  stack<AVLNode<Elem, Key>*> AVL_node_stack;

  AVLNode<Elem, Key>* delete_node_ptr = GetDeleteNodePtrAndInitStack(key,
                                                                     sub_tree_root_ptr,
                                                                     AVL_node_stack);

  if (delete_node_ptr == NULL) {
    return false; // δ�ҵ�ɾ�����
  }

  if (delete_node_ptr->LeftChildPtr() != NULL && delete_node_ptr->RightChildPtr() != NULL) {
    AVL_node_stack.push(delete_node_ptr); // ����ɾ���ڵ���stack

    cur_node_pre_ptr = delete_node_ptr->LeftChildPtr();
    while(cur_node_pre_ptr->RightChildPtr() != NULL) {
      AVL_node_stack.push(cur_node_pre_ptr);
      cur_node_pre_ptr = cur_node_pre_ptr->RightChildPtr();
    }

    delete_node_ptr->SetKey(cur_node_pre_ptr->GetKey());
    delete_node_ptr->SetData(cur_node_pre_ptr->GetData());

    delete_node_ptr = cur_node_pre_ptr;
  }

  AVLNode<Elem, Key>* child_of_delete_node_ptr = NULL; // ��ɾ���ڵ�ĺ��ӽڵ�

  // �ҵ���ʱ�Ĵ�ɾ���ڵ��һ�����ӽڵ�, ��������
  if (delete_node_ptr->LeftChildPtr() != NULL) {
    child_of_delete_node_ptr = delete_node_ptr->LeftChildPtr();
  } else {
    child_of_delete_node_ptr = delete_node_ptr->RightChildPtr();
  }

  if (AVL_node_stack.empty() == true) { // ɾ�����Ǹ��ڵ�
    sub_tree_root_ptr = child_of_delete_node_ptr;
  } else {

    AVLNode<Elem, Key>* cur_stack_node_ptr = AVL_node_stack.top();

    if (cur_stack_node_ptr->LeftChildPtr() == delete_node_ptr) { // ��ɾ���ڵ���cur_stack_node_ptr������
      cur_stack_node_ptr->SetLeftChildPtr(child_of_delete_node_ptr); // ����
    } else { // ��ɾ���ڵ���cur_stack_node_ptr���Һ���
      cur_stack_node_ptr->SetRightChildPtr(child_of_delete_node_ptr); // ����
    }

    AVLNode<Elem, Key>* parent_node_ptr;

    // ����ƽ�⻯
    while (AVL_node_stack.empty() == false) {

      AVLNode<Elem, Key>* grand_parent_node_ptr = NULL;
      parent_node_ptr = AVL_node_stack.top();
      AVL_node_stack.pop();

      int grand_parent_direction;
      int parent_direction;

      if (parent_node_ptr->RightChildPtr() == child_of_delete_node_ptr) {
        parent_node_ptr->balance_factor--;
      } else {
        parent_node_ptr->balance_factor++;
      }

      if (AVL_node_stack.empty() == false) {
        grand_parent_node_ptr = AVL_node_stack.top();
        AVL_node_stack.pop();

        grand_parent_direction = (grand_parent_node_ptr->LeftChildPtr() == parent_node_ptr) ? -1 : 1;
      } else {
        grand_parent_direction = 0;
      }

      if (parent_node_ptr->balance_factor == 1 || parent_node_ptr->balance_factor == -1) { // ͼ7.20
        break;
      }

      if (parent_node_ptr->balance_factor != 0) { // |bf| = 2
        if (parent_node_ptr->balance_factor < 0) {
          parent_direction = -1;
          child_of_delete_node_ptr = parent_node_ptr->LeftChildPtr();
        } else {
          parent_direction = 1;
          child_of_delete_node_ptr = parent_node_ptr->RightChildPtr();
        }

        if (child_of_delete_node_ptr->balance_factor == 0) {
          if (parent_direction == -1) {
            this->RotateRight_(parent_node_ptr);
            parent_node_ptr->balance_factor = 1;
            parent_node_ptr->LeftChildPtr()->balance_factor = -1;
          } else {
            this->RotateLeft_(parent_node_ptr);
            parent_node_ptr->balance_factor = -1;
            parent_node_ptr->RightChildPtr()->balance_factor = 1;
          }

          break;
        }

        if (child_of_delete_node_ptr->balance_factor == parent_direction) { // ͼ7.23, ���ڵ�ƽ������ͬ��
          if (parent_direction == -1) {
            this->RotateRight_(parent_node_ptr);
          } else {
            this->RotateLeft_(parent_node_ptr);
          }
        } else { // ͼ7.24, ���ڵ�ƽ�����ӷ���
          if (parent_direction == -1) {
            this->RotateLeftRight_(parent_node_ptr);
          } else {
            this->RotateRightLeft_(parent_node_ptr);
          }
        }

        // ��ת��, �¸����ϲ�����
        if (grand_parent_direction == -1) {
          grand_parent_node_ptr->SetLeftChildPtr(parent_node_ptr);
        } else {
          grand_parent_node_ptr->SetRightChildPtr(parent_node_ptr);
        }
      }

      child_of_delete_node_ptr = parent_node_ptr; // ͼ7.21, |bf| = 0
    }

    if (AVL_node_stack.empty() == true) {
      sub_tree_root_ptr = parent_node_ptr;
    }
  }

  delete delete_node_ptr;
  delete_node_ptr = NULL;

  return true;
}


/**
 * @brief ��ӡ����(�ݹ�)
 * @tparam Elem
 * @tparam Key
 * @param sub_tree_root_ptr
 * @param visit
 */
template <class Elem, class Key>
void AVLTree<Elem, Key>::PrintSubTree_(AVLNode<Elem, Key>* sub_tree_root_ptr, void (*visit)(AVLNode<Elem, Key>*)) {

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


template<class Elem, class Key>
void AVLTree<Elem, Key>::PrintTree(void (*visit)(AVLNode<Elem, Key> *)) {
  this->PrintSubTree_((AVLNode<Elem, Key>*)this->root_node_ptr_, visit); cout << endl;
}


template<class Elem, class Key>
bool AVLTree<Elem, Key>::RemoveByCyberDash(Key key) {
  return this->RemoveInSubTreeByCyberDash_(this->RootRef(), key);
}


template <class Elem, class Key>
AVLNode<Elem, Key>* AVLTree<Elem, Key>::MinInSubTree_(AVLNode<Elem, Key>* sub_tree_root_ptr) const {

  if (sub_tree_root_ptr == NULL) {
    return NULL;
  }

  AVLNode<Elem, Key>* cur_node_ptr = sub_tree_root_ptr;

  while (cur_node_ptr->LeftChildPtr() != NULL) {
    cur_node_ptr = cur_node_ptr->LeftChildPtr();
  }

  return cur_node_ptr;
}


template<class Elem, class Key>
Elem AVLTree<Elem, Key>::Max() {
  AVLNode<Elem, Key>* root_node_ptr = this->root_node_ptr_;
  AVLNode<Elem, Key>* max_node = this->MaxInSubTree_(root_node_ptr);
  return max_node->GetData();
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
AVLNode<Elem, Key>* AVLTree<Elem, Key>::MaxInSubTree_(AVLNode<Elem, Key>* sub_tree_root_ptr) const {

  if (sub_tree_root_ptr == NULL) {
    return NULL;
  }

  AVLNode<Elem, Key>* cur_node_ptr = sub_tree_root_ptr;
  while (cur_node_ptr->RightChildPtr() != NULL) {
    cur_node_ptr = cur_node_ptr->RightChildPtr();
  }

  return cur_node_ptr;
}


template<class Elem, class Key>
Elem AVLTree<Elem, Key>::Min() {
  AVLNode<Elem, Key>* max_node = this->MinInSubTree_(this->Root());
  return max_node->GetData();
}


template<class Elem, class Key>
int AVLTree<Elem, Key>::SubTreeHeight_(AVLNode<Elem, Key>* sub_tree_root_ptr) {
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

#endif // CYBER_DASH_AVL_TREE_H
