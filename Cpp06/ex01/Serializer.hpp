/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 08:22:46 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/02 09:54:02 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_CPP
#define SERIALIZER_CPP

#include <iostream>
#include <stdint.h>

struct Data
{
  int n;
  std::string str;
};

class Serializer
{
private:
  Serializer();
  Serializer(const Serializer &copy);
  Serializer &operator=(const Serializer &copy);
  ~Serializer();

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif