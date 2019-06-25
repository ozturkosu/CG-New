#!/bin/bash
#SBATCH --time=23:59:00
mkdir CG_EnergyIntoR60to63rangeNis200
./mainCGEnergy 5 729 144 60 63 0 bcsstk19.mtx >> CG_EnergyIntoR60to63rangeNis200/Energy60to63result_bcsstk19.txt
mkdir CG_EnergyIntoR60to63rangeNis400
./mainCGEnergy 5 729 288 60 63 0 bcsstk19.mtx >> CG_EnergyIntoR60to63rangeNis400/Energy60to63result_bcsstk19.txt
mkdir CG_EnergyIntoR60to63rangeNis600
./mainCGEnergy 5 729 450 60 63 0 bcsstk19.mtx >> CG_EnergyIntoR60to63rangeNis600/Energy60to63result_bcsstk19.txt
mkdir CG_EnergyIntoR60to63rangeNis800
./mainCGEnergy 5 729 572 60 63 0 bcsstk19.mtx >> CG_EnergyIntoR60to63rangeNis800/Energy60to63result_bcsstk19.txt
mkdir CG_EnergyIntoP60to63rangeNis200
./mainCGEnergy 5 729 144 60 63 1 bcsstk19.mtx >> CG_EnergyIntoP60to63rangeNis200/Energy60to63result_bcsstk19.txt
mkdir CG_EnergyIntoP60to63rangeNis400
./mainCGEnergy 5 729 288 60 63 1 bcsstk19.mtx >> CG_EnergyIntoP60to63rangeNis400/Energy60to63result_bcsstk19.txt
mkdir CG_EnergyIntoP60to63rangeNis600
./mainCGEnergy 5 729 450 60 63 1 bcsstk19.mtx >> CG_EnergyIntoP60to63rangeNis600/Energy60to63result_bcsstk19.txt
mkdir CG_EnergyIntoP60to63rangeNis800
./mainCGEnergy 5 729 572 60 63 1 bcsstk19.mtx >> CG_EnergyIntoP60to63rangeNis800/Energy60to63result_bcsstk19.txt
mkdir CG_EnergyIntoX60to63rangeNis200
./mainCGEnergy 5 729 144 60 63 2 bcsstk19.mtx >> CG_EnergyIntoX60to63rangeNis200/Energy60to63result_bcsstk19.txt
mkdir CG_EnergyIntoX60to63rangeNis400
./mainCGEnergy 5 729 288 60 63 2 bcsstk19.mtx >> CG_EnergyIntoX60to63rangeNis400/Energy60to63result_bcsstk19.txt
mkdir CG_EnergyIntoX60to63rangeNis600
./mainCGEnergy 5 729 450 60 63 2 bcsstk19.mtx >> CG_EnergyIntoX60to63rangeNis600/Energy60to63result_bcsstk19.txt
mkdir CG_EnergyIntoX60to63rangeNis800
./mainCGEnergy 5 729 572 60 63 2 bcsstk19.mtx >> CG_EnergyIntoX60to63rangeNis800/Energy60to63result_bcsstk19.txt
mkdir CG_EnergyIntoR56to59rangeNis200
./mainCGEnergy 5 729 144 56 59 0 bcsstk19.mtx >> CG_EnergyIntoR56to59rangeNis200/Energy56to63result_bcsstk19.txt
mkdir CG_EnergyIntoR56to59rangeNis400
./mainCGEnergy 5 729 288 56 59 0 bcsstk19.mtx >> CG_EnergyIntoR56to59rangeNis400/Energy56to63result_bcsstk19.txt
mkdir CG_EnergyIntoR56to59rangeNis600
./mainCGEnergy 5 729 450 56 59 0 bcsstk19.mtx >> CG_EnergyIntoR56to59rangeNis600/Energy56to63result_bcsstk19.txt
mkdir CG_EnergyIntoR56to59rangeNis800
./mainCGEnergy 5 729 572 56 59 0 bcsstk19.mtx >> CG_EnergyIntoR56to59rangeNis800/Energy56to63result_bcsstk19.txt
mkdir CG_EnergyIntoP56to59rangeNis200
./mainCGEnergy 5 729 144 56 59 1 bcsstk19.mtx >> CG_EnergyIntoP56to59rangeNis200/Energy56to63result_bcsstk19.txt
mkdir CG_EnergyIntoP56to59rangeNis400
./mainCGEnergy 5 729 288 56 59 1 bcsstk19.mtx >> CG_EnergyIntoP56to59rangeNis400/Energy56to63result_bcsstk19.txt
mkdir CG_EnergyIntoP56to59rangeNis600
./mainCGEnergy 5 729 450 56 59 1 bcsstk19.mtx >> CG_EnergyIntoP56to59rangeNis600/Energy56to63result_bcsstk19.txt
mkdir CG_EnergyIntoP56to59rangeNis800
./mainCGEnergy 5 729 572 56 59 1 bcsstk19.mtx >> CG_EnergyIntoP56to59rangeNis800/Energy56to63result_bcsstk19.txt
mkdir CG_EnergyIntoX56to59rangeNis200
./mainCGEnergy 5 729 144 56 59 2 bcsstk19.mtx >> CG_EnergyIntoX56to59rangeNis200/Energy56to63result_bcsstk19.txt
mkdir CG_EnergyIntoX56to59rangeNis400
./mainCGEnergy 5 729 288 56 59 2 bcsstk19.mtx >> CG_EnergyIntoX56to59rangeNis400/Energy56to63result_bcsstk19.txt
mkdir CG_EnergyIntoX56to59rangeNis600
./mainCGEnergy 5 729 450 56 59 2 bcsstk19.mtx >> CG_EnergyIntoX56to59rangeNis600/Energy56to63result_bcsstk19.txt
mkdir CG_EnergyIntoX56to59rangeNis800
./mainCGEnergy 5 729 572 56 59 2 bcsstk19.mtx >> CG_EnergyIntoX56to59rangeNis800/Energy56to63result_bcsstk19.txt
mkdir CG_EnergyIntoR52to55rangeNis200
./mainCGEnergy 5 729 144 52 55 0 bcsstk19.mtx >> CG_EnergyIntoR52to55rangeNis200/Energy52to55result_bcsstk19.txt
mkdir CG_EnergyIntoR52to55rangeNis400
./mainCGEnergy 5 729 288 52 55 0 bcsstk19.mtx >> CG_EnergyIntoR52to55rangeNis400/Energy52to55result_bcsstk19.txt
mkdir CG_EnergyIntoR52to55rangeNis600
./mainCGEnergy 5 729 450 52 55 0 bcsstk19.mtx >> CG_EnergyIntoR52to55rangeNis600/Energy52to55result_bcsstk19.txt
mkdir CG_EnergyIntoR52to55rangeNis800
./mainCGEnergy 5 729 572 52 55 0 bcsstk19.mtx >> CG_EnergyIntoR52to55rangeNis800/Energy52to55result_bcsstk19.txt
mkdir CG_EnergyIntoP52to55rangeNis200
./mainCGEnergy 5 729 144 52 55 1 bcsstk19.mtx >> CG_EnergyIntoP52to55rangeNis200/Energy52to55result_bcsstk19.txt
mkdir CG_EnergyIntoP52to55rangeNis400
./mainCGEnergy 5 729 288 52 55 1 bcsstk19.mtx >> CG_EnergyIntoP52to55rangeNis400/Energy52to55result_bcsstk19.txt
mkdir CG_EnergyIntoP52to55rangeNis600
./mainCGEnergy 5 729 450 52 55 1 bcsstk19.mtx >> CG_EnergyIntoP52to55rangeNis600/Energy52to55result_bcsstk19.txt
mkdir CG_EnergyIntoP52to55rangeNis800
./mainCGEnergy 5 729 572 52 55 1 bcsstk19.mtx >> CG_EnergyIntoP52to55rangeNis800/Energy52to55result_bcsstk19.txt
mkdir CG_EnergyIntoX52to55rangeNis200
./mainCGEnergy 5 729 144 52 55 2 bcsstk19.mtx >> CG_EnergyIntoX52to55rangeNis200/Energy52to55result_bcsstk19.txt
mkdir CG_EnergyIntoX52to55rangeNis400
./mainCGEnergy 5 729 288 52 55 2 bcsstk19.mtx >> CG_EnergyIntoX52to55rangeNis400/Energy52to55result_bcsstk19.txt
mkdir CG_EnergyIntoX52to55rangeNis600
./mainCGEnergy 5 729 450 52 55 2 bcsstk19.mtx >> CG_EnergyIntoX52to55rangeNis600/Energy52to55result_bcsstk19.txt
mkdir CG_EnergyIntoX52to55rangeNis800
./mainCGEnergy 5 729 572 52 55 2 bcsstk19.mtx >> CG_EnergyIntoX52to55rangeNis800/Energy52to55result_bcsstk19.txt
mkdir CG_EnergyIntoR48to51rangeNis200
./mainCGEnergy 5 729 144 48 51 0 bcsstk19.mtx >> CG_EnergyIntoR48to51rangeNis200/Energy48to51result_bcsstk19.txt
mkdir CG_EnergyIntoR48to51rangeNis400
./mainCGEnergy 5 729 288 48 51 0 bcsstk19.mtx >> CG_EnergyIntoR48to51rangeNis400/Energy48to51result_bcsstk19.txt
mkdir CG_EnergyIntoR48to51rangeNis600
./mainCGEnergy 5 729 450 48 51 0 bcsstk19.mtx >> CG_EnergyIntoR48to51rangeNis600/Energy48to51result_bcsstk19.txt
mkdir CG_EnergyIntoR48to51rangeNis800
./mainCGEnergy 5 729 572 48 51 0 bcsstk19.mtx >> CG_EnergyIntoR48to51rangeNis800/Energy48to51result_bcsstk19.txt
mkdir CG_EnergyIntoP48to51rangeNis200
./mainCGEnergy 5 729 144 48 51 1 bcsstk19.mtx >> CG_EnergyIntoP48to51rangeNis200/Energy48to51result_bcsstk19.txt
mkdir CG_EnergyIntoP48to51rangeNis400
./mainCGEnergy 5 729 288 48 51 1 bcsstk19.mtx >> CG_EnergyIntoP48to51rangeNis400/Energy48to51result_bcsstk19.txt
mkdir CG_EnergyIntoP48to51rangeNis600
./mainCGEnergy 5 729 450 48 51 1 bcsstk19.mtx >> CG_EnergyIntoP48to51rangeNis600/Energy48to51result_bcsstk19.txt
mkdir CG_EnergyIntoP48to51rangeNis800
./mainCGEnergy 5 729 572 48 51 1 bcsstk19.mtx >> CG_EnergyIntoP48to51rangeNis800/Energy48to51result_bcsstk19.txt
mkdir CG_EnergyIntoX48to51rangeNis200
./mainCGEnergy 5 729 144 48 51 2 bcsstk19.mtx >> CG_EnergyIntoX48to51rangeNis200/Energy48to51result_bcsstk19.txt
mkdir CG_EnergyIntoX48to51rangeNis400
./mainCGEnergy 5 729 288 48 51 2 bcsstk19.mtx >> CG_EnergyIntoX48to51rangeNis400/Energy48to51result_bcsstk19.txt
mkdir CG_EnergyIntoX48to51rangeNis600
./mainCGEnergy 5 729 450 48 51 2 bcsstk19.mtx >> CG_EnergyIntoX48to51rangeNis600/Energy48to51result_bcsstk19.txt
mkdir CG_EnergyIntoX48to51rangeNis800
./mainCGEnergy 5 729 572 48 51 2 bcsstk19.mtx >> CG_EnergyIntoX48to51rangeNis800/Energy48to51result_bcsstk19.txt
 