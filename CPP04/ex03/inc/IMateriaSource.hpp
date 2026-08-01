/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 21:42:07 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/04 04:33:18 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "AMateria.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <string>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class IMateriaSource
 * @brief Interface for MateriaSource objects.
 * @details Pure abstract class defining the contract for learning and creating 
 * Materias (Prototype pattern). Exempt from Orthodox Canonical Form.
 */
class IMateriaSource
{
    public:
        /* ------------------------------------------------------------------ */
        /* DESTRUCTORS                                                        */
        /* ------------------------------------------------------------------ */
        virtual ~IMateriaSource(void) {}

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        virtual void      learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
