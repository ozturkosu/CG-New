#!/bin/bash
#SBATCH --time=23:59:00
mkdir IntoR60to63rangeNis200
./mainCGEnergyRelative 5 494 100 60 63 0 494_bus.mtx >> IntoR60to63rangeNis200/relative_494_bus.txt
mkdir IntoR60to63rangeNis400
./mainCGEnergyRelative 5 494 200 60 63 0 494_bus.mtx >> IntoR60to63rangeNis400/relative_494_bus.txt
mkdir IntoR60to63rangeNis600
./mainCGEnergyRelative 5 494 300 60 63 0 494_bus.mtx >> IntoR60to63rangeNis600/relative_494_bus.txt
mkdir IntoR60to63rangeNis800
./mainCGEnergyRelative 5 494 400 60 63 0 494_bus.mtx >> IntoR60to63rangeNis800/relative_494_bus.txt
mkdir IntoP60to63rangeNis200
./mainCGEnergyRelative 5 494 100 60 63 1 494_bus.mtx >> IntoP60to63rangeNis200/relative_494_bus.txt
mkdir IntoP60to63rangeNis400
./mainCGEnergyRelative 5 494 200 60 63 1 494_bus.mtx >> IntoP60to63rangeNis400/relative_494_bus.txt
mkdir IntoP60to63rangeNis600
./mainCGEnergyRelative 5 494 300 60 63 1 494_bus.mtx >> IntoP60to63rangeNis600/relative_494_bus.txt
mkdir IntoP60to63rangeNis800
./mainCGEnergyRelative 5 494 400 60 63 1 494_bus.mtx >> IntoP60to63rangeNis800/relative_494_bus.txt
mkdir IntoX60to63rangeNis200
./mainCGEnergyRelative 5 494 100 60 63 2 494_bus.mtx >> IntoX60to63rangeNis200/relative_494_bus.txt
mkdir IntoX60to63rangeNis400
./mainCGEnergyRelative 5 494 200 60 63 2 494_bus.mtx >> IntoX60to63rangeNis400/relative_494_bus.txt
mkdir IntoX60to63rangeNis600
./mainCGEnergyRelative 5 494 300 60 63 2 494_bus.mtx >> IntoX60to63rangeNis600/relative_494_bus.txt
mkdir IntoX60to63rangeNis800
./mainCGEnergyRelative 5 494 400 60 63 2 494_bus.mtx >> IntoX60to63rangeNis800/relative_494_bus.txt
mkdir IntoR56to59rangeNis200
./mainCGEnergyRelative 5 494 100 56 59 0 494_bus.mtx >> IntoR56to59rangeNis200/relative_494_bus.txt
mkdir IntoR56to59rangeNis400
./mainCGEnergyRelative 5 494 200 56 59 0 494_bus.mtx >> IntoR56to59rangeNis400/relative_494_bus.txt
mkdir IntoR56to59rangeNis600
./mainCGEnergyRelative 5 494 300 56 59 0 494_bus.mtx >> IntoR56to59rangeNis600/relative_494_bus.txt
mkdir IntoR56to59rangeNis800
./mainCGEnergyRelative 5 494 400 56 59 0 494_bus.mtx >> IntoR56to59rangeNis800/relative_494_bus.txt
mkdir IntoP56to59rangeNis200
./mainCGEnergyRelative 5 494 100 56 59 1 494_bus.mtx >> IntoP56to59rangeNis200/relative_494_bus.txt
mkdir IntoP56to59rangeNis400
./mainCGEnergyRelative 5 494 200 56 59 1 494_bus.mtx >> IntoP56to59rangeNis400/relative_494_bus.txt
mkdir IntoP56to59rangeNis600
./mainCGEnergyRelative 5 494 300 56 59 1 494_bus.mtx >> IntoP56to59rangeNis600/relative_494_bus.txt
mkdir IntoP56to59rangeNis800
./mainCGEnergyRelative 5 494 400 56 59 1 494_bus.mtx >> IntoP56to59rangeNis800/relative_494_bus.txt
mkdir IntoX56to59rangeNis200
./mainCGEnergyRelative 5 494 100 56 59 2 494_bus.mtx >> IntoX56to59rangeNis200/relative_494_bus.txt
mkdir IntoX56to59rangeNis400
./mainCGEnergyRelative 5 494 200 56 59 2 494_bus.mtx >> IntoX56to59rangeNis400/relative_494_bus.txt
mkdir IntoX56to59rangeNis600
./mainCGEnergyRelative 5 494 300 56 59 2 494_bus.mtx >> IntoX56to59rangeNis600/relative_494_bus.txt
mkdir IntoX56to59rangeNis800
./mainCGEnergyRelative 5 494 400 56 59 2 494_bus.mtx >> IntoX56to59rangeNis800/relative_494_bus.txt
mkdir IntoR52to55rangeNis200
./mainCGEnergyRelative 5 494 100 52 55 0 494_bus.mtx >> IntoR52to55rangeNis200/relative_494_bus.txt
mkdir IntoR52to55rangeNis400
./mainCGEnergyRelative 5 494 200 52 55 0 494_bus.mtx >> IntoR52to55rangeNis400/relative_494_bus.txt
mkdir IntoR52to55rangeNis600
./mainCGEnergyRelative 5 494 300 52 55 0 494_bus.mtx >> IntoR52to55rangeNis600/relative_494_bus.txt
mkdir IntoR52to55rangeNis800
./mainCGEnergyRelative 5 494 400 52 55 0 494_bus.mtx >> IntoR52to55rangeNis800/relative_494_bus.txt
mkdir IntoP52to55rangeNis200
./mainCGEnergyRelative 5 494 100 52 55 1 494_bus.mtx >> IntoP52to55rangeNis200/relative_494_bus.txt
mkdir IntoP52to55rangeNis400
./mainCGEnergyRelative 5 494 200 52 55 1 494_bus.mtx >> IntoP52to55rangeNis400/relative_494_bus.txt
mkdir IntoP52to55rangeNis600
./mainCGEnergyRelative 5 494 300 52 55 1 494_bus.mtx >> IntoP52to55rangeNis600/relative_494_bus.txt
mkdir IntoP52to55rangeNis800
./mainCGEnergyRelative 5 494 400 52 55 1 494_bus.mtx >> IntoP52to55rangeNis800/relative_494_bus.txt
mkdir IntoX52to55rangeNis200
./mainCGEnergyRelative 5 494 100 52 55 2 494_bus.mtx >> IntoX52to55rangeNis200/relative_494_bus.txt
mkdir IntoX52to55rangeNis400
./mainCGEnergyRelative 5 494 200 52 55 2 494_bus.mtx >> IntoX52to55rangeNis400/relative_494_bus.txt
mkdir IntoX52to55rangeNis600
./mainCGEnergyRelative 5 494 300 52 55 2 494_bus.mtx >> IntoX52to55rangeNis600/relative_494_bus.txt
mkdir IntoX52to55rangeNis800
./mainCGEnergyRelative 5 494 400 52 55 2 494_bus.mtx >> IntoX52to55rangeNis800/relative_494_bus.txt
mkdir IntoR48to51rangeNis200
./mainCGEnergyRelative 5 494 100 48 51 0 494_bus.mtx >> IntoR48to51rangeNis200/relative_494_bus.txt
mkdir IntoR48to51rangeNis400
./mainCGEnergyRelative 5 494 200 48 51 0 494_bus.mtx >> IntoR48to51rangeNis400/relative_494_bus.txt
mkdir IntoR48to51rangeNis600
./mainCGEnergyRelative 5 494 300 48 51 0 494_bus.mtx >> IntoR48to51rangeNis600/relative_494_bus.txt
mkdir IntoR48to51rangeNis800
./mainCGEnergyRelative 5 494 400 48 51 0 494_bus.mtx >> IntoR48to51rangeNis800/relative_494_bus.txt
mkdir IntoP48to51rangeNis200
./mainCGEnergyRelative 5 494 100 48 51 1 494_bus.mtx >> IntoP48to51rangeNis200/relative_494_bus.txt
mkdir IntoP48to51rangeNis400
./mainCGEnergyRelative 5 494 200 48 51 1 494_bus.mtx >> IntoP48to51rangeNis400/relative_494_bus.txt
mkdir IntoP48to51rangeNis600
./mainCGEnergyRelative 5 494 300 48 51 1 494_bus.mtx >> IntoP48to51rangeNis600/relative_494_bus.txt
mkdir IntoP48to51rangeNis800
./mainCGEnergyRelative 5 494 400 48 51 1 494_bus.mtx >> IntoP48to51rangeNis800/relative_494_bus.txt
mkdir IntoX48to51rangeNis200
./mainCGEnergyRelative 5 494 100 48 51 2 494_bus.mtx >> IntoX48to51rangeNis200/relative_494_bus.txt
mkdir IntoX48to51rangeNis400
./mainCGEnergyRelative 5 494 200 48 51 2 494_bus.mtx >> IntoX48to51rangeNis400/relative_494_bus.txt
mkdir IntoX48to51rangeNis600
./mainCGEnergyRelative 5 494 300 48 51 2 494_bus.mtx >> IntoX48to51rangeNis600/relative_494_bus.txt
mkdir IntoX48to51rangeNis800
./mainCGEnergyRelative 5 494 400 48 51 2 494_bus.mtx >> IntoX48to51rangeNis800/relative_494_bus.txt
 