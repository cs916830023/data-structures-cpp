/*!
 * @file test.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ͼ����ͷ�ļ�
 * @version 0.2.1
 * @date 2021-10-9
 *
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */
#ifndef CYBER_DASH_GRAPH_TEST_H
#define CYBER_DASH_GRAPH_TEST_H


#include "adjacency_list_graph.h"
#include "matrix_graph.h"
#include <iostream>


/*! ���Ծ���ͼ�ľ��� */
void TestMatrixGraphMatrix();

/*! ����ʹ�ý��������ȡ��� */
void TestGetVertexByIndex();

/*! ����DFS */
void TestDFS();

/*! ����BFS */
void TestBFS();

/*! ������ͨ���� */
void TestComponents();

/*! ����KrusKal */
void TestKruskal();

/*! ����Prim�㷨 */
void TestPrim();

/*! ����Dijkstra��С������ */
void TestDijkstraShortestPath();

/*! ����CyberDash */
void TestCyberDashShow();


#endif //CYBER_DASH_GRAPH_TEST_H
