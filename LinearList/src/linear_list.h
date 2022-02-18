/*!
 * @file linear_list.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ���Ա����ģ�����
 * @version 0.2.1
 * @date 2020-06-06
 * @copyright Copyright (c) 2021
 * **CyberDash���������**
 */

#ifndef CYBER_DASH_LINEAR_LIST_H
#define CYBER_DASH_LINEAR_LIST_H


/*!
 * @brief ���Ա�������
 * @tparam T ����ģ�����
 */
template <class T>
class LinearList {
public:
  /*!
   * @brief ��ȡ����
   * @return ���Ա���
   */
  virtual int Length() const = 0;

  /*!
   * @brief ��ȡ��pos������������
   * @param pos ��pos��
   * @param data ������(���ڱ�����)
   * @return �Ƿ��ȡ�ɹ�
   */
  virtual bool GetData(int pos, T& data) const = 0;

  /*!
   * @brief ���õ�pos������������
   * @param pos ��pos��
   * @param data ������
   * @return
   */
  virtual bool SetData(int pos, const T& data) = 0;

  /*!
   * @brief �ڵ�pos��Ԫ��֮��, ��������
   * @param pos λ��pos
   * @param data ������ֵ
   * @return �Ƿ�ɹ�
   * @note
   * ����������, ��1��ʼ\n
   * ��posΪ0ʱ, ��ʾ����λ��1
   */
  virtual bool Insert(int pos, const T& data) = 0;

  /*!
   * @brief ɾ����pos��Ԫ��
   * @param pos λ��pos
   * @param data ������ֵ(���汻ɾ����Ԫ��������)
   * @return �Ƿ�ɹ�
   */
  virtual bool Remove(int pos, T& data) = 0;

  /*!
   * @brief �ж��Ƿ�Ϊ��
   * @return �Ƿ�Ϊ��
   */
  virtual bool IsEmpty() const = 0;

  /*!
   * @brief ��ӡ���Ա�
   */
  virtual void Output() = 0;
};


#endif // CYBER_DASH_LINEAR_LIST_H
