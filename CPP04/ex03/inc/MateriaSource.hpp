/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 01:33:16 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/05 03:46:04 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

/* --------------------------- Internal Libraries --------------------------- */
#include <string>

/* ========================================================================== */
/* CLASSES                                                                    */
/* ========================================================================== */

/**
 * @class MateriaSource
 * @brief Concrete implementation of the IMateriaSource interface.
 * @details Acts as a factory utilizing the Prototype pattern. Stores up to 4 
 * learned Materia blueprints and can clone them on demand based on their type.
 */
class MateriaSource : public IMateriaSource
{
    private:
        /* ------------------------------------------------------------------ */
        /* CONSTANTS & SETTINGS                                               */
        /* ------------------------------------------------------------------ */
        static int const _maxMaterias = 4;

        /* ------------------------------------------------------------------ */
        /* PRIVATE ATTRIBUTES                                                 */
        /* ------------------------------------------------------------------ */
        AMateria* _materias[_maxMaterias];

    public:
        /* ------------------------------------------------------------------ */
        /* CONSTRUCTORS & DESTRUCTORS                                         */
        /* ------------------------------------------------------------------ */
        MateriaSource(void);
        MateriaSource(MateriaSource const & other);
        virtual ~MateriaSource(void);

        /* ------------------------------------------------------------------ */
        /* OPERATOR OVERLOADS                                                 */
        /* ------------------------------------------------------------------ */
        MateriaSource& operator=(MateriaSource const & other);

        /* ------------------------------------------------------------------ */
        /* PUBLIC METHODS                                                     */
        /* ------------------------------------------------------------------ */
        void      learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);
};

#endif
