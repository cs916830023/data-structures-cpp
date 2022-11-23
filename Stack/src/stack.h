﻿/*!
 * @file stack.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 栈虚基类
 * @version 0.2.1
 * @date 2020-07-28
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_STACK_H
#define CYBER_DASH_STACK_H


 /*!
  * @brief 栈虚基类
  * @tparam TData 类型模板参数
  */
template<typename TData>
class Stack {
public:
	/*!
	 * @brief 入栈
	 * @param data 数据
	 */
	virtual bool Push(const TData& data) = 0;

	/*!
	 * @brief 出栈(保存数据)
	 * @param data 数据(保存数据项)
	 * @return 是否成功
	 */
	virtual bool Pop(TData& data) = 0;

	/*!
	 * @brief 获取栈顶数据
	 * @param data 数据(保存数据项)
	 * @return 是否成功
	 */
	virtual bool Top(TData& data) const = 0;

	/*!
	 * @brief 是否为空
	 * @return 是否为空
	 */
	virtual bool IsEmpty() const = 0;

	/*!
	 * @brief 获取大小
	 * @return 大小
	 */
	virtual int Length() const = 0;
};


#endif //CYBER_DASH_STACK_H
