/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 03:45:04 by maaugust          #+#    #+#             */
/*   Updated: 2026/08/24 03:22:49 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
#include <algorithm>
#include <iterator>

/* ========================================================================== */
/* PRIVATE TEMPLATE METHODS                                                   */
/* ========================================================================== */

/**
 * @fn void PmergeMe::_fordJohnsonMergeInsert(Container& container, size_t chunk_size)
 * @brief Recursively pairs and sorts memory chunks based on winner comparisons.
 * @details Implements the recursive pairing phase of the algorithm without 
 * allocating nested arrays. It groups elements conceptually using 
 * 'chunk_size', compares the "winner" (the last element) of adjacent chunks, 
 * and uses std::swap_ranges to sort the chunks. Upon recursion return, it 
 * splits the newly ordered chunks into a mainChain (winners) and a pendChain 
 * (losers) before passing them to the insertion phase.
 * @param container  The STL container (std::vector or std::deque) being sorted.
 * @param chunk_size The current size of the paired blocks being evaluated.
 */
template <typename Container>
void PmergeMe::_fordJohnsonMergeInsert(Container& container, size_t chunk_size)
{
    if (container.size() / chunk_size < 2)
        return;

    typename Container::iterator it = container.begin();
    typename Container::iterator ite = container.end();

    for (; static_cast<size_t>(std::distance(it, ite)) >= 2 * chunk_size; std::advance(it, 2 * chunk_size))
    {
        if (*(it + chunk_size - 1) > *(it + 2 * chunk_size - 1))
            std::swap_ranges(it, it + chunk_size, it + chunk_size);
    }

    _fordJohnsonMergeInsert(container, chunk_size * 2);

    Container mainChain;
    Container pendChain;

    it = container.begin();
    ite = container.end();

    mainChain.insert(mainChain.end(), it, it + 2 * chunk_size);
    for (std::advance(it, 2 * chunk_size); static_cast<size_t>(std::distance(it, ite)) >= 2 * chunk_size; std::advance(it, 2 * chunk_size))
    {
        pendChain.insert(pendChain.end(), it, it + chunk_size);
        mainChain.insert(mainChain.end(), it + chunk_size, it + 2 * chunk_size);
    }
    if (it != ite)
        pendChain.insert(pendChain.end(), it, ite);

    _jacobsthalInsert(mainChain, pendChain, chunk_size);

    container = mainChain;
}

/**
 * @fn void PmergeMe::_jacobsthalInsert(Container& mainChain, Container const & pendChain, size_t chunk_size)
 * @brief Inserts pending chunks into the main chain using optimal binary 
 * search boundaries.
 * @details Employs the Jacobsthal sequence to generate optimal insertion 
 * batches with a custom, chunk-aware binary search. Dynamically limits the 
 * binary search space using powers-of-two boundaries ((1 << batch_k) - 1) to 
 * guarantee worst-case comparison counts remain within Knuth's strict 
 * mathematical budget. Properly handles unpaired straggler integers by safely 
 * appending them at the end.
 * @param mainChain  The sequence of sorted winner chunks.
 * @param pendChain  The sequence of pending loser chunks to be inserted.
 * @param chunk_size The current physical size of the memory chunks being 
 * evaluated.
 */
template <typename Container>
void PmergeMe::_jacobsthalInsert(Container& mainChain, Container const & pendChain, size_t chunk_size)
{
    size_t pend_chunks = pendChain.size() / chunk_size;

    if (pend_chunks > 0)
    {
        for (size_t batch_k = 2, prev_jacob = 1, curr_jacob = 3; prev_jacob < pend_chunks + 1; ++batch_k)
        {
            size_t max_elements = (1 << batch_k) - 1;

            for (size_t b_index = (curr_jacob > pend_chunks + 1 ? pend_chunks + 1 : curr_jacob); b_index > prev_jacob; --b_index)
            {
                size_t pend_index = b_index - 2;
                size_t main_chunks = mainChain.size() / chunk_size;

                size_t low = 0;
                size_t high = (max_elements > main_chunks ? main_chunks : max_elements);
                while (low < high)
                {
                    size_t mid = low + (high - low) / 2;
                    size_t pend_winner = (pend_index * chunk_size) + (chunk_size - 1);
                    size_t main_winner = (mid * chunk_size) + (chunk_size - 1);

                    if (pendChain.at(pend_winner) < mainChain.at(main_winner))
                        high = mid;
                    else
                        low = mid + 1;
                }

                mainChain.insert(mainChain.begin() + (low * chunk_size),
                                 pendChain.begin() + (pend_index * chunk_size),
                                 pendChain.begin() + ((1 + pend_index) * chunk_size));
            }

            size_t next_jacob = 2 * prev_jacob + curr_jacob;
            prev_jacob = curr_jacob;
            curr_jacob = next_jacob;
        }
    }

    size_t processed_pend_elements = pend_chunks * chunk_size;
    if (processed_pend_elements < pendChain.size())
        mainChain.insert(mainChain.end(), pendChain.begin() + processed_pend_elements, pendChain.end());
}
