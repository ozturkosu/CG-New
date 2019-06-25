#!/bin/bash
#SBATCH --time=23:59:00
mkdir CG_EnergyIntoR60to63rangeNis200
./mainCGEnergy 5 1138 220 60 63 0 1138_bus.mtx >> CG_EnergyIntoR60to63rangeNis200/Energy60to63result_1138_bus.txt
mkdir CG_EnergyIntoR60to63rangeNis400
./mainCGEnergy 5 1138 440 60 63 0 1138_bus.mtx >> CG_EnergyIntoR60to63rangeNis400/Energy60to63result_1138_bus.txt
mkdir CG_EnergyIntoR60to63rangeNis600
./mainCGEnergy 5 1138 660 60 63 0 1138_bus.mtx >> CG_EnergyIntoR60to63rangeNis600/Energy60to63result_1138_bus.txt
mkdir CG_EnergyIntoR60to63rangeNis800
./mainCGEnergy 5 1138 880 60 63 0 1138_bus.mtx >> CG_EnergyIntoR60to63rangeNis800/Energy60to63result_1138_bus.txt
mkdir CG_EnergyIntoP60to63rangeNis200
./mainCGEnergy 5 1138 220 60 63 1 1138_bus.mtx >> CG_EnergyIntoP60to63rangeNis200/Energy60to63result_1138_bus.txt
mkdir CG_EnergyIntoP60to63rangeNis400
./mainCGEnergy 5 1138 440 60 63 1 1138_bus.mtx >> CG_EnergyIntoP60to63rangeNis400/Energy60to63result_1138_bus.txt
mkdir CG_EnergyIntoP60to63rangeNis600
./mainCGEnergy 5 1138 660 60 63 1 1138_bus.mtx >> CG_EnergyIntoP60to63rangeNis600/Energy60to63result_1138_bus.txt
mkdir CG_EnergyIntoP60to63rangeNis800
./mainCGEnergy 5 1138 880 60 63 1 1138_bus.mtx >> CG_EnergyIntoP60to63rangeNis800/Energy60to63result_1138_bus.txt
mkdir CG_EnergyIntoX60to63rangeNis200
./mainCGEnergy 5 1138 220 60 63 2 1138_bus.mtx >> CG_EnergyIntoX60to63rangeNis200/Energy60to63result_1138_bus.txt
mkdir CG_EnergyIntoX60to63rangeNis400
./mainCGEnergy 5 1138 440 60 63 2 1138_bus.mtx >> CG_EnergyIntoX60to63rangeNis400/Energy60to63result_1138_bus.txt
mkdir CG_EnergyIntoX60to63rangeNis600
./mainCGEnergy 5 1138 660 60 63 2 1138_bus.mtx >> CG_EnergyIntoX60to63rangeNis600/Energy60to63result_1138_bus.txt
mkdir CG_EnergyIntoX60to63rangeNis800
./mainCGEnergy 5 1138 880 60 63 2 1138_bus.mtx >> CG_EnergyIntoX60to63rangeNis800/Energy60to63result_1138_bus.txt
mkdir CG_EnergyIntoR56to59rangeNis200
./mainCGEnergy 5 1138 220 56 59 0 1138_bus.mtx >> CG_EnergyIntoR56to59rangeNis200/Energy56to63result_1138_bus.txt
mkdir CG_EnergyIntoR56to59rangeNis400
./mainCGEnergy 5 1138 440 56 59 0 1138_bus.mtx >> CG_EnergyIntoR56to59rangeNis400/Energy56to63result_1138_bus.txt
mkdir CG_EnergyIntoR56to59rangeNis600
./mainCGEnergy 5 1138 660 56 59 0 1138_bus.mtx >> CG_EnergyIntoR56to59rangeNis600/Energy56to63result_1138_bus.txt
mkdir CG_EnergyIntoR56to59rangeNis800
./mainCGEnergy 5 1138 880 56 59 0 1138_bus.mtx >> CG_EnergyIntoR56to59rangeNis800/Energy56to63result_1138_bus.txt
mkdir CG_EnergyIntoP56to59rangeNis200
./mainCGEnergy 5 1138 220 56 59 1 1138_bus.mtx >> CG_EnergyIntoP56to59rangeNis200/Energy56to63result_1138_bus.txt
mkdir CG_EnergyIntoP56to59rangeNis400
./mainCGEnergy 5 1138 440 56 59 1 1138_bus.mtx >> CG_EnergyIntoP56to59rangeNis400/Energy56to63result_1138_bus.txt
mkdir CG_EnergyIntoP56to59rangeNis600
./mainCGEnergy 5 1138 660 56 59 1 1138_bus.mtx >> CG_EnergyIntoP56to59rangeNis600/Energy56to63result_1138_bus.txt
mkdir CG_EnergyIntoP56to59rangeNis800
./mainCGEnergy 5 1138 880 56 59 1 1138_bus.mtx >> CG_EnergyIntoP56to59rangeNis800/Energy56to63result_1138_bus.txt
mkdir CG_EnergyIntoX56to59rangeNis200
./mainCGEnergy 5 1138 220 56 59 2 1138_bus.mtx >> CG_EnergyIntoX56to59rangeNis200/Energy56to63result_1138_bus.txt
mkdir CG_EnergyIntoX56to59rangeNis400
./mainCGEnergy 5 1138 440 56 59 2 1138_bus.mtx >> CG_EnergyIntoX56to59rangeNis400/Energy56to63result_1138_bus.txt
mkdir CG_EnergyIntoX56to59rangeNis600
./mainCGEnergy 5 1138 660 56 59 2 1138_bus.mtx >> CG_EnergyIntoX56to59rangeNis600/Energy56to63result_1138_bus.txt
mkdir CG_EnergyIntoX56to59rangeNis800
./mainCGEnergy 5 1138 880 56 59 2 1138_bus.mtx >> CG_EnergyIntoX56to59rangeNis800/Energy56to63result_1138_bus.txt
mkdir CG_EnergyIntoR52to55rangeNis200
./mainCGEnergy 5 1138 220 52 55 0 1138_bus.mtx >> CG_EnergyIntoR52to55rangeNis200/Energy52to55result_1138_bus.txt
mkdir CG_EnergyIntoR52to55rangeNis400
./mainCGEnergy 5 1138 440 52 55 0 1138_bus.mtx >> CG_EnergyIntoR52to55rangeNis400/Energy52to55result_1138_bus.txt
mkdir CG_EnergyIntoR52to55rangeNis600
./mainCGEnergy 5 1138 660 52 55 0 1138_bus.mtx >> CG_EnergyIntoR52to55rangeNis600/Energy52to55result_1138_bus.txt
mkdir CG_EnergyIntoR52to55rangeNis800
./mainCGEnergy 5 1138 880 52 55 0 1138_bus.mtx >> CG_EnergyIntoR52to55rangeNis800/Energy52to55result_1138_bus.txt
mkdir CG_EnergyIntoP52to55rangeNis200
./mainCGEnergy 5 1138 220 52 55 1 1138_bus.mtx >> CG_EnergyIntoP52to55rangeNis200/Energy52to55result_1138_bus.txt
mkdir CG_EnergyIntoP52to55rangeNis400
./mainCGEnergy 5 1138 440 52 55 1 1138_bus.mtx >> CG_EnergyIntoP52to55rangeNis400/Energy52to55result_1138_bus.txt
mkdir CG_EnergyIntoP52to55rangeNis600
./mainCGEnergy 5 1138 660 52 55 1 1138_bus.mtx >> CG_EnergyIntoP52to55rangeNis600/Energy52to55result_1138_bus.txt
mkdir CG_EnergyIntoP52to55rangeNis800
./mainCGEnergy 5 1138 880 52 55 1 1138_bus.mtx >> CG_EnergyIntoP52to55rangeNis800/Energy52to55result_1138_bus.txt
mkdir CG_EnergyIntoX52to55rangeNis200
./mainCGEnergy 5 1138 220 52 55 2 1138_bus.mtx >> CG_EnergyIntoX52to55rangeNis200/Energy52to55result_1138_bus.txt
mkdir CG_EnergyIntoX52to55rangeNis400
./mainCGEnergy 5 1138 440 52 55 2 1138_bus.mtx >> CG_EnergyIntoX52to55rangeNis400/Energy52to55result_1138_bus.txt
mkdir CG_EnergyIntoX52to55rangeNis600
./mainCGEnergy 5 1138 660 52 55 2 1138_bus.mtx >> CG_EnergyIntoX52to55rangeNis600/Energy52to55result_1138_bus.txt
mkdir CG_EnergyIntoX52to55rangeNis800
./mainCGEnergy 5 1138 880 52 55 2 1138_bus.mtx >> CG_EnergyIntoX52to55rangeNis800/Energy52to55result_1138_bus.txt
mkdir CG_EnergyIntoR48to51rangeNis200
./mainCGEnergy 5 1138 220 48 51 0 1138_bus.mtx >> CG_EnergyIntoR48to51rangeNis200/Energy48to51result_1138_bus.txt
mkdir CG_EnergyIntoR48to51rangeNis400
./mainCGEnergy 5 1138 440 48 51 0 1138_bus.mtx >> CG_EnergyIntoR48to51rangeNis400/Energy48to51result_1138_bus.txt
mkdir CG_EnergyIntoR48to51rangeNis600
./mainCGEnergy 5 1138 660 48 51 0 1138_bus.mtx >> CG_EnergyIntoR48to51rangeNis600/Energy48to51result_1138_bus.txt
mkdir CG_EnergyIntoR48to51rangeNis800
./mainCGEnergy 5 1138 880 48 51 0 1138_bus.mtx >> CG_EnergyIntoR48to51rangeNis800/Energy48to51result_1138_bus.txt
mkdir CG_EnergyIntoP48to51rangeNis200
./mainCGEnergy 5 1138 220 48 51 1 1138_bus.mtx >> CG_EnergyIntoP48to51rangeNis200/Energy48to51result_1138_bus.txt
mkdir CG_EnergyIntoP48to51rangeNis400
./mainCGEnergy 5 1138 440 48 51 1 1138_bus.mtx >> CG_EnergyIntoP48to51rangeNis400/Energy48to51result_1138_bus.txt
mkdir CG_EnergyIntoP48to51rangeNis600
./mainCGEnergy 5 1138 660 48 51 1 1138_bus.mtx >> CG_EnergyIntoP48to51rangeNis600/Energy48to51result_1138_bus.txt
mkdir CG_EnergyIntoP48to51rangeNis800
./mainCGEnergy 5 1138 880 48 51 1 1138_bus.mtx >> CG_EnergyIntoP48to51rangeNis800/Energy48to51result_1138_bus.txt
mkdir CG_EnergyIntoX48to51rangeNis200
./mainCGEnergy 5 1138 220 48 51 2 1138_bus.mtx >> CG_EnergyIntoX48to51rangeNis200/Energy48to51result_1138_bus.txt
mkdir CG_EnergyIntoX48to51rangeNis400
./mainCGEnergy 5 1138 440 48 51 2 1138_bus.mtx >> CG_EnergyIntoX48to51rangeNis400/Energy48to51result_1138_bus.txt
mkdir CG_EnergyIntoX48to51rangeNis600
./mainCGEnergy 5 1138 660 48 51 2 1138_bus.mtx >> CG_EnergyIntoX48to51rangeNis600/Energy48to51result_1138_bus.txt
mkdir CG_EnergyIntoX48to51rangeNis800
./mainCGEnergy 5 1138 880 48 51 2 1138_bus.mtx >> CG_EnergyIntoX48to51rangeNis800/Energy48to51result_1138_bus.txt
 