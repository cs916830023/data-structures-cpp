/*!
 * @file test.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ������������
 * @version 0.2.1
 * @date 2020-05-04
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#ifndef CYBER_DASH_BINARY_TREE_TEST_H
#define CYBER_DASH_BINARY_TREE_TEST_H


#include "binary_tree.h"

/*!
 * @brief ������������
 */
class BinaryTreeTest {
public:
  /*! @brief ���Ը��ƹ��캯�� */
  static void TestCopyConstructor();

  /*! @brief ���Զ�������� */
  static void TestHeight();

  /*! @brief ����LeftChild��RightChild */
  static void TestChild();

  /*! @brief ���Ը��ڵ㺯��Parent */
  static void TestParent();

  /*! @brief ����ǰ����� */
  static void TestPreOrder();

  /*! @brief ����������� */
  static void TestInOrder();

  /*! @brief ���Ժ������ */
  static void TestPostOrder();

  /*! @brief ���Բ������ */
  static void TestLevelOrder();

  /*! @brief ���Բ����Ƿ��ڶ����� */
  static void TestFind();

  /*! @brief ����ʹ��ǰ������ͺ������������������� */
  static void TestCreateBinTreeByPreAndInOrderString();

  /*! @brief �����Ƿ�Ϊ�� */
  static void TestIsEmpty();
};


/*!
 * @brief ����ӡ����
 * @param node ���������
 */
void visit(BinTreeNode<int>* node) {
  cout << node->data << " ";
};


void BinaryTreeTest::TestCopyConstructor() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|              Test BinaryTree CopyConstructor              |"<<endl;
  cout<<"|                     ���Զ��������ƹ��캯��                   |"<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  BinaryTree<int> bin_tree_2(bin_tree);

  bin_tree_2.Print();

  cout << endl << "------------------------- CyberDash -------------------------"<<endl;
}


void BinaryTreeTest::TestHeight() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                   Test BinaryTree Height                  |"<<endl;
  cout<<"|                        ���Զ������߶�                       |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  int height = bin_tree.Height();

  cout<<"���������: "<<height<<endl;

  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void BinaryTreeTest::TestIsEmpty() {

}


void BinaryTreeTest::TestChild() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|            Test BinaryTree LeftChild & RightChild         |"<<endl;
  cout<<"|                     ���Զ��������Һ��Ӻ���                   |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  BinTreeNode<int>* root_ptr = bin_tree.GetRoot();
  BinTreeNode<int>* root_left_child_ptr = bin_tree.LeftChild(root_ptr);
  BinTreeNode<int>* root_right_child_ptr = bin_tree.RightChild(root_ptr);

  cout << "���ڵ�: " << root_ptr->data << endl;
  cout << "���ڵ�����: " << root_left_child_ptr->data << endl;
  cout << "���ڵ��Һ���: " << root_right_child_ptr->data << endl;

  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void BinaryTreeTest::TestParent() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                  Test BinaryTree Parent                   |"<<endl;
  cout<<"|                       ���Զ��������ڵ�                      |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  BinTreeNode<int>* root_ptr = bin_tree.GetRoot();
  BinTreeNode<int>* root_parent_ptr = bin_tree.Parent(root_ptr);

  BinTreeNode<int>* target_ptr = bin_tree.LeftChild(bin_tree.LeftChild(root_ptr));
  BinTreeNode<int>* target_parent_ptr = bin_tree.Parent(target_ptr);

  if (root_parent_ptr == NULL) {
    cout<<"���ڵ�ĸ��ڵ�ΪNULL"<<endl;
  } else {
    cout << "���ڵ�ĸ��ڵ�: " << root_parent_ptr->data << endl;
  }

  cout << target_ptr->data << "�ĸ��ڵ㣺 " << target_parent_ptr->data << endl;

  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void BinaryTreeTest::TestPreOrder() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                  Test BinaryTree PreOrder                 |"<<endl;
  cout<<"|                      ���Զ�����ǰ�����                      |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  cout<<"ǰ�����(�ݹ�):"<<endl;
  bin_tree.PreOrder(visit);
  cout<<endl;

  cout<<"ǰ�����(�ǵݹ�):"<<endl;
  bin_tree.PreOrderNonRecursive(visit);
  cout<<endl;

  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void BinaryTreeTest::TestInOrder() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                   Test BinaryTree SubTreeInOrder_                 |"<<endl;
  cout<<"|                      ���Զ������������                      |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  cout<<"�������(�ݹ�):"<<endl;
  bin_tree.InOrder(visit);
  cout<<endl;

  cout<<"�������(�ǵݹ�):"<<endl;
  bin_tree.InOrderNonRecursive(visit);
  cout<<endl;

  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void BinaryTreeTest::TestPostOrder() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                 Test BinaryTree PostOrder                 |"<<endl;
  cout<<"|                      ���Զ������������                      |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  cout<<"�������(�ݹ�):"<<endl;
  bin_tree.PostOrder(visit);
  cout<<endl;

  cout<<"�������(�ǵݹ�):"<<endl;
  bin_tree.PostOrderNonRecursive(visit);
  cout<<endl;

  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


// ���Բ������
void BinaryTreeTest::TestLevelOrder() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                 Test BinaryTree LevelOrder                |"<<endl;
  cout<<"|                      ���Զ������������                      |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  bin_tree.LevelOrder(visit);

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void BinaryTreeTest::TestFind() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                    Test BinaryTree Find                   |"<<endl;
  cout<<"|                        ���Զ���������                       |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  bool in_tree = bin_tree.Find(5);

  if (in_tree) {
    cout<<"5 is in the tree"<<endl;
  } else {
    cout<<"5 isn't in the tree"<<endl;
  }

  in_tree = bin_tree.Find(7);

  if (in_tree) {
    cout<<"7 is in the tree"<<endl;
  } else {
    cout << "7 isn't in the tree" << endl;
  }

  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void BinaryTreeTest::TestCreateBinTreeByPreAndInOrderString() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|  Test BinaryTree TestCreateBinTreeByPreAndInOrderString   |"<<endl;
  cout<<"|                ����ǰ�����������������ɶ�����                |"<<endl;

  BinaryTree<int> bin_tree;

  int pre_order_traverse_arr[] = { 0, 1, 3, 6, 5, 9, 2, 4, 8, 7 }; // ǰ��������
  int in_order_traverse_arr[] = { 6, 3, 1, 9, 5, 0, 8, 4, 2, 7 }; // ����������
  bin_tree.CreateBinTreeByPreAndInOrderString(
    pre_order_traverse_arr,
    in_order_traverse_arr,
    10);

  cout<<"��ӡ������:"<<endl;
  bin_tree.Print();

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


#endif // CYBER_DASH_BINARY_TREE_TEST_H
