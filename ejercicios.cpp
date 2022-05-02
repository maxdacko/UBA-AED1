#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"


using namespace std;
// Implementacion Problema 1
bool esEncuestaValida ( eph_h th, eph_i ti ) {
    return NoEsVacia(th)
    && NoEsVacia(ti)
    && esMatriz(ti)
    && esMatriz(th)
    && cantCorrectaColumnasI(ti)
    && cantCorrectaColumnasH (th)
    && noHayIndividuosSinHogares(th,ti)
    && noHayHogaresSinIndividuos(th,ti)
    && noHayHogaresRepetidos(th)
    && noHayIndividuosRepetidos(ti)
    && mismoAnioTrimestre(th,ti)
    && menos21Hab(th,ti)
    && cantidadValidaDormitorios(th,ti)
    && valoresIndRango(ti)
    && valoresHogRango(th);
}

// Implementacion Problema 2
vector < int > histHabitacional ( eph_h th, eph_i ti, int region ) {
    vector < int > res;
    for(int h=0;h<th.size();h++){
        if(enRegion(th[h],region)){
            int habitaciones = th[h][IV2];
            while(res.size()<habitaciones){ //largo
                res.push_back(0);
            }
            if(esCasa(th[h])){
                res[habitaciones-1]++;
            }
        }
    }
    return res;
}

// Implementacion Problema 3
vector< pair < int, float > > laCasaEstaQuedandoChica ( eph_h th, eph_i ti ) {
    vector<pair<int,float>> resp = {make_pair(1,-1.0),
                                    make_pair(40, -1.0),
                                    make_pair(41, -1.0),
                                    make_pair(42,-1.0),
                                    make_pair(43,-1.0),
                                    make_pair(44,-1.0)};
    for(int i=0;i<resp.size();i++){
        dato region = resp[i].first;
        int total =0;
        int hogarConHC =0;
        for(int h=0; h<th.size();h++){
            if (hogarValido(th[h],region)){
                total=total+1;
                if(hogarHC(th[h],ti)){
                    hogarConHC=hogarConHC+1;
                }
            }
        }
        if(total==0){
            resp[i].second=0;
        }else{
            resp[i].second =float(hogarConHC)/float(total);
        }
    }
    return resp;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
    return proporcionTeleworking(t2h,t2i)>proporcionTeleworking(t1h,t1i);
}

// Implementacion Problema 5
int costoSubsidioMejora( eph_h th, eph_i ti, int monto ){
    int resp =0;
    for(int h=0;h<th.size();h++){
        if(th[h][II7]==1 && casaChica(th[h],ti)){
            resp=resp+monto;
        }
    }
    return  resp;
}

// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){
    join_hi resp;
    for(int h=0;h<th.size();h++){
        for(int i=0;i<ti.size();i++){
            if(ti[i][INDCODUSU]==th[h][HOGCODUSU]){
                resp.push_back(make_pair(th[h],ti[i]));
            }
        }
    }
    return  resp;
}

// Implementacion Problema 7
void ordenarRegionYCODUSU (eph_h & th, eph_i & ti) {
    ordenarHogares(th);
    for(int i=0;i<ti.size();i++) {
        for (int j=ti.size()-1;j>i;j--) {
            if(indiceEnTablaHogares(ti[j],th)<indiceEnTablaHogares(ti[j-1],th)||
            (indiceEnTablaHogares(ti[j],th)==indiceEnTablaHogares(ti[j-1],th)&&ti[j][COMPONENTE]<ti[j-1][COMPONENTE])){
                swap(ti[j],ti[j-1]);
            }
        }
    }
}

// Implementacion Problema 8
vector < hogar > muestraHomogenea( eph_h & th, eph_i & ti ){
    vector <hogar> resp;
    vector<int> ingresosHogares= ingresosPorHogar(th,ti);
    ordenarPorIngresos(th,ingresosHogares);
    vector<int> muestra= buscarMuestra(ingresosHogares);
    for(int i=0;i<muestra.size();i++){
        resp.push_back(th[muestra[i]]);
    }
    return resp.size() >= 3 ? resp : vector<hogar>{}; //si largo de resp es >= 3 entrego resp, sino vector vacio
}

// Implementacion Problema 9
void corregirRegion( eph_h & th, eph_i ti ) {
    for(int h=0;h<th.size();h++){
        if(th[h][REGION]==1){
            th[h][REGION]=43;
        }
    }
}

// Implementacion Problema 10
vector < int > histogramaDeAnillosConcentricos( eph_h th, eph_i ti, pair < int, int > centro, vector < int > distancias ){
    vector < int > res={};
    for(int i=0;i<distancias.size();i++){
        int j=0;
        int desde=i== 0 ? 0 : distancias[i - 1]; //si i==0 desde=0, sino desde=distancias[i-1]
        int hasta=distancias[i];
        for(int h=0;h<th.size();h++){
            pair<int,int> posicion= make_pair(th[h][HOGLATITUD],th[h][HOGLONGITUD]);
            if(hogarEnAnillo(desde,hasta,centro,posicion)){
                j++;
            }
        }
        res.push_back(j);
    }
    return res;
}

// Implementacion Problema 11
pair < eph_h, eph_i > quitarIndividuos(eph_i & ti, eph_h & th, vector < pair < int, dato > >  busqueda ){
    eph_h rth = {};
    eph_i rti = {};
    pair<eph_h, eph_i> res = make_pair(rth, rti);

    eph_i ti0 = ti;
    eph_h th0= th;

    for(int i=0;i<ti0.size();i++){
        if(indCoincide(ti0[i],busqueda)){
            if (indiceEnTablaHogares(ti0[i],res.first)==-1){
                res.first.push_back(th[indiceEnTablaHogares(ti0[i], th)]);
            }
            res.second.push_back(ti[i]);
            ti.erase(ti.begin() + i - res.second.size() + 1);
        }
    }
    int cant_borrados = 0;
    for (int h=0;h<th0.size();h++) {
        if(cantidadHabitantes(ti,th0[h])==0) {
            th.erase(th.begin() + h - cant_borrados);
            cant_borrados++;
        }
    }
    return res;
}
