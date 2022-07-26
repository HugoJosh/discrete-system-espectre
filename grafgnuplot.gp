# GRAFICA CUATRO GRAFICAS EN UNA VENTANA
set term png
set output  "magyfase.png"

set autoscale
set multiplot layout 2,1 rowsfirst
set grid
set style data lines

#------------- Graf 1 ----------------
set title "Magnitud"
#unset label
set logscale y 10
set xlabel   "k"
set ylabel   "|y(k)|"
plot  "fespec.dat"
unset xlabel
unset ylabel
unset title

unset logscale
#------------- Graf 2 ----------------
set title "Fase"
# unset label
set xlabel   "k"
set ylabel   "theta(k)"
plot  "fespec2.dat"
unset xlabel
unset ylabel
unset title
#pause(3)
#unset multiplot

#