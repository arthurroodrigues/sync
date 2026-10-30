#include "sync_car.h"

void station_init(struct station *estacao)
{
	pthread_mutex_init(&estacao->trava, NULL);
	pthread_cond_init(&estacao->carro_chegou, NULL);
	pthread_cond_init(&estacao->todos_sentados, NULL);
	estacao->esperando = 0;
	estacao->assentos_livres = 0;
	estacao->embarcando = 0;
}