#!/bin/bash
#SBATCH --time=23:59:00
mkdir CG_EnergyIntoR60to63rangeNis200
./mainCGEnergy2 5 685 140 60 63 0 685_bus.mtx >> CG_EnergyIntoR60to63rangeNis200/EnergyWithProp60to63result_685_bus.txt
mkdir CG_EnergyIntoR60to63rangeNis400
./mainCGEnergy2 5 685 280 60 63 0 685_bus.mtx >> CG_EnergyIntoR60to63rangeNis400/EnergyWithProp60to63result_685_bus.txt
mkdir CG_EnergyIntoR60to63rangeNis600
./mainCGEnergy2 5 685 420 60 63 0 685_bus.mtx >> CG_EnergyIntoR60to63rangeNis600/EnergyWithProp60to63result_685_bus.txt
mkdir CG_EnergyIntoR60to63rangeNis800
./mainCGEnergy2 5 685 560 60 63 0 685_bus.mtx >> CG_EnergyIntoR60to63rangeNis800/EnergyWithProp60to63result_685_bus.txt
mkdir CG_EnergyIntoP60to63rangeNis200
./mainCGEnergy2 5 685 140 60 63 1 685_bus.mtx >> CG_EnergyIntoP60to63rangeNis200/EnergyWithProp60to63result_685_bus.txt
mkdir CG_EnergyIntoP60to63rangeNis400
./mainCGEnergy2 5 685 280 60 63 1 685_bus.mtx >> CG_EnergyIntoP60to63rangeNis400/EnergyWithProp60to63result_685_bus.txt
mkdir CG_EnergyIntoP60to63rangeNis600
./mainCGEnergy2 5 685 420 60 63 1 685_bus.mtx >> CG_EnergyIntoP60to63rangeNis600/EnergyWithProp60to63result_685_bus.txt
mkdir CG_EnergyIntoP60to63rangeNis800
./mainCGEnergy2 5 685 560 60 63 1 685_bus.mtx >> CG_EnergyIntoP60to63rangeNis800/EnergyWithProp60to63result_685_bus.txt
mkdir CG_EnergyIntoX60to63rangeNis200
./mainCGEnergy2 5 685 140 60 63 2 685_bus.mtx >> CG_EnergyIntoX60to63rangeNis200/EnergyWithProp60to63result_685_bus.txt
mkdir CG_EnergyIntoX60to63rangeNis400
./mainCGEnergy2 5 685 280 60 63 2 685_bus.mtx >> CG_EnergyIntoX60to63rangeNis400/EnergyWithProp60to63result_685_bus.txt
mkdir CG_EnergyIntoX60to63rangeNis600
./mainCGEnergy2 5 685 420 60 63 2 685_bus.mtx >> CG_EnergyIntoX60to63rangeNis600/EnergyWithProp60to63result_685_bus.txt
mkdir CG_EnergyIntoX60to63rangeNis800
./mainCGEnergy2 5 685 560 60 63 2 685_bus.mtx >> CG_EnergyIntoX60to63rangeNis800/EnergyWithProp60to63result_685_bus.txt
mkdir CG_EnergyIntoR56to59rangeNis200
./mainCGEnergy2 5 685 140 56 59 0 685_bus.mtx >> CG_EnergyIntoR56to59rangeNis200/EnergyWithProp56to63result_685_bus.txt
mkdir CG_EnergyIntoR56to59rangeNis400
./mainCGEnergy2 5 685 280 56 59 0 685_bus.mtx >> CG_EnergyIntoR56to59rangeNis400/EnergyWithProp56to63result_685_bus.txt
mkdir CG_EnergyIntoR56to59rangeNis600
./mainCGEnergy2 5 685 420 56 59 0 685_bus.mtx >> CG_EnergyIntoR56to59rangeNis600/EnergyWithProp56to63result_685_bus.txt
mkdir CG_EnergyIntoR56to59rangeNis800
./mainCGEnergy2 5 685 560 56 59 0 685_bus.mtx >> CG_EnergyIntoR56to59rangeNis800/EnergyWithProp56to63result_685_bus.txt
mkdir CG_EnergyIntoP56to59rangeNis200
./mainCGEnergy2 5 685 140 56 59 1 685_bus.mtx >> CG_EnergyIntoP56to59rangeNis200/EnergyWithProp56to63result_685_bus.txt
mkdir CG_EnergyIntoP56to59rangeNis400
./mainCGEnergy2 5 685 280 56 59 1 685_bus.mtx >> CG_EnergyIntoP56to59rangeNis400/EnergyWithProp56to63result_685_bus.txt
mkdir CG_EnergyIntoP56to59rangeNis600
./mainCGEnergy2 5 685 420 56 59 1 685_bus.mtx >> CG_EnergyIntoP56to59rangeNis600/EnergyWithProp56to63result_685_bus.txt
mkdir CG_EnergyIntoP56to59rangeNis800
./mainCGEnergy2 5 685 560 56 59 1 685_bus.mtx >> CG_EnergyIntoP56to59rangeNis800/EnergyWithProp56to63result_685_bus.txt
mkdir CG_EnergyIntoX56to59rangeNis200
./mainCGEnergy2 5 685 140 56 59 2 685_bus.mtx >> CG_EnergyIntoX56to59rangeNis200/EnergyWithProp56to63result_685_bus.txt
mkdir CG_EnergyIntoX56to59rangeNis400
./mainCGEnergy2 5 685 280 56 59 2 685_bus.mtx >> CG_EnergyIntoX56to59rangeNis400/EnergyWithProp56to63result_685_bus.txt
mkdir CG_EnergyIntoX56to59rangeNis600
./mainCGEnergy2 5 685 420 56 59 2 685_bus.mtx >> CG_EnergyIntoX56to59rangeNis600/EnergyWithProp56to63result_685_bus.txt
mkdir CG_EnergyIntoX56to59rangeNis800
./mainCGEnergy2 5 685 560 56 59 2 685_bus.mtx >> CG_EnergyIntoX56to59rangeNis800/EnergyWithProp56to63result_685_bus.txt
mkdir CG_EnergyIntoR52to55rangeNis200
./mainCGEnergy2 5 685 140 52 55 0 685_bus.mtx >> CG_EnergyIntoR52to55rangeNis200/EnergyWithProp52to55result_685_bus.txt
mkdir CG_EnergyIntoR52to55rangeNis400
./mainCGEnergy2 5 685 280 52 55 0 685_bus.mtx >> CG_EnergyIntoR52to55rangeNis400/EnergyWithProp52to55result_685_bus.txt
mkdir CG_EnergyIntoR52to55rangeNis600
./mainCGEnergy2 5 685 420 52 55 0 685_bus.mtx >> CG_EnergyIntoR52to55rangeNis600/EnergyWithProp52to55result_685_bus.txt
mkdir CG_EnergyIntoR52to55rangeNis800
./mainCGEnergy2 5 685 560 52 55 0 685_bus.mtx >> CG_EnergyIntoR52to55rangeNis800/EnergyWithProp52to55result_685_bus.txt
mkdir CG_EnergyIntoP52to55rangeNis200
./mainCGEnergy2 5 685 140 52 55 1 685_bus.mtx >> CG_EnergyIntoP52to55rangeNis200/EnergyWithProp52to55result_685_bus.txt
mkdir CG_EnergyIntoP52to55rangeNis400
./mainCGEnergy2 5 685 280 52 55 1 685_bus.mtx >> CG_EnergyIntoP52to55rangeNis400/EnergyWithProp52to55result_685_bus.txt
mkdir CG_EnergyIntoP52to55rangeNis600
./mainCGEnergy2 5 685 420 52 55 1 685_bus.mtx >> CG_EnergyIntoP52to55rangeNis600/EnergyWithProp52to55result_685_bus.txt
mkdir CG_EnergyIntoP52to55rangeNis800
./mainCGEnergy2 5 685 560 52 55 1 685_bus.mtx >> CG_EnergyIntoP52to55rangeNis800/EnergyWithProp52to55result_685_bus.txt
mkdir CG_EnergyIntoX52to55rangeNis200
./mainCGEnergy2 5 685 140 52 55 2 685_bus.mtx >> CG_EnergyIntoX52to55rangeNis200/EnergyWithProp52to55result_685_bus.txt
mkdir CG_EnergyIntoX52to55rangeNis400
./mainCGEnergy2 5 685 280 52 55 2 685_bus.mtx >> CG_EnergyIntoX52to55rangeNis400/EnergyWithProp52to55result_685_bus.txt
mkdir CG_EnergyIntoX52to55rangeNis600
./mainCGEnergy2 5 685 420 52 55 2 685_bus.mtx >> CG_EnergyIntoX52to55rangeNis600/EnergyWithProp52to55result_685_bus.txt
mkdir CG_EnergyIntoX52to55rangeNis800
./mainCGEnergy2 5 685 560 52 55 2 685_bus.mtx >> CG_EnergyIntoX52to55rangeNis800/EnergyWithProp52to55result_685_bus.txt
mkdir CG_EnergyIntoR48to51rangeNis200
./mainCGEnergy2 5 685 140 48 51 0 685_bus.mtx >> CG_EnergyIntoR48to51rangeNis200/EnergyWithProp48to51result_685_bus.txt
mkdir CG_EnergyIntoR48to51rangeNis400
./mainCGEnergy2 5 685 280 48 51 0 685_bus.mtx >> CG_EnergyIntoR48to51rangeNis400/EnergyWithProp48to51result_685_bus.txt
mkdir CG_EnergyIntoR48to51rangeNis600
./mainCGEnergy2 5 685 420 48 51 0 685_bus.mtx >> CG_EnergyIntoR48to51rangeNis600/EnergyWithProp48to51result_685_bus.txt
mkdir CG_EnergyIntoR48to51rangeNis800
./mainCGEnergy2 5 685 560 48 51 0 685_bus.mtx >> CG_EnergyIntoR48to51rangeNis800/EnergyWithProp48to51result_685_bus.txt
mkdir CG_EnergyIntoP48to51rangeNis200
./mainCGEnergy2 5 685 140 48 51 1 685_bus.mtx >> CG_EnergyIntoP48to51rangeNis200/EnergyWithProp48to51result_685_bus.txt
mkdir CG_EnergyIntoP48to51rangeNis400
./mainCGEnergy2 5 685 280 48 51 1 685_bus.mtx >> CG_EnergyIntoP48to51rangeNis400/EnergyWithProp48to51result_685_bus.txt
mkdir CG_EnergyIntoP48to51rangeNis600
./mainCGEnergy2 5 685 420 48 51 1 685_bus.mtx >> CG_EnergyIntoP48to51rangeNis600/EnergyWithProp48to51result_685_bus.txt
mkdir CG_EnergyIntoP48to51rangeNis800
./mainCGEnergy2 5 685 560 48 51 1 685_bus.mtx >> CG_EnergyIntoP48to51rangeNis800/EnergyWithProp48to51result_685_bus.txt
mkdir CG_EnergyIntoX48to51rangeNis200
./mainCGEnergy2 5 685 140 48 51 2 685_bus.mtx >> CG_EnergyIntoX48to51rangeNis200/EnergyWithProp48to51result_685_bus.txt
mkdir CG_EnergyIntoX48to51rangeNis400
./mainCGEnergy2 5 685 280 48 51 2 685_bus.mtx >> CG_EnergyIntoX48to51rangeNis400/EnergyWithProp48to51result_685_bus.txt
mkdir CG_EnergyIntoX48to51rangeNis600
./mainCGEnergy2 5 685 420 48 51 2 685_bus.mtx >> CG_EnergyIntoX48to51rangeNis600/EnergyWithProp48to51result_685_bus.txt
mkdir CG_EnergyIntoX48to51rangeNis800
./mainCGEnergy2 5 685 560 48 51 2 685_bus.mtx >> CG_EnergyIntoX48to51rangeNis800/EnergyWithProp48to51result_685_bus.txt
 