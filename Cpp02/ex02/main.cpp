/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:03:00 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/13 13:40:24 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <limits>

#define GREEN "\033[1;32m"
#define RED   "\033[1;31m"
#define RESET "\033[0m"

void check(bool condition, const std::string &msg) {
    if (condition)
        std::cout << GREEN << "[PASS] " << RESET << msg << "\n";
    else
        std::cout << RED << "[FAIL] " << RESET << msg << "\n";
}

int main() {
    std::cout << "=== Constructors & Conversion ===\n";
    Fixed a;
    Fixed b(10);
    Fixed c(3.75f);
    Fixed d(b);
    Fixed e;
    e = c;

    check(a.getRawBits() == 0, "Default constructor a == 0");
    check(b.toInt() == 10, "Int constructor b == 10");
    check(fabs(c.toFloat() - 3.75f) < 1e-5, "Float constructor c == 3.75");
    check(d.toInt() == b.toInt(), "Copy constructor d == b");
    check(e.toFloat() == c.toFloat(), "Assignment operator e == c");

    std::cout << "\n=== Arithmetic Tests ===\n";
    Fixed f = b + c;
    Fixed g = b - c;
    Fixed h = b * c;
    Fixed i = b / c;

    std::cout << "i = " << i << std::endl;
    check(fabs(f.toFloat() - 13.75f) < __FLT_EPSILON__, "b + c == 13.75");
    check(fabs(g.toFloat() - 6.25f) < __FLT_EPSILON__, "b - c == 6.25");
    check(fabs(h.toFloat() - 37.5f) < __FLT_EPSILON__, "b * c == 37.5");
    check(fabs(i.toFloat() - 2.6666667f) < 0.005f, "b / c ≈ 2.666667");

    std::cout << "\n=== Comparison Operators ===\n";
    check(b > c, "b > c");
    check(!(b < c), "b < c");
    check(b >= d, "b >= d");
    check(b <= d, "b <= d");
    check(b == d, "b == d");
    check(b != c, "b != c");

    std::cout << "\n=== Increment / Decrement ===\n";
    Fixed inc(0);
    ++inc;
    check(inc.toFloat() == 0.00390625f, "++inc == 0.00390625");
    inc++;
    check(inc.toFloat() == 0.0078125f, "inc++ == 0.0078125");
    --inc;
    check(inc.toFloat() == 0.00390625f, "--inc == 0.00390625");
    inc--;
    check(inc.toFloat() == 0.0f, "inc-- == 0");

    std::cout << "\n=== Min / Max ===\n";
    Fixed k(3.3f), l(7.7f);
    check(Fixed::min(k,l).toFloat() == k.toFloat(), "min(k,l) == k");
    check(Fixed::max(k,l).toFloat() == l.toFloat(), "max(k,l) == l");

    Fixed m(4.398f), n(9.898f);
    check(Fixed::min(m,n).toFloat() == m.toFloat(), "min(m,n) == m");
    check(Fixed::max(m,n).toFloat() == n.toFloat(), "max(m,n) == n");

    // std::cout << "\n=== Divide by Zero ===\n";
    // Fixed zero(0);
    // try {
    //     Fixed divZero = b / zero;
    //     check(false, "b / 0 should throw");
    // } catch (...) {
    //     check(true, "b / 0 throws exception");
    // }

    std::cout << "\n=== Edge Cases ===\n";
    Fixed large(std::numeric_limits<int>::max() >> 8);
    Fixed small(1.0f / 256);
    Fixed sum = large + small;
    check(sum.toInt() == large.toInt() + 0, "Adding small fraction to large int preserves integer part");

    return 0;
}
