#!/bin/bash
#SBATCH --time=23:59:00
mkdir CG_EnergyIntoR60to63rangeNis200
./mainCGEnergy 5 494 100 60 63 0 494_bus.mtx >> CG_EnergyIntoR60to63rangeNis200/Energy60to63result_494_bus.txt
mkdir CG_EnergyIntoR60to63rangeNis400
./mainCGEnergy 5 494 200 60 63 0 494_bus.mtx >> CG_EnergyIntoR60to63rangeNis400/Energy60to63result_494_bus.txt
mkdir CG_EnergyIntoR60to63rangeNis600
./mainCGEnergy 5 494 300 60 63 0 494_bus.mtx >> CG_EnergyIntoR60to63rangeNis600/Energy60to63result_494_bus.txt
mkdir CG_EnergyIntoR60to63rangeNis800
./mainCGEnergy 5 494 400 60 63 0 494_bus.mtx >> CG_EnergyIntoR60to63rangeNis800/Energy60to63result_494_bus.txt
mkdir CG_EnergyIntoP60to63rangeNis200
./mainCGEnergy 5 494 100 60 63 1 494_bus.mtx >> CG_EnergyIntoP60to63rangeNis200/Energy60to63result_494_bus.txt
mkdir CG_EnergyIntoP60to63rangeNis400
./mainCGEnergy 5 494 200 60 63 1 494_bus.mtx >> CG_EnergyIntoP60to63rangeNis400/Energy60to63result_494_bus.txt
mkdir CG_EnergyIntoP60to63rangeNis600
./mainCGEnergy 5 494 300 60 63 1 494_bus.mtx >> CG_EnergyIntoP60to63rangeNis600/Energy60to63result_494_bus.txt
mkdir CG_EnergyIntoP60to63rangeNis800
./mainCGEnergy 5 494 400 60 63 1 494_bus.mtx >> CG_EnergyIntoP60to63rangeNis800/Energy60to63result_494_bus.txt
mkdir CG_EnergyIntoX60to63rangeNis200
./mainCGEnergy 5 494 100 60 63 2 494_bus.mtx >> CG_EnergyIntoX60to63rangeNis200/Energy60to63result_494_bus.txt
mkdir CG_EnergyIntoX60to63rangeNis400
./mainCGEnergy 5 494 200 60 63 2 494_bus.mtx >> CG_EnergyIntoX60to63rangeNis400/Energy60to63result_494_bus.txt
mkdir CG_EnergyIntoX60to63rangeNis600
./mainCGEnergy 5 494 300 60 63 2 494_bus.mtx >> CG_EnergyIntoX60to63rangeNis600/Energy60to63result_494_bus.txt
mkdir CG_EnergyIntoX60to63rangeNis800
./mainCGEnergy 5 494 400 60 63 2 494_bus.mtx >> CG_EnergyIntoX60to63rangeNis800/Energy60to63result_494_bus.txt
mkdir CG_EnergyIntoR56to59rangeNis200
./mainCGEnergy 5 494 100 56 59 0 494_bus.mtx >> CG_EnergyIntoR56to59rangeNis200/Energy56to63result_494_bus.txt
mkdir CG_EnergyIntoR56to59rangeNis400
./mainCGEnergy 5 494 200 56 59 0 494_bus.mtx >> CG_EnergyIntoR56to59rangeNis400/Energy56to63result_494_bus.txt
mkdir CG_EnergyIntoR56to59rangeNis600
./mainCGEnergy 5 494 300 56 59 0 494_bus.mtx >> CG_EnergyIntoR56to59rangeNis600/Energy56to63result_494_bus.txt
mkdir CG_EnergyIntoR56to59rangeNis800
./mainCGEnergy 5 494 400 56 59 0 494_bus.mtx >> CG_EnergyIntoR56to59rangeNis800/Energy56to63result_494_bus.txt
mkdir CG_EnergyIntoP56to59rangeNis200
./mainCGEnergy 5 494 100 56 59 1 494_bus.mtx >> CG_EnergyIntoP56to59rangeNis200/Energy56to63result_494_bus.txt
mkdir CG_EnergyIntoP56to59rangeNis400
./mainCGEnergy 5 494 200 56 59 1 494_bus.mtx >> CG_EnergyIntoP56to59rangeNis400/Energy56to63result_494_bus.txt
mkdir CG_EnergyIntoP56to59rangeNis600
./mainCGEnergy 5 494 300 56 59 1 494_bus.mtx >> CG_EnergyIntoP56to59rangeNis600/Energy56to63result_494_bus.txt
mkdir CG_EnergyIntoP56to59rangeNis800
./mainCGEnergy 5 494 400 56 59 1 494_bus.mtx >> CG_EnergyIntoP56to59rangeNis800/Energy56to63result_494_bus.txt
mkdir CG_EnergyIntoX56to59rangeNis200
./mainCGEnergy 5 494 100 56 59 2 494_bus.mtx >> CG_EnergyIntoX56to59rangeNis200/Energy56to63result_494_bus.txt
mkdir CG_EnergyIntoX56to59rangeNis400
./mainCGEnergy 5 494 200 56 59 2 494_bus.mtx >> CG_EnergyIntoX56to59rangeNis400/Energy56to63result_494_bus.txt
mkdir CG_EnergyIntoX56to59rangeNis600
./mainCGEnergy 5 494 300 56 59 2 494_bus.mtx >> CG_EnergyIntoX56to59rangeNis600/Energy56to63result_494_bus.txt
mkdir CG_EnergyIntoX56to59rangeNis800
./mainCGEnergy 5 494 400 56 59 2 494_bus.mtx >> CG_EnergyIntoX56to59rangeNis800/Energy56to63result_494_bus.txt
mkdir CG_EnergyIntoR52to55rangeNis200
./mainCGEnergy 5 494 100 52 55 0 494_bus.mtx >> CG_EnergyIntoR52to55rangeNis200/Energy52to55result_494_bus.txt
mkdir CG_EnergyIntoR52to55rangeNis400
./mainCGEnergy 5 494 200 52 55 0 494_bus.mtx >> CG_EnergyIntoR52to55rangeNis400/Energy52to55result_494_bus.txt
mkdir CG_EnergyIntoR52to55rangeNis600
./mainCGEnergy 5 494 300 52 55 0 494_bus.mtx >> CG_EnergyIntoR52to55rangeNis600/Energy52to55result_494_bus.txt
mkdir CG_EnergyIntoR52to55rangeNis800
./mainCGEnergy 5 494 400 52 55 0 494_bus.mtx >> CG_EnergyIntoR52to55rangeNis800/Energy52to55result_494_bus.txt
mkdir CG_EnergyIntoP52to55rangeNis200
./mainCGEnergy 5 494 100 52 55 1 494_bus.mtx >> CG_EnergyIntoP52to55rangeNis200/Energy52to55result_494_bus.txt
mkdir CG_EnergyIntoP52to55rangeNis400
./mainCGEnergy 5 494 200 52 55 1 494_bus.mtx >> CG_EnergyIntoP52to55rangeNis400/Energy52to55result_494_bus.txt
mkdir CG_EnergyIntoP52to55rangeNis600
./mainCGEnergy 5 494 300 52 55 1 494_bus.mtx >> CG_EnergyIntoP52to55rangeNis600/Energy52to55result_494_bus.txt
mkdir CG_EnergyIntoP52to55rangeNis800
./mainCGEnergy 5 494 400 52 55 1 494_bus.mtx >> CG_EnergyIntoP52to55rangeNis800/Energy52to55result_494_bus.txt
mkdir CG_EnergyIntoX52to55rangeNis200
./mainCGEnergy 5 494 100 52 55 2 494_bus.mtx >> CG_EnergyIntoX52to55rangeNis200/Energy52to55result_494_bus.txt
mkdir CG_EnergyIntoX52to55rangeNis400
./mainCGEnergy 5 494 200 52 55 2 494_bus.mtx >> CG_EnergyIntoX52to55rangeNis400/Energy52to55result_494_bus.txt
mkdir CG_EnergyIntoX52to55rangeNis600
./mainCGEnergy 5 494 300 52 55 2 494_bus.mtx >> CG_EnergyIntoX52to55rangeNis600/Energy52to55result_494_bus.txt
mkdir CG_EnergyIntoX52to55rangeNis800
./mainCGEnergy 5 494 400 52 55 2 494_bus.mtx >> CG_EnergyIntoX52to55rangeNis800/Energy52to55result_494_bus.txt
mkdir CG_EnergyIntoR48to51rangeNis200
./mainCGEnergy 5 494 100 48 51 0 494_bus.mtx >> CG_EnergyIntoR48to51rangeNis200/Energy48to51result_494_bus.txt
mkdir CG_EnergyIntoR48to51rangeNis400
./mainCGEnergy 5 494 200 48 51 0 494_bus.mtx >> CG_EnergyIntoR48to51rangeNis400/Energy48to51result_494_bus.txt
mkdir CG_EnergyIntoR48to51rangeNis600
./mainCGEnergy 5 494 300 48 51 0 494_bus.mtx >> CG_EnergyIntoR48to51rangeNis600/Energy48to51result_494_bus.txt
mkdir CG_EnergyIntoR48to51rangeNis800
./mainCGEnergy 5 494 400 48 51 0 494_bus.mtx >> CG_EnergyIntoR48to51rangeNis800/Energy48to51result_494_bus.txt
mkdir CG_EnergyIntoP48to51rangeNis200
./mainCGEnergy 5 494 100 48 51 1 494_bus.mtx >> CG_EnergyIntoP48to51rangeNis200/Energy48to51result_494_bus.txt
mkdir CG_EnergyIntoP48to51rangeNis400
./mainCGEnergy 5 494 200 48 51 1 494_bus.mtx >> CG_EnergyIntoP48to51rangeNis400/Energy48to51result_494_bus.txt
mkdir CG_EnergyIntoP48to51rangeNis600
./mainCGEnergy 5 494 300 48 51 1 494_bus.mtx >> CG_EnergyIntoP48to51rangeNis600/Energy48to51result_494_bus.txt
mkdir CG_EnergyIntoP48to51rangeNis800
./mainCGEnergy 5 494 400 48 51 1 494_bus.mtx >> CG_EnergyIntoP48to51rangeNis800/Energy48to51result_494_bus.txt
mkdir CG_EnergyIntoX48to51rangeNis200
./mainCGEnergy 5 494 100 48 51 2 494_bus.mtx >> CG_EnergyIntoX48to51rangeNis200/Energy48to51result_494_bus.txt
mkdir CG_EnergyIntoX48to51rangeNis400
./mainCGEnergy 5 494 200 48 51 2 494_bus.mtx >> CG_EnergyIntoX48to51rangeNis400/Energy48to51result_494_bus.txt
mkdir CG_EnergyIntoX48to51rangeNis600
./mainCGEnergy 5 494 300 48 51 2 494_bus.mtx >> CG_EnergyIntoX48to51rangeNis600/Energy48to51result_494_bus.txt
mkdir CG_EnergyIntoX48to51rangeNis800
./mainCGEnergy 5 494 400 48 51 2 494_bus.mtx >> CG_EnergyIntoX48to51rangeNis800/Energy48to51result_494_bus.txt
 