#!/bin/bash
#SBATCH --time=23:59:00
mkdir CG_EnergyPropIntoR60to63rangeNis200
./mainCGEnergyProp2 5 485 96 60 63 0 bcsstk20.mtx >> CG_EnergyPropIntoR60to63rangeNis200/EnergyProp60to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoR60to63rangeNis400
./mainCGEnergyProp2 5 485 192 60 63 0 bcsstk20.mtx >> CG_EnergyPropIntoR60to63rangeNis400/EnergyProp60to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoR60to63rangeNis600
./mainCGEnergyProp2 5 485 288 60 63 0 bcsstk20.mtx >> CG_EnergyPropIntoR60to63rangeNis600/EnergyProp60to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoR60to63rangeNis800
./mainCGEnergyProp2 5 485 394 60 63 0 bcsstk20.mtx >> CG_EnergyPropIntoR60to63rangeNis800/EnergyProp60to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoP60to63rangeNis200
./mainCGEnergyProp2 5 485 96 60 63 1 bcsstk20.mtx >> CG_EnergyPropIntoP60to63rangeNis200/EnergyProp60to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoP60to63rangeNis400
./mainCGEnergyProp2 5 485 192 60 63 1 bcsstk20.mtx >> CG_EnergyPropIntoP60to63rangeNis400/EnergyProp60to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoP60to63rangeNis600
./mainCGEnergyProp2 5 485 288 60 63 1 bcsstk20.mtx >> CG_EnergyPropIntoP60to63rangeNis600/EnergyProp60to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoP60to63rangeNis800
./mainCGEnergyProp2 5 485 394 60 63 1 bcsstk20.mtx >> CG_EnergyPropIntoP60to63rangeNis800/EnergyProp60to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoX60to63rangeNis200
./mainCGEnergyProp2 5 485 96 60 63 2 bcsstk20.mtx >> CG_EnergyPropIntoX60to63rangeNis200/EnergyProp60to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoX60to63rangeNis400
./mainCGEnergyProp2 5 485 192 60 63 2 bcsstk20.mtx >> CG_EnergyPropIntoX60to63rangeNis400/EnergyProp60to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoX60to63rangeNis600
./mainCGEnergyProp2 5 485 288 60 63 2 bcsstk20.mtx >> CG_EnergyPropIntoX60to63rangeNis600/EnergyProp60to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoX60to63rangeNis800
./mainCGEnergyProp2 5 485 394 60 63 2 bcsstk20.mtx >> CG_EnergyPropIntoX60to63rangeNis800/EnergyProp60to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoR56to59rangeNis200
./mainCGEnergyProp2 5 485 96 56 59 0 bcsstk20.mtx >> CG_EnergyPropIntoR56to59rangeNis200/EnergyProp56to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoR56to59rangeNis400
./mainCGEnergyProp2 5 485 192 56 59 0 bcsstk20.mtx >> CG_EnergyPropIntoR56to59rangeNis400/EnergyProp56to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoR56to59rangeNis600
./mainCGEnergyProp2 5 485 288 56 59 0 bcsstk20.mtx >> CG_EnergyPropIntoR56to59rangeNis600/EnergyProp56to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoR56to59rangeNis800
./mainCGEnergyProp2 5 485 394 56 59 0 bcsstk20.mtx >> CG_EnergyPropIntoR56to59rangeNis800/EnergyProp56to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoP56to59rangeNis200
./mainCGEnergyProp2 5 485 96 56 59 1 bcsstk20.mtx >> CG_EnergyPropIntoP56to59rangeNis200/EnergyProp56to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoP56to59rangeNis400
./mainCGEnergyProp2 5 485 192 56 59 1 bcsstk20.mtx >> CG_EnergyPropIntoP56to59rangeNis400/EnergyProp56to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoP56to59rangeNis600
./mainCGEnergyProp2 5 485 288 56 59 1 bcsstk20.mtx >> CG_EnergyPropIntoP56to59rangeNis600/EnergyProp56to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoP56to59rangeNis800
./mainCGEnergyProp2 5 485 394 56 59 1 bcsstk20.mtx >> CG_EnergyPropIntoP56to59rangeNis800/EnergyProp56to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoX56to59rangeNis200
./mainCGEnergyProp2 5 485 96 56 59 2 bcsstk20.mtx >> CG_EnergyPropIntoX56to59rangeNis200/EnergyProp56to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoX56to59rangeNis400
./mainCGEnergyProp2 5 485 192 56 59 2 bcsstk20.mtx >> CG_EnergyPropIntoX56to59rangeNis400/EnergyProp56to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoX56to59rangeNis600
./mainCGEnergyProp2 5 485 288 56 59 2 bcsstk20.mtx >> CG_EnergyPropIntoX56to59rangeNis600/EnergyProp56to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoX56to59rangeNis800
./mainCGEnergyProp2 5 485 394 56 59 2 bcsstk20.mtx >> CG_EnergyPropIntoX56to59rangeNis800/EnergyProp56to63result_bcsstk20.txt
mkdir CG_EnergyPropIntoR52to55rangeNis200
./mainCGEnergyProp2 5 485 96 52 55 0 bcsstk20.mtx >> CG_EnergyPropIntoR52to55rangeNis200/EnergyProp52to55result_bcsstk20.txt
mkdir CG_EnergyPropIntoR52to55rangeNis400
./mainCGEnergyProp2 5 485 192 52 55 0 bcsstk20.mtx >> CG_EnergyPropIntoR52to55rangeNis400/EnergyProp52to55result_bcsstk20.txt
mkdir CG_EnergyPropIntoR52to55rangeNis600
./mainCGEnergyProp2 5 485 288 52 55 0 bcsstk20.mtx >> CG_EnergyPropIntoR52to55rangeNis600/EnergyProp52to55result_bcsstk20.txt
mkdir CG_EnergyPropIntoR52to55rangeNis800
./mainCGEnergyProp2 5 485 394 52 55 0 bcsstk20.mtx >> CG_EnergyPropIntoR52to55rangeNis800/EnergyProp52to55result_bcsstk20.txt
mkdir CG_EnergyPropIntoP52to55rangeNis200
./mainCGEnergyProp2 5 485 96 52 55 1 bcsstk20.mtx >> CG_EnergyPropIntoP52to55rangeNis200/EnergyProp52to55result_bcsstk20.txt
mkdir CG_EnergyPropIntoP52to55rangeNis400
./mainCGEnergyProp2 5 485 192 52 55 1 bcsstk20.mtx >> CG_EnergyPropIntoP52to55rangeNis400/EnergyProp52to55result_bcsstk20.txt
mkdir CG_EnergyPropIntoP52to55rangeNis600
./mainCGEnergyProp2 5 485 288 52 55 1 bcsstk20.mtx >> CG_EnergyPropIntoP52to55rangeNis600/EnergyProp52to55result_bcsstk20.txt
mkdir CG_EnergyPropIntoP52to55rangeNis800
./mainCGEnergyProp2 5 485 394 52 55 1 bcsstk20.mtx >> CG_EnergyPropIntoP52to55rangeNis800/EnergyProp52to55result_bcsstk20.txt
mkdir CG_EnergyPropIntoX52to55rangeNis200
./mainCGEnergyProp2 5 485 96 52 55 2 bcsstk20.mtx >> CG_EnergyPropIntoX52to55rangeNis200/EnergyProp52to55result_bcsstk20.txt
mkdir CG_EnergyPropIntoX52to55rangeNis400
./mainCGEnergyProp2 5 485 192 52 55 2 bcsstk20.mtx >> CG_EnergyPropIntoX52to55rangeNis400/EnergyProp52to55result_bcsstk20.txt
mkdir CG_EnergyPropIntoX52to55rangeNis600
./mainCGEnergyProp2 5 485 288 52 55 2 bcsstk20.mtx >> CG_EnergyPropIntoX52to55rangeNis600/EnergyProp52to55result_bcsstk20.txt
mkdir CG_EnergyPropIntoX52to55rangeNis800
./mainCGEnergyProp2 5 485 394 52 55 2 bcsstk20.mtx >> CG_EnergyPropIntoX52to55rangeNis800/EnergyProp52to55result_bcsstk20.txt
mkdir CG_EnergyPropIntoR48to51rangeNis200
./mainCGEnergyProp2 5 485 96 48 51 0 bcsstk20.mtx >> CG_EnergyPropIntoR48to51rangeNis200/EnergyProp48to51result_bcsstk20.txt
mkdir CG_EnergyPropIntoR48to51rangeNis400
./mainCGEnergyProp2 5 485 192 48 51 0 bcsstk20.mtx >> CG_EnergyPropIntoR48to51rangeNis400/EnergyProp48to51result_bcsstk20.txt
mkdir CG_EnergyPropIntoR48to51rangeNis600
./mainCGEnergyProp2 5 485 288 48 51 0 bcsstk20.mtx >> CG_EnergyPropIntoR48to51rangeNis600/EnergyProp48to51result_bcsstk20.txt
mkdir CG_EnergyPropIntoR48to51rangeNis800
./mainCGEnergyProp2 5 485 394 48 51 0 bcsstk20.mtx >> CG_EnergyPropIntoR48to51rangeNis800/EnergyProp48to51result_bcsstk20.txt
mkdir CG_EnergyPropIntoP48to51rangeNis200
./mainCGEnergyProp2 5 485 96 48 51 1 bcsstk20.mtx >> CG_EnergyPropIntoP48to51rangeNis200/EnergyProp48to51result_bcsstk20.txt
mkdir CG_EnergyPropIntoP48to51rangeNis400
./mainCGEnergyProp2 5 485 192 48 51 1 bcsstk20.mtx >> CG_EnergyPropIntoP48to51rangeNis400/EnergyProp48to51result_bcsstk20.txt
mkdir CG_EnergyPropIntoP48to51rangeNis600
./mainCGEnergyProp2 5 485 288 48 51 1 bcsstk20.mtx >> CG_EnergyPropIntoP48to51rangeNis600/EnergyProp48to51result_bcsstk20.txt
mkdir CG_EnergyPropIntoP48to51rangeNis800
./mainCGEnergyProp2 5 485 394 48 51 1 bcsstk20.mtx >> CG_EnergyPropIntoP48to51rangeNis800/EnergyProp48to51result_bcsstk20.txt
mkdir CG_EnergyPropIntoX48to51rangeNis200
./mainCGEnergyProp2 5 485 96 48 51 2 bcsstk20.mtx >> CG_EnergyPropIntoX48to51rangeNis200/EnergyProp48to51result_bcsstk20.txt
mkdir CG_EnergyPropIntoX48to51rangeNis400
./mainCGEnergyProp2 5 485 192 48 51 2 bcsstk20.mtx >> CG_EnergyPropIntoX48to51rangeNis400/EnergyProp48to51result_bcsstk20.txt
mkdir CG_EnergyPropIntoX48to51rangeNis600
./mainCGEnergyProp2 5 485 288 48 51 2 bcsstk20.mtx >> CG_EnergyPropIntoX48to51rangeNis600/EnergyProp48to51result_bcsstk20.txt
mkdir CG_EnergyPropIntoX48to51rangeNis800
./mainCGEnergyProp2 5 485 394 48 51 2 bcsstk20.mtx >> CG_EnergyPropIntoX48to51rangeNis800/EnergyProp48to51result_bcsstk20.txt
 