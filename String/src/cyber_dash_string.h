/*!
 * @file cyber_dash_string.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief �ַ���ƥ��ģ����
 * @version 0.2.1
 * @date 2021-07-29
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#ifndef CYBER_DASH_YUAN_STRING_H
#define CYBER_DASH_YUAN_STRING_H


#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;


const int DEFAULT_SIZE = 128;


/*!
 * @brief CyberDash�ַ�����
 */
class CyberDashString {

public:
  // ���캯��(�ַ�������)
  CyberDashString(int size = DEFAULT_SIZE);
  /*! ���캯�� */
  CyberDashString(const char* char_ptr);
  /*! �������� */
  ~CyberDashString() { delete[] char_array_; };

  int Length() const { return this->length_; };
  CyberDashString operator() (int index, int len) const;
  bool operator == (const CyberDashString& cyber_dash_str) const;
  bool operator != (CyberDashString& cyber_dash_str) const;
  bool operator ! () const;
  CyberDashString& operator = (const CyberDashString& cyber_dash_str);
  CyberDashString& operator += (CyberDashString& cyber_dash_str);
  char& operator[] (int index);

  // BF�ַ���ƥ��
  int BruteForceFind(CyberDashString& pattern, int offset) const;

  // KMP�ַ���ƥ�����
  int KMPFind(CyberDashString& pattern, int offset) const;

  // KMP�ַ���ƥ�����(ʹ��KMPNextByCyberDash����next����)
  int KMPFindCyberDash(CyberDashString& pattern, int offset) const;

  // ����<<
  friend ostream& operator<<(ostream& os, CyberDashString& cyber_dash_str) {
    os << cyber_dash_str.char_array_;
    return os;
  }

  static void CyberDashShow();

  static int* KMPNext(const char* pattern, int pattern_len);
  static int* KMPNextByCyberDash(const char* pattern, int pattern_len);
  static void PrintNextArray(const int* next_arr, int next_arr_len);

private:
  char* char_array_; //!< �ַ�������
  int length_; //!< ��ǰ�ַ�������
  int max_size_; //!< ��󳤶�
};


/*!
 * @brief ���캯��(�ַ�������)
 * @param size �ַ�����󳤶�
 */
CyberDashString::CyberDashString(int size) {

  max_size_ = size;

  char_array_ = new char[max_size_ + 1];
  if (char_array_ == NULL) {
    cerr<<"Allocation Error"<<endl;
    exit(1);
  }

  length_ = 0;
  // ��ȫ����0
  memset(char_array_, 0, sizeof(char) * (max_size_ + 1));
}


/*!
 * @brief ���캯��(�ַ���)
 * @param char_ptr �ַ���
 */
CyberDashString::CyberDashString(const char* char_ptr) {
  int char_len = strlen(char_ptr);

  if (char_len > DEFAULT_SIZE) {
    max_size_ = char_len;
  } else {
    max_size_ = DEFAULT_SIZE;
  }

  char_array_ = new char[max_size_ + 1];
  if (char_array_ == NULL) {
    cerr<<"Allocation Error"<<endl;
    exit(1);
  }

  length_ = char_len;

  // ��ȫ����0
  memset(char_array_, 0, sizeof(char) * (max_size_ + 1));
  // �ٸ����ַ�������
  memcpy(char_array_, char_ptr, sizeof(char) * char_len);
}


/*!
 * @brief ����()
 * @param index ��ʼindex
 * @param offset ƫ����
 * @return �ַ���
 */
CyberDashString CyberDashString::operator () (int index, int offset) const {

  CyberDashString ret_str(offset + 1);

  if (index < 0 || index + offset > max_size_ || offset <= 0 || index + 1 > length_) {

    ret_str.length_ = 0;
    ret_str.char_array_[0] = '\0';
  } else {

    if (index + offset > length_) {
      offset = length_ - index;
    }

    ret_str.length_ = offset;

    memcpy(ret_str.char_array_, char_array_ + index, sizeof(char) * offset);

    ret_str.char_array_[offset] = '\0';
  }

  return ret_str;
}


/*!
 * @brief ����==
 * @param cyber_dash_str �ַ���
 * @return �Ƿ���ͬ
 */
bool CyberDashString::operator == (const CyberDashString& cyber_dash_str) const {
  int cmp_res = strcmp(char_array_, cyber_dash_str.char_array_);
  if (cmp_res == 0) {
    return true;
  } else {
    return false;
  }
}


/*!
 * @brief ����!=
 * @param cyber_dash_str �ַ���
 * @return �Ƿ�ͬ
 */
bool CyberDashString::operator != (CyberDashString& cyber_dash_str) const {
  int cmp_res = strcmp(char_array_, cyber_dash_str.char_array_);
  if (cmp_res != 0) {
    return true;
  } else {
    return false;
  }
}


// todo
bool CyberDashString::operator ! () const {
  return true;
}


/*!
 * @brief ����=
 * @param src_str Դ�ַ���
 * @return �����ַ���
 */
CyberDashString& CyberDashString::operator = (const CyberDashString& src_str) {

  if (&src_str != this) {

    delete[] char_array_;

    char_array_ = new char[src_str.max_size_ + 1];
    if (char_array_ == NULL) {
      cerr<<"�洢����ʧ��!"<<endl;
      exit(1);
    }

    memcpy(char_array_, src_str.char_array_, sizeof(char) * src_str.length_);

    length_ = src_str.length_;

  } else {
    cout<<"�ַ�������ֵ����"<<endl;
  }

  return *this;
}


// todo
CyberDashString& CyberDashString::operator += (CyberDashString& cyber_dash_str) {
  return *this;
}


/*!
 * @brief ����[]
 * @param index
 * @return
 */
char& CyberDashString::operator[] (int index) {
  if (index < 0 || index >= Length()) {
    cerr<<"Out of Range."<<endl;
    exit(1);
  }

  return char_array_[index];
}


/*!
 * @brief BF�ַ���ƥ��
 * @param pattern ģʽ��
 * @param offset Ŀ�괮����ʼƫ����
 * @return Ŀ�괮�е�ƥ��λ��, -1Ϊ��ƥ�� / ����Ϊ��һ��ƥ���ַ�����������ֵ
 */
int CyberDashString::BruteForceFind(CyberDashString& pattern, int offset) const {

  int match_offset = -1;
  int pattern_idx;

  for (int i = offset; i <= length_ - pattern.length_; i++) {
    for (pattern_idx = 0; pattern_idx < pattern.length_; pattern_idx++) {
      if (char_array_[i + pattern_idx] != pattern[pattern_idx]) {
        break;
      }
    }

    if (pattern_idx == pattern.length_) {
      match_offset = i;
      break;
    }
  }

  return match_offset;
}


/*!
 * @brief ��ģʽ����next����
 * @param pattern ģʽ����һ���ַ�����ָ��
 * @param pattern_len ģʽ������
 * @return next������ʼ��ַ
 */
int* CyberDashString::KMPNext(const char* pattern, int pattern_len) {

  // ����next�����ڴ�
  int* next = new int[pattern_len];
  if (next == NULL) {
    cerr<<"next array allocate error"<<endl;
    return NULL;
  }

  /// ����next[0] = -1
  int i = 0;
  int starting_index = -1;

  next[0] = starting_index;

  while (i < pattern_len) {

    /// ʹ��next[0]����next[1]
    /// ��ģʽ���ַ�pattern[1]ʧ��ʱ, ��Ȼ��pattern[0]��ʼ���½���ƥ��, ���next[1] = 0
    /// �˴��߼����Ժ������pattern[i] == pattern[starting_index]��֧�߼��ϲ�
    /// ���next[0] = -1
    /// ���ಿ������ͬ(������Ժϲ�)
    if (starting_index == -1) {
      i++;
      starting_index++;
      next[i] = starting_index;
    }
      /// ʹ��next[i]��next[i + 1]
    else
    {
      /// ���pattern[i]��pattern[starting_index]��ͬ, �������������ͬ�ַ���������չ
      /// ʾ��
      ///  a b c d 5 6 a b c d 7
      ///  a b
      ///              a b
      ///                  ^
      ///                  |
      ///
      ///
      /// i == 8, starting_index == 2
      /// pattern[8] == pattern[2] == 'c', ��if( == )��֧:
      ///     8++ -> 9,
      ///     starting_index++ -> 3
      ///     next[9] == pattern[3]
      ///
      ///
      ///  a b c d 5 6 a b c d 7
      ///  a b c
      ///              a b c
      ///                    ^
      ///                    |
      ///
      if (pattern[i] == pattern[starting_index]) {
        i++;
        starting_index++;
        next[i] = starting_index;
      }
        /// ���pattern[i]��pattern[starting_index]��ͬ, ��ʹ��next������еݹ�, ����֤
      else
      {
        starting_index = next[starting_index];
      }
    }
  }

  return next;
}


/*!
 * @brief ��ģʽ����next����(CyberDash�汾)
 * @param pattern ģʽ����һ���ַ�����ָ��
 * @param pattern_len ģʽ������
 * @return next������ʼ��ַ
 */
int* CyberDashString::KMPNextByCyberDash(const char* pattern, int pattern_len) {

  int* next = new int[pattern_len];
  if (next == NULL) {
    cerr<<"next array allocate error"<<endl;
    return NULL;
  }

  next[0] = -1;
  next[1] = 0;

  int i = 1;
  int starting_index = 0;

  while (i < pattern_len) {
    if (pattern[i] == pattern[starting_index]) {
      i++;
      starting_index++;
      next[i] = starting_index;
    } else {
      if (starting_index == 0) {
        i++;
        next[i] = starting_index;
      } else {
        starting_index = next[starting_index];
      }
    }
  }

  return next;
}


/*!
 * @brief ��ӡnext����
 * @param next_arr next����
 * @param next_arr_len
 */
void CyberDashString::PrintNextArray(const int* next_arr, int next_arr_len) {
  /// ʾ��
  /// ģʽ�ַ���:  a b c d 5 6 a b c d 7
  /// next����:  -1 0 0 0 0 0 0 1 2 3 4
  for (int i = 0; i < next_arr_len; i++) {
    cout << *(next_arr + i) << " ";
  }
  cout<<endl;
}


/*!
 * @brief KMP�ַ���ƥ�����
 * @param pattern ģʽ��
 * @param offset Ŀ�괮����ʼƫ����
 * @return Ŀ�괮�е�ƥ��λ��, -1Ϊ��ƥ�� / ����Ϊ��һ��ƥ���ַ�����������ֵ
 * @note
 */
int CyberDashString::KMPFind(CyberDashString& pattern, int offset) const {

  int pattern_len = pattern.Length();
  int* next = KMPNext(pattern.char_array_, pattern_len);
  if (next == NULL) {
    cerr<<"next array allocation error"<<endl;
    return -2; //
  }

  // cout<<"ģʽ��: "<<pattern<<endl<<"��Ӧ��next����: ";
  // PrintNextArray(next, pattern_len); // show the next array

  int pattern_str_i = 0;
  int target_str_i = offset;

  while (pattern_str_i < pattern_len && target_str_i < this->length_) {
    /// ���ģʽ���ַ�(λ��pattern_str_i)��Ŀ�괮�ַ�(λ��target_str_i)��ͬ, �������λ
    if (pattern[pattern_str_i] == this->char_array_[target_str_i]) {
      pattern_str_i++;
      target_str_i++;
    }
      /// ���ģʽ���ַ�(λ��pattern_str_i)��Ŀ�괮�ַ�(λ��target_str_i)��ͬ
    else
    {
      // �����ģʽ����1���ַ���ƥ��, ��Ŀ�괮�����λ
      if (pattern_str_i == 0) {
        target_str_i++;
      }
        // �������ģʽ����1���ַ���ƥ��, ���ģʽ����next[pattern_str_i]��ʼִ����һ��ƥ��
      else
      {
        pattern_str_i = next[pattern_str_i];
      }
    }
  }

  delete[] next; // ɾ��next����

  int match_pos;

  if (pattern_str_i < pattern_len) {
    match_pos = -1; // ��ƥ��
  } else {
    match_pos = target_str_i - pattern_len; // ���Ŀ�괮��ƥ��ĵ�һ���ַ���(��Ŀ�괮�е�)λ��
  }

  return match_pos;
}


/*!
 * @brief KMP�ַ���ƥ�����(ʹ��KMPNextByCyberDash����next����)
 * @param pattern ģʽ��
 * @param offset Ŀ�괮����ʼƫ����
 * @return Ŀ�괮�е�ƥ��λ��, -1Ϊ��ƥ�� / ����Ϊ��һ��ƥ���ַ�����������ֵ
 * @note
 */
int CyberDashString::KMPFindCyberDash(CyberDashString& pattern, int offset) const {

  int match_pos;

  int pattern_len = pattern.Length();
  int* next = KMPNextByCyberDash(pattern.char_array_, pattern_len);
  // PrintNextArray(next, pattern_len);
  if (!next) {
    cerr<<"next array allocation error"<<endl;
    return -2;
  }

  int pattern_index = 0;
  int target_str_index = offset;

  while (pattern_index < pattern_len && target_str_index < length_) {
    if (pattern_index == -1 || pattern[pattern_index] == char_array_[target_str_index]) {
      pattern_index++;
      target_str_index++;
    } else {
      pattern_index = next[pattern_index];
    }
  }

  delete[] next;

  if (pattern_index < pattern_len) {
    match_pos = -1;
  } else {
    match_pos = target_str_index - pattern_len;
  }

  return match_pos;
}


/*!
 * @brief ������CyberDash:-)
 */
void CyberDashString::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"������\"CyberDash���������\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash��Ա:"<<endl
      <<"Ԫ��(cyberdash@163.com), "<<"�����ʵ��ѧ(ͨ�Ź��̱���)/�����ʵ��ѧ(��Ϣ��ͨ��ϵͳ�о���)"<<endl
      <<"�ڸ�(alei_go@163.com), "<<"ɽ������ѧ(��ѧ����)/�����ʵ��ѧ(������о���)"<<endl<<endl
      <<"L_Dash(lyu2586@163.com), "<<"�����ʵ��ѧ(������ڶ��о���)"<<endl<<endl
      <<"���ݽṹ��Դ����(C++�廪��ѧ������)ħ�������汾: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}


#endif //CYBER_DASH_YUAN_STRING_H
