/*
 * GMLGraphWriter.cpp
 *
 *  Created on: 05.08.2013
 *      Author: Stefan Bertsch
 */

#include "GMLGraphWriter.h"
#include "../auxiliary/Enforce.h"

namespace NetworKit {

void GMLGraphWriter::write(Graph& G, const std::string& path) {
	std::ofstream file(path);
	Aux::enforceOpened(file);
	
	file << "graph [\n";
	if (G.isDirected()) {
		file << "  directed 1\n";
	}
	
	G.forNodes([&](node u) {
		file << "  node [\n";
		file << "    id " << u << "\n";
                file << "  ]\n";
	});
		
	G.forEdges([&](node u, node v) {
			file << "  edge [\n";
			file << "    source "<< u << "\n";
			file << "    target "<< v << "\n";
			file << "  ]\n";
	});
	file << "]\n";
}

} /* namespace NetworKit */
