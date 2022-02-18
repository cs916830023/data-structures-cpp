/*!
 * @file test.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ��Ů�ֵ�������.h�ļ�
 * @version 0.2.1
 * @date 2020-11-01
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#ifndef CYBER_DASH_CHILD_SIBLING_TREE_TEST_H
#define CYBER_DASH_CHILD_SIBLING_TREE_TEST_H


#include <iostream>
#include "child_sibling_tree.h"


using namespace std;


// �ڵ��������
// void visit(ChildSiblingNode<int>* node);

// ����ʹ���ַ���������Ů������
void TestChildSiblingTreeCreateTreeByStr();

// �������
void TestChildSiblingTreeDepth();

// ���Խڵ�����
void TestChildSiblingTreeNodeCount();

// �����ȸ�����
void TestChildSiblingTreePreOrder();

// ���Ժ������
void TestChildSiblingTreePostOrder();

// ���Բ������
void TestChildSiblingTreeLevelOrder();


#endif // CYBER_DASH_CHILD_SIBLING_TREE_TEST_H
