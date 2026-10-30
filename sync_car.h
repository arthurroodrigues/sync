#ifndef SYNC_CAR_H
#define SYNC_CAR_H

#include <pthread.h>

struct station {
	pthread_mutex_t trava;
	pthread_cond_t carro_chegou;
	pthread_cond_t todos_sentados;
	int esperando;
	int assentos_livres;
	int embarcando;
};

void station_init(struct station *estacao);


#endif