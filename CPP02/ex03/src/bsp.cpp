/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 00:57:21 by maaugust          #+#    #+#             */
/*   Updated: 2026/07/30 02:38:20 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
#include "Point.hpp"

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

/**
 * @fn bool bsp(Point const a, Point const b, Point const c, Point const point)
 * @brief Determines if a point is inside a triangle.
 * @details Uses Binary Space Partitioning (BSP) math to check if the given 
 * point resides strictly inside the triangle defined by vertices a, b, and c.
 * @param a     First vertex of the triangle.
 * @param b     Second vertex of the triangle.
 * @param c     Third vertex of the triangle.
 * @param point The point to check.
 * @return      True if the point is strictly inside the triangle, 
 * false otherwise.
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed const x[4] = {a.getX(), b.getX(), c.getX(), point.getX()};
    Fixed const y[4] = {a.getY(), b.getY(), c.getY(), point.getY()};
    Fixed const cross[3] = {(x[1] - x[0]) * (y[3] - y[0]) - (y[1] - y[0]) * (x[3] - x[0]),
                            (x[2] - x[1]) * (y[3] - y[1]) - (y[2] - y[1]) * (x[3] - x[1]),
                            (x[0] - x[2]) * (y[3] - y[2]) - (y[0] - y[2]) * (x[3] - x[2])};

    bool has_zero = (cross[0] == 0 || cross[1] == 0 || cross[2] == 0);
    bool has_neg = (cross[0] < 0 || cross[1] < 0 || cross[2] < 0);
    bool has_pos = (cross[0] > 0 || cross[1] > 0 || cross[2] > 0);

    return has_zero ? false : !(has_neg && has_pos);
}
