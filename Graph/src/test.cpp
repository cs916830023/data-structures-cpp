/*!
 * @file test.cpp
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ͼ����.cpp�ļ�
 * @version 0.2.1
 * @date 2021-10-9
 *
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#include "test.h"
#include "graph_algorithm.h"
#include "graph_algorithm.cpp"


using namespace std;


// ���Ծ���ͼ�ľ���
void TestMatrixGraphMatrix() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test PrintMatrix                     |"<<endl;
  cout<<"|                       ���Ծ���ͼ�ľ���                      |"<<endl;

  MatrixGraph<string, double> matrix_graph(10);
  matrix_graph.InsertVertex("����");
  matrix_graph.InsertVertex("����");
  matrix_graph.InsertVertex("ľ��");
  matrix_graph.InsertVertex("ˮ��");

  matrix_graph.InsertEdge("����", "����", 0.8);
  matrix_graph.InsertEdge("����", "ľ��", 3.9);
  matrix_graph.InsertEdge("ľ��", "ˮ��", 7.3);
  matrix_graph.InsertEdge("����", "ľ��", 11.3);
  matrix_graph.InsertEdge("����", "ˮ��", 0.3);

  matrix_graph.PrintMatrix();

  cout<<"-------------------------------------------------------------"<<endl;
}


// ����ʹ�ý��������ȡ���
void TestGetVertexByIndex() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                   Test GetVertexByIndex                   |"<<endl;
  cout<<"|                   ����ʹ�ý��������ȡ���                    |"<<endl;

  cout<<"**�ڽӱ�ͼ**"<<endl;
  AdjacencyListGraph<string, double> adjacency_list_graph;

  adjacency_list_graph.InsertVertex("����");
  adjacency_list_graph.InsertVertex("�Ϻ�");
  adjacency_list_graph.InsertVertex("����");
  adjacency_list_graph.InsertVertex("����");

  adjacency_list_graph.InsertEdge("����", "�Ϻ�", 0.8);
  adjacency_list_graph.InsertEdge("�Ϻ�", "����", 3.9);
  adjacency_list_graph.InsertEdge("����", "����", 7.3);
  adjacency_list_graph.InsertEdge("����", "����", 11.3);
  adjacency_list_graph.InsertEdge("�Ϻ�", "����", 0.3);

  string BJ;
  string SH;
  string GZ;
  string SZ;

  adjacency_list_graph.GetVertexByIndex(BJ, 0);
  adjacency_list_graph.GetVertexByIndex(SH, 1);
  adjacency_list_graph.GetVertexByIndex(GZ, 2);
  adjacency_list_graph.GetVertexByIndex(SZ, 3);

  cout<<"���0: "<<BJ<<endl;
  cout<<"���1: "<<SH<<endl;
  cout<<"���2: "<<GZ<<endl;
  cout<<"���3: "<<SZ<<endl;

  cout<<endl<<"**����ͼ**"<<endl;
  MatrixGraph<string, double> matrix_graph(10);
  matrix_graph.InsertVertex("����");
  matrix_graph.InsertVertex("����");
  matrix_graph.InsertVertex("ľ��");
  matrix_graph.InsertVertex("ˮ��");

  matrix_graph.InsertEdge("����", "����", 0.8);
  matrix_graph.InsertEdge("����", "ľ��", 3.9);
  matrix_graph.InsertEdge("ľ��", "ˮ��", 7.3);
  matrix_graph.InsertEdge("����", "ľ��", 11.3);
  matrix_graph.InsertEdge("����", "ˮ��", 0.3);

  matrix_graph.GetVertexByIndex(BJ, 0);
  matrix_graph.GetVertexByIndex(SH, 1);
  matrix_graph.GetVertexByIndex(GZ, 2);
  matrix_graph.GetVertexByIndex(SZ, 3);

  cout<<"���0: "<<BJ<<endl;
  cout<<"���1: "<<SH<<endl;
  cout<<"���2: "<<GZ<<endl;
  cout<<"���3: "<<SZ<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


// ����DFS
void TestDFS() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                          Test DFS                         |"<<endl;
  cout<<"|                       ����������ȱ���                      |"<<endl;

  int v0 = 0;
  int v1 = 1;
  int v2 = 2;
  int v3 = 3;
  int v4 = 4;

  AdjacencyListGraph<int, int> adjacency_list_graph;

  adjacency_list_graph.InsertVertex(v0);
  adjacency_list_graph.InsertVertex(v1);
  adjacency_list_graph.InsertVertex(v2);
  adjacency_list_graph.InsertVertex(v3);
  adjacency_list_graph.InsertVertex(v4);

  adjacency_list_graph.InsertEdge(v0, v1, 100);
  adjacency_list_graph.InsertEdge(v1, v2, 50);
  adjacency_list_graph.InsertEdge(v2, v3, 20);
  adjacency_list_graph.InsertEdge(v3, v4, 60);
  adjacency_list_graph.InsertEdge(v0, v3, 30);
  adjacency_list_graph.InsertEdge(v0, v4, 100);
  adjacency_list_graph.InsertEdge(v2, v4, 10);

  MatrixGraph<int, int> matrix_graph;

  matrix_graph.InsertVertex(v0);
  matrix_graph.InsertVertex(v1);
  matrix_graph.InsertVertex(v2);
  matrix_graph.InsertVertex(v3);
  matrix_graph.InsertVertex(v4);

  matrix_graph.InsertEdge(v0, v1, 100);
  matrix_graph.InsertEdge(v1, v2, 50);
  matrix_graph.InsertEdge(v2, v3, 20);
  matrix_graph.InsertEdge(v3, v4, 60);
  matrix_graph.InsertEdge(v0, v3, 30);
  matrix_graph.InsertEdge(v0, v4, 100);
  matrix_graph.InsertEdge(v2, v4, 10);

  cout<<"**�ڽӱ�ͼ**"<<endl;
  DFS(adjacency_list_graph, v0);

  cout<<endl<<"**����ͼ**"<<endl;
  DFS(matrix_graph, v0);

  cout<<"-------------------------------------------------------------"<<endl;
}


// ����BFS
void TestBFS() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                          Test BFS                         |"<<endl;
  cout<<"|                       ���Թ�����ȱ���                      |"<<endl;

  int v0 = 0;
  int v1 = 1;
  int v2 = 2;
  int v3 = 3;
  int v4 = 4;

  AdjacencyListGraph<int, int> adjacency_list_graph;
  MatrixGraph<int, int> matrix_graph;

  adjacency_list_graph.InsertVertex(v0);
  adjacency_list_graph.InsertVertex(v1);
  adjacency_list_graph.InsertVertex(v2);
  adjacency_list_graph.InsertVertex(v3);
  adjacency_list_graph.InsertVertex(v4);

  matrix_graph.InsertVertex(v0);
  matrix_graph.InsertVertex(v1);
  matrix_graph.InsertVertex(v2);
  matrix_graph.InsertVertex(v3);
  matrix_graph.InsertVertex(v4);

  adjacency_list_graph.InsertEdge(v0, v1, 100);
  adjacency_list_graph.InsertEdge(v1, v2, 50);
  adjacency_list_graph.InsertEdge(v2, v3, 20);
  adjacency_list_graph.InsertEdge(v3, v4, 60);
  adjacency_list_graph.InsertEdge(v0, v3, 30);
  adjacency_list_graph.InsertEdge(v0, v4, 100);
  adjacency_list_graph.InsertEdge(v2, v4, 10);

  matrix_graph.InsertEdge(v0, v1, 100);
  matrix_graph.InsertEdge(v1, v2, 50);
  matrix_graph.InsertEdge(v2, v3, 20);
  matrix_graph.InsertEdge(v3, v4, 60);
  matrix_graph.InsertEdge(v0, v3, 30);
  matrix_graph.InsertEdge(v0, v4, 100);
  matrix_graph.InsertEdge(v2, v4, 10);

  cout<<"**�ڽӱ�ͼ**"<<endl;
  BFS(adjacency_list_graph, v0);

  cout<<endl<<"**����ͼ**"<<endl;
  BFS(matrix_graph, v0);

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestComponents() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test Components                      |"<<endl;
  cout<<"|                        ������ͨ����                         |"<<endl;
  cout<<"|  �ڵ�:                                                     |"<<endl;
  cout<<"|    0, 1, 2, 3                                             |"<<endl;
  cout<<"|  ��:                                                      |"<<endl;
  cout<<"|    0-1Ȩֵ: 0.8                                            |"<<endl<<endl;
  cout<<"|    2-3Ȩֵ: 7.3                                            |"<<endl<<endl;

  AdjacencyListGraph<int, double> adjacency_list_graph;

  adjacency_list_graph.InsertVertex(0);
  adjacency_list_graph.InsertVertex(1);
  adjacency_list_graph.InsertVertex(2);
  adjacency_list_graph.InsertVertex(3);

  adjacency_list_graph.InsertEdge(0, 1, 0.8);
  adjacency_list_graph.InsertEdge(2, 3, 7.3);

  MatrixGraph<int, double> matrix_graph;

  matrix_graph.InsertVertex(0);
  matrix_graph.InsertVertex(1);
  matrix_graph.InsertVertex(2);
  matrix_graph.InsertVertex(3);

  matrix_graph.InsertEdge(0, 1, 0.8);
  matrix_graph.InsertEdge(2, 3, 7.3);

  cout<<"**�ڽӱ�ͼ����**"<<endl;
  Components(adjacency_list_graph);

  cout<<endl<<"**����ͼ����**"<<endl;
  Components(matrix_graph);

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestKruskal() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                        Test Kruskal                       |"<<endl;
  cout<<"|                       ����Kruskal�㷨                      |"<<endl;
  cout<<"|  �ڵ�:                                                     |"<<endl;
  cout<<"|    \"����\", \"�Ϻ�\", \"����\", \"����\"                           |"<<endl;
  cout<<"|  ��:                                                      |"<<endl;
  cout<<"|    \"����\"-\"�Ϻ�\"Ȩֵ: 0.8                                   |"<<endl<<endl;
  cout<<"|    \"�Ϻ�\"-\"����\"Ȩֵ: 3.9                                   |"<<endl<<endl;
  cout<<"|    \"����\"-\"����\"Ȩֵ: 7.3                                   |"<<endl<<endl;
  cout<<"|    \"����\"-\"����\"Ȩֵ: 11.3                                  |"<<endl<<endl;
  cout<<"|    \"�Ϻ�\"-\"����\"Ȩֵ: 0.3                                   |"<<endl<<endl;

  string BJ = "����";
  string SH = "�Ϻ�";
  string GZ = "����";
  string SZ = "����";

  MinSpanTree<string, double> min_span_tree_adj(100);
  MinSpanTree<string, double> min_span_tree_matrix(100);

  AdjacencyListGraph<string, double> adjacency_list_graph;

  adjacency_list_graph.InsertVertex(BJ);
  adjacency_list_graph.InsertVertex(SH);
  adjacency_list_graph.InsertVertex(GZ);
  adjacency_list_graph.InsertVertex(SZ);

  adjacency_list_graph.InsertEdge(BJ, SH, 0.8);
  adjacency_list_graph.InsertEdge(SH, GZ, 3.9);
  adjacency_list_graph.InsertEdge(GZ, SZ, 7.3);
  adjacency_list_graph.InsertEdge(BJ, GZ, 11.3);
  adjacency_list_graph.InsertEdge(SH, SZ, 0.3);

  MatrixGraph<string, double> matrix_graph;
  matrix_graph.InsertVertex(BJ);
  matrix_graph.InsertVertex(SH);
  matrix_graph.InsertVertex(GZ);
  matrix_graph.InsertVertex(SZ);

  matrix_graph.InsertEdge(BJ, SH, 0.8);
  matrix_graph.InsertEdge(SH, GZ, 3.9);
  matrix_graph.InsertEdge(GZ, SZ, 7.3);
  matrix_graph.InsertEdge(BJ, GZ, 11.3);
  matrix_graph.InsertEdge(SH, SZ, 0.3);

  cout<<"**�ڽӱ�ͼ����**"<<endl;
  Kruskal(adjacency_list_graph, min_span_tree_adj);
  min_span_tree_adj.Show();

  cout<<endl<<"**����ͼ����**"<<endl;
  Kruskal(matrix_graph, min_span_tree_matrix);

  min_span_tree_matrix.Show();
  cout<<"-------------------------------------------------------------"<<endl;
}


void TestPrim() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                         Test Prim                         |"<<endl;
  cout<<"|                        ����Prim�㷨                        |"<<endl;
  cout<<"|  �ڵ�:                                                     |"<<endl;
  cout<<"|    \"����\", \"�Ϻ�\", \"����\", \"����\"                           |"<<endl;
  cout<<"|  ��:                                                      |"<<endl;
  cout<<"|    \"����\"-\"�Ϻ�\"Ȩֵ: 0.8                                   |"<<endl<<endl;
  cout<<"|    \"�Ϻ�\"-\"����\"Ȩֵ: 3.9                                   |"<<endl<<endl;
  cout<<"|    \"����\"-\"����\"Ȩֵ: 7.3                                   |"<<endl<<endl;
  cout<<"|    \"����\"-\"����\"Ȩֵ: 11.3                                  |"<<endl<<endl;
  cout<<"|    \"�Ϻ�\"-\"����\"Ȩֵ: 0.3                                   |"<<endl<<endl;

  string BJ = "����";
  string SH = "�Ϻ�";
  string GZ = "����";
  string SZ = "����";

  AdjacencyListGraph<string, double> adjacency_list_graph;

  adjacency_list_graph.InsertVertex(BJ);
  adjacency_list_graph.InsertVertex(SH);
  adjacency_list_graph.InsertVertex(GZ);
  adjacency_list_graph.InsertVertex(SZ);

  adjacency_list_graph.InsertEdge(BJ, SH, 0.8);
  adjacency_list_graph.InsertEdge(SH, GZ, 3.9);
  adjacency_list_graph.InsertEdge(GZ, SZ, 7.3);
  adjacency_list_graph.InsertEdge(BJ, GZ, 11.3);
  adjacency_list_graph.InsertEdge(SH, SZ, 0.3);

  MatrixGraph<string, double> matrix_graph;

  matrix_graph.InsertVertex(BJ);
  matrix_graph.InsertVertex(SH);
  matrix_graph.InsertVertex(GZ);
  matrix_graph.InsertVertex(SZ);

  matrix_graph.InsertEdge(BJ, SH, 0.8);
  matrix_graph.InsertEdge(SH, GZ, 3.9);
  matrix_graph.InsertEdge(GZ, SZ, 7.3);
  matrix_graph.InsertEdge(BJ, GZ, 11.3);
  matrix_graph.InsertEdge(SH, SZ, 0.3);

  cout<<endl<<"**�ڽӱ�ͼ����**"<<endl;
  MinSpanTree<string, double> min_span_tree_adj(100);
  // Prim(adjacency_list_graph, BJ, min_span_tree_adj); // ����ԭ��ʵ��
  Prim(adjacency_list_graph, BJ, min_span_tree_adj); // ���ذ�Prim
  min_span_tree_adj.Show();

  cout<<endl<<"**����ͼ����**"<<endl;
  MinSpanTree<string, double> min_span_tree_matrix(100);
  Prim(matrix_graph, BJ, min_span_tree_matrix); // ���ذ�Prim
  min_span_tree_matrix.Show();

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestDijkstraShortestPath() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                 Test DijkstraShortestPath                 |"<<endl;
  cout<<"|                     ����Dijkstra���·��                    |"<<endl;

  string v0 = "����";
  string v1 = "�Ϻ�";
  string v2 = "����";
  string v3 = "����";
  string v4 = "����";

  AdjacencyListGraph<string, double> adjacency_list_graph;

  adjacency_list_graph.InsertVertex(v0);
  adjacency_list_graph.InsertVertex(v1);
  adjacency_list_graph.InsertVertex(v2);
  adjacency_list_graph.InsertVertex(v3);
  adjacency_list_graph.InsertVertex(v4);

  adjacency_list_graph.InsertEdge(v0, v1, 98.63);
  adjacency_list_graph.InsertEdge(v1, v2, 51.52);
  adjacency_list_graph.InsertEdge(v2, v3, 17);
  adjacency_list_graph.InsertEdge(v3, v4, 58.98);
  adjacency_list_graph.InsertEdge(v0, v3, 29.3);
  adjacency_list_graph.InsertEdge(v0, v4, 100.003);
  adjacency_list_graph.InsertEdge(v2, v4, 9.34);

  MatrixGraph<string, double> matrix_graph;

  matrix_graph.InsertVertex(v0);
  matrix_graph.InsertVertex(v1);
  matrix_graph.InsertVertex(v2);
  matrix_graph.InsertVertex(v3);
  matrix_graph.InsertVertex(v4);

  matrix_graph.InsertEdge(v0, v1, 98.63);
  matrix_graph.InsertEdge(v1, v2, 51.52);
  matrix_graph.InsertEdge(v2, v3, 17);
  matrix_graph.InsertEdge(v3, v4, 58.98);
  matrix_graph.InsertEdge(v0, v3, 29.3);
  matrix_graph.InsertEdge(v0, v4, 100.003);
  matrix_graph.InsertEdge(v2, v4, 9.34);

  cout<<endl<<"**�ڽӱ�ͼDijkstra����**"<<endl;
  double min_dist_arr_adj[5];
  int from_path_arr_adj[5];

  DijkstraShortestPath(adjacency_list_graph, v0, min_dist_arr_adj, from_path_arr_adj);
  PrintDijkstraShortestPath(adjacency_list_graph, v0, min_dist_arr_adj, from_path_arr_adj);

  cout<<endl<<"**����ͼ����**"<<endl;
  double min_dist_arr_matrix[5];
  int from_path_arr_matrix[5];

  DijkstraShortestPath(adjacency_list_graph, v0, min_dist_arr_matrix, from_path_arr_matrix);
  PrintDijkstraShortestPath(adjacency_list_graph, v0, min_dist_arr_matrix, from_path_arr_matrix);

  cout<<"-------------------------------------------------------------"<<endl;
}


// ����CyberDash, :)
void TestCyberDashShow() {
  MatrixGraph<int, int> cyber_dash_graph;
  cyber_dash_graph.CyberDashShow();
}
