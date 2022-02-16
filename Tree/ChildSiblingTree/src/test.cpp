/*!
 * @file test.cpp
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ��Ů�ֵ�������.cpp�ļ�
 * @version 0.2.1
 * @date 2020-11-01
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#include "test.h"
#include "child_sibling_tree.h"


/*!
 * @brief �ڵ��������
 * @param node �ڵ�(ָ��)
 */
void visit(ChildSiblingNode<int>* node) {
  cout << node->data << " ";
}


/*!
 * @brief ����ʹ���ַ���������Ů������
 */
void TestChildSiblingTreeCreateTreeByStr() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|              Test ChildSiblingTree CreateByStr            |" << endl;
  cout << "|                   ����ʹ���ַ���������Ů������                |" << endl << endl << endl;

  char* str = (char*)"(0(1(2))(2))";
  cout << "�ַ���: " << str << endl << endl;

  ChildSiblingTree<int> child_sibling_tree;
  child_sibling_tree.CreateTreeByStr(str);

  int node_count = child_sibling_tree.NodeCount();
  cout << "���Ľڵ�����: " << node_count << endl;

  cout << "����ShowTree()��ʾ: ";
  child_sibling_tree.ShowTree();

  cout << endl;

  cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief �������
 */
void TestChildSiblingTreeDepth() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|                 Test ChildSiblingTree Depth               |" << endl;
  cout << "|                          �������                          |" << endl << endl << endl;

  char* str = (char*)"(0(1(2))(2))";
  cout << "�ַ���: " << str << endl << endl;

  ChildSiblingTree<int> child_sibling_tree;
  child_sibling_tree.CreateTreeByStr(str);

  int depth = child_sibling_tree.Depth();
  cout << "���: " << depth << endl;

  cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief ���Խڵ�����
 */
void TestChildSiblingTreeNodeCount() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|               Test ChildSiblingTree NodeCount             |" << endl;
  cout << "|                         ���Խڵ�����                        |" << endl << endl << endl;

  char* str = (char*)"(0(1(2))(2))";
  cout << "�ַ���: " << str << endl << endl;

  ChildSiblingTree<int> child_sibling_tree;
  child_sibling_tree.CreateTreeByStr(str);

  int node_count = child_sibling_tree.NodeCount();
  cout << "�ڵ�����: " << node_count << endl;

  cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief �����ȸ�����
 */
void TestChildSiblingTreePreOrder() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|                Test ChildSiblingTree PreOrder             |" << endl;
  cout << "|                         �����ȸ�����                        |" << endl << endl << endl;

  char* str = (char*)"(0(1(2))(2))";
  cout << "�ַ���: " << str << endl << endl;

  ChildSiblingTree<int> child_sibling_tree;
  child_sibling_tree.CreateTreeByStr(str);

  cout << "�ȸ�����: " << endl;
  child_sibling_tree.PreOrder(visit);

  cout << endl;

  cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief ���Ժ������
 */
void TestChildSiblingTreePostOrder() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|               Test ChildSiblingTree PostOrder             |" << endl;
  cout << "|                         ���Ժ������                        |" << endl << endl << endl;

  char* str = (char*)"(0(1(2))(2))";
  cout << "�ַ���: " << str << endl << endl;

  ChildSiblingTree<int> child_sibling_tree;
  child_sibling_tree.CreateTreeByStr(str);

  cout << "�������: " << endl;
  child_sibling_tree.PostOrder(visit);

  cout << endl;

  cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief ���Բ������
 */
void TestChildSiblingTreeLevelOrder() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|              Test ChildSiblingTree LevelOrder             |" << endl;
  cout << "|                         ���Բ������                        |" << endl << endl << endl;

  char* str = (char*)"(0(1(2))(2))";
  cout << "�ַ���: " << str << endl << endl;

  ChildSiblingTree<int> child_sibling_tree;
  child_sibling_tree.CreateTreeByStr(str);

  cout << "�������: " << endl;
  child_sibling_tree.LevelOrder(cout);

  cout << endl;


  cout<<"-------------------------------------------------------------"<<endl;
}
