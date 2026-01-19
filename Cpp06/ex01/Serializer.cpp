/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 08:22:15 by mbousset          #+#    #+#             */
/*   Updated: 2025/12/02 08:54:40 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &copy) { (void)copy; }
Serializer &Serializer::operator=(const Serializer &copy)
{
  (void)copy;
  return (*this);
}
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr)
{
  return reinterpret_cast<uintptr_t>(ptr);
}
Data *Serializer::deserialize(uintptr_t raw)
{
  return (reinterpret_cast<Data *>(raw));
}