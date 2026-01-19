/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 08:47:56 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/02 09:04:18 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
  // Basic test
  Data data;
  data.n = 42;
  data.str = "Hello, World!";

  std::cout << "=== Basic Test ===\n";
  uintptr_t raw = Serializer::serialize(&data);
  Data *deserialized = Serializer::deserialize(raw);

  std::cout << "Original:     n = " << data.n << ", str = " << data.str << "\n";
  std::cout << "Deserialized: n = " << deserialized->n
            << ", str = " << deserialized->str << "\n\n";

  // Check if both pointers refer to the same memory
  std::cout << "Pointer check: "
            << (deserialized == &data ? "OK (same address)" : "FAIL")
            << "\n\n";

  // Modify through deserialized pointer
  std::cout << "=== Mutability Test ===\n";
  deserialized->n = 1337;
  deserialized->str = "Modified";

  std::cout << "After modification through deserialized pointer:\n";
  std::cout << "data.n = " << data.n << ", data.str = " << data.str << "\n\n";

  // Multiple objects test
  std::cout << "=== Multiple Serialization Test ===\n";
  Data d1 = {1, "One"};
  Data d2 = {2, "Two"};

  uintptr_t r1 = Serializer::serialize(&d1);
  uintptr_t r2 = Serializer::serialize(&d2);

  Data *p1 = Serializer::deserialize(r1);
  Data *p2 = Serializer::deserialize(r2);

  std::cout << "d1 -> n=" << p1->n << ", str=" << p1->str << "\n";
  std::cout << "d2 -> n=" << p2->n << ", str=" << p2->str << "\n\n";

  // Null test (if your serializer handles or prohibits null)
  std::cout << "=== Null Pointer Test ===\n";
  uintptr_t nullRaw = Serializer::serialize(NULL);
  Data *nullPtr = Serializer::deserialize(nullRaw);

  std::cout << "Serialize(NULL) -> " << nullRaw << "\n";
  std::cout << "Deserialize(NULL) -> " << nullPtr << "\n";

  return 0;
}
