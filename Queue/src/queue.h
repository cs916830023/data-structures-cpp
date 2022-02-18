/*!
 * @file queue.h
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief ���������
 * @version 0.2.1
 * @date 2021-07-14
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#ifndef CYBER_DASH_QUEUE_H
#define CYBER_DASH_QUEUE_H


/*!
 * @brief ���������
 * @tparam T ����ģ�����
 */
template<class T>
class Queue {
public:
   /*!
   * @brief ���
   * @param data ��ӽڵ��ֵ
   * @return �Ƿ��ȡ�ɹ�
   */
  virtual bool EnQueue(const T& data) = 0;

   /*!
   * @brief ����
   * @param data ���ӽڵ��ֵ
   * @return �Ƿ��ȡ�ɹ�
   */
  virtual bool DeQueue(T& data) = 0;

   /*!
   * @brief ��ȡͷ�ڵ�
   * @param data ͷ�ڵ��ֵ
   * @return �Ƿ��ȡ�ɹ�
   */
  virtual bool GetFront(T& data) const = 0;

   /*!
   * @brief �����Ƿ�Ϊ��
   * @return �Ƿ�Ϊ��
   */
  virtual bool IsEmpty() const = 0;

   /*!
   * @brief ��ȡ���г���
   * @return ���г���
   */
  virtual int GetSize() const = 0;
};


#endif //CYBER_DASH_QUEUE_H