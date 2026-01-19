/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:03:00 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/13 18:11:23 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Terminal colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

// Tolerance-based check for floats
void check(bool condition, const char* testName) {
    if (condition)
        std::cout << GREEN << "[PASS] " << testName << RESET << std::endl;
    else
        std::cout << RED << "[FAIL] " << testName << RESET << std::endl;
}

int main() {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    Point inside1(2.5f, 2.0f);
    Point inside2(2.0f, 1.0f);
    Point outside1(-1.0f, 2.0f);
    Point outside2(5.0f, 5.0f);
    Point edge(2.5f, 0.0f); // On the edge

    std::cout << "=== BSP Triangle Tests ===\n";

    check(bsp(a, b, c, inside1), "inside1 is inside the triangle");
    check(bsp(a, b, c, inside2), "inside2 is inside the triangle");
    check(!bsp(a, b, c, outside1), "outside1 is outside the triangle");
    check(!bsp(a, b, c, outside2), "outside2 is outside the triangle");
    check(bsp(a, b, c, edge), "edge point is considered inside the triangle");

    return 0;
}
