#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

//auxiliares problema 1
bool hogarValido(hogar &h,dato region);
bool hogarHC(hogar &h, eph_i &ti);
bool enRegion (hogar &h, dato region);
bool esCasa (hogar &h);
bool NoEsVacia(vector<vector<dato>> m);
bool esMatriz (vector<vector<dato>> &m);
bool cantCorrectaColumnasI(eph_i &ti);
bool cantCorrectaColumnasH(eph_h &th);
bool noHayIndividuosSinHogares(eph_h &th, eph_i &ti);
bool noHayHogaresSinIndividuos(eph_h &th, eph_i &ti);
bool noHayHogaresRepetidos(eph_h &th);
bool noHayIndividuosRepetidos(eph_i &ti);
bool mismoAnioTrimestre(eph_h th, eph_i ti);
bool menos21Hab(eph_h &th, eph_i &ti);
bool cantidadValidaDormitorios(eph_h &th, eph_i &ti);
bool valoresHogRango(eph_h &th);
bool valoresIndRango(eph_i &ti);
float proporcionTeleworking (eph_h &th, eph_i &ti);
bool casaChica(hogar &h,eph_i ti);
void ordenarHogares(eph_h &th);
vector <int> ingresosPorHogar(eph_h &th,eph_i &ti);
void ordenarPorIngresos(eph_h &th,vector<int> &ingresos);
vector <int> buscarMuestra(vector<int> &ingresos);
float distanciaEuclideana(pair<int,int> p1, pair<int,int> p2);
bool hogarEnAnillo(int desde, int hasta, pair<int,int> centro, pair<int,int> posicion);
bool indCoincide(individuo &ind, vector<pair<int,dato>> &busqueda);
int cantidadHabitantes(eph_i &ti, hogar &h);
int indiceEnTablaHogares(individuo &ind, eph_h  &th);


#endif //SOLUCION_AUXILIARES_H
