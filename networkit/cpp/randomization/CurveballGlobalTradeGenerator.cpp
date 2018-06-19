/*
 * CurveballGlobalTradeGenerator.cpp
 *
 *  Created on: Jul 11, 2017
 *      Author: Hung Tran <htran@ae.cs.uni-frankfurt.de>
 */

#include <cassert>
#include <algorithm>
#include <vector>

#include "CurveballGlobalTradeGenerator.h"

#include "../auxiliary/Random.h"

namespace NetworKit {

CurveballGlobalTradeGenerator::value_type CurveballGlobalTradeGenerator::generate() const {
    using node_vector = std::vector<node>;

    value_type _trades_out;
    _trades_out.reserve(_run_length * _trades_per_run);

    node_vector node_permutation(_num_nodes);
    for (node node_id = 0; node_id < _num_nodes; node_id++) {
        node_permutation[node_id] = node_id;
    }

    for (count run = 0; run < _run_length; run++) {
        // shuffling a shuffled node_permutation is okay, no need
        // to reinitialize it
        std::shuffle(node_permutation.begin(), node_permutation.end(),
                     Aux::Random::getURNG());

        auto rand_node_iter = node_permutation.cbegin();
        for (count t_id = 0; t_id < _trades_per_run; t_id++) {
            assert(rand_node_iter != node_permutation.cend());

            const node fst = *rand_node_iter;
            rand_node_iter++;
            const node snd = *rand_node_iter;
            rand_node_iter++;

            _trades_out.emplace_back(fst, snd);
        }
    }

    return _trades_out;
}

}
