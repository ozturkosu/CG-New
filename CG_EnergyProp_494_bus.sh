#!/bin/bash
#SBATCH --time=23:59:00
mkdir CG_EnergyIntoR60to63rangeNis200
./mainCGEnergy2 5 494 100 60 63 0 494_bus.mtx >> CG_EnergyIntoR60to63rangeNis200/EnergyWithProposed60to63result_494_bus.txt
mkdir CG_EnergyIntoR60to63rangeNis400
./mainCGEnergy2 5 494 200 60 63 0 494_bus.mtx >> CG_EnergyIntoR60to63rangeNis400/EnergyWithProposed60to63result_494_bus.txt
mkdir CG_EnergyIntoR60to63rangeNis600
./mainCGEnergy2 5 494 300 60 63 0 494_bus.mtx >> CG_EnergyIntoR60to63rangeNis600/EnergyWithProposed60to63result_494_bus.txt
mkdir CG_EnergyIntoR60to63rangeNis800
./mainCGEnergy2 5 494 400 60 63 0 494_bus.mtx >> CG_EnergyIntoR60to63rangeNis800/EnergyWithProposed60to63result_494_bus.txt
mkdir CG_EnergyIntoP60to63rangeNis200
./mainCGEnergy2 5 494 100 60 63 1 494_bus.mtx >> CG_EnergyIntoP60to63rangeNis200/EnergyWithProposed60to63result_494_bus.txt
mkdir CG_EnergyIntoP60to63rangeNis400
./mainCGEnergy2 5 494 200 60 63 1 494_bus.mtx >> CG_EnergyIntoP60to63rangeNis400/EnergyWithProposed60to63result_494_bus.txt
mkdir CG_EnergyIntoP60to63rangeNis600
./mainCGEnergy2 5 494 300 60 63 1 494_bus.mtx >> CG_EnergyIntoP60to63rangeNis600/EnergyWithProposed60to63result_494_bus.txt
mkdir CG_EnergyIntoP60to63rangeNis800
./mainCGEnergy2 5 494 400 60 63 1 494_bus.mtx >> CG_EnergyIntoP60to63rangeNis800/EnergyWithProposed60to63result_494_bus.txt
mkdir CG_EnergyIntoX60to63rangeNis200
./mainCGEnergy2 5 494 100 60 63 2 494_bus.mtx >> CG_EnergyIntoX60to63rangeNis200/EnergyWithProposed60to63result_494_bus.txt
mkdir CG_EnergyIntoX60to63rangeNis400
./mainCGEnergy2 5 494 200 60 63 2 494_bus.mtx >> CG_EnergyIntoX60to63rangeNis400/EnergyWithProposed60to63result_494_bus.txt
mkdir CG_EnergyIntoX60to63rangeNis600
./mainCGEnergy2 5 494 300 60 63 2 494_bus.mtx >> CG_EnergyIntoX60to63rangeNis600/EnergyWithProposed60to63result_494_bus.txt
mkdir CG_EnergyIntoX60to63rangeNis800
./mainCGEnergy2 5 494 400 60 63 2 494_bus.mtx >> CG_EnergyIntoX60to63rangeNis800/EnergyWithProposed60to63result_494_bus.txt
mkdir CG_EnergyIntoR56to59rangeNis200
./mainCGEnergy2 5 494 100 56 59 0 494_bus.mtx >> CG_EnergyIntoR56to59rangeNis200/EnergyWithProposed56to63result_494_bus.txt
mkdir CG_EnergyIntoR56to59rangeNis400
./mainCGEnergy2 5 494 200 56 59 0 494_bus.mtx >> CG_EnergyIntoR56to59rangeNis400/EnergyWithProposed56to63result_494_bus.txt
mkdir CG_EnergyIntoR56to59rangeNis600
./mainCGEnergy2 5 494 300 56 59 0 494_bus.mtx >> CG_EnergyIntoR56to59rangeNis600/EnergyWithProposed56to63result_494_bus.txt
mkdir CG_EnergyIntoR56to59rangeNis800
./mainCGEnergy2 5 494 400 56 59 0 494_bus.mtx >> CG_EnergyIntoR56to59rangeNis800/EnergyWithProposed56to63result_494_bus.txt
mkdir CG_EnergyIntoP56to59rangeNis200
./mainCGEnergy2 5 494 100 56 59 1 494_bus.mtx >> CG_EnergyIntoP56to59rangeNis200/EnergyWithProposed56to63result_494_bus.txt
mkdir CG_EnergyIntoP56to59rangeNis400
./mainCGEnergy2 5 494 200 56 59 1 494_bus.mtx >> CG_EnergyIntoP56to59rangeNis400/EnergyWithProposed56to63result_494_bus.txt
mkdir CG_EnergyIntoP56to59rangeNis600
./mainCGEnergy2 5 494 300 56 59 1 494_bus.mtx >> CG_EnergyIntoP56to59rangeNis600/EnergyWithProposed56to63result_494_bus.txt
mkdir CG_EnergyIntoP56to59rangeNis800
./mainCGEnergy2 5 494 400 56 59 1 494_bus.mtx >> CG_EnergyIntoP56to59rangeNis800/EnergyWithProposed56to63result_494_bus.txt
mkdir CG_EnergyIntoX56to59rangeNis200
./mainCGEnergy2 5 494 100 56 59 2 494_bus.mtx >> CG_EnergyIntoX56to59rangeNis200/EnergyWithProposed56to63result_494_bus.txt
mkdir CG_EnergyIntoX56to59rangeNis400
./mainCGEnergy2 5 494 200 56 59 2 494_bus.mtx >> CG_EnergyIntoX56to59rangeNis400/EnergyWithProposed56to63result_494_bus.txt
mkdir CG_EnergyIntoX56to59rangeNis600
./mainCGEnergy2 5 494 300 56 59 2 494_bus.mtx >> CG_EnergyIntoX56to59rangeNis600/EnergyWithProposed56to63result_494_bus.txt
mkdir CG_EnergyIntoX56to59rangeNis800
./mainCGEnergy2 5 494 400 56 59 2 494_bus.mtx >> CG_EnergyIntoX56to59rangeNis800/EnergyWithProposed56to63result_494_bus.txt
mkdir CG_EnergyIntoR52to55rangeNis200
./mainCGEnergy2 5 494 100 52 55 0 494_bus.mtx >> CG_EnergyIntoR52to55rangeNis200/EnergyWithProposed52to55result_494_bus.txt
mkdir CG_EnergyIntoR52to55rangeNis400
./mainCGEnergy2 5 494 200 52 55 0 494_bus.mtx >> CG_EnergyIntoR52to55rangeNis400/EnergyWithProposed52to55result_494_bus.txt
mkdir CG_EnergyIntoR52to55rangeNis600
./mainCGEnergy2 5 494 300 52 55 0 494_bus.mtx >> CG_EnergyIntoR52to55rangeNis600/EnergyWithProposed52to55result_494_bus.txt
mkdir CG_EnergyIntoR52to55rangeNis800
./mainCGEnergy2 5 494 400 52 55 0 494_bus.mtx >> CG_EnergyIntoR52to55rangeNis800/EnergyWithProposed52to55result_494_bus.txt
mkdir CG_EnergyIntoP52to55rangeNis200
./mainCGEnergy2 5 494 100 52 55 1 494_bus.mtx >> CG_EnergyIntoP52to55rangeNis200/EnergyWithProposed52to55result_494_bus.txt
mkdir CG_EnergyIntoP52to55rangeNis400
./mainCGEnergy2 5 494 200 52 55 1 494_bus.mtx >> CG_EnergyIntoP52to55rangeNis400/EnergyWithProposed52to55result_494_bus.txt
mkdir CG_EnergyIntoP52to55rangeNis600
./mainCGEnergy2 5 494 300 52 55 1 494_bus.mtx >> CG_EnergyIntoP52to55rangeNis600/EnergyWithProposed52to55result_494_bus.txt
mkdir CG_EnergyIntoP52to55rangeNis800
./mainCGEnergy2 5 494 400 52 55 1 494_bus.mtx >> CG_EnergyIntoP52to55rangeNis800/EnergyWithProposed52to55result_494_bus.txt
mkdir CG_EnergyIntoX52to55rangeNis200
./mainCGEnergy2 5 494 100 52 55 2 494_bus.mtx >> CG_EnergyIntoX52to55rangeNis200/EnergyWithProposed52to55result_494_bus.txt
mkdir CG_EnergyIntoX52to55rangeNis400
./mainCGEnergy2 5 494 200 52 55 2 494_bus.mtx >> CG_EnergyIntoX52to55rangeNis400/EnergyWithProposed52to55result_494_bus.txt
mkdir CG_EnergyIntoX52to55rangeNis600
./mainCGEnergy2 5 494 300 52 55 2 494_bus.mtx >> CG_EnergyIntoX52to55rangeNis600/EnergyWithProposed52to55result_494_bus.txt
mkdir CG_EnergyIntoX52to55rangeNis800
./mainCGEnergy2 5 494 400 52 55 2 494_bus.mtx >> CG_EnergyIntoX52to55rangeNis800/EnergyWithProposed52to55result_494_bus.txt
mkdir CG_EnergyIntoR48to51rangeNis200
./mainCGEnergy2 5 494 100 48 51 0 494_bus.mtx >> CG_EnergyIntoR48to51rangeNis200/EnergyWithProposed48to51result_494_bus.txt
mkdir CG_EnergyIntoR48to51rangeNis400
./mainCGEnergy2 5 494 200 48 51 0 494_bus.mtx >> CG_EnergyIntoR48to51rangeNis400/EnergyWithProposed48to51result_494_bus.txt
mkdir CG_EnergyIntoR48to51rangeNis600
./mainCGEnergy2 5 494 300 48 51 0 494_bus.mtx >> CG_EnergyIntoR48to51rangeNis600/EnergyWithProposed48to51result_494_bus.txt
mkdir CG_EnergyIntoR48to51rangeNis800
./mainCGEnergy2 5 494 400 48 51 0 494_bus.mtx >> CG_EnergyIntoR48to51rangeNis800/EnergyWithProposed48to51result_494_bus.txt
mkdir CG_EnergyIntoP48to51rangeNis200
./mainCGEnergy2 5 494 100 48 51 1 494_bus.mtx >> CG_EnergyIntoP48to51rangeNis200/EnergyWithProposed48to51result_494_bus.txt
mkdir CG_EnergyIntoP48to51rangeNis400
./mainCGEnergy2 5 494 200 48 51 1 494_bus.mtx >> CG_EnergyIntoP48to51rangeNis400/EnergyWithProposed48to51result_494_bus.txt
mkdir CG_EnergyIntoP48to51rangeNis600
./mainCGEnergy2 5 494 300 48 51 1 494_bus.mtx >> CG_EnergyIntoP48to51rangeNis600/EnergyWithProposed48to51result_494_bus.txt
mkdir CG_EnergyIntoP48to51rangeNis800
./mainCGEnergy2 5 494 400 48 51 1 494_bus.mtx >> CG_EnergyIntoP48to51rangeNis800/EnergyWithProposed48to51result_494_bus.txt
mkdir CG_EnergyIntoX48to51rangeNis200
./mainCGEnergy2 5 494 100 48 51 2 494_bus.mtx >> CG_EnergyIntoX48to51rangeNis200/EnergyWithProposed48to51result_494_bus.txt
mkdir CG_EnergyIntoX48to51rangeNis400
./mainCGEnergy2 5 494 200 48 51 2 494_bus.mtx >> CG_EnergyIntoX48to51rangeNis400/EnergyWithProposed48to51result_494_bus.txt
mkdir CG_EnergyIntoX48to51rangeNis600
./mainCGEnergy2 5 494 300 48 51 2 494_bus.mtx >> CG_EnergyIntoX48to51rangeNis600/EnergyWithProposed48to51result_494_bus.txt
mkdir CG_EnergyIntoX48to51rangeNis800
./mainCGEnergy2 5 494 400 48 51 2 494_bus.mtx >> CG_EnergyIntoX48to51rangeNis800/EnergyWithProposed48to51result_494_bus.txt
 