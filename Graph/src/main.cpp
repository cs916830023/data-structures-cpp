/*!
 * @file main.cpp
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ͼdemo��ʾ
 * @version 0.2.1
 * @date 2021-07-14
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#include "graph_algorithm.cpp"
#include "test.h"


using namespace std;


int main(int argc, char** argv) {

  TestMatrixGraphMatrix();

  TestGetVertexByIndex();

  TestDFS();

  TestBFS();

  TestComponents();

  TestPrim();

  TestKruskal();

  TestDijkstraShortestPath();

  TestCyberDashShow();

  return 0;
}