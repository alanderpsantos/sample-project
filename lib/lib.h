/**
 * \file lib.h
 * \brief a brief description
 */

#ifndef MY_LIB_H_
#define MY_LIB_H_

/**
 * \brief sum lhs to rhs
 *
 * \param lhs first operand
 * \param rhs second operand
 * \return the sum between lhs and rhs
 */
[[nodiscard]] const int add(int const lhs, int const rhs);

/**
 * \brief sub lhs from rhs
 *
 * \param lhs first operand
 * \param rhs second operand
 * \return the sum between lhs and rhs
 */
[[nodiscard]] const int sub(int const lhs, int const rhs);

/**
 * \brief verify 
 *
 * \param lhs first operand
 * \param rhs second operand
 * \return the sum between lhs and rhs
 */
[[nodiscard]] const int verify(int const lhs, int const rhs);
/**
 * @example int x = foo(10);
 */
#endif