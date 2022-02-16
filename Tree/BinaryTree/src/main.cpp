/*!
 * @file main.cpp
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ������demo��ʾ
 * @version 0.2.1
 * @date 2020-11-01
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#include "test.h"


using namespace std;


int main() {

  BinaryTreeTest::TestCopyConstructor();

  // ���Զ��������
  BinaryTreeTest::TestHeight();

  // ����LeftChild��RightChild
  BinaryTreeTest::TestChild();

  // ���Ը��ڵ㺯��Parent
  BinaryTreeTest::TestParent();

  // ����ǰ�����
  BinaryTreeTest::TestPreOrder();

  // �����������
  BinaryTreeTest::TestInOrder();

  // ���Ժ������
  BinaryTreeTest::TestPostOrder();

  // ���Բ������
  BinaryTreeTest::TestLevelOrder();

  // ���Բ����Ƿ��ڶ�����
  BinaryTreeTest::TestFind();

  // ����ʹ��ǰ������ͺ�������������������
  BinaryTreeTest::TestCreateBinTreeByPreAndInOrderString();

  return 0;
}
