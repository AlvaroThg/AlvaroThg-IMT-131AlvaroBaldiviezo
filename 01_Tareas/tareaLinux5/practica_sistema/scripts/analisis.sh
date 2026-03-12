#!/bin/bash
wc -l ../datos/usuarios.txt

grep "error" ../datos/accesos.log | wc -l

sort ../datos/usuarios.txt

