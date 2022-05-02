#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

//auxiliares Generales
bool enRegion (hogar &h, dato region){
    return h[REGION]== region;
}

bool esCasa (hogar &h){
    return h[IV1]==1;
}

bool menos500000Hab (hogar &h){
    return h[MAS_500]==0;
}

int cantidadHabitantes(eph_i &ti, hogar &h) {
    int res = 0;
    for (int i = 0; i < ti.size(); i++) {
        if (ti[i][INDCODUSU]==h[HOGCODUSU]) {
            res++;
        }
    }
    return res;
}

int cantidadDormitorios(hogar &h) {
    return h[II2];
}

bool casaODepartamento(hogar &h){
    return (h[IV1]==1||h[IV1]==2);
}


bool ciudadGrande(hogar &h){
    return h[MAS_500]==1;
}

hogar hogarDelInd(eph_h &th, individuo &i){
    hogar res;
    for(int h=0;h<th.size();h++)
        if(i[INDCODUSU]==th[h][HOGCODUSU]){
            res=th[h];
        }
    return res;
}

int indiceEnTablaHogares(individuo &ind, eph_h &th){
    int res = -1;
    for (int i = 0; i<th.size(); i++) {
        if (th[i][HOGCODUSU] == ind[INDCODUSU]){
            res = i;
        }
    }
    return res;
}

//auxiliares problema 1
bool NoEsVacia(vector<vector<dato>> m){
    return m.size()>0;
}

bool esMatriz (vector<vector<dato>> &m){
    for(int i=1;i<m.size();i++){
        if(m[i].size() != m[0].size()){
            return false;
        }
    }
    return true;
}

bool cantCorrectaColumnasI(eph_i &ti){
    for(int i=0;i<ti.size();i++){
        if(ti[i].size()!=11){
            return false;
    }
    return true;
    }
}

bool cantCorrectaColumnasH(eph_h &th){
    for(int h=0;h<th.size();h++){
        if(th[h].size()!=12){
            return false;
        }
    }
    return true;
}

bool noHayIndividuosSinHogares(eph_h &th, eph_i &ti){
    int aux=0;
    for(int i=0;i<ti.size();i++){
        for(int h=0;h<th.size();h++){
            if(th[h][HOGCODUSU]==ti[i][INDCODUSU]){
                aux++;
            }
        }
    }
    if(aux==ti.size()){
        return true;
    }else{
        return false;
    }
}

bool noHayHogaresSinIndividuos(eph_h &th, eph_i &ti){
    int aux=0;
    for(int h=0;h<th.size();h++){
        for(int i=0;i<ti.size();i++){
            if(th[h][HOGCODUSU]==ti[i][INDCODUSU]){
                aux++;
            }
        }
    }
    if(aux==ti.size()){
        return true;
    }else{
        return false;
    }
}

bool noHayHogaresRepetidos(eph_h &th){
    for(int i=0; i<th.size();i++){
        for(int j=0; j<th.size();j++){
            if(i!=j && th[i][HOGCODUSU]==th[j][HOGCODUSU]){
                return false;
            }
        }
    }
    return true;
}

bool noHayIndividuosRepetidos(eph_i &ti){
    for(int i=0; i<ti.size();i++){
        for(int j=0; j<ti.size();j++){
            if(i!=j && ti[i][INDCODUSU]==ti[j][INDCODUSU] && ti[i][COMPONENTE]==ti[j][COMPONENTE]){
                return false;
            }
        }
    }
    return true;
}

bool mismoAnioTrimestre(eph_h th, eph_i ti){
    dato anio=ti[0][INDANIO];
    dato trimestre=ti[0][INDTRIMESTRE];
    for(int i=0; i<ti.size(); i++){
        if(ti[i][INDANIO]!=anio ||ti[i][INDTRIMESTRE]!=trimestre){
            return false;
        }
    }
    for(int h=0;h<th.size(); h++){
        if(th[h][HOGANIO]!=anio || th[h][HOGTRIMESTRE]!=trimestre){
            return false;
        }
    }
    return true;
}

bool menos21Hab(eph_h &th, eph_i &ti){
    for(int h=0;h<th.size();h++){
        int i=0;
        int habitantes =0;
        while(i<ti.size() && habitantes <21){
            if(th[h][HOGCODUSU]==ti[i][INDCODUSU]){
                habitantes++;
            }
            i++;
        }
        if (habitantes==21){
            return false;
        }
    }
    return true;
}


bool cantidadValidaDormitorios(eph_h &th, eph_i &ti){
    for(int h=0;h<th.size();h++){
        if(th[h][IV2]<th[h][II2]){
            return false;
        }
    }
    return true;
}

bool valoresEnRangoH(hogar &h){
    return 0 < h[HOGCODUSU]
    && 0 < h[HOGTRIMESTRE] && h[HOGTRIMESTRE] <= 4
    && 0 < h[II7] && h[II7] <= 3
    && (h[REGION] == 1 || (40 <= h[REGION] && h[REGION] <= 44))
    && 0 <= h[MAS_500] && h[MAS_500] <= 1
    && 0 < h[IV1] && h[IV1] <= 5
    && 0 < h[IV2]
    && 0 < h[II2]
    && 1 <= h[II3] && h[II3] <= 2;
}

bool valoresHogRango(eph_h &th){
    bool res=true;
    for(int h=0; h<th.size() && res;h++){
        if(!valoresEnRangoH(th[h])){
            res=false;
        }
    }
    return res;
}

bool valoresEnRangoI(individuo &i){
    return 0 < i[INDCODUSU]
    && 0 < i[COMPONENTE]
    && 0 < i[INDTRIMESTRE] && i[INDTRIMESTRE] <= 4
    && 0 < i[CH4] && i[CH4] <= 2
    && 0 <= i[CH6]
    && 0 <= i[NIVEL_ED] && i[NIVEL_ED] <= 1
    && -1 <= i[ESTADO] && i[ESTADO] <= 1
    && 0 <= i[CAT_OCUP] && i[CAT_OCUP] <= 4
    && -1 <= i[p47T]
    && 0 <= i[PP04G] && i[PP04G] <= 10;
}

bool valoresIndRango(eph_i &ti){
    bool res=true;
    for(int i=0; i<ti.size() && res;i++){
        if(!valoresEnRangoI(ti[i])){
            res=false;
        }
    }
    return res;
}


//auxiliares problema 3
bool hogarValido(hogar &h,dato region){
    return (enRegion(h,region) && esCasa(h) && menos500000Hab(h));
}

bool hogarHC(hogar &h, eph_i &ti) {
    return cantidadHabitantes(ti, h) > 3 * cantidadDormitorios(h);
}

//auxiliares problema 4
float proporcionTeleworking(eph_h &th, eph_i &ti){
    int cantTrabajan=0;
    int cantTW=0;
    for(int i=0;i<ti.size();i++){
        hogar h= hogarDelInd(th,ti[i]);
        if(ti[i][ESTADO]==1 && ciudadGrande(h) && casaODepartamento(h)){
            cantTrabajan++;
            if(ti[i][PP04G]==6 && h[II3]==1){
                cantTW++;
            }
        }
    }
    if(cantTrabajan==0){
        return 0;
    }else{
        return float(cantTW)/float(cantTrabajan);
    }
}

//auxiliares problema 5
bool casaChica(hogar &h,eph_i ti){
    return cantidadHabitantes(ti,h)-2> cantidadDormitorios(h);
}

//auxiliares problema 7
void ordenarHogares(eph_h &th){
    for (int i=0;i<th.size();i++) {
        for (int j=th.size()-1;j>i;j--) {
            if (th[j][REGION]< th[j-1][REGION]||
            (th[j][REGION]==th[j-1][REGION]&& th[j][HOGCODUSU]<th[j-1][HOGCODUSU])){
                swap(th[j],th[j-1]);
            }
        }
    }
}


//auxiliares problema 8
int ingresosDelHogar(hogar &h,eph_i &ti){
    int res=0;
    for(int i=0;i<ti.size();i++){
        int ingresosInd=ti[i][p47T];
        if(ti[i][INDCODUSU]==h[HOGCODUSU] && ingresosInd>0){
            res=res+ingresosInd;
        }
    }
    return res;
}

vector <int> ingresosPorHogar(eph_h &th,eph_i &ti){
    vector<int> res(th.size());
    for(int h=0;h<th.size();h++){
        res[h]=ingresosDelHogar(th[h],ti);
    }
    return res;
}

void ordenarPorIngresos(eph_h &th, vector<int> &ingresosHogares){
    for(int i=0;i<ingresosHogares.size();i++){
        int ingresoMin=i;
        for(int j=i;j<ingresosHogares.size();j++){
            if(ingresosHogares[j]<ingresosHogares[ingresoMin]){
                ingresoMin=j;
            }
        }
        swap(th[ingresoMin],th[i]);
        swap(ingresosHogares[ingresoMin],ingresosHogares[i]);
    }
}

void completarMuestra(vector<int> &muestra, int diferencia,vector<int> &ingresosHogares){
    int i=muestra[1];
    int j=muestra[1]+1;
    while(j<ingresosHogares.size()){
        if(ingresosHogares[j]-ingresosHogares[i]==diferencia){
            i=j;
            muestra.push_back(j);
        }
        j++;
    }
}

vector <int> buscarMuestra(vector<int> &ingresosHogares){
    vector<int> res;
    for(int i=0; i<ingresosHogares.size();i++){
        for (int j=i+1; j<ingresosHogares.size(); j++){
            int diferencia=ingresosHogares[j]-ingresosHogares[i];
            if(diferencia>0){
                vector<int> muestra={i,j};
                completarMuestra(muestra,diferencia,ingresosHogares);
                if(muestra.size()>res.size()){
                    res=muestra;
                }
            }
        }
    }
    return res;
}


//auxiliares problema 10
float distanciaEuclideana(pair<int,int> centro, pair<int,int> posicion){
    float a=centro.first-posicion.first;
    float b=centro.second-posicion.second;
    return sqrt(a*a + b*b);
}

bool hogarEnAnillo(int desde, int hasta, pair<int,int> centro, pair<int,int> posicion){
    return desde < distanciaEuclideana(centro,posicion) &&
    distanciaEuclideana(centro,posicion) <= hasta;
}

//auxiliares problema 11
bool indCoincide(individuo &ind, vector<pair<int,dato>> &busqueda){
    for (int i=0;i<busqueda.size();i++){
        if(ind[busqueda[i].first]!= busqueda[i].second){
            return false;
        }
    }
    return true;
}

