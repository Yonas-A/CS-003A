#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>

using namespace std;

class Rational {
   public:
    /**
    * @brief a defult constructor that initializes Rational::_n to zero and 
    * Rational::_d to 1
    */
    Rational();

    /**
    * @brief a constructor that initializes Rational::_n and Rational::_d to the
    * given values
    * @param num the numerator for the rational number
    * @param denom the denominator for the rational number
    */
    Rational(int num, int denom);

    /**
    * @brief a ctor that initializes Rational::_n to w and Rational::_d to
    * 1
    * @param w the numerator for the rational number
    */
    Rational(int w);

    /**
     * Sets the Rational::_n to num and Rational::_d to denom
     * @param num the numerator for the rational number
     * @param denom the denominator for the rational number
     */
    void set(int num, int denom);

    /**
     * Sets the Rational::_n to num
     * @param num the numerator for the rational number
     */
    void set_num(int num);

    /**
     * Sets the Rational::_d to denom
     * @param denom the denominator for the rational number
     */
    void set_denom(int denom);

    /**
     * @returns Rational::_n
     */
    int get_num() const;
    /**
     * @returns Rational::_d
     */
    int get_denom() const;

    /**
     * @returns the error state of the Rational
     */
    int error() const;  // returns error state
    /**
     * @brief checks if the Rational is in error state
     * @returns the error code for the Rational error
     */
    int is_error();

    /**
     * @returns a brief explanation about the error
     */
    string error_description();

    /**
     * @brief resets the Rational::_n to 0, Rational::_d to 1 and 
     * Rational::_error to 0.
     */
    void clear();

    /**
     * @brief adds two Rational.
     * @param num1 the first Rational to be added.
     * @param num2 the second Rational to be added.
     * @returns a Rational with the sum of the two Rationals or a Rational
     * whose error state is set if one of the Rationals is in error state.
     */
    friend Rational operator+(const Rational &num1, const Rational &num2);

    /**
     * @brief subtracts the second Rational from the first Rational.
     * @param num1 the Rational to subtact from.
     * @param num2 the Rational to be subtracted.
     * @returns a Rational with the difference of the two Rationals or a Rational
     * whose error state is set if one of the Rationals is in error state.
     */
    friend Rational operator-(const Rational &num1, const Rational &num2);

    /**
     * @brief multiplies the first Rational with the second Rational.
     * @param num1 the Rational to be multiplied.
     * @param num2 the Rational multiplier.
     * @returns a Rational with the multiple of the two Rationals or a Rational
     * whose error state is set if one of the Rationals is in error state.
     */
    friend Rational operator*(const Rational &num1, const Rational &num2);

    /**
     * @brief divides the first Rational with the second Rational.
     * @param num1 the Rational to be divided.
     * @param num2 the Rational divisor.
     * @returns a Rational with the quotient of the two Rationals or a Rational
     * whose error state is set if one of the Rationals is in error state.
     */
    friend Rational operator/(const Rational &num1, const Rational &num2);

    /**
     * @brief prints the Rational::num to console, or UNDEFINED if Rations is
     * in error state
     * @param outs an ostream operator
     * @param num the Rational to be printed to console
     * @returns an ostream operator
     */
    friend ostream &operator<<(ostream &outs, const Rational &num);
    friend istream &operator>>(istream &ins, Rational &num);

   private:
    int _n;      // numerator
    int _d;      // denominator
    int _error;  // error number
};

#endif  // RATIONAL_H
