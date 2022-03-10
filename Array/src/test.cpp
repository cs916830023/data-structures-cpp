﻿/*!
 * @file test.cpp
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ϡ��������.cpp�ļ�
 * @version 0.2.1
 * @date 2021-05-16
 *
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */


#include "test.h"


void TestSparseMatrixConstructor() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                Test SparseMatrixConstructor               |"<<endl;
  cout<<"|                    ���Զ���ϡ������캯��                   |"<<endl<<endl<<endl;

  SparseMatrix<int> sparse_matrix(100);

  cout<<sparse_matrix;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestSparseMatrixCopyConstructor() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|              Test SparseMatrixCopyConstructor             |"<<endl;
  cout<<"|                  ���Զ���ϡ������ƹ��캯��                 |"<<endl<<endl<<endl;

  SparseMatrix<int> sparse_matrix_1(100);
  sparse_matrix_1.SetRows(10);
  sparse_matrix_1.SetCols(20);
  sparse_matrix_1.AddElement(3, 9, 100);
  sparse_matrix_1.AddElement(4, 17, 83);

  cout<<"��ӡsparse_matrix_1:"<<endl;
  cout<<sparse_matrix_1<<endl<<endl;

  SparseMatrix<int> sparse_matrix_2(sparse_matrix_1);
  cout<<"��ӡsparse_matrix_2:"<<endl;
  cout<<sparse_matrix_2;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestSparseMatrixInput() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                   Test SparseMatrixInput                  |"<<endl;
  cout<<"|                    ���Զ���ϡ��������빹��                   |"<<endl<<endl<<endl;

  SparseMatrix<int> sparse_matrix_1(100);

  cin>>sparse_matrix_1;

  SparseMatrix<int>* sparse_matrix_ptr_3 = sparse_matrix_1.Transpose();

  cout << *sparse_matrix_ptr_3 << endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestSparseMatrixTranspose() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                 Test SparseMatrixTranspose                |"<<endl;
  cout<<"|                     ���Զ���ϡ�����ת��                     |"<<endl<<endl<<endl;

  SparseMatrix<double> sparse_matrix_1(100);

  sparse_matrix_1.SetRows(10);
  sparse_matrix_1.SetCols(20);

  sparse_matrix_1.AddElement(0, 1, 11.345);
  sparse_matrix_1.AddElement(1, 0, 4.2);
  sparse_matrix_1.AddElement(6, 7, 432.569);
  sparse_matrix_1.AddElement(9, 19, 54.8);

  cout<<"sparse_matrix_1����:"<<endl;
  cout<<sparse_matrix_1<<endl;

  SparseMatrix<double>* sparse_matrix_ptr = sparse_matrix_1.Transpose();

  cout<<"ת�ú�ľ���:"<<endl;
  cout<<*sparse_matrix_ptr<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestSparseMatrixFastTranspose() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|               Test SparseMatrixFastTranspose              |"<<endl;
  cout<<"|                   ���Զ���ϡ�����(����)ת��                  |"<<endl<<endl<<endl;

  SparseMatrix<double> sparse_matrix_1(100);

  sparse_matrix_1.SetRows(50);
  sparse_matrix_1.SetCols(40);

  sparse_matrix_1.AddElement(0, 0, 9);
  sparse_matrix_1.AddElement(0, 1, 11.345);
  sparse_matrix_1.AddElement(1, 0, 4.2);
  sparse_matrix_1.AddElement(6, 7, 432.569);
  sparse_matrix_1.AddElement(6, 22, 5490.989);
  sparse_matrix_1.AddElement(49, 38, 19.7989);
  sparse_matrix_1.AddElement(49, 39, 64);

  cout<<"sparse_matrix_1����:"<<endl;
  cout<<sparse_matrix_1<<endl;

  SparseMatrix<double>* sparse_matrix_ptr = sparse_matrix_1.FastTranspose();

  cout<<"ת�ú�ľ���:"<<endl;
  cout<<*sparse_matrix_ptr<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}
