/*!
 * @file sparse_matrix.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ϡ����� 
 * @version 0.2.1
 * @date 2021-05-13
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#ifndef CYBER_DASH_SPARSE_MATRIX_H
#define CYBER_DASH_SPARSE_MATRIX_H


#include <iostream>
#include <cstdlib>


using namespace std;


//! ϡ�������Ԫ��ṹ��
template<class T>
struct TriTuple {
  int row; //!< ������
  int col; //!< ������
  T value; //!< ֵ

  /*!
   * @brief ��ֵ��������غ���
   * @param tri_tuple ϡ�躯����Ԫ������
   * @return ��ǰ������
   */
  TriTuple<T>& operator=(TriTuple<T>& tri_tuple) {
    row = tri_tuple.row;
    col = tri_tuple.col;
    value = tri_tuple.value;

    return *this;
  }
};


//! ϡ�����ģ����
template<class T>
class SparseMatrix {
public:

  // ���캯��(����Ϊϡ��������Ԫ�ظ���)
  SparseMatrix(int max_size = 100);

  // ���ƹ��캯��(����Ϊϡ�����)
  SparseMatrix(SparseMatrix<T>& sparse_matrix);

  /*! @brief �������� */
  virtual ~SparseMatrix() { delete[] sparse_matrix_array_; }

  /*! @brief ��ȡ���� */
  int Rows() { return this->rows_; }
  /*! @brief �������� */
  void SetRows(int rows) { this->rows_ = rows; }

  /*! @brief ��ȡ���� */
  int Cols() { return this->cols_; };
  /*! @brief �������� */
  void SetCols(int cols) { this->cols_ = cols; };

  /*! @brief ��ȡԪ���� */
  int Terms() { return this->terms_; }
  /*! @brief ����Ԫ���� */
  void SetTerms(int terms) { this->terms_ = terms; }

  /*! @brief ��ȡ���Ԫ���� */
  int MaxTerms() { return this->max_terms_; }
  /*! @brief �������Ԫ���� */
  int SetMaxTerms(int max_terms) { this->max_terms_ = max_terms; }

  // ��ȡԪ��
  bool GetElement(int row, int col, T& value);
  // ���Ԫ��(�����λ��Ԫ�ش���, �򸲸�)
  bool AddElement(int row, int col, T value);

  /*! @brief ��ȡԪ��������ʼ��ַ */
  TriTuple<T>* SparseMatrixArray() { return this->sparse_matrix_array_; }

  // ��ֵ��������غ���
  SparseMatrix<T>& operator = (SparseMatrix<T>& sparse_matrix);

  // ת������
  SparseMatrix<T>* Transpose();

  // ����ת������
  SparseMatrix<T>* FastTranspose();

  // ��ǰ������sparse_matrix��� todo: δʵ��
  SparseMatrix<T> Add(SparseMatrix<T>& sparse_matrix);

  // ��ǰ���������sparse_matrix��� todo: δʵ��
  SparseMatrix<T> Multiply(SparseMatrix<T>& sparse_matrix);

  // ��ӡϡ�����
  template <class U>
  friend ostream& operator << (ostream& out, SparseMatrix<T>& sparse_matrix);
  // ����ϡ�����
  template <class U>
  friend istream& operator >> (istream& in, SparseMatrix<T>& sparse_matrix);

private:
  int rows_; //!< ����
  int cols_; //!< ����
  int terms_; //!< ��ǰԪ����
  int max_terms_; //!< ���Ԫ����
  TriTuple<T>* sparse_matrix_array_; //!< Ԫ������
};


/*!
 * @brief ���캯��(����Ϊϡ��������Ԫ�ظ���)
 * @tparam T ����ģ�����
 * @param max_size ���Ԫ�ظ���
 */
template<class T>
SparseMatrix<T>::SparseMatrix(int max_size): max_terms_(max_size) {
  if (max_size < 1) {
    cerr<<"��ʼ��max_size����"<<endl;
    return;
  }

  this->sparse_matrix_array_ = new TriTuple<T>[max_size];
  /* error handler */

  this->max_terms_ = max_size;
  this->rows_ = 0;
  this->cols_ = 0;
  this->terms_ = 0;
}


/*!
 * @brief ���ƹ��캯��(����Ϊϡ�����)
 * @tparam T ����ģ�����
 * @param sparse_matrix ϡ�����(������)
 */
template<class T>
SparseMatrix<T>::SparseMatrix(SparseMatrix<T>& sparse_matrix) :
  rows_(sparse_matrix.Rows()), cols_(sparse_matrix.Cols()),
  terms_(sparse_matrix.Terms()), max_terms_(sparse_matrix.MaxTerms())
{
  this->sparse_matrix_array_ = new TriTuple<T>[this->MaxTerms()];
  /* error handler */

  for (int i = 0; i < this->terms_; i++) {
    this->sparse_matrix_array_[i] = sparse_matrix.SparseMatrixArray()[i];
  }
}


/*!
 * @brief ��ȡ����Ԫ��
 * @tparam T ����ģ�����
 * @param row ������
 * @param col ������
 * @param value ֵ����(���ڱ�����)
 * @return �Ƿ��ȡ�ɹ�
 */
template<class T>
bool SparseMatrix<T>::GetElement(int row, int col, T& value) {
  for (int i = 0; i < this->Terms(); i++) {
    if (this->sparse_matrix_array_[i].row == row && this->sparse_matrix_array_[i].col == col) {
      value = this->sparse_matrix_array_[i].value;
      return true;
    }
  }

  return false;
}


/*!
 * @brief ���Ԫ��
 * @tparam T ����ģ�����
 * @param row ������
 * @param col ������
 * @param value ֵ
 * @return �Ƿ���ӳɹ�
 * @note
 * ���row/col��Ӧ��λ���Ѿ�������Ԫ��, ���������Ԫ�ص�ֵ
 */
template<class T>
bool SparseMatrix<T>::AddElement(int row, int col, T value) {

  if (row >= this->Rows() || col >= this->Cols()) {
    return false;
  }

  for (int i = 0; i < this->Terms(); i++) {
    if (this->sparse_matrix_array_[i].row == row && this->sparse_matrix_array_[i].col == col) {
      this->sparse_matrix_array_[i].value = value;
      return true;
    }
  }

  if (this->Terms() == this->MaxTerms()) { // �����ٲ���
    return false;
  }

  this->sparse_matrix_array_[this->terms_].row =  row;
  this->sparse_matrix_array_[this->terms_].col =  col;
  this->sparse_matrix_array_[this->terms_].value = value;

  this->terms_++;

  return true;
}


/*!
 * @brief ��ֵ��������غ���
 * @tparam T ����ģ�����
 * @param sparse_matrix ϡ�����(������)
 * @return ��ǰ���鱾��
 */
template<class T>
SparseMatrix<T>& SparseMatrix<T>::operator = (SparseMatrix<T>& sparse_matrix) {

  this->SetRows(sparse_matrix.Rows());
  this->SetCols(sparse_matrix.Cols());
  this->SetTerms(sparse_matrix.Terms());
  this->SetMaxTerms(sparse_matrix.MaxTerms());

  this->sparse_matrix_array_ = new TriTuple<T>[this->MaxTerms()];
  /* error handler */

  for (int i = 0; i < this->terms_; i++) {
    this->sparse_matrix_array_[i] = sparse_matrix.SparseMatrixArray()[i];
  }

  return *this;
}


/*!
 * @brief ��ӡϡ�����
 * @tparam T ����ģ�����
 * @param out �����(������)
 * @param sparse_matrix ϡ�����(������)
 * @return �����(������)
 * ����ʾ��
 * ```
 * cout << sparse_matrix;
 * ```
 */
template<class T>
ostream& operator<<(ostream& out, SparseMatrix<T>& sparse_matrix) {
  out<<"rows = "<<sparse_matrix.Rows()<<endl;
  out<<"cols = "<<sparse_matrix.Cols()<<endl;
  out<<"NonZero terms: "<<sparse_matrix.Terms()<<endl;

  for (int i = 0; i < sparse_matrix.Terms(); i++) {
    out<<"M["<<sparse_matrix.SparseMatrixArray()[i].row<<"]["<<
      sparse_matrix.SparseMatrixArray()[i].col<<"] = "<<
      sparse_matrix.SparseMatrixArray()[i].value<<endl;
  }

  return out;
}


/*!
 * @brief ����ϡ�����
 * @tparam T ����ģ�����
 * @param out ������(������)
 * @param sparse_matrix ϡ�����(������)
 * @return ������(������)
 * @note
 * ����ʾ��
 * ```
 * cin >> sparse_matrix;
 * ```
 */
template<class T>
istream& operator>>(istream& in, SparseMatrix<T>& sparse_matrix) {
  cout << "����rows, cols��terms" << endl;

  int rows = 0;
  int cols = 0;
  int terms = 0;

  in >> rows >> cols >> terms;

  if (terms > sparse_matrix.MaxTerms()) {
    /* error handler */
    exit(1);
  }

  sparse_matrix.SetRows(rows);
  sparse_matrix.SetCols(cols);
  sparse_matrix.SetTerms(terms);

  for (int i = 0; i < sparse_matrix.Terms(); i++) {
    cout << "�����" << i << "��row, column��term��ֵ" << endl;
    in >> sparse_matrix.SparseMatrixArray()[i].row
      >> sparse_matrix.SparseMatrixArray()[i].col
      >> sparse_matrix.SparseMatrixArray()[i].value;
  }

  cout << sparse_matrix << endl;

  return in;
}


/*!
 * @brief ϡ�����ת��
 * @tparam T ����ģ�����
 * @return ת�þ���ĵ�ַ
 * @note
 *   ����forѭ�� \n
 *   ʱ�临�Ӷ�O(col^2*row)
 */
template<class T>
SparseMatrix<T>* SparseMatrix<T>::Transpose() {
  SparseMatrix<T>* trans_sparse_matrix_ptr = new SparseMatrix<T>(this->MaxTerms());

  trans_sparse_matrix_ptr->SetRows(this->Cols());
  trans_sparse_matrix_ptr->SetCols(this->Rows());
  trans_sparse_matrix_ptr->SetTerms(this->Terms());

  if (this->Terms() == 0) {
    return trans_sparse_matrix_ptr;
  }

  int cur = 0;
  for (int i = 0; i < this->Cols(); i++) { // ���к���ɨ��, ��Cols��
    for (int j = 0; j < this->Terms(); j++) { // ������sparse_matrix_array_���ҵ��к�Ϊi����Ԫ��
      if (this->SparseMatrixArray()[j].col == i) {
        trans_sparse_matrix_ptr->SparseMatrixArray()[cur].row = i; // row����col
        trans_sparse_matrix_ptr->SparseMatrixArray()[cur].col = this->SparseMatrixArray()[j].row; // col����row
        trans_sparse_matrix_ptr->SparseMatrixArray()[cur].value = this->SparseMatrixArray()[j].value; // value
        cur++;
      }
    }
  }

  return trans_sparse_matrix_ptr;
}


/*!
 * @brief ϡ��������ת��
 * @tparam T ����ģ�����
 * @return ת�þ����ָ��
 * @note
 *  �ռ任ʱ���˼��\n\n
 *
 *  **row_size_arr**: ����ԭ������зֱ��ж��ٸ�Ԫ��, ��Ӧת�þ���ĸ����ж��ٸ�Ԫ�� \n
 *  **trans_pos_at_each_row_arr**: ִ��ת��ʱ, ԭ�������(ת�þ������)��ÿһ��(ת�þ���ÿһ��)������ִ������ \n
 *
 *  \n�ȳ�ʼ�������������� \n\n
 *  ����sparse_matrix_array_ \n
 *  �Ե�i��Ԫ�ؽ���ת�þ����Ӧ�ĸ�ֵ \n
 *  ��ֵ������, ����trans_pos_at_each_row_arr[this->SparseMatrixArray()[i].col]��ֵ(��һ��ת�þ�������ִ�б����λ�����Ųһλ) \n
 */
template<class T>
SparseMatrix<T>* SparseMatrix<T>::FastTranspose() {
  int* row_item_count_arr = new int[this->Cols()];
  int* iter_pos_arr = new int[this->Cols()];

  SparseMatrix<T>* trans_sparse_matrix = new SparseMatrix<T>(this->MaxTerms());

  trans_sparse_matrix->SetRows(this->Cols());
  trans_sparse_matrix->SetCols(this->Rows());
  trans_sparse_matrix->SetTerms(this->Terms());

  if (this->Terms() == 0) {
    return trans_sparse_matrix;
  }

  for (int i = 0; i < this->Cols(); i++) {
    row_item_count_arr[i] = 0;
  }

  // ��ת������ÿ���ж��ٸ�Ԫ��, ���浽row_item_count_arr
  for (int i = 0; i < this->Terms(); i++) {
    row_item_count_arr[this->SparseMatrixArray()[i].col]++;
  }

  // ��ʼ��ת���������Ԫ������sparse_matrix_array�ķֲ�
  //
  // this->sparse_matrix_array[ 0 ... ��1�е���Ԫ�ص�λ�� ... ��i�е��׸�Ԫ�ص�λ�� ... ]
  //                            ^             ^                       ^
  //                            |             |                       |
  //                iter_pos_arr[0]   iter_pos_arr[1]           iter_pos_arr[i] ...
  //
  // �����㷨:
  //    iter_pos_arr[i] = iter_pos_arr[i - 1] + row_item_count_arr[i - 1];
  // ������Ԫ������sparse_matrix_array��, ÿ���׸�Ԫ�����ڵ�λ��, ������һ���׸�Ԫ�ص�λ�� + ���е�����Ԫ����
  iter_pos_arr[0] = 0;
  for (int i = 1; i < this->Cols(); i++) {
    iter_pos_arr[i] = iter_pos_arr[i - 1] + row_item_count_arr[i - 1];
  }

  for (int i = 0; i < this->Terms(); i++) {
    // ת�ƺ����ĵ�ǰ������(����ԭ�����������)
    int cur_row = this->SparseMatrixArray()[i].col;
    // ��ǰϡ��������Ԫ���������������, ȡiter_pos_arr[cur_row];
    int cur_sparse_matrix_index = iter_pos_arr[cur_row];

    // ת�þ������Ԫ������
    TriTuple<T>* trans_sparse_matrix_array = trans_sparse_matrix->SparseMatrixArray();
    // ԭ�������Ԫ������
    TriTuple<T>* src_spase_matrix_array = this->SparseMatrixArray();

    // ת�þ���Ԫ�ص�row/col��ԭ���黥��, value��ͬ
    trans_sparse_matrix_array[cur_sparse_matrix_index].row = src_spase_matrix_array[i].col;
    trans_sparse_matrix_array[cur_sparse_matrix_index].col = src_spase_matrix_array[i].row;
    trans_sparse_matrix_array[cur_sparse_matrix_index].value = src_spase_matrix_array[i].value;

    // ����trans_sparse_matrix_array[ iter_pos_arr[cur_row] ]�����Ѿ�����, cur_row����һ�δ���Ӧ����һ��λ��
    // iter_pos_arr[cur_row]��1, ��ʾ���Ųһλ
    iter_pos_arr[cur_row]++;
  }

  delete[] iter_pos_arr;
  delete[] row_item_count_arr;

  return trans_sparse_matrix;
}


#endif
