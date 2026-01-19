/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:25:12 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/20 20:17:05 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ------------------- Constructors ------------------- */

Brain::Brain() {
    std::cout << "Brain is constructed" << std::endl;
    for (int i = 0; i < 100; ++i)
        ideas[i] = "";
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain is copied" << std::endl;
    *this = other;
}

/* ------------------- Assignment Operator ------------------- */

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

/* ------------------- Destructor ------------------- */

Brain::~Brain() {
    std::cout << "Brain is destroyed" << std::endl;
}



// setters / getters

void Brain::setIdea(int index, const std::string &idea)
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}
