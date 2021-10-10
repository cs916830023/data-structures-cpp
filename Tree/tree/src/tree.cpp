//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#include <iostream>
#include <queue>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

#include "tree.h"
#include "tree_node.h"

template <class T>
bool Tree<T>::IsRoot(void) {
  if (root == NULL) {
    current = NULL;
    return false;
  }

  current = root;

  return true;
}

template<class T>
void Tree<T>::RemoveSubTree(TreeNode<T> *p){
  if (p){
    RemoveSubTree(p->first_child);
    RemoveSubTree(p->next_sibling);
    delete p;
  }
}

template <class T>
bool Tree<T>::Parent(void) {
  TreeNode<T> *p = current;

  if (current == NULL || current == root) {
    current = NULL;
    return false;
  }

  return FindParent(root, p);
}

template <class T>
bool Tree<T>::FindParent(TreeNode<T> *t, TreeNode<T> *p) {
  TreeNode<T> *q = t->first_child;
  bool succ;

  while (q != NULL && q != p) {
    if ((succ = FindParent(q, p)) == true) {
      return succ;
    }
    q = q->next_sibling;
  }

  if (q != NULL && q == p) {
    current = t;
    return true;
  } else {
    current = NULL;
    return false;
  }
}

template <class T>
bool Tree<T>::FirstChild(void) {
  if (current != NULL && current->first_child != NULL) {
    current = current->first_child;
    return true;
  }

  current = NULL;

  return false;
}

template <class T>
bool Tree<T>::NextSibling(void) {
  if (current != NULL && current->next_sibling != NULL) {
    current = current->next_sibling;
    return true;
  }

  current = NULL;

  return false;
}

template <class T>
bool Tree<T>::Find(T value) {
  if (IsEmpty()) {
    return false;
  }

  return Find(root, value);
}

template <class T>
bool Tree<T>::Find(TreeNode<T> *p, T value) {
  bool result = false;

  if (p->data == value) {
    result = true;
    current = p;
  } else {
    TreeNode<T> *q = p->first_child;
    while (q != NULL && !(result = Find(q, value))) {
      q = q->next_sibling;
    }
  }

  return result;
}

template <class T>
void Tree<T>::Insert(TreeNode<T> *& subTree, T& x) {
  if (subTree == NULL) {
    subTree = new TreeNode<T>(x);
    if (subTree == NULL) {
      cerr << "存储分配错误!" << endl; 
      exit(1);
    }
  } else {
    Insert(subTree->first_child, x);
    if (subTree == GetRoot()) {
      return;
    }
    Insert(subTree->next_sibling, x);
  }
}

template <class T>
void Tree<T>::PreOrder(ostream& out, TreeNode<T> *p) {
  if (p != NULL) {
    out << p->data;

    for (p = p->first_child; p != NULL; p = p->next_sibling) {
      PreOrder(out, p);
    }
  }
}

template <class T>
void Tree<T>::PostOrder(ostream& out, TreeNode<T> *p) {
  if (p != NULL) {
    TreeNode<T> *q;

    for (q = p->first_child; q != NULL; q = q->next_sibling) {
      PostOrder(out, q);
    }
    out << p->data;
  }
}

template <class T>
void Tree<T>::preorder(TreeNode<T> *t, void (*visit)(TreeNode<T> *p))
{
  if (t == NULL) {
    return;
  }

  visit(t);

  preorder(t->first_child, visit);
  preorder(t->next_sibling, visit);
}

template <class T>
void Tree<T>::postorder(TreeNode<T> *t, void (*visit)(TreeNode<T> *p))
{
  if (t == NULL) {
    return;
  }

  postorder(t->first_child, visit);
  visit(t);
  postorder(t->next_sibling, visit);
}

template <class T>
void Tree<T>::LevelOrder(ostream& out, TreeNode<T> *p)
{
  queue<TreeNode<T> *> Q;

  if (p != NULL) {
    Q.push(p);

    while (!Q.empty()) {
      p = Q.front();
      Q.pop();
      out << p->data;
      for (p = p->first_child; p != NULL; p = p->next_sibling) {
        Q.push(p);
      }
    }
  }
}

template <class T>
int Tree<T>::count_node(TreeNode<T> *t) {
  if (t == NULL) {
    return 0;
  }

  int count = 1;

  count += count_node(t->first_child);
  count += count_node(t->next_sibling);

  return count;
}

template <class T>
int Tree<T>::find_depth(TreeNode<T> *t) {
  if (t == NULL) {
    return 0;
  }

  int fc_depth = find_depth(t->first_child) + 1;
  int ns_depth = find_depth(t->next_sibling);

  return (fc_depth > ns_depth) ? fc_depth : ns_depth;
}

template <class T>
void Tree<T>::create_tree(TreeNode<T> *& subTree, char *&GL) {
  if (*GL == '\0') {
    return;
  }

  if (*GL == ')') {
    GL++;
    return;
  }

  while (*GL == '(') {
    GL++;
  }

  subTree = new TreeNode<T>(*(GL++) - '0');
  if (subTree == NULL) {
    cerr << "存储分配错误!" << endl; 
    exit(1);
  }
  create_tree(subTree->first_child, GL);
  create_tree(subTree->next_sibling, GL);
}

template <class T>
void Tree<T>::show_tree(TreeNode<T> *t) {
  if (t == NULL) {
    return;
  }

  cout << '(';
  cout << t->data;

  for (TreeNode<T> *p = t->first_child; p != NULL; p = p->next_sibling) {
    show_tree(p);
  }

  cout << ')';
}


template<class T>
void Tree<T>::CyberDashShow() {
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
