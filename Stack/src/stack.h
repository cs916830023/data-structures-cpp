/*!
 * @file stack.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ջ�����
 * @version 0.2.1
 * @date 2020-07-28
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#ifndef CYBER_DASH_STACK_H
#define CYBER_DASH_STACK_H


/*!
 * @brief ջ�����
 * @tparam T ����ģ�����
 */
template<class T>
class Stack {
public:
  /*!
   * @brief ��ջ
   * @param data ����
   */
  virtual void Push(const T& data) = 0;

  /*!
   * @brief ��ջ(��������)
   * @param data ����(����������)
   * @return �Ƿ�ɹ�
   */
  virtual bool Pop(T& data) = 0;

  /*!
   * @brief ��ȡջ������
   * @param data ����(����������)
   * @return �Ƿ�ɹ�
   */
  virtual bool GetTop(T& data) const = 0;

  /*!
   * @brief �Ƿ�Ϊ��
   * @return �Ƿ�Ϊ��
   */
  virtual bool IsEmpty() const = 0;

  /*!
   * @brief ��ȡ��С
   * @return ��С
   */
  virtual int GetSize() const = 0;
};


#endif //CYBER_DASH_STACK_H
