#!/bin/bash
#SBATCH --time=23:59:00
mkdir CG_EnergyIntoR60to63rangeNis200
./mainCGEnergy 5 112 22 60 63 0 bcsstk03.mtx >> CG_EnergyIntoR60to63rangeNis200/residual60to63result_bcsstk03.txt
mkdir CG_EnergyIntoR60to63rangeNis400
./mainCGEnergy 5 112 44 60 63 0 bcsstk03.mtx >> CG_EnergyIntoR60to63rangeNis400/residual60to63result_bcsstk03.txt
mkdir CG_EnergyIntoR60to63rangeNis600
./mainCGEnergy 5 112 66 60 63 0 bcsstk03.mtx >> CG_EnergyIntoR60to63rangeNis600/residual60to63result_bcsstk03.txt
mkdir CG_EnergyIntoR60to63rangeNis800
./mainCGEnergy 5 112 88 60 63 0 bcsstk03.mtx >> CG_EnergyIntoR60to63rangeNis800/residual60to63result_bcsstk03.txt
mkdir CG_EnergyIntoP60to63rangeNis200
./mainCGEnergy 5 112 22 60 63 1 bcsstk03.mtx >> CG_EnergyIntoP60to63rangeNis200/residual60to63result_bcsstk03.txt
mkdir CG_EnergyIntoP60to63rangeNis400
./mainCGEnergy 5 112 44 60 63 1 bcsstk03.mtx >> CG_EnergyIntoP60to63rangeNis400/residual60to63result_bcsstk03.txt
mkdir CG_EnergyIntoP60to63rangeNis600
./mainCGEnergy 5 112 66 60 63 1 bcsstk03.mtx >> CG_EnergyIntoP60to63rangeNis600/residual60to63result_bcsstk03.txt
mkdir CG_EnergyIntoP60to63rangeNis800
./mainCGEnergy 5 112 88 60 63 1 bcsstk03.mtx >> CG_EnergyIntoP60to63rangeNis800/residual60to63result_bcsstk03.txt
mkdir CG_EnergyIntoX60to63rangeNis200
./mainCGEnergy 5 112 22 60 63 2 bcsstk03.mtx >> CG_EnergyIntoX60to63rangeNis200/residual60to63result_bcsstk03.txt
mkdir CG_EnergyIntoX60to63rangeNis400
./mainCGEnergy 5 112 44 60 63 2 bcsstk03.mtx >> CG_EnergyIntoX60to63rangeNis400/residual60to63result_bcsstk03.txt
mkdir CG_EnergyIntoX60to63rangeNis600
./mainCGEnergy 5 112 66 60 63 2 bcsstk03.mtx >> CG_EnergyIntoX60to63rangeNis600/residual60to63result_bcsstk03.txt
mkdir CG_EnergyIntoX60to63rangeNis800
./mainCGEnergy 5 112 88 60 63 2 bcsstk03.mtx >> CG_EnergyIntoX60to63rangeNis800/residual60to63result_bcsstk03.txt
mkdir CG_EnergyIntoR56to59rangeNis200
./mainCGEnergy 5 112 22 56 59 0 bcsstk03.mtx >> CG_EnergyIntoR56to59rangeNis200/residual56to63result_bcsstk03.txt
mkdir CG_EnergyIntoR56to59rangeNis400
./mainCGEnergy 5 112 44 56 59 0 bcsstk03.mtx >> CG_EnergyIntoR56to59rangeNis400/residual56to63result_bcsstk03.txt
mkdir CG_EnergyIntoR56to59rangeNis600
./mainCGEnergy 5 112 66 56 59 0 bcsstk03.mtx >> CG_EnergyIntoR56to59rangeNis600/residual56to63result_bcsstk03.txt
mkdir CG_EnergyIntoR56to59rangeNis800
./mainCGEnergy 5 112 88 56 59 0 bcsstk03.mtx >> CG_EnergyIntoR56to59rangeNis800/residual56to63result_bcsstk03.txt
mkdir CG_EnergyIntoP56to59rangeNis200
./mainCGEnergy 5 112 22 56 59 1 bcsstk03.mtx >> CG_EnergyIntoP56to59rangeNis200/residual56to63result_bcsstk03.txt
mkdir CG_EnergyIntoP56to59rangeNis400
./mainCGEnergy 5 112 44 56 59 1 bcsstk03.mtx >> CG_EnergyIntoP56to59rangeNis400/residual56to63result_bcsstk03.txt
mkdir CG_EnergyIntoP56to59rangeNis600
./mainCGEnergy 5 112 66 56 59 1 bcsstk03.mtx >> CG_EnergyIntoP56to59rangeNis600/residual56to63result_bcsstk03.txt
mkdir CG_EnergyIntoP56to59rangeNis800
./mainCGEnergy 5 112 88 56 59 1 bcsstk03.mtx >> CG_EnergyIntoP56to59rangeNis800/residual56to63result_bcsstk03.txt
mkdir CG_EnergyIntoX56to59rangeNis200
./mainCGEnergy 5 112 22 56 59 2 bcsstk03.mtx >> CG_EnergyIntoX56to59rangeNis200/residual56to63result_bcsstk03.txt
mkdir CG_EnergyIntoX56to59rangeNis400
./mainCGEnergy 5 112 44 56 59 2 bcsstk03.mtx >> CG_EnergyIntoX56to59rangeNis400/residual56to63result_bcsstk03.txt
mkdir CG_EnergyIntoX56to59rangeNis600
./mainCGEnergy 5 112 66 56 59 2 bcsstk03.mtx >> CG_EnergyIntoX56to59rangeNis600/residual56to63result_bcsstk03.txt
mkdir CG_EnergyIntoX56to59rangeNis800
./mainCGEnergy 5 112 88 56 59 2 bcsstk03.mtx >> CG_EnergyIntoX56to59rangeNis800/residual56to63result_bcsstk03.txt
mkdir CG_EnergyIntoR52to55rangeNis200
./mainCGEnergy 5 112 22 52 55 0 bcsstk03.mtx >> CG_EnergyIntoR52to55rangeNis200/residual52to55result_bcsstk03.txt
mkdir CG_EnergyIntoR52to55rangeNis400
./mainCGEnergy 5 112 44 52 55 0 bcsstk03.mtx >> CG_EnergyIntoR52to55rangeNis400/residual52to55result_bcsstk03.txt
mkdir CG_EnergyIntoR52to55rangeNis600
./mainCGEnergy 5 112 66 52 55 0 bcsstk03.mtx >> CG_EnergyIntoR52to55rangeNis600/residual52to55result_bcsstk03.txt
mkdir CG_EnergyIntoR52to55rangeNis800
./mainCGEnergy 5 112 88 52 55 0 bcsstk03.mtx >> CG_EnergyIntoR52to55rangeNis800/residual52to55result_bcsstk03.txt
mkdir CG_EnergyIntoP52to55rangeNis200
./mainCGEnergy 5 112 22 52 55 1 bcsstk03.mtx >> CG_EnergyIntoP52to55rangeNis200/residual52to55result_bcsstk03.txt
mkdir CG_EnergyIntoP52to55rangeNis400
./mainCGEnergy 5 112 44 52 55 1 bcsstk03.mtx >> CG_EnergyIntoP52to55rangeNis400/residual52to55result_bcsstk03.txt
mkdir CG_EnergyIntoP52to55rangeNis600
./mainCGEnergy 5 112 66 52 55 1 bcsstk03.mtx >> CG_EnergyIntoP52to55rangeNis600/residual52to55result_bcsstk03.txt
mkdir CG_EnergyIntoP52to55rangeNis800
./mainCGEnergy 5 112 88 52 55 1 bcsstk03.mtx >> CG_EnergyIntoP52to55rangeNis800/residual52to55result_bcsstk03.txt
mkdir CG_EnergyIntoX52to55rangeNis200
./mainCGEnergy 5 112 22 52 55 2 bcsstk03.mtx >> CG_EnergyIntoX52to55rangeNis200/residual52to55result_bcsstk03.txt
mkdir CG_EnergyIntoX52to55rangeNis400
./mainCGEnergy 5 112 44 52 55 2 bcsstk03.mtx >> CG_EnergyIntoX52to55rangeNis400/residual52to55result_bcsstk03.txt
mkdir CG_EnergyIntoX52to55rangeNis600
./mainCGEnergy 5 112 66 52 55 2 bcsstk03.mtx >> CG_EnergyIntoX52to55rangeNis600/residual52to55result_bcsstk03.txt
mkdir CG_EnergyIntoX52to55rangeNis800
./mainCGEnergy 5 112 88 52 55 2 bcsstk03.mtx >> CG_EnergyIntoX52to55rangeNis800/residual52to55result_bcsstk03.txt
mkdir CG_EnergyIntoR48to51rangeNis200
./mainCGEnergy 5 112 22 48 51 0 bcsstk03.mtx >> CG_EnergyIntoR48to51rangeNis200/residual48to51result_bcsstk03.txt
mkdir CG_EnergyIntoR48to51rangeNis400
./mainCGEnergy 5 112 44 48 51 0 bcsstk03.mtx >> CG_EnergyIntoR48to51rangeNis400/residual48to51result_bcsstk03.txt
mkdir CG_EnergyIntoR48to51rangeNis600
./mainCGEnergy 5 112 66 48 51 0 bcsstk03.mtx >> CG_EnergyIntoR48to51rangeNis600/residual48to51result_bcsstk03.txt
mkdir CG_EnergyIntoR48to51rangeNis800
./mainCGEnergy 5 112 88 48 51 0 bcsstk03.mtx >> CG_EnergyIntoR48to51rangeNis800/residual48to51result_bcsstk03.txt
mkdir CG_EnergyIntoP48to51rangeNis200
./mainCGEnergy 5 112 22 48 51 1 bcsstk03.mtx >> CG_EnergyIntoP48to51rangeNis200/residual48to51result_bcsstk03.txt
mkdir CG_EnergyIntoP48to51rangeNis400
./mainCGEnergy 5 112 44 48 51 1 bcsstk03.mtx >> CG_EnergyIntoP48to51rangeNis400/residual48to51result_bcsstk03.txt
mkdir CG_EnergyIntoP48to51rangeNis600
./mainCGEnergy 5 112 66 48 51 1 bcsstk03.mtx >> CG_EnergyIntoP48to51rangeNis600/residual48to51result_bcsstk03.txt
mkdir CG_EnergyIntoP48to51rangeNis800
./mainCGEnergy 5 112 88 48 51 1 bcsstk03.mtx >> CG_EnergyIntoP48to51rangeNis800/residual48to51result_bcsstk03.txt
mkdir CG_EnergyIntoX48to51rangeNis200
./mainCGEnergy 5 112 22 48 51 2 bcsstk03.mtx >> CG_EnergyIntoX48to51rangeNis200/residual48to51result_bcsstk03.txt
mkdir CG_EnergyIntoX48to51rangeNis400
./mainCGEnergy 5 112 44 48 51 2 bcsstk03.mtx >> CG_EnergyIntoX48to51rangeNis400/residual48to51result_bcsstk03.txt
mkdir CG_EnergyIntoX48to51rangeNis600
./mainCGEnergy 5 112 66 48 51 2 bcsstk03.mtx >> CG_EnergyIntoX48to51rangeNis600/residual48to51result_bcsstk03.txt
mkdir CG_EnergyIntoX48to51rangeNis800
./mainCGEnergy 5 112 88 48 51 2 bcsstk03.mtx >> CG_EnergyIntoX48to51rangeNis800/residual48to51result_bcsstk03.txt
 